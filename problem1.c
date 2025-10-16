#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 20

// Function to check if a cell is part of an island
bool isIsland(int grid[MAX_SIZE][MAX_SIZE], int n, int startRow, int startCol, int *endRow, int *endCol) {
    if (grid[startRow][startCol] == 0) {
        return false;
    }
    
    // Find the bottom-right corner of the rectangle
    *endRow = startRow;
    *endCol = startCol;
    
    // Extend right as far as possible
    while (*endCol + 1 < n && grid[startRow][*endCol + 1] == 1) {
        (*endCol)++;
    }
    
    // Extend down as far as possible
    while (*endRow + 1 < n && grid[*endRow + 1][startCol] == 1) {
        (*endRow)++;
    }
    
    // Verify that the entire rectangle is filled with 1s
    for (int i = startRow; i <= *endRow; i++) {
        for (int j = startCol; j <= *endCol; j++) {
            if (grid[i][j] != 1) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to mark an island as visited
void markIslandVisited(int grid[MAX_SIZE][MAX_SIZE], int startRow, int startCol, int endRow, int endCol) {
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            grid[i][j] = 0; // Mark as visited
        }
    }
}

// Function to count rectangular islands
int countIslands(int grid[MAX_SIZE][MAX_SIZE], int n) {
    int count = 0;
    int tempGrid[MAX_SIZE][MAX_SIZE];
    
    // Create a copy of the grid to avoid modifying the original
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempGrid[i][j] = grid[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tempGrid[i][j] == 1) {
                int endRow, endCol;
                if (isIsland(tempGrid, n, i, j, &endRow, &endCol)) {
                    count++;
                    markIslandVisited(tempGrid, i, j, endRow, endCol);
                }
            }
        }
    }
    
    return count;
}

int main() {
    int n;
    int grid[MAX_SIZE][MAX_SIZE];
    
    // Read input
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // Count and print the number of islands
    int islandCount = countIslands(grid, n);
    printf("%d\n", islandCount);
    
    return 0;
}
