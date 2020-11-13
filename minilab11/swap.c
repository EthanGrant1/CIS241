#include <stdio.h>
#include <stdlib.h>

void swap(int, int);

int main (void) {

swap(5, 100);

return 0;
}

void swap(int num1, int num2) {
        
int *point1;
int *point2;
int *point3;

int num3 = num1;

point1 = &num1;
point2 = &num2;
point3 = &num3;

*point1 = *point2;
*point2 = *point3;

printf("num1: %d, num2: %d\n", num1, num2);

return;
}

