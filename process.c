#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "error.h"
#include <stdlib.h>

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
if (execve(command, args, NULL) == -1)
{
reportError("execve");
exit(1);
}
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
