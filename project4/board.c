#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

// This program takes a Board and updates it according to the rules of Conway's Game of Life.

// update_board function which takes a board and updates each cell.
Board* update_board(Board * CurrentBoard) {
        
        // Char to hold the value of an updated cell
        char UpdatedCell = 'a';
        
        // Instantiating a new array to hold the new char values
        char *UpdatedGrid = (char *) malloc(CurrentBoard->nrows*CurrentBoard->ncols*sizeof(char));
        char **newRowPntr = (char **) malloc(CurrentBoard->nrows*sizeof(char*));
        for (int i = 0; i < CurrentBoard->nrows; i++) { newRowPntr[i] = UpdatedGrid + i * CurrentBoard->ncols; }

        // Checks every cell on the Board and assigns it a new value
        for (int i = 0; i < CurrentBoard->nrows; i++) {
                for (int j = 0; j < CurrentBoard->ncols; j++) {
                
                // Top left corner case
                if (i == 0 && j == 0) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[CurrentBoard->nrows-1][CurrentBoard->ncols-1], CurrentBoard->rowPntr[CurrentBoard->nrows-1][j],
                        CurrentBoard->rowPntr[CurrentBoard->nrows-1][j+1], CurrentBoard->rowPntr[i][CurrentBoard->ncols-1], CurrentBoard->rowPntr[i][j],
                        CurrentBoard->rowPntr[i][j+1], CurrentBoard->rowPntr[i+1][CurrentBoard->ncols-1], CurrentBoard->rowPntr[i+1][j], CurrentBoard->rowPntr[i+1][j+1]);
                        
                        newRowPntr[i][j] = UpdatedCell; }
                
                // Top row case
                if (i == 0 && (j > 0 && j < CurrentBoard->ncols-1)) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[CurrentBoard->nrows-1][j-1], CurrentBoard->rowPntr[CurrentBoard->nrows-1][j],
                        CurrentBoard->rowPntr[CurrentBoard->nrows-1][j+1], CurrentBoard->rowPntr[i][j-1], CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][j+1],
                        CurrentBoard->rowPntr[i+1][j-1], CurrentBoard->rowPntr[i+1][j], CurrentBoard->rowPntr[i+1][j+1]);

                        newRowPntr[i][j] = UpdatedCell; }

                // Top right corner case
                if (i == 0 && j == CurrentBoard->ncols-1) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[CurrentBoard->nrows-1][j-1], CurrentBoard->rowPntr[CurrentBoard->nrows-1][j], CurrentBoard->rowPntr[CurrentBoard->nrows-1][0],
                        CurrentBoard->rowPntr[i][j-1], CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][0], CurrentBoard->rowPntr[i+1][j-1],CurrentBoard->rowPntr[i+1][j], 
                        CurrentBoard->rowPntr[i+1][0]);

                        newRowPntr[i][j] = UpdatedCell; }
                
                // Leftmost column case
                if ((i != 0 && i != CurrentBoard->nrows-1) && j == 0) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[i-1][CurrentBoard->ncols-1], CurrentBoard->rowPntr[i-1][j], CurrentBoard->rowPntr[i-1][j+1],
                        CurrentBoard->rowPntr[i][CurrentBoard->ncols-1], CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][j+1],
                        CurrentBoard->rowPntr[i+1][CurrentBoard->ncols-1], CurrentBoard->rowPntr[i+1][j], CurrentBoard->rowPntr[i+1][j+1]);
                        
                        newRowPntr[i][j] = UpdatedCell; }

                // Middle of the board case (every cell except for edges)
                if (i != 0 && i != CurrentBoard->nrows-1 && j != 0 && j != CurrentBoard->ncols-1) {
                       UpdatedCell =
                       CheckCells(CurrentBoard->rowPntr[i-1][j-1], CurrentBoard->rowPntr[i-1][j], CurrentBoard->rowPntr[i-1][j+1],
                       CurrentBoard->rowPntr[i][j-1], CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][j+1],
                       CurrentBoard->rowPntr[i+1][j-1], CurrentBoard->rowPntr[i+1][j], CurrentBoard->rowPntr[i+1][j+1]); 
                       
                       newRowPntr[i][j] = UpdatedCell; }
                
                // Rightmost column case
                if ((i != 0 && i != CurrentBoard->nrows-1) && j == CurrentBoard->ncols-1) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[i-1][j-1], CurrentBoard->rowPntr[i-1][j], CurrentBoard->rowPntr[i-1][0], CurrentBoard->rowPntr[i][j-1],
                        CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][0], CurrentBoard->rowPntr[i+1][j-1], CurrentBoard->rowPntr[i+1][j], CurrentBoard->rowPntr[i+1][0]);

                        newRowPntr[i][j] = UpdatedCell; }

                // Bottom left corner case
                if (i == CurrentBoard->nrows-1 && j == 0) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[i-1][CurrentBoard->ncols-1], CurrentBoard->rowPntr[i-1][j], CurrentBoard->rowPntr[i-1][j+1], 
                        CurrentBoard->rowPntr[i][CurrentBoard->ncols-1], CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][j+1],
                        CurrentBoard->rowPntr[0][CurrentBoard->ncols-1], CurrentBoard->rowPntr[0][0], CurrentBoard->rowPntr[0][1]);

                        newRowPntr[i][j] = UpdatedCell; }

                // Bottom row case
                if (i == CurrentBoard->nrows-1 && (j > 0 && j < CurrentBoard->ncols-1)) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[i-1][j-1], CurrentBoard->rowPntr[i-1][j], CurrentBoard->rowPntr[i-1][j+1], CurrentBoard->rowPntr[i][j-1],
                        CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][j+1], CurrentBoard->rowPntr[0][j-1], CurrentBoard->rowPntr[0][j], CurrentBoard->rowPntr[0][j+1]);

                        newRowPntr[i][j] = UpdatedCell; }

                // Bottom right corner case
                if (i == CurrentBoard->nrows-1 && j == CurrentBoard->ncols-1) {
                        UpdatedCell =
                        CheckCells(CurrentBoard->rowPntr[i-1][j-1], CurrentBoard->rowPntr[i-1][j], CurrentBoard->rowPntr[i-1][0], CurrentBoard->rowPntr[i][j-1],
                        CurrentBoard->rowPntr[i][j], CurrentBoard->rowPntr[i][0], CurrentBoard->rowPntr[0][j-1], CurrentBoard->rowPntr[0][j], CurrentBoard->rowPntr[0][0]);

                        newRowPntr[i][j] = UpdatedCell; } } }
        
        // Assigns values from new Board to the CurrentBoard
        for (int i = 0; i < CurrentBoard->nrows; i++) {
                for (int j = 0; j < CurrentBoard->ncols; j++) {
                        CurrentBoard->rowPntr[i][j] = newRowPntr[i][j]; } }
        
        // Frees allocated memory
        free(UpdatedGrid);
        free(newRowPntr);

        return CurrentBoard; }

// Checks the CurrentCell and its eight neighboring cells
char CheckCells(char NW, char N, char NE, char W, char CurrentCell, char E, char SW, char S, char SE) {
               
                // Counts for neighbors that are alive, red, and green
                int LiveNeighbors = 0;
                int RedNeighbors = 0;
                int GreenNeighbors = 0;

                // The updated cell value
                char cell = 'a';
                
                // Checks if any of the eight neighbors are green or red and adds them to the count
                if (NW == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (NW == 'r') { RedNeighbors++; LiveNeighbors++; }

                if (N == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (N == 'r') { RedNeighbors++; LiveNeighbors++; }

                if (NE == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (NE == 'r') { RedNeighbors++; LiveNeighbors++; }

                if (W == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (W == 'r') { RedNeighbors++; LiveNeighbors++; }

                if (E == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (E == 'r') { RedNeighbors++; LiveNeighbors++; }

                if (SW == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (SW == 'r') { RedNeighbors++; LiveNeighbors++; }

                if (S == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (S == 'r') { RedNeighbors++; LiveNeighbors++; }

                if (SE == 'g') { GreenNeighbors++; LiveNeighbors++; }
                else if (SE == 'r') { RedNeighbors++; LiveNeighbors++; }

                // Cells that are alive will die from underpopulation or overpopulation
                if ((CurrentCell == 'g' || CurrentCell == 'r') && (LiveNeighbors > 3 || LiveNeighbors < 2)) { cell = 'x'; }

                // Cells that are alive will stay alive
                else if (CurrentCell == 'g' && (LiveNeighbors == 2 || LiveNeighbors == 3)) { cell = 'g'; }
                else if (CurrentCell == 'r' && (LiveNeighbors == 2 || LiveNeighbors == 3)) { cell = 'r'; }

                // Cells that are dead will become alive and inherit the color of the most plentiful neighbor
                else if (CurrentCell == 'x' && LiveNeighbors == 3) {
                        if (GreenNeighbors > RedNeighbors) { cell = 'g'; }
                        else { cell = 'r'; } }
                
                // If all else fails, keep the cell as is
                else { return CurrentCell; }

                return cell; }
