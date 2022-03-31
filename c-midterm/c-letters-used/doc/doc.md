Count letters
-------------

In the file `letters.c` write a function with the following
prototype:

    void letters_used(char *line);

Given a line of text, it should report on which letters are used in
the line. It should count upper- and lower-case letters, and should
report by printing the letters used in alphabetical order and in
lower case. For example, given the the following input as a single
line:

    When Mr Bilbo Baggins of Bag End announced that he would shortly
    be celebrating his eleventyifirst birthday with a party of
    special magnificence, there was much talk and excitement in
    Hobbiton.

It should print this output (including a newline at the end):

    abcdefghiklmnoprstuvwxy
