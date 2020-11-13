# project-c-parentheses

## Project Overview

The goal of this project is to get used to working
with the following topics in C:

1. Dynamic memory allocation
2. Pointers
3. Reading from stdin

## Project Instructions

Create a C program that will:

1. Create a function that accepts will check if
   a single string is a valid string.
2. Accept strings from stdin until an EOF signal is received
   (each string will be on it's own line).
3. For each string, call the function you created in step 1
   to check if the string contains valid
   parentheticals:

   * A string is valid if every open parenthesis/bracket/curly brace
     is closed by the correct brace and nested correctly
   * Example 1:  `(djfk[kfdsj{012}hello]world)` is valid
   * Example 2:  `(hello[how{are]youtoday})` is not valid
     because the closing `]` is encountered before the closing
     `}`
   * Example 3:  `(()[{()}][])` is valid
   * Example 4:  `[(a)(b)(c){d[b]}` is not valid because there
     is no closing `]` matching the first opening `[`.

3. For every string, print out a line that simply says
   `VALID` or `NOT VALID` (this will be case sensitive).
   These lines should occur in the same order the strings are
   read in and there should be no additional lines or additional
   text.

Hints: there may be other characters in addition to parentheses,
curly braces, and brakcets.  However, these characters
will not affect whether the string is valid (only the parenthetical
t
pe characters matter).

Your program will be graded on the following:

* Autograded score (24pts)
    * Whatever Prairielearn determines,
      Prairielearn will run your code with the example inputs
      given above and additional inputs that you will not see.
    * It will also check for memory leaks, so make sure to
      free memory as necessssary
* Github commit score (3pts):
    * To get in the practice of using git/Github for more
      than just submitting, part of your grade will be
      determined based on your commit history. 
      Try to implement your program in logical steps
      and make commits once you finish a small part.
    * Start by cloning this repo to your local machine (or EOS).
      As you get parts of your code working, add and commit your
      changes on your local machine.  You can either push them as you work or wait
      until you've made all of your commits to push.  
    * For example, for this problem you might start with
      step 2, accepting strings, and make a commit once
      your program can accept strings until EOF (even 
      if the program does nothing with them).
    * You will lose points if you simply make one big
      commit adding your entire file at the end -- just make
      some commits along the way.
    * Make sure you use descriptive commit messages (aka, avoid things
      like "test" or random words.
    * Make sure you are actually adding your source code file.
