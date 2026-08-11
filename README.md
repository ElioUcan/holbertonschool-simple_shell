# Simple shell

This repo is a simple shell (`hsh`) written in C for Holberton School.
It has an interactive and a non-interactive mode.

## Description

`hsh` reads a line, tokenizes the input, checks if the command is a
built-in, resolves PATH when needed, and executes a command in a child
process.

In interactive mode the prompt is `UZ$`.
In non-interactive mode there is no prompt.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

Interactive:

```bash
./hsh
UZ$ ls
UZ$ env
UZ$ exit
```

Non-interactive:

```bash
echo "ls" | ./hsh
```

Man page:

```bash
man ./man_1_simple_shell
```

## Builtins

| Command | Description |
| ------- | ----------- |
| `exit`  | Exits the shell |
| `env`   | Prints the environment |

## Files

| File | Description |
| ---- | ----------- |
| `main.c` | Runs the simple shell |
| `main.h` | Header with the function prototypes |
| `uz_tokenizeinput.c` | Tokenizes the input |
| `uz_builtins.c` | Checks if the command is a built-in and executes it |
| `uz_path.c` | Gives the PATH |
| `uz_handleexecution.c` | Resolves PATH and makes fork |
| `uz_sh.c` | Executes a command in a child process |
| `man_1_simple_shell` | Man page for the shell |
| `AUTHORS` | List of contributors |

## Author

ElioUZ <elioeduardo06@gmail.com>
