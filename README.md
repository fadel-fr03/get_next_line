# get\_next\_line

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/build-passing-brightgreen)

`get_next_line` is a 42 school project focused on implementing a function that reads a line from a file descriptor, one call at a time. The function handles varying buffer sizes, memory management, and static variables, and includes bonus functionality for handling multiple file descriptors simultaneously.

---

## 📌 Table of Contents

* [About](#about)
* [Features](#features)
* [Project Structure](#project-structure)
* [How It Works](#how-it-works)
* [How to Compile](#how-to-compile)
* [Usage Example](#usage-example)
* [Key Implementation Highlights](#key-implementation-highlights)
* [Bonus Part](#bonus-part)
* [Learnings](#learnings)
* [License](#license)

---

## 📖 About

This project aims to:

* Deepen understanding of file descriptors and memory buffering in C.
* Introduce the importance of `static` variables in state retention across function calls.
* Emphasize efficient use of `read()` to minimize I/O.

The core deliverable is a function:

```c
char *get_next_line(int fd);
```

which reads from a file descriptor and returns a single line, including the newline character if present.

---

## ✨ Features

### Mandatory:

* Reads from file descriptor line-by-line using `read()`
* Memory-safe (no leaks)
* Uses static variable for persistent buffer between calls
* Handles both files and standard input
* Returns `NULL` on EOF or error

### Bonus:

* Only one static variable is used
* Supports **multiple file descriptors** at once without data loss

---

## 📁 Project Structure

```bash
.
├── get_next_line.c             # Main logic
├── get_next_line.h             # Header with function prototype
├── get_next_line_utils.c       # String helpers and memory logic
├── get_next_line_bonus.c       # Bonus logic (multi-FD)
├── get_next_line_bonus.h       # Header for bonus version
├── get_next_line_utils_bonus.c # Helpers for bonus
```

---

## 🔄 How It Works

1. The function reads from `fd` using a buffer of size `BUFFER_SIZE`
2. It appends data to a static string until it finds a `\n`
3. Once a full line is found, it returns it, keeping the remaining data for the next call
4. When EOF is reached, the last partial line (if any) is returned, then `NULL`

> The bonus version uses a static array `buffer[1024]` to manage multiple file descriptors independently.

---

## 📅 How to Compile

You can compile the project with any `BUFFER_SIZE` using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

To compile the **bonus version**:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

> You can change `BUFFER_SIZE` to stress test your implementation (e.g., 1, 10, 9999, etc.)

---

## 🔍 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 📈 Key Implementation Highlights

### `read_from_file`

Performs buffered reads from the file and appends to the current buffer until a newline is found:

```c
while (!ft_strchr(*buffer, '\n')) {
    chars_read = read(fd, temp_buffer, BUFFER_SIZE);
    *buffer = ft_strjoin(*buffer, temp_buffer);
}
```

### `extract_line`

Isolates and returns the current line from the buffer:

```c
line = (char *)malloc(sizeof(char) * (i + 1));
while (buffer[i] && buffer[i] != '\n')
    line[i++] = buffer[i];
```

### `clean_buffer`

Removes the extracted line and shifts the buffer contents for the next call:

```c
new_buffer = ft_strdup(buffer + index_after_line);
free(buffer);
buffer = new_buffer;
```

### Bonus: `buffer[1024]`

Stores static buffers for each possible fd (up to 1024):

```c
static char *buffer[1024];
```

---

## 🚀 Bonus Part

The bonus implementation supports reading from multiple file descriptors in parallel. For example:

```c
get_next_line(fd1); // reads from fd1
get_next_line(fd2); // reads from fd2
get_next_line(fd1); // continues reading fd1 correctly
```

This is achieved using a static array `buffer[1024]`, so each file descriptor maintains its own reading state.

---

## 📚 Learnings

* Mastered file I/O with `read()`
* Efficient dynamic memory usage
* Proper use of `static` for persistent internal state
* Handling edge cases: EOF without newline, empty lines, varying buffer sizes
* Managing multiple independent file streams with a static array

---

## 📄 License

This project is part of the 42 School curriculum and is meant for educational use.

---

## 💬 Questions?

Feel free to reach out or fork and test the project!

---
