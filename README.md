# 0x19. C - Stacks, Queues - LIFO, FIFO

# The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

# The monty program

- Usage: `monty file`:
```
./m bytecode.m
```
  - where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If, for any reason, its not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where `<file>` is the name of the file
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where `<line_number>`is the line number where the instruction appears.
  - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured
- If you cant malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`
- You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, )

# Usage

The code is compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
- Any output is printed on `stdout`
- Any error message is printed on `stderr`

## Operation codes :

| Opcode | Description |
| --- | --- |
| push | Pushes an element to the stack |
| pall | prints all the values on the stack, starting from the top of the stack |
| pint | prints the value at the top of the stack |
| pop | removes the top element of the stack |
| swap | swaps the top two elements of the stack |
| add | adds the top two elements of the stack |
| sub | subtracts the top element of the stack from the second top element of the stack |
| mul | multiplies the second top element of the stack with the top element of the stack |
| div | divides the second top element of the stack by the top element of the stack |
| mod | computes the rest of the division of the second top element of the stack by the top element of the stack |
| pchar | prints the char at the top of the stack, followed by a new line |
| pstr | prints the string starting at the top of the stack, followed by a new line |
| rotr | rotates the stack to the bottom |
| rotl | rotates the stack to the top |
| nop | doesnt do anything |

## Learning Objectives

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables
