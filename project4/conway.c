#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

// A simulation of Conway's Game of Life 
int main(void) {
        
        // Board struct and various variables
        Board brd;
        brd.nrows = 0;
        brd.ncols = 0;

        // The number of timesteps to perform
        int steps = 0;

        // The current cell being assigned
        char CurrentCell = 'a';

        // The number of elements in the Board's array of chars
        int ele = 0;

        // The number of red and green cells in the array
        int red = 0;
        int green = 0;
        
        // The user enters the number of rows and columns the Board will have
        scanf("%d %d", &brd.nrows, &brd.ncols);
        // The user enters the number of timesteps to perform
        scanf("%d", &steps);
        
        // Allocates memory for the Board's array of chars
        brd.grid = (char *) malloc (brd.nrows*brd.ncols*sizeof(char));
        brd.rowPntr = (char **) malloc (brd.nrows*sizeof(char*));
        
        // Allows for [][] notation in functions
        for (int i = 0; i < brd.nrows; i++) { brd.rowPntr[i] = brd.grid + i * brd.ncols; }
        
        // Assigning chars to cells in the array
        while (ele < brd.nrows*brd.ncols) {
                // The user inputs a char and it gets added to the array
                scanf("%c", &CurrentCell);
                brd.grid[ele] = CurrentCell;
                // Only the chars 'g', 'r', and 'x' are allowed
                if (CurrentCell == 'g' || CurrentCell == 'r' || CurrentCell == 'x') { ele++; } }
        
        // Pointer to the Board
        Board *CurrentBoard = &brd;        

        // Updates the Board the requested number of timesteps
        for (int i = 0; i < steps; i++) { update_board(CurrentBoard); }

        // Counts the number of green and red cells on the Board
        for (int i = 0; i < brd.nrows; i++) {
                for (int j = 0; j < brd.ncols; j++) {
                        if (brd.rowPntr[i][j] == 'g') { green++; }
                        else if (brd.rowPntr[i][j] == 'r') { red++; } } }
        
        // Prints the result
        printf("green: %d, red: %d\n", green, red);
        
        // Frees allocated memory
        free(brd.grid);
        free(brd.rowPntr);

        return 0; }
