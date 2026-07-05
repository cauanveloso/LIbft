*This project has been created as part of the 42 curriculum by csilva-v.*

<div align="center">

# Libft

### A custom C static library built from the ground up.

![C](https://img.shields.io/badge/Language-C-blue)
![42](https://img.shields.io/badge/School-42-black)
![Status](https://img.shields.io/badge/Status-Completed-success)
![Library](https://img.shields.io/badge/Type-Static%20Library-informational)

</div>

---

## Description

Libft is a static library written in C as part of the 42 curriculum. The project focuses on recreating several standard C library functions, while also adding useful utilities for memory manipulation, string handling, character checks, type conversion, linked lists, file descriptor output, formatted printing, and line-by-line file reading.

The main goal of this project is to build a deeper understanding of the C language by manually implementing commonly used functions. Through this process, the project explores pointers, dynamic memory allocation, low-level memory access, modular code organization, static libraries, data structures, and resource management.

Over time, this library has also been extended with extra modules stored in `src/extra`, including `ft_printf` and `get_next_line`. These additions make the library more practical for future 42 projects, since they provide reusable tools for formatted output and file descriptor reading.

Libft is designed to serve as a personal foundation for future C projects, keeping frequently used functions organized, reusable, and easy to maintain.

---

## Table of Contents

* [Learning Goals](#learning-goals)
* [Available Functions](#available-functions)
* [Instructions](#instructions)
* [Project Structure](#project-structure)
* [Character Manipulation](#character-manipulation)
* [Memory Manipulation](#memory-manipulation)
* [String Manipulation](#string-manipulation)
* [Type Conversion](#type-conversion)
* [File Descriptor Manipulation](#file-descriptor-manipulation)
* [Linked Lists](#linked-lists)
* [Extra Modules](#extra-modules)
  * [ft_printf](#ft_printf)
  * [get_next_line](#get_next_line)
* [Resources](#resources)

---

## Learning Goals

Libft was one of the first major challenges in my C programming journey. Implementing each function manually helped me understand how many standard library functions work internally and how low-level programming concepts connect with real code.

During this project, I practiced and improved concepts such as:

* Pointer manipulation
* Dynamic memory allocation
* String and character manipulation
* Direct memory operations
* Type conversion
* Modular code organization
* Static library creation
* Linked list data structures
* File descriptor usage
* Formatted output handling
* Line-by-line file reading
* Error handling and memory leak prevention
* Writing reusable and maintainable C code

Beyond the technical concepts, this project also helped develop debugging skills, problem-solving habits, and a better understanding of how to write clean and reliable code in C.

---

## Available Functions

Libft is organized into the following categories:

* Character Manipulation
* Memory Manipulation
* String Manipulation
* Type Conversion
* File Descriptor Manipulation
* Linked Lists
* Extra Modules

The extra modules are stored inside `src/extra` and currently include:

* `ft_printf`
* `get_next_line`

These modules extend the library beyond the original Libft scope, making it more useful for larger projects that need formatted output or file reading utilities.

---

## Instructions

Libft is compiled as a static library using a `Makefile`.

During compilation, each source file (`.c`) is converted into an object file (`.o`). After that, all object files are archived into the static library `libft.a`, which can be linked and reused in other C projects.

### Compile the library

```bash
make
```

### Remove object files

```bash
make clean
```

### Remove object files and the static library

```bash
make fclean
```

### Rebuild everything from scratch

```bash
make re
```

### Run tests

If your local version includes the testing rule, you can run:

```bash
make test
```

After compilation, the generated `libft.a` can be linked with other projects together with the library header.

Example:

```bash
cc main.c libft.a -I include
```

---

## Project Structure

```text
libft/
├── Makefile
├── README.md
├── include/
│   └── libft.h
├── src/
│   ├── char/
│   ├── memory/
│   ├── string/
│   ├── conversion/
│   ├── fd/
│   ├── list/
│   └── extra/
│       ├── ft_printf/
│       └── get_next_line/
├── tests/
└── logs/
```

### Main components

| Path | Description |
| ---- | ----------- |
| `Makefile` | Automates the compilation process |
| `include/libft.h` | Contains function prototypes, type definitions, and required includes |
| `src/` | Contains the library source files |
| `src/extra/` | Contains additional reusable modules such as `ft_printf` and `get_next_line` |
| `libft.a` | Static library generated after compilation |
| `tests/` | Contains local test files and test scripts |
| `logs/` | Stores test output logs |

---

## Character Manipulation

In C, characters are represented by integer values from the ASCII table. This makes it possible to compare and transform characters using numeric ranges and conditions.

Examples:

```c
'A' = 65
'B' = 66
'a' = 97
'b' = 98
'0' = 48
'1' = 49
```

Character manipulation is commonly used to:

* Validate user input
* Check whether a character is alphabetic or numeric
* Convert uppercase letters to lowercase
* Convert lowercase letters to uppercase
* Process text and strings
* Build parsing and validation logic

Functions in this category:

* [`ft_isalpha`](#ft_isalpha)
* [`ft_isdigit`](#ft_isdigit)
* [`ft_isalnum`](#ft_isalnum)
* [`ft_isascii`](#ft_isascii)
* [`ft_isprint`](#ft_isprint)
* [`ft_tolower`](#ft_tolower)
* [`ft_toupper`](#ft_toupper)

---

## Memory Manipulation

In C, memory is handled as a continuous sequence of bytes. Variables, arrays, buffers, and structures occupy specific memory regions that can be accessed and modified through pointers.

Memory manipulation functions are used to fill, copy, move, compare, and allocate memory blocks.

Example:

```c
char buffer[10];

ft_memset(buffer, 'A', 10);
```

Memory manipulation is commonly used to:

* Initialize arrays and structures
* Copy data between memory regions
* Safely move data between overlapping areas
* Compare memory blocks
* Search inside raw memory
* Allocate initialized memory
* Build more complex data structures

Functions in this category:

* [`ft_memset`](#ft_memset)
* [`ft_bzero`](#ft_bzero)
* [`ft_memcpy`](#ft_memcpy)
* [`ft_memmove`](#ft_memmove)
* [`ft_memchr`](#ft_memchr)
* [`ft_memcmp`](#ft_memcmp)
* [`ft_calloc`](#ft_calloc)

---

## String Manipulation

In C, a string is an array of characters terminated by the null character (`'\0'`). Since C does not have a native string type, string manipulation depends on functions that operate directly on character arrays.

String functions are used to create, copy, join, compare, search, split, and transform text.

Example:

```c
char *joined;

joined = ft_strjoin("Hello ", "World");
```

String manipulation is commonly used to:

* Process user input
* Parse files
* Search for characters or substrings
* Compare textual data
* Split and join strings
* Format messages
* Build dynamic strings

Functions in this category:

* [`ft_strlen`](#ft_strlen)
* [`ft_strlcpy`](#ft_strlcpy)
* [`ft_strlcat`](#ft_strlcat)
* [`ft_strchr`](#ft_strchr)
* [`ft_strrchr`](#ft_strrchr)
* [`ft_strncmp`](#ft_strncmp)
* [`ft_strnstr`](#ft_strnstr)
* [`ft_strdup`](#ft_strdup)
* [`ft_substr`](#ft_substr)
* [`ft_strjoin`](#ft_strjoin)
* [`ft_strtrim`](#ft_strtrim)
* [`ft_split`](#ft_split)
* [`ft_strmapi`](#ft_strmapi)
* [`ft_striteri`](#ft_striteri)

---

## Type Conversion

Type conversion functions transform data from one representation to another. For example, text can be interpreted as a number, or a number can be converted into a string.

Example:

```c
int number;

number = ft_atoi("42");
```

Type conversion is commonly used to:

* Process user input
* Interpret data from files
* Convert numbers for display
* Validate textual information
* Format messages and reports

Functions in this category:

* [`ft_atoi`](#ft_atoi)
* [`ft_itoa`](#ft_itoa)

---

## File Descriptor Manipulation

In Unix-like systems, a file descriptor is an integer used by the operating system to identify an open file, terminal, pipe, or other input/output resource.

Common file descriptors:

```c
0 -> Standard input  (stdin)
1 -> Standard output (stdout)
2 -> Standard error  (stderr)
```

File descriptor functions make it possible to write characters, strings, and numbers to a specific output destination.

Example:

```c
ft_putstr_fd("Hello World", 1);
```

Functions in this category:

* [`ft_putchar_fd`](#ft_putchar_fd)
* [`ft_putstr_fd`](#ft_putstr_fd)
* [`ft_putendl_fd`](#ft_putendl_fd)
* [`ft_putnbr_fd`](#ft_putnbr_fd)

These functions are especially useful for terminal output, error messages, file writing, and simple logging systems.

---

## Linked Lists

Linked lists are dynamic data structures made of nodes connected through pointers. Each node stores content and a pointer to the next node.

Unlike arrays, linked lists do not need to occupy contiguous memory, which makes insertion and removal operations more flexible.

Example:

```c
t_list *node1;
t_list *node2;

node1 = ft_lstnew("Hello");
node2 = ft_lstnew("World");
node1->next = node2;
```

Linked lists are commonly used to:

* Store dynamic collections of data
* Insert and remove elements efficiently
* Build queues and stacks
* Traverse data sequentially
* Manage collections whose size changes at runtime

Functions in this category:

* [`ft_lstnew`](#ft_lstnew)
* [`ft_lstadd_front`](#ft_lstadd_front)
* [`ft_lstsize`](#ft_lstsize)
* [`ft_lstlast`](#ft_lstlast)
* [`ft_lstadd_back`](#ft_lstadd_back)
* [`ft_lstdelone`](#ft_lstdelone)
* [`ft_lstclear`](#ft_lstclear)
* [`ft_lstiter`](#ft_lstiter)
* [`ft_lstmap`](#ft_lstmap)

---

## Extra Modules

The `src/extra` directory contains additional modules that were added to make the library more complete and reusable in future projects.

These modules are not just isolated exercises. They extend the practical use of Libft by adding two important capabilities:

* Formatted output with `ft_printf`
* Line-by-line reading from file descriptors with `get_next_line`

Both modules rely on concepts already practiced in Libft, such as string manipulation, memory management, file descriptors, and modular design.

---

## ft_printf

`ft_printf` is a custom implementation of the standard `printf` function.

It formats and prints different types of data to the standard output, making it one of the most useful utilities in the library for debugging, logging, and displaying information.

### Prototype

```c
int ft_printf(const char *format, ...);
```

### Supported concepts

This module introduces and reinforces:

* Variadic functions
* Format string parsing
* Character and string output
* Number conversion
* Hexadecimal formatting
* Pointer formatting
* Return value tracking
* Modular output handling

### Common conversions

| Conversion | Description |
| ---------- | ----------- |
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in lowercase hexadecimal |
| `%X` | Prints a number in uppercase hexadecimal |
| `%%` | Prints a percent sign |

### Example

```c
ft_printf("Name: %s | Score: %d\n", "Cauan", 42);
```

Output:

```text
Name: Cauan | Score: 42
```

---

## get_next_line

`get_next_line` is a function that reads from a file descriptor one line at a time.

Each call returns the next available line while preserving unread content for future calls. This makes the function useful when reading files, standard input, pipes, or any other valid file descriptor.

### Prototype

```c
char *get_next_line(int fd);
```

### How it works

The function reads data using `read()` and stores any unread content in static storage. When a newline is found, it returns a complete line and keeps the remaining content for the next call.

This implementation also supports multiple file descriptors independently by keeping a separate storage slot for each file descriptor.

```c
static char *storage[MAX_FD];
```

### Supported concepts

This module introduces and reinforces:

* File descriptors
* The `read()` system call
* Static variables
* Persistent storage between function calls
* Dynamic memory allocation
* Buffer-based reading
* EOF handling
* Reading multiple file descriptors independently

### Example

```c
int     fd;
char    *line;

fd = open("file.txt", O_RDONLY);
line = get_next_line(fd);
while (line)
{
    ft_printf("%s", line);
    free(line);
    line = get_next_line(fd);
}
close(fd);
```

The caller is responsible for freeing each returned line.

---

# Function Details

<a id="ft_isalpha"></a>
## ft_isalpha

Checks whether a character is alphabetic.

Returns:

* A non-zero value if the character is a letter (`A-Z` or `a-z`)
* `0` otherwise

Example:

```c
ft_isalpha('A'); // non-zero
ft_isalpha('z'); // non-zero
ft_isalpha('5'); // 0
ft_isalpha('@'); // 0
```

---

<a id="ft_isdigit"></a>
## ft_isdigit

Checks whether a character is a decimal digit.

Returns:

* A non-zero value if the character is between `0` and `9`
* `0` otherwise

Example:

```c
ft_isdigit('5'); // non-zero
ft_isdigit('0'); // non-zero
ft_isdigit('A'); // 0
ft_isdigit('@'); // 0
```

---

<a id="ft_isalnum"></a>
## ft_isalnum

Checks whether a character is alphanumeric.

Returns:

* A non-zero value if the character is alphabetic or numeric
* `0` otherwise

Example:

```c
ft_isalnum('A'); // non-zero
ft_isalnum('7'); // non-zero
ft_isalnum('#'); // 0
```

---

<a id="ft_isascii"></a>
## ft_isascii

Checks whether a value belongs to the ASCII table.

Returns:

* A non-zero value if the value is between `0` and `127`
* `0` otherwise

Example:

```c
ft_isascii('A'); // non-zero
ft_isascii(65);  // non-zero
ft_isascii(128); // 0
```

---

<a id="ft_isprint"></a>
## ft_isprint

Checks whether a character is printable.

Returns:

* A non-zero value if the character is between `32` and `126`
* `0` otherwise

Example:

```c
ft_isprint('A');  // non-zero
ft_isprint(' ');  // non-zero
ft_isprint('\n'); // 0
```

---

<a id="ft_tolower"></a>
## ft_tolower

Converts an uppercase letter to lowercase.

Returns:

* The lowercase version if the character is between `A` and `Z`
* The original character otherwise

Example:

```c
ft_tolower('A'); // 'a'
ft_tolower('5'); // '5'
```

---

<a id="ft_toupper"></a>
## ft_toupper

Converts a lowercase letter to uppercase.

Returns:

* The uppercase version if the character is between `a` and `z`
* The original character otherwise

Example:

```c
ft_toupper('a'); // 'A'
ft_toupper('5'); // '5'
```

---

<a id="ft_memset"></a>
## ft_memset

Fills a memory region with a specific byte.

Returns:

* A pointer to the modified memory region

Example:

```c
char str[6] = "Hello";

ft_memset(str, 'A', 5);
// str = "AAAAA"
```

---

<a id="ft_bzero"></a>
## ft_bzero

Sets all bytes of a memory region to zero.

Returns:

* Nothing (`void`)

Example:

```c
char str[6] = "Hello";

ft_bzero(str, 5);
```

---

<a id="ft_memcpy"></a>
## ft_memcpy

Copies a specific number of bytes from one memory region to another.

Returns:

* A pointer to the destination memory region

This function should not be used when memory regions overlap.

Example:

```c
char src[] = "Hello";
char dst[6];

ft_memcpy(dst, src, 6);
```

---

<a id="ft_memmove"></a>
## ft_memmove

Copies bytes between memory regions safely, even when they overlap.

Returns:

* A pointer to the destination memory region

Example:

```c
char str[] = "abcdef";

ft_memmove(str + 2, str, 4);
// str = "ababcd"
```

---

<a id="ft_memchr"></a>
## ft_memchr

Searches for the first occurrence of a byte inside a memory region.

Returns:

* A pointer to the found byte
* `NULL` if the byte is not found

Example:

```c
ft_memchr("Hello", 'e', 5);
ft_memchr("Hello", 'x', 5);
```

---

<a id="ft_memcmp"></a>
## ft_memcmp

Compares two memory regions byte by byte.

Returns:

* A value less than `0` if the first region is lower
* `0` if both regions are equal
* A value greater than `0` if the first region is greater

Example:

```c
ft_memcmp("abc", "abc", 3); // 0
ft_memcmp("abc", "abd", 3); // negative value
```

---

<a id="ft_calloc"></a>
## ft_calloc

Allocates memory dynamically and initializes all bytes to zero.

Returns:

* A pointer to the allocated memory
* `NULL` if allocation fails

Example:

```c
int *array;

array = ft_calloc(5, sizeof(int));
```

---

<a id="ft_strlen"></a>
## ft_strlen

Calculates the length of a string, excluding the null terminator.

Returns:

* The number of characters in the string

Example:

```c
ft_strlen("Hello"); // 5
```

---

<a id="ft_strlcpy"></a>
## ft_strlcpy

Copies a string into another buffer while respecting the destination size.

Returns:

* The total length of the source string

Example:

```c
char dst[10];

ft_strlcpy(dst, "Hello", sizeof(dst));
```

---

<a id="ft_strlcat"></a>
## ft_strlcat

Concatenates a string to the end of another while respecting the destination size.

Returns:

* The total length the final string would have had if enough space was available

Example:

```c
char dst[20] = "Hello ";

ft_strlcat(dst, "World", sizeof(dst));
```

---

<a id="ft_strchr"></a>
## ft_strchr

Searches for the first occurrence of a character in a string.

Returns:

* A pointer to the first occurrence
* `NULL` if the character is not found

Example:

```c
ft_strchr("Hello", 'l');
ft_strchr("Hello", 'x');
```

---

<a id="ft_strrchr"></a>
## ft_strrchr

Searches for the last occurrence of a character in a string.

Returns:

* A pointer to the last occurrence
* `NULL` if the character is not found

Example:

```c
ft_strrchr("Hello", 'l');
```

---

<a id="ft_strncmp"></a>
## ft_strncmp

Compares two strings up to a specific number of characters.

Returns:

* A value less than `0` if the first string is lower
* `0` if both strings are equal
* A value greater than `0` if the first string is greater

Example:

```c
ft_strncmp("abc", "abc", 3); // 0
ft_strncmp("abc", "abd", 3); // negative value
```

---

<a id="ft_strnstr"></a>
## ft_strnstr

Searches for a substring inside another string, limited by a maximum number of characters.

Returns:

* A pointer to the first occurrence
* `NULL` if the substring is not found

Example:

```c
ft_strnstr("Hello World", "World", 11);
ft_strnstr("Hello World", "42", 11);
```

---

<a id="ft_strdup"></a>
## ft_strdup

Creates a dynamically allocated copy of a string.

Returns:

* A pointer to the new string
* `NULL` if allocation fails

Example:

```c
char *copy;

copy = ft_strdup("Hello");
```

---

<a id="ft_substr"></a>
## ft_substr

Creates a new string containing a portion of another string.

Returns:

* A pointer to the created substring
* `NULL` if allocation fails

Example:

```c
ft_substr("Hello World", 6, 5);
// "World"
```

---

<a id="ft_strjoin"></a>
## ft_strjoin

Creates a new string by joining two strings.

Returns:

* A pointer to the new string
* `NULL` if allocation fails

Example:

```c
ft_strjoin("Hello ", "World");
// "Hello World"
```

---

<a id="ft_strtrim"></a>
## ft_strtrim

Removes specific characters from the beginning and end of a string.

Returns:

* A pointer to the new trimmed string
* `NULL` if allocation fails

Example:

```c
ft_strtrim("###Hello###", "#");
// "Hello"
```

---

<a id="ft_split"></a>
## ft_split

Splits a string into an array of substrings using a delimiter.

Returns:

* A `NULL`-terminated array of strings
* `NULL` if allocation fails

Example:

```c
char **words;

words = ft_split("Hello World 42", ' ');
```

---

<a id="ft_atoi"></a>
## ft_atoi

Converts a string containing an integer into an `int`.

Returns:

* The integer value represented by the string

Example:

```c
ft_atoi("42");      // 42
ft_atoi("-42");     // -42
ft_atoi("   +123"); // 123
ft_atoi("abc");     // 0
```

---

<a id="ft_itoa"></a>
## ft_itoa

Converts an integer into a dynamically allocated string.

Returns:

* A pointer to the created string
* `NULL` if allocation fails

Example:

```c
ft_itoa(42);  // "42"
ft_itoa(-42); // "-42"
```

---

<a id="ft_putchar_fd"></a>
## ft_putchar_fd

Writes a single character to a file descriptor.

Returns:

* Nothing (`void`)

Example:

```c
ft_putchar_fd('A', 1);
```

---

<a id="ft_putstr_fd"></a>
## ft_putstr_fd

Writes a string to a file descriptor.

Returns:

* Nothing (`void`)

Example:

```c
ft_putstr_fd("Hello World", 1);
```

---

<a id="ft_putendl_fd"></a>
## ft_putendl_fd

Writes a string followed by a newline to a file descriptor.

Returns:

* Nothing (`void`)

Example:

```c
ft_putendl_fd("Hello World", 1);
```

---

<a id="ft_putnbr_fd"></a>
## ft_putnbr_fd

Writes an integer to a file descriptor.

Returns:

* Nothing (`void`)

Example:

```c
ft_putnbr_fd(42, 1);
ft_putnbr_fd(-42, 1);
```

---

<a id="ft_strmapi"></a>
## ft_strmapi

Creates a new string by applying a function to each character of the original string.

Returns:

* A pointer to the created string
* `NULL` if allocation fails

Example:

```c
char add_index(unsigned int i, char c)
{
    return (c + i);
}

ft_strmapi("abc", add_index);
// "ace"
```

---

<a id="ft_striteri"></a>
## ft_striteri

Iterates over a string and applies a function directly to each character.

Returns:

* Nothing (`void`)

Example:

```c
void to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

char str[] = "hello";

ft_striteri(str, to_upper);
// str = "HELLO"
```

---

<a id="ft_lstnew"></a>
## ft_lstnew

Creates a new linked list node.

Returns:

* A pointer to the created node
* `NULL` if allocation fails

Example:

```c
t_list *node;

node = ft_lstnew("Hello");
```

---

<a id="ft_lstadd_front"></a>
## ft_lstadd_front

Adds a node to the beginning of a linked list.

Returns:

* Nothing (`void`)

Example:

```c
t_list *list;

list = ft_lstnew("World");
ft_lstadd_front(&list, ft_lstnew("Hello"));
```

---

<a id="ft_lstsize"></a>
## ft_lstsize

Counts the number of nodes in a linked list.

Returns:

* The number of nodes

Example:

```c
ft_lstsize(list);
```

---

<a id="ft_lstlast"></a>
## ft_lstlast

Returns the last node of a linked list.

Returns:

* A pointer to the last node
* `NULL` if the list is empty

Example:

```c
t_list *last;

last = ft_lstlast(list);
```

---

<a id="ft_lstadd_back"></a>
## ft_lstadd_back

Adds a node to the end of a linked list.

Returns:

* Nothing (`void`)

Example:

```c
t_list *list;

list = ft_lstnew("Hello");
ft_lstadd_back(&list, ft_lstnew("World"));
```

---

<a id="ft_lstdelone"></a>
## ft_lstdelone

Deletes a single node and frees its content using a provided delete function.

Returns:

* Nothing (`void`)

Example:

```c
t_list *node;

node = ft_lstnew("Hello");
ft_lstdelone(node, del);
```

---

<a id="ft_lstclear"></a>
## ft_lstclear

Deletes and frees all nodes of a linked list.

Returns:

* Nothing (`void`)

Example:

```c
ft_lstclear(&list, del);
```

---

<a id="ft_lstiter"></a>
## ft_lstiter

Iterates over a linked list and applies a function to the content of each node.

Returns:

* Nothing (`void`)

Example:

```c
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

ft_lstiter(list, print_content);
```

---

<a id="ft_lstmap"></a>
## ft_lstmap

Creates a new linked list by applying a function to each node of the original list.

Returns:

* A pointer to the new list
* `NULL` if allocation fails

Example:

```c
void *duplicate_content(void *content)
{
    return (ft_strdup((char *)content));
}

t_list *new_list;

new_list = ft_lstmap(list, duplicate_content, del);
```

---

## Resources

Several references were used during the development and documentation of this project.

### Documentation

* Linux Manual Pages (`man`)
* The Open Group Base Specifications
* GNU C Library Documentation
* C Reference

### Study Materials

* *The C Programming Language* — Brian W. Kernighan & Dennis M. Ritchie
* Beej's Guide to C Programming
* 42 School official project documentation

### AI Usage Declaration

AI tools were used only as learning and documentation support.

Usage included:

* Reviewing C language concepts
* Explaining standard library behavior
* Clarifying pointers and memory management
* Understanding linked lists
* Improving the documentation of this README

All code was implemented, tested, debugged, and validated manually by the project author.

---

<div align="center">

Made as part of the 42 curriculum.

</div>
