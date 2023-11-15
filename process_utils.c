#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
