# Client-Server Communication Program

This project implements a simple client-server communication mechanism using UNIX signals in C. 
The program includes the following components:

- **Server**: Receives and displays messages.
- **Client**: Sends messages to the server.

## Features

- Communication between client and server is achieved using **UNIX signals** (`SIGUSR1` and `SIGUSR2`).
- The **server** runs persistently, allowing it to handle multiple clients sequentially without restarting.
- The **client** sends a string message along with the server's PID to establish communication.
- Includes robust error handling to prevent segmentation faults, double frees, or memory leaks.
- Efficient message display adheres to performance requirements.

## Instructions

### Executable Files
- The compiled executables must be named `client` and `server`.

### Compilation
- Use the provided `Makefile` to compile the source files. The Makefile ensures no unnecessary relinking.

### Usage
1. Start the **server**:
   ```bash
   ./server
The server will print its PID upon launch.

2. Start the client:
bash
./client <server_pid> "<message>"

Replace <server_pid> with the PID displayed by the server, and <message> with the string you want to send.

## Rules and Constraints
The server must display received messages promptly.
Allowed system calls:

write, signal, sigemptyset, sigaddset, sigaction, kill, 
getpid, malloc, free, pause, sleep, usleep, exit

Memory leaks are strictly prohibited.
Each program can have only one global variable, and its usage must be justified.

## Notes
This project uses a custom implementation of ft_printf for formatted output.
The libft library can be utilized for common utility functions.

## Getting Started
Clone the repository, compile the project using the provided Makefile, and follow the usage instructions to test the client-server communication.

