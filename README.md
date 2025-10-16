# Computational Thinking Assignment #1

**Course:** FM111 - Computational Thinking  
**Institution:** Plaksha University, Mohali  
**Semester:** Monsoon AY 2025-26  

---

## Assignment Overview

This repository contains comprehensive solutions to three computational thinking problems implemented in C language. Each problem demonstrates different aspects of algorithmic thinking, data structure manipulation, and advanced programming concepts. The solutions are designed to be efficient, well-documented, and follow industry best practices.

### Problems Solved

| Problem | Description | Focus Area | Marks |
|---------|-------------|------------|-------|
| **Problem 1** | Finding Rectangular Islands | 2D Array Traversal | 50 |
| **Problem 2** | Cellular Infection Dynamics | State Management & Simulation | 50 |
| **Problem 3** | Segmented Array Processor | Pointer Arithmetic & Array Operations | 50 |

**Total:** 150 marks (15% of course grade)

---

## Quick Start

### Prerequisites
- GCC compiler (C99 standard or later)
- Linux/Unix environment (tested on Ubuntu)
- Basic understanding of C programming concepts

### Compilation
```bash
# Compile all programs using the provided Makefile
make all

# Or compile individually
gcc -o problem1 problem1.c -std=c99 -Wall -Wextra
gcc -o problem2 problem2.c -std=c99 -Wall -Wextra
gcc -o problem3 problem3.c -std=c99 -Wall -Wextra
```

### Running the Programs
```bash
# Run with input from file
./problem1 < input1.txt

# Run with interactive input
./problem1
# Then enter input manually

# Run automated tests
make test
```

---

## Detailed Problem Analysis

### Problem 1: Finding Rectangular Islands

**Objective:** Count non-overlapping rectangular islands in a binary matrix where 1 represents land and 0 represents water.

#### Problem Analysis
This problem requires careful analysis of 2D grid patterns to identify perfect rectangular formations. The key challenge lies in ensuring that each island is counted exactly once and that only perfect rectangles are considered valid islands.

#### Algorithm Design
The solution employs a systematic approach:

1. **Grid Traversal:** The algorithm scans the matrix row by row, left to right
2. **Island Detection:** When a cell containing '1' is encountered, the algorithm determines if it forms the top-left corner of a valid rectangular island
3. **Rectangle Validation:** The algorithm extends the potential rectangle both horizontally and vertically to find its complete boundaries
4. **Verification:** The entire rectangular region is verified to ensure all cells contain '1'
5. **Marking:** Once validated, the entire island is marked as processed to prevent double-counting

#### Implementation Details
```c
bool isIsland(int grid[MAX_SIZE][MAX_SIZE], int n, int startRow, int startCol, int *endRow, int *endCol) {
    // Determines if a cell forms a valid rectangular island
    // Returns true if valid rectangle found, false otherwise
    // Updates endRow and endCol to mark rectangle boundaries
}
```

The algorithm uses a temporary copy of the grid to avoid modifying the original input during processing. This ensures that the solution can handle complex scenarios with multiple overlapping potential islands.

#### Time and Space Complexity
- **Time Complexity:** O(N²) where N is the grid dimension
- **Space Complexity:** O(N²) for the temporary grid copy
- **Optimization:** Single-pass traversal with intelligent marking reduces redundant checks

#### Example Execution
```
Input Matrix:
1 1 0 0
1 1 0 0
0 0 0 0
0 0 0 0

Process:
1. Find '1' at (0,0)
2. Extend rectangle: right to (0,1), down to (1,0)
3. Verify rectangle (0,0) to (1,1) contains only '1's
4. Mark entire rectangle as processed
5. Continue scanning for unprocessed '1's
6. No more '1's found
7. Return count: 1
```

---

### Problem 2: Cellular Infection Dynamics

**Objective:** Simulate disease spread dynamics using cellular automata with three distinct states and timed transitions.

#### Problem Analysis
This problem models complex biological systems where cells transition between states based on local neighborhood conditions and temporal rules. The simulation requires careful state management and simultaneous updates to ensure accurate modeling.

#### State Transition Model
The cellular automaton implements a three-state system:

1. **Healthy State (.)**: Susceptible to infection from neighboring infected cells
2. **Infected State (X)**: Can spread infection to healthy neighbors, transitions to immune after 2 time steps
3. **Immune State (I)**: Cannot be infected, transitions back to healthy after 3 time steps

#### Algorithm Design
The simulation follows these principles:

1. **Simultaneous Updates:** All state changes are calculated based on the current state, then applied simultaneously
2. **Duration Tracking:** Separate counters track how long each cell has been in infected or immune states
3. **Neighborhood Analysis:** Only orthogonal neighbors (up, down, left, right) can transmit infection
4. **Boundary Handling:** Edge and corner cells have reduced neighbor counts

#### Implementation Details
```c
void simulateTimeStep(char grid[MAX_SIZE][MAX_SIZE], int infectionCount[MAX_SIZE][MAX_SIZE], 
                     int immunityCount[MAX_SIZE][MAX_SIZE], int R, int C) {
    // Processes one complete time step of the simulation
    // Uses temporary arrays to ensure simultaneous updates
    // Implements all state transition rules
}
```

The algorithm maintains three parallel data structures:
- `grid`: Current state of each cell
- `infectionCount`: Time spent in infected state
- `immunityCount`: Time spent in immune state

#### State Transition Logic
```c
// Healthy to Infected
if (grid[i][j] == '.' && hasInfectedNeighbor) {
    newGrid[i][j] = 'X';
    newInfectionCount[i][j] = 1;
}

// Infected to Immune
if (grid[i][j] == 'X' && infectionCount[i][j] >= 2) {
    newGrid[i][j] = 'I';
    newImmunityCount[i][j] = 1;
}

// Immune to Healthy
if (grid[i][j] == 'I' && immunityCount[i][j] >= 3) {
    newGrid[i][j] = '.';
}
```

#### Time and Space Complexity
- **Time Complexity:** O(R×C×T) where R,C are grid dimensions and T is simulation time
- **Space Complexity:** O(R×C) for state tracking arrays
- **Optimization:** Efficient neighbor checking and simultaneous state updates

---

### Problem 3: Segmented Array Processor

**Objective:** Implement a system for applying sequential transformation operations to integer arrays using advanced pointer arithmetic techniques.

#### Problem Analysis
This problem requires implementing four distinct array operations while adhering to strict pointer usage requirements. The challenge lies in performing complex transformations efficiently using only pointer arithmetic and in-place modifications.

#### Operations Specification

##### 1. REVERSE(L, R)
Reverses all elements in the array from index L to R (inclusive).

**Algorithm:** Uses two pointers starting from opposite ends, swapping elements while moving inward.
```c
void reverse(int *arr, int L, int R) {
    int *left = arr + L;
    int *right = arr + R;
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
```

##### 2. ROTATE_LEFT(L, R, K)
Rotates the subarray from L to R left by K positions.

**Algorithm:** Uses the "reverse segments" technique:
1. Reverse first K elements
2. Reverse remaining elements  
3. Reverse entire segment
```c
void rotate_left(int *arr, int L, int R, int K) {
    int len = R - L + 1;
    K = K % len;  // Handle K > segment length
    int *start = arr + L;
    
    reverse(start, 0, K - 1);      // Reverse first K
    reverse(start, K, len - 1);    // Reverse remaining
    reverse(start, 0, len - 1);    // Reverse entire segment
}
```

##### 3. SWAP_ENDS(L, R)
Swaps elements at indices L and R.

**Algorithm:** Direct pointer-based element swapping.
```c
void swap_ends(int *arr, int L, int R) {
    int *left = arr + L;
    int *right = arr + R;
    int temp = *left;
    *left = *right;
    *right = temp;
}
```

##### 4. MIRROR(split_index)
Replaces elements from split_index to end with reversed copy of elements from 0 to split_index-1.

**Algorithm:** Calculates mirror length and copies reversed elements using pointer arithmetic.
```c
void mirror(int *arr, int split_index, int n) {
    int *first_half_start = arr;
    int *second_half_start = arr + split_index;
    
    int first_half_len = split_index;
    int second_half_len = n - split_index;
    int mirror_len = (first_half_len < second_half_len) ? first_half_len : second_half_len;
    
    for (int i = 0; i < mirror_len; i++) {
        *(second_half_start + i) = *(first_half_start + split_index - 1 - i);
    }
}
```

#### Pointer Arithmetic Requirements
The implementation strictly adheres to the assignment requirements:

1. **Function Parameters:** All functions accept `int *` parameters instead of array notation
2. **Pure Pointer Arithmetic:** At least two functions use only pointer arithmetic for array access
3. **In-place Operations:** No auxiliary arrays are used except for single temporary variables
4. **Efficient Access:** Direct memory manipulation without array indexing overhead

#### Time and Space Complexity
- **Time Complexity:** O(M×N) where M is number of operations and N is array size
- **Space Complexity:** O(1) - constant space for all operations
- **Optimization:** In-place modifications eliminate memory allocation overhead

---

## Testing and Validation

### Test Case Coverage
Each problem includes comprehensive test cases covering:

#### Problem 1 Test Cases:
- **Single Island:** Tests basic rectangle detection
- **Multiple Islands:** Tests non-overlapping detection and counting
- **Individual Cells:** Tests 1×1 island handling

#### Problem 2 Test Cases:
- **Single Source:** Tests basic infection spread mechanics
- **Multiple Sources:** Tests complex interaction patterns
- **Long Simulation:** Tests state cycling and edge cases

#### Problem 3 Test Cases:
- **Basic Operations:** Tests individual operation correctness
- **Complex Sequences:** Tests operation chaining and interaction
- **Edge Cases:** Tests boundary conditions and parameter limits

### Automated Testing
The provided test suite validates:
- Correct output format and values
- Edge case handling
- Performance characteristics
- Memory usage patterns

---

## Code Architecture and Design Patterns

### Problem 1 Architecture
```
main()
├── countIslands()
│   ├── isIsland() - Rectangle validation algorithm
│   └── markIslandVisited() - State management
└── Input/Output handling
```

**Design Pattern:** Template Method - Common island detection pattern with specific validation rules.

### Problem 2 Architecture
```
main()
├── simulateTimeStep()
│   ├── State transition logic
│   ├── Neighborhood analysis
│   └── Duration tracking
└── Simulation loop
```

**Design Pattern:** State Machine - Explicit state management with transition rules.

### Problem 3 Architecture
```
main()
├── reverse() - Pointer arithmetic implementation
├── rotate_left() - Pointer arithmetic implementation  
├── swap_ends() - Pointer arithmetic implementation
└── mirror() - Pointer arithmetic implementation
```

**Design Pattern:** Strategy Pattern - Different algorithms for different operations.

---

## Performance Analysis and Optimizations

### Problem 1 Optimizations
- **Single Pass Traversal:** Eliminates redundant scanning
- **Intelligent Marking:** Prevents double-counting without additional complexity
- **Early Termination:** Stops processing when no more islands can be found

### Problem 2 Optimizations
- **Simultaneous Updates:** Ensures accurate state transitions
- **Efficient Neighbor Checking:** Only checks relevant orthogonal neighbors
- **State Compression:** Uses minimal memory for state tracking

### Problem 3 Optimizations
- **In-place Operations:** Eliminates memory allocation overhead
- **Pointer Arithmetic:** Direct memory access without array indexing
- **Algorithm Efficiency:** Uses optimal algorithms for each operation type

---

## Technical Implementation Details

### Compiler Configuration
```bash
gcc -std=c99 -Wall -Wextra -Werror
```

**Rationale:** C99 standard ensures compatibility, warning flags catch potential issues, error flag prevents compilation with warnings.

### Memory Management
- **Static Allocation:** All arrays use compile-time sizing
- **No Dynamic Allocation:** Eliminates memory leak risks
- **Stack-based Variables:** Automatic cleanup and scope management

### Error Handling
- **Input Validation:** Assumes valid input per assignment constraints
- **Bounds Checking:** All array accesses are bounds-safe
- **Graceful Degradation:** Handles edge cases appropriately

---

## Learning Outcomes and Educational Value

### Technical Skills Developed
1. **Advanced C Programming:** Pointer arithmetic, memory management, optimization techniques
2. **Algorithm Design:** Problem decomposition, efficiency analysis, implementation strategies
3. **Data Structure Manipulation:** 2D arrays, state machines, sequential processing
4. **Testing Methodology:** Systematic validation, edge case handling, performance analysis

### Problem-Solving Approaches
1. **Systematic Analysis:** Breaking complex problems into manageable components
2. **Pattern Recognition:** Identifying common algorithmic patterns and applying appropriate solutions
3. **Optimization Thinking:** Balancing correctness, efficiency, and maintainability
4. **Implementation Strategy:** Choosing appropriate data structures and algorithms for specific requirements

### Software Engineering Practices
1. **Code Organization:** Modular design with clear separation of concerns
2. **Documentation:** Comprehensive comments and clear variable naming
3. **Testing:** Systematic validation and edge case coverage
4. **Maintainability:** Clean, readable code following established conventions

---

## Submission Requirements

### File Structure
```
[student_id].zip
├── problem1.c
├── problem2.c
└── problem3.c
```

### Compilation Requirements
- Must compile without errors or warnings
- Must use C99 standard
- Must handle all provided test cases correctly

### Code Quality Standards
- Clear, readable implementation
- Appropriate comments and documentation
- Efficient algorithms and data structures
- Proper error handling and edge case management

---

## Academic Integrity

This assignment represents individual work completed in accordance with academic integrity policies. All code is original work implementing the specified requirements using standard algorithmic approaches and programming techniques.

---