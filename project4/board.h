#ifndef BOARD_H
#define BOARD_H

// Defines the Board Struct
typedef struct Board {
        /* Pointers for the array of chars. Elements of a 1D array, and an array of 1D arrays.
        This allows for the use of [][] notation in functions */
        char *grid;
        char **rowPntr;

        // The number of rows and columns in the array
        int nrows;
        int ncols;
} Board;

// A prototype for the update_board function found in board.c
Board* update_board(Board * CurrentBoard);

// A prototype for the CheckCells function found in board.c
char CheckCells(char NW, char N, char NE, char W, char CurrentCell, char E, char SW, char S, char SE);

#endif
