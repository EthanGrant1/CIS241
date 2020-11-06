#include<stdio.h>
#include<stdlib.h>

int main(void) {

// Two statically allocated arrays to perform
// functions on
int nums[11];
int sums[11];

// Function for cumulative sums using statically
// allocated areays
int CumulativeSum = 0;

for (int i = 0; i < 12; i++) {
        nums[i] = i;
    }

for (int i = 0; i < 12; i++) {
        CumulativeSum += nums[i];
        sums[i] = CumulativeSum;
    }

for (int i = 0; i < 12; i++) {
        printf("The cumulative sum for sums[%d] is %d\n", i, sums[i]);
    }

// Function for cuulative sums using pointer arithmetic
int *numpointer;
numpointer = (int *) malloc(sizeof(int) * 12);

int *sumpointer;
sumpointer = (int *) malloc(sizeof(int) * 12);

int sum2 = 0;

for (int i = 0; i < 12; i++) {
        *(numpointer + i) = i;
    }

for (int i = 0; i < 12; i++) {
        sum2 += *(numpointer + i);
        *(sumpointer+ i) = sum2;
    }

for (int i = 0; i < 12; i++) {
        printf("The value of the sum for sumpointer + %d is: %d\n" , i, *(sumpointer + i));
    }

return 0;
}
