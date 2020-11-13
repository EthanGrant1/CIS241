#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/******************************

  VALID PARENTHETICAL CHECKER

This program takes a string as
input and determines if it has
proper parenthetical format.

*******************************/

/* Function prototype. Takes
a string as argument and returns
a string ("VALID" or "NOT VALID. */.
char* parentheses (char str[]);

int main(void) {
        
        // The string to be read.
        char *s;

        // Input for number of characters read.
        int read;

        // Size of string to be allocated to memory.
        size_t max = 10;
        
        /* Continues accepting strings until
        the End of File signal (Ctrl+D) is sent */
        while (read != EOF) {

        // Allocates some memory for the string
        s = (char *) malloc(sizeof(char)*max);

        // Reads the string from Standard In
        read = getline(&s, &max, stdin);

        // If EOF is sent, do nothing
        if (read == EOF) { }

        // Otherwise, run the function with the string
        else { printf("%s", parentheses(s)); }

        // Frees up allocated memory
        free(s); }

        return 0; }

// Function to check valid parentheticals of strings
char* parentheses(char str[]) {
        
        /* Initializing variables for all 3 parenthetical
        types. Square brackets [], parentheses (), and
        curly braces {}. Each parenthetical type has a
        open parenthetical and close parenthetical count,
        as well as a boolean for whether or not a parenthetical
        of tha type is open or closed. */

        int openBrackCount = 0;
        int closeBrackCount = 0;
        bool brackOpen = false;
        bool brackClosed = false;
        
        int openParenCount = 0;
        int closeParenCount = 0;
        bool parenOpen = false;
        bool parenClosed = false;

        int openCurlyCount = 0;
        int closeCurlyCount = 0;
        bool curlyOpen = false;
        bool curlyClosed = false;
        
        // Counts the number of open and closing parentheticals
        for (int i = 0; i < strlen(str); i++) {
                if (str[i] == '[') { openBrackCount++; }
                else if (str[i] == ']') { closeBrackCount++; }
                else if (str[i] == '(') { openParenCount++; }
                else if (str[i] == ')') { closeParenCount++; }
                else if (str[i] == '{') { openCurlyCount++; }
                else if (str[i] == '}') { closeCurlyCount++; }
        }

        // Loops over every character in the string
        for (int i = 0; i < strlen(str); i++) {
                
                // Initializes all open and close bools to false
                brackOpen = false;
                brackClosed = false;
                parenOpen = false;
                parenClosed = false;
                curlyOpen = false;
                curlyClosed = false;

                // Case 1: Square brackets []
                if (str[i] == '[') {
                        
                        brackOpen = true;
                        
                        // Stops when encountering an opening square bracket and reads the rest of the string
                        for (int j = i; j < strlen(str); j++) {
                                
                                // Checks if either parentheses or curly brace parenthetical types are open
                                if (str[j] == '(') { parenOpen = true; }

                                if (str[j] == '{') { curlyOpen = true; }

                                // Properly closes the square bracket                                
                                if (str[j] == ']' && brackClosed == false) { brackClosed = true; }
                                
                                /* If the square bracket hasn't been closed, and another parenthetical type 
                                is attempting to be closed but is not open, the string is not valid. */
                                else if (str[j] == ')' && brackClosed == false && parenOpen == false) {  return "NOT VALID"; }

                                else if (str[j] == '}' && brackClosed == false && curlyOpen == false) { return "NOT VALID"; } } 
                                
                                /* If open and close parenthetical counts for parentheses and curly braces do not evenly match, 
                                the string is not valid. */
                                if ((openParenCount != closeParenCount) || (openCurlyCount != closeCurlyCount)) { return "NOT VALID"; } }
                
                // Case 2: Parentheses ()
                else if (str[i] == '(') {

                        parenOpen = true;
                        
                        // Stops when encountering an opening parentheses and reads the rest of the string
                        for (int j = i; j <= strlen(str); j++) {
                                
                                // Checks if either square bracket or curly brace parenthetical types are open
                                if (str[j] == '[') { brackOpen = true; }

                                if (str[j] == '{') { curlyOpen = true; }
                                
                                // Properly closes the parentheses
                                if (str[j] == ')' && parenClosed == false) { parenClosed = true; }
                                
                                /* If the parentheses haven't been closed, and another parenthetical type
                                is attempting to be closed but is not open, the string is not valid */
                                else if (str[j] == ']' && parenClosed == false && brackOpen == false) { return "NOT VALID"; }

                                else if (str[j] == '}' && parenClosed == false && curlyOpen == false) { return "NOT VALID"; } } 
                                
                                /* If open and close parenthetical counts for square brackets and curly braces do not evenly match,
                                the string is not valid */
                                if ((openBrackCount != closeBrackCount) || (openCurlyCount != closeCurlyCount)) { return "NOT VALID"; } }

                // Case 3: Curly Braces {}
                else if (str[i] == '{') {

                        curlyOpen = true;

                        // Stops when enconutering an opening curly brace and reads the rest of the string
                        for (int j = i; j <= strlen(str); j++) {
                                
                                // Check is either square bracket or curly brace parenthetical types are open 
                                if (str[j] == '[') { brackOpen = true; }

                                if (str[j] == '(') { parenOpen = true; }
                                
                                // Properly closes the curly brace
                                if (str[j] == '}' && curlyClosed == false) { curlyClosed = true; }
                                
                                /* If the curly brace has not been closed, and another parenthetical type
                                is attempting to be closed but is not open, the string is not valid */
                                else if (str[j] == ']' && curlyClosed == false && brackOpen == false) { return "NOT VALID"; }

                                else if (str[j] == ')' && curlyClosed == false && parenOpen == false) { return "NOT VALID"; } }

                                /* If open and close parenthetical counts for square brackets and parentheses do not evenly match,
                                the string is not valid */
                                if ((openBrackCount != closeBrackCount) || (openParenCount != closeParenCount)) { return "NOT VALID"; } } }

        // Final check to determine if the open and close parenthetical counts match
        if ((openBrackCount == closeBrackCount) && (openParenCount == closeParenCount) && (openCurlyCount == closeCurlyCount)) {
                return "VALID"; }

        // Otherwise, the string is not valid
        else { return "NOT VALID"; } }
