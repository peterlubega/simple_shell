#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "error.h"
#include <stdlib.h>
#include <string.h>

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
 * executeCommand - Executes a command with arguments in the child process.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 */

void executeCommand(const char *command, char * const args[])
{
/* Get the PATH environment variable */
char *path = getenv("PATH");

if (path == NULL)
{
/* Handle the case where PATH is not set */
reportError("getenv(PATH)");
exit(1);
}

/* Duplicate path string to avoid modifying the original */
char *pathCopy = strdup(path);

if (pathCopy == NULL)
{
reportError("strdup");
exit(1);
}

/* Declare variables */

char *dir = strtok(pathCopy, ":");
/* Declare variables before using them */
while (dir != NULL)
{
/* Construct the full path to the command */
char fullPath[1024];
/* Assuming a maximum path length of 1024 */
snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, command);

/* Check if the command exists in the current directory */
if (access(fullPath, X_OK) == 0)
{
/* Command exists, execute it */
if (execve(fullPath, args, NULL) == -1)
{
reportError("execve");
exit(1);
}
}

/* Move to the next directory in PATH */
dir = strtok(NULL, ":");
}


/* If the loop completes, the command was not found in any directory */
fprintf(stderr, "Command not found: %s\n", command);
exit(1);
}



/**
 * waitForChildProcess - Waits for the child process to finish.
 * @childPid: The PID of the child process to wait for.
 */
void waitForChildProcess(pid_t childPid __attribute__((unused)))
{
int status;
wait(&status);
}
