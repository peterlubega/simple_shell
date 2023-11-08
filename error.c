#include <stdio.h>


/**
 * reportError - Prints an error message using perror.
 * @errorMessage: A description of the error.
 */
void reportError(const char *errorMessage)
{
perror(errorMessage);
}
