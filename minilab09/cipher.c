#include <stdio.h>

/********************************
This program uses a simple cipher
to encode some text.
*********************************/

/* Main */
int main(void) {
        
        /* The array of chars to be encoded */
        char mystring[] = "ThisIsAStringToEncode";

        /* The number of letters to shift by */
        int shift = 3;

        /* Holds the ASCII value of a char in the array */
        int shifted_char;

        printf("The string to be encoded is %s and the shift to use is %d \n", mystring, shift);
        
        /* For loop to shift every char in the array by shift amount */
        for (int i = 0; i < (sizeof(mystring)/sizeof(mystring[0])); i++) {
                printf("Char before shift: %c \n", mystring[i]);
                shifted_char = (int)mystring[i] + shift;
                mystring[i] = (char)shifted_char;
                printf("Char after shift: %c \n", mystring[i]);
        }

        printf("The encoded string is %s \n", mystring);
        
        /* For loop to decode an encoded string */
        for (int i = 0; i < (sizeof(mystring)/sizeof(mystring[0])); i++) {
                printf("Char before shift: %c \n", mystring[i]);
                shifted_char = (int)mystring[i] - shift;
                mystring[i] = (char)shifted_char;
                printf("Char after shift: %c \n", mystring[i]);
        }

        printf("The string after decoding is %s \n", mystring);

return 0;
}
