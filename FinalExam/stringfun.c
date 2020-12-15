/******************************
          STRINGFUN.C
-------------------------------
This program reads strings from
stdin, and simultaneously reverses
the string, as well as omits any
occurrences of the letters, 'g',
'v', 's', and 'u' (lowercase only).
*******************************/

// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	
	// Initializing variables for reading a string
	char *s;
	int read = EOF + 1;
	size_t max = 10;

	// While "End-Of-File" signal is not being sent
	while (read != EOF) {

		// Allocate memory for the string
		s = (char *) malloc(sizeof(char)*max);

		// Accept user input for a string
		read = getline(&s, &max, stdin);

		// If "End-Of-File" signal is sent, do nothing
		if (read == EOF) {}

		// Otherwise, perform this function
		else { 
		
		// Read the string in reverse and print all of the chars, excluding 'g', 'v', 's', and 'u'
		for (int i = strlen(s)-1; i >= 0; i--) {
			if (s[i] != 'g' && s[i] != 'v' && s[i] != 's' && s[i] != 'u' && (isalpha(s[i]) != 0 || s[i] == ' ')) {
			printf("%c", s[i]); } } 
			printf("\n"); }
		
		// Frees up allocated memory
		free(s); }
return 0; }
