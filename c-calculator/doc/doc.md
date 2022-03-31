Calculator
----------

In this problem you will explore using `sscanf`. This function lets
you scan and parse formatted text, similar to how `printf` lets you
format text for output.

Important reminders: you should write your code in `calculate.c`,
and you should only write a single function. The function type
should match the prototype in `main.c`, i.e., it should look like:

    void calculate(char *line) { ... }

Note that you should NOT copy any code over from `main.c`. Both
`main.c` and `calculate.c` will be compiled and linked together to
create the final `a.out` program.

The `main` function will read a line of input from *stdin*, which is
the standard input. When you run a program from the command line,
the keyboard is standard in. When you type `make` to run the tests
for this problem, the system will feed lines of input from the input
test file instead of the keyboard.

The `calculate` function will be given one line of text input at a
time. Its job is to parse the input line for a simple math problem
(using `sscanf`), then give a printed response (using `printf`).

Here is an example. If the user types:

    What is 9 added to 12?

your program should respond with:

    9 + 12 = 21

There are several different question formats that you must handle,
and if the user input does not match any of them you should respond
with:

    I do not understand the question, sorry!


### Using sscanf

The `stdio.h` library has a family of `scanf` functions. `scanf`
reads directly from the keyboard, `fscanf` reads from an open file,
and `sscanf` (the one we are using) scans a string that is already
in memory. You can get the full documentation for it by typing:

    man sscanf

or a search will turn up many tutorials. The basic idea is simple:
it works like `printf` in reverse. Here is an example:

``` c
// an example input string:
char *line = "What is 5 added to 7?\n";

// we need to capture some values, so define a few variables
int a, b, n;

// call sscanf
n = sscanf(line, "What is %d added to %d?\n", &a, &b);
```

Here are some notes about this code sample:

*   Literal characters in the format string must exactly match
    characters from the input, so "What" in the `sscanf` call must
    match the exact string "What" from the input. If there is a
    mismatch, it stops reading and gives up.

*   For `%d`, it must successfully read and parse a decimal integer
    (just like `printf` would format and print an integer). If it
    does not find a suitable value to parse, it will give up and
    stop reading.

*   `sscanf` returns the number of values that it successfully reads
    and converts. In this case it would parse the "5" and "7"
    strings into the integers 5 and 7, storing them in variables "a"
    and "b", respectively, so it will return 2.

*   When parsing the first integer and storing it in the variable
    "a", `sscanf` needs to know where to store the value. We must
    give it a pointer to "a" so it can change the value of "a", so
    we use the address-of operator.

*   Whitespace does not have to match exactly. A space character in
    the format string will match zero or more whitespace characters
    (spaces, tabs, newlines, etc.) in the input.

There is an added complication for our problem. Say I have the input
string:

    What is 43 negated?

and I try to parse it using:

``` c
n = sscanf(line, "What is %d squared?\n", &a);
```

It will successfully parse the number 43 and store it in the
variable "a". Then it will try to match “negated” from the input
with “squared” from the format string and will fail. However, it did
parse and store a single value, so it will return 1, which is the
same value it would have returned if the entire string was a match.
This makes it difficult to test if the entire string was parsed
successfully.

Here is one way to do it:

``` c
char nl;
n = sscanf(line, "What is %d squared?%c", &a, &nl);
```

The `%c` tells it to read and store a single character. Since our
input lines always end with a newline, you can then check if the
entire string was a match by testing two things:

1.  Did `sscanf` return 2 to indicate that it read and stored 2
    values (the integer and the character)?

2.  Is the value of the variable "nl" a newline character, i.e., is
    `nl == '\n'`? If not, there must have been some extra character
    at the end other than the expected newline.


### How to proceed

Start by creating `calculate` in `calculate.c` and write code that
only reads and understands addition problems of the form illustrated
above. When it successfully reads a problem, have it print the
solution using `printf`.

Once you have done just this much, run "make" to test it. You should
see output like this:

    What is 6 added to 7?
    6 + 7 = 13
    What is -34 added to 102314?
    -34 + 102314 = 102280
    What is 1 added to 3??
    I do not understand the question, sorry!
    What is 5 subtracted from 7?

    !!INCORRECT OUTPUT!! Your next line of output was:
    'I do not understand the question, sorry!\n'
    but the next line of output expected was:
    '7 - 5 = 2\n'

This means that you are successfully handling addition problems
(note that the input with two question marks was rejected) but the
tests fail when it tries to ask about a subtraction problem. From
the message, you should be able to see the expected format of
subtraction problems, both what you will be given as input and what
the expected output is.

Based on this new example, add code to handle subtraction problems.
If a line of input does not parse correctly as an addition problem,
try parsing it as a subtraction problem. If it does not match the
expected input format, print the same message as before about the
input not being understood.

Keep repeating this process for each new kind of question until you
are parsing and handling all problem types.

Note: you can also run it without the tests. To jump compile your
program use:

    make a.out

and then to run it use:

    ./a.out
