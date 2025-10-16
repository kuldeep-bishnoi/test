#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 25

// Cell states
#define HEALTHY 0
#define INFECTED 1
#define IMMUNE 2

// Function to simulate one time step
void simulateTimeStep(char grid[MAX_SIZE][MAX_SIZE], int infectionCount[MAX_SIZE][MAX_SIZE], 
                     int immunityCount[MAX_SIZE][MAX_SIZE], int R, int C) {
    char newGrid[MAX_SIZE][MAX_SIZE];
    int newInfectionCount[MAX_SIZE][MAX_SIZE];
    int newImmunityCount[MAX_SIZE][MAX_SIZE];
    
    // Initialize new arrays
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            newGrid[i][j] = grid[i][j];
            newInfectionCount[i][j] = infectionCount[i][j];
            newImmunityCount[i][j] = immunityCount[i][j];
        }
    }
    
    // Process each cell
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'X') { // Currently infected
                if (infectionCount[i][j] >= 2) {
                    // Transition to immune
                    newGrid[i][j] = 'I';
                    newInfectionCount[i][j] = 0;
                    newImmunityCount[i][j] = 1;
                } else {
                    // Stay infected, increment count
                    newInfectionCount[i][j]++;
                }
            } else if (grid[i][j] == 'I') { // Currently immune
                if (immunityCount[i][j] >= 3) {
                    // Transition to healthy
                    newGrid[i][j] = '.';
                    newImmunityCount[i][j] = 0;
                } else {
                    // Stay immune, increment count
                    newImmunityCount[i][j]++;
                }
            } else if (grid[i][j] == '.') { // Currently healthy
                // Check if any orthogonal neighbor is infected
                bool willBeInfected = false;
                
                // Check up
                if (i > 0 && grid[i-1][j] == 'X') {
                    willBeInfected = true;
                }
                // Check down
                if (i < R-1 && grid[i+1][j] == 'X') {
                    willBeInfected = true;
                }
                // Check left
                if (j > 0 && grid[i][j-1] == 'X') {
                    willBeInfected = true;
                }
                // Check right
                if (j < C-1 && grid[i][j+1] == 'X') {
                    willBeInfected = true;
                }
                
                if (willBeInfected) {
                    newGrid[i][j] = 'X';
                    newInfectionCount[i][j] = 1;
                }
            }
        }
    }
    
    // Copy new state back to original arrays
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            grid[i][j] = newGrid[i][j];
            infectionCount[i][j] = newInfectionCount[i][j];
            immunityCount[i][j] = newImmunityCount[i][j];
        }
    }
}

int main() {
    int R, C, N, T;
    char grid[MAX_SIZE][MAX_SIZE];
    int infectionCount[MAX_SIZE][MAX_SIZE];
    int immunityCount[MAX_SIZE][MAX_SIZE];
    
    // Initialize grid to healthy state
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid[i][j] = '.';
            infectionCount[i][j] = 0;
            immunityCount[i][j] = 0;
        }
    }
    
    // Read input
    scanf("%d %d", &R, &C);
    scanf("%d", &N);
    
    // Set initially infected cells
    for (int i = 0; i < N; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        grid[r][c] = 'X';
        infectionCount[r][c] = 1;
    }
    
    scanf("%d", &T);
    
    // Simulate T time steps
    for (int t = 0; t < T; t++) {
        simulateTimeStep(grid, infectionCount, immunityCount, R, C);
    }
    
    // Print final grid
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", grid[i][j]);
            if (j < C - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
