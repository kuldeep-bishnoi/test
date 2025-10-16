#!/bin/bash

echo "Testing Problem 1 - Finding Rectangular Islands"
echo "=============================================="

# Test Case 1
echo "Test Case 1:"
echo "4
1 1 0 0
1 1 0 0
0 0 0 0
0 0 0 0" | ./problem1
echo "Expected: 1"
echo ""

# Test Case 2  
echo "Test Case 2:"
echo "6
1 1 1 1 0 0
1 1 1 1 0 0
0 0 0 0 0 0
1 1 0 0 1 1
1 1 0 0 1 1
1 1 0 0 0 0" | ./problem1
echo "Expected: 3"
echo ""

# Test Case 3
echo "Test Case 3:"
echo "5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1" | ./problem1
echo "Expected: 9"
echo ""

echo "Testing Problem 2 - Cellular Infection Dynamics"
echo "================================================"

# Test Case 1
echo "Test Case 1:"
echo "5 5
1
2 2
4" | ./problem2
echo "Expected: Grid with X, I, and . characters"
echo ""

echo "Testing Problem 3 - Segmented Array Processor"
echo "============================================="

# Test Case 1
echo "Test Case 1:"
echo "5
1 2 3 4 5
2
REVERSE 1 3
SWAP_ENDS 0 4" | ./problem3
echo "Expected: 5 4 3 2 1"
echo ""
