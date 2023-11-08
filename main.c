#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "process.h"
#include "error.h"
#include <string.h>


#define MAX_COMMAND_LENGTH 1024

/**
 * main - Entry point for the simple shell program.
 *
 * This function is the entry point of the simple shell program. It displays
 * a command prompt, reads user input, processes and executes the commands,
 * and waits for the child processes to complete.
 *
 * Return: Always returns 0.
 */
int main(void)
{
char input[MAX_COMMAND_LENGTH];
pid_t child_pid;

while (1)
{
printf("$ ");
fflush(stdout);

readUserInput(input, MAX_COMMAND_LENGTH);
cleanInput(input);

child_pid = createChildProcess();

if (child_pid == -1)
{
reportError("fork");
exit(1);
}
else if (child_pid == 0)
{
char *args[2];
args[0] = strtok(input, " ");
args[1] = NULL;

executeCommand(args[0], args);
exit(1);
}
else
{
waitForChildProcess(child_pid);
}
}

return (0);
}
