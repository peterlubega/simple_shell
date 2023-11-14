#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

/**
 * createChildProcess - Creates a child process using fork().
 *
 * Return: The PID of the child process for the parent, or 0 for the child.
 */
pid_t createChildProcess(void)
{
return (fork());
}

/**
 * waitForChildProcess - Waits for the child process to finish.
 * @childPid: The PID of the child process to wait for.
 */
void waitForChildProcess(pid_t childPid __attribute__((unused)))
{
int status;
waitpid(childPid, &status, 0);
}

/**
 * executeCommand - Executes a command with arguments in the child process.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 */
void executeCommand(const char *command, char *const args[])
{
/* Find the command in the PATH */
char *path = getenv("PATH");
char *token;
char commandPath[1024];  /* Assuming a maximum path length */

token = strtok(path, ":");

while (token != NULL)
{
snprintf(commandPath, sizeof(commandPath), "%s/%s", token, command);

if (access(commandPath, X_OK) == 0)
{
/* If the command exists, execute it */
pid_t child_pid = createChildProcess();

if (child_pid == -1)
{
reportError("fork");
exit(1);
}
else if (child_pid == 0)
{
/* In the child process */
execve(commandPath, args, NULL);
/* If execve fails, report an error */
reportError("execve");
exit(1);
}
else
{
/* In the parent process */
waitForChildProcess(child_pid);
return;  /* Return after waiting for the child process */
}
}

token = strtok(NULL, ":");
}

/* If the loop completes, the command was not found */
fprintf(stderr, "Command not found: %s\n", command);
exit(1);
}
