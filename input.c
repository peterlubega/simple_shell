#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * readUserInput - Reads user input from the standard input.
 * @input: A character array to store the user input.
 * @maxLength: The maximum length of input to read.
 */
void readUserInput(char *input, int maxLength)
{
if (fgets(input, maxLength, stdin) == NULL)
{
exit(0); /* Exit on Ctrl+D (end of file) */
}
}

/**
 * cleanInput - Removes the newline character from user input.
 * @input: A character array containing user input.
 */
void cleanInput(char *input)
{
int i = 0;
while (input[i] != '\0')
{
if (input[i] == '\n')
{
input[i] = '\0';
/* Stop iterating after replacing the first newline character */
break;
}
i++;
}
}
