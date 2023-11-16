#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "process.h"
#include "error.h"
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

/**
 * handleExitCommand - Handles the exit command.
 *
 * This function is called when the user inputs the "exit" command. It prints
 * a message indicating the shell is exiting and terminates the program.
 */
void handleExitCommand(void)
{
exit(0);
}

/**
 * executeChildProcess - Executes a child process.
 *
 * This function creates a child process, handles errors if the fork fails,
 * and executes the command with its arguments in the child process. It waits
 * for the child process to complete in the parent process.
 *
 * @input: The user input containing the command and arguments.
 */
void executeChildProcess(char *input)
{
pid_t child_pid = createChildProcess();

if (child_pid == -1)
{
reportError("fork");
exit(1);
}
else if (child_pid == 0)
{
char *args[MAX_COMMAND_LENGTH];
int i = 0;
args[i] = strtok(input, " ");

while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " ");
}

executeCommand(args[0], args);
exit(1);
}
else
{
waitForChildProcess(child_pid);
}
}

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

while (1)
{
fflush(stdout);

readUserInput(input, MAX_COMMAND_LENGTH);
cleanInput(input);

if (strcmp(input, "exit") == 0)
{
handleExitCommand();
}

executeChildProcess(input);
}

return (0);
}
