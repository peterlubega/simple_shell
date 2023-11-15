#ifndef PROCESS_H
#define PROCESS_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Function declarations */
pid_t createChildProcess(void);
void executeCommand(const char *command, char *const args[]);
void waitForChildProcess(pid_t childPid);

#endif
