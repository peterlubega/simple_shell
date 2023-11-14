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

/* Check for the exit command */
if (strcmp(input, "exit") == 0)
{
printf("Exiting the shell...\n");
exit(0);
}

child_pid = createChildProcess();

if (child_pid == -1)
{
reportError("fork");
exit(1);
}
else if (child_pid == 0)
{
/* Split the input into command and arguments */
char *args[MAX_COMMAND_LENGTH];
int i = 0;
args[i] = strtok(input, " ");

while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " ");
}

/* Call executeCommand with the command and arguments */
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
