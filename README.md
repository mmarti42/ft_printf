# ft_printf

Recode the libc’s printf function.

That project enable to **discover variadic functions in C in a particularly relevant context** as well as learn about a great example of a **basic “dispatcher” in C via the use of an array of function’s pointers**.

Improving skills:

> Imperative programming

> Unix

> Algorithms & AI

> Rigor

### Installation

```
$ git clone https://github.com/Kugumi/ft_printf.git
$ cd ft_printf
$ make
$ gcc -Wall -Wextra -Werror main.c libftprintf.a
```

### Usage

```
Change main.c with the following conversions and flags and compile again (gcc -Wall -Wextra -Werror main.c libftprintf.a)
```

### Conversions
|        |        |
| ------ | ------ |
| c | char (character). |
| s | null-terminated string. |
| p | void * (pointer to void) in an implementation-defined format. |
| d, i | int as a signed integer. |
| o | unsigned int in octal. |
| u | Print decimal unsigned int. |
| x, X | unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case. |
| hh | For integer types, causes printf to expect an int-sized integer argument which was promoted from a char. |
| h | For integer types, causes printf to expect an int-sized integer argument which was promoted from a short. |
| l | For integer types, causes printf to expect a long-sized integer argument. |
| ll | For integer types, causes printf to expect a long long-sized integer argument. |
| f, lf, Lf | double in normal (fixed-point) notation. For floating point types, l has no effect. L for floating point types, causes printf to expect a long double argument. |
| %% | Prints a literal % character |

### Flags
|        |        |
| ------ | ------ |
| # | Alternate form: For f type, the output always contains a decimal point. For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers. |
| 0 | When the 'width' option is specified, prepends zeros for numeric types. |
| - | Left-align the output of this placeholder. (The default is to right-align the output.) |
| + | Prepends a plus for positive signed-numeric types. |
| ⌴ (space) | Prepends a space for positive signed-numeric types. |

Manage the field-width and precision.
