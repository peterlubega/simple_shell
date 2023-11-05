0x16. C - Simple Shell
"In this project, we are building a simple shell"
Who designed and implemented the original Unix operating system:
The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie, and other collaborators at Bell Labs in the late 1960s and early 1970s.

Who wrote the first version of the UNIX shell:
The first version of the UNIX shell, known as the Thompson shell, was written by Ken Thompson in 1971. It was a command-line interface that allowed users to interact with the Unix operating system.

Who invented the B programming language (the direct predecessor to the C programming language):
The B programming language, a precursor to the C programming language, was developed by Ken Thompson in 1970 at Bell Labs. Dennis Ritchie later developed C based on the ideas and syntax of the B language.

Who is Ken Thompson:
Ken Thompson is a computer scientist and one of the original creators of the Unix operating system. He is also known for his work on the B programming language and the development of early Unix tools and utilities. Thompson has made significant contributions to the field of computer science.

How does a shell work:
A shell is a command-line interface that allows users to interact with an operating system. It interprets and executes commands entered by the user. When a user enters a command, the shell parses the command, searches for the corresponding program or executable in the system's PATH, and then runs the program with any specified arguments. It also manages processes, file I/O, and other system-related tasks.

What is a pid and a ppid:

PID (Process ID): A PID is a unique identifier assigned to each running process in an operating system. It is used to track and manage processes, making it easier to monitor and control them.
PPID (Parent Process ID): The PPID is the PID of the parent process that spawned the current process. It is used to establish the parent-child relationship between processes.
How to manipulate the environment of the current process:
The environment of a process can be manipulated in Unix-like operating systems using environment variables. You can set, modify, or remove environment variables for the current process using commands like export, unset, and by directly modifying the environment variable values.

What is the difference between a function and a system call:

Function: In programming, a function is a self-contained block of code that performs a specific task within a program. Functions are part of the program itself and are executed within the program's address space.
System Call: A system call is a request for a service provided by the operating system. It is a way for a program to interact with the operating system kernel. System calls provide access to various operating system functions, such as file I/O, process control, and networking. They involve a context switch from user mode to kernel mode.
How to create processes:
Processes can be created in Unix-like operating systems using system calls like fork(), exec(), and clone(). The fork() system call is commonly used to create a new process that is a copy of the parent process, and the exec() system call is used to replace the current process image with a new one.

What are the three prototypes of main:
In C and C++ programming, the main function can have three different prototypes:

int main(void): This prototype indicates that the main function takes no arguments.
int main(int argc, char *argv[]): This prototype accepts command-line arguments through the argc (argument count) and argv (argument vector) parameters.
int main(int argc, char *argv[], char *envp[]): This prototype includes an additional envp parameter, allowing access to the environment variables of the process.
How does the shell use the PATH to find programs:
The shell uses the PATH environment variable to locate executable programs. It contains a list of directories separated by colons (in Unix-like systems) or semicolons (in Windows). When you enter a command in the shell, it searches each directory listed in the PATH variable in order. If it finds an executable file with the same name as the command you entered, it will run that program.

How to execute another program with the execve system call:
The execve system call is used to execute another program in Unix-like operating systems. You pass the path to the executable file as an argument to execve, along with command-line arguments and the environment. When execve is called, it replaces the current process with the new program specified in the path.

How to suspend the execution of a process until one of its children terminates:
You can use the wait system call in Unix-like operating systems to suspend the execution of a process until one of its child processes terminates. The wait system call allows the parent process to wait for the child process to complete its execution and retrieve its exit status.

What is EOF ("end-of-file"):
EOF stands for "end-of-file" and is a marker used in file I/O to indicate that the end of a file has been reached. It is a special value returned by file input functions to signal that there is no more data to read from a file. EOF is commonly used to terminate reading from a file, typically when you reach the end of the file or encounter an error while reading.
