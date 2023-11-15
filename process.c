#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "process.h"

/**
 * executeAbsolutePath - Executes a command with an absolute path
 * in the child process.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 */
static void executeAbsolutePath(const char *command, char *const args[])
{
pid_t child_pid = fork();

if (child_pid == -1)
{
perror("fork");
exit(1);
}
else if (child_pid == 0)
{
/* In the child process */
execve(command, args, NULL);
/* If execve fails, report an error */
perror("execve");
_exit(1);
}
else
{
/* In the parent process */
waitpid(child_pid, NULL, 0);
}
}

/**
 * executeCommandInChild - Executes a command in the child process.
 * @commandPath: The full path of the command to execute.
 * @args: An array of arguments for the command.
 */
static void executeCommandInChild(const char *commandPath, char *const args[])
{
execve(commandPath, args, environ);
/* If execve fails, report an error */
perror("execve");
exit(1);
}

/**
 * findAndExecuteCommand - Finds a command in the PATH and executes
 * it in the child process.
 *
 * This function searches for the specified command in the directories listed
 * in the PATH environment variable.
 * If the command is found, it is executed in a child process.
 *
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 * Return: 1 if the command is found and executed successfully, 0 otherwise.
 */
static int findAndExecuteCommand(const char *command, char *const args[])
{
char *path = getenv("PATH");
char *token;
char commandPath[1024]; /* Assuming a maximum path length */

token = strtok(path, ":");

while (token != NULL)
{
strcpy(commandPath, token);
strcat(commandPath, "/");
strcat(commandPath, command);

if (access(commandPath, X_OK) == 0)
{
/* If the command exists, execute it */
pid_t child_pid = createChildProcess();

if (child_pid == -1)
{
perror("fork");
exit(1);
}
else if (child_pid == 0)
{
/* In the child process */
executeCommandInChild(commandPath, args);
}
else
{
/* In the parent process */
waitpid(child_pid, NULL, 0);
return (1); /* Command found and executed */
}
}

token = strtok(NULL, ":");
}

return (0); /* Command not found */
}

/**
 * executeInPath - Executes a command found in the PATH in the child process.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 */
static void executeInPath(const char *command, char *const args[])
{
int found = findAndExecuteCommand(command, args);

if (!found)
{
fprintf(stderr, "Command not found: %s\n", command);
exit(1);
}
}

/**
 * executeCommand - Executes a command with arguments in the child process.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 */
void executeCommand(const char *command, char *const args[])
{
/* Check if the command is an absolute path */
if (strchr(command, '/') != NULL)
{
executeAbsolutePath(command, args);
}
else
{
/* Find the command in the PATH */
executeInPath(command, args);
}
}
