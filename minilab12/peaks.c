#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPeak(int NW, int N, int NE, int W, int CELL, int E, int SW, int S, int SE);

int main(void) {

        int rows = 0;
        int cols = 0;
        int peaks = 0;
        int cell = 0;

        int i = 0;
        int j = 0;

        int read = EOF + 1;

        printf("Enter number of rows and cols, with a space. (ex: 3 4)\n");
        read = scanf("%d %d", &rows, &cols);

        int *A = (int *) malloc(rows*cols*sizeof(int));
        int **elev = (int **) malloc(rows*sizeof(int*));

        for (int i = 0; i < rows; i++) { elev[i] = A + i * cols; }

        while (read != EOF || (i < rows && j < cols)) {
                if (read == EOF) {}

                else {
                printf("Enter the elevation for the current cell.\n");
                read = scanf("%d", &cell);
                elev[i][j] = cell;
                j++;
                if (j == cols) { j = 0; i++; } } }

        printf("Final Elevation Map:\n");

        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                        
                        printf("%d ", elev[i][j]);

                        
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {}
                        
                        else {

                        if (isPeak(elev[i-1][j-1], elev[i-1][j], elev[i-1][j+1], elev[i][j-1], 
                        elev[i][j], elev[i][j+1], elev[i+1][j-1], elev[i+1][j], elev[i+1][j+1]) == 1) { peaks++; }

                        else {}}} printf("\n");  }

        free(A);
        free(elev);

        printf("Number of peaks is: %d\n", peaks);
        return 0; }


int isPeak(int NW, int N, int NE, int W, int CELL, int E, int SW, int S, int SE) {

        if (NW < CELL && N < CELL && NE < CELL && W < CELL && E < CELL && SW < CELL && S < CELL && SE < CELL) { return 1; }
        else { return 0; } }
