Format phone numbers
--------------------

In the file `phonenumber.c` write a function with the following
prototype:

    void format_phone_number(char *line);

It is given a line of input with a 10-digit phone number, and it
should format and print that phone number in this format:

    (435) 652-5000

If the input is invalid, it should instead print the message:

    Invalid input

The input has a few rules to be considered valid:

*   The area code (the first three digits) must appear as a group of
    three digits with no spaces or punctuation between them.
*   The prefix (the next three digits) must also appear as a group
    with nothing breaking up the three digits.
*   The line number (the last four digits) must appear as a group.
*   Any number of non-digits may appear before the area code,
    between the area code and the prefix, between the prefix and the
    line number, or after the line number, but no extra digits are
    permitted.

So, for example, the following are valid inputs:

    (435) 555-1698
    801-123-9876
    9874327654

But the following are not valid:

    (435) 555-16982
    801-1239-876
    8-0-1-1-2-3-9-8-7-6

Your function should print one line of output in the correct format
(or the "Invalid input" message) followed by a newline.
