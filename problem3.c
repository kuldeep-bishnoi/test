#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to reverse elements from index L to R using pointer arithmetic
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

// Function to rotate left using pointer arithmetic
void rotate_left(int *arr, int L, int R, int K) {
    int len = R - L + 1;
    if (len <= 1) return;
    
    K = K % len;
    if (K == 0) return;
    
    int *start = arr + L;
    
    // Reverse the first K elements
    reverse(start, 0, K - 1);
    
    // Reverse the remaining elements
    reverse(start, K, len - 1);
    
    // Reverse the entire segment
    reverse(start, 0, len - 1);
}

// Function to swap elements at indices L and R using pointer arithmetic
void swap_ends(int *arr, int L, int R) {
    int *left = arr + L;
    int *right = arr + R;
    
    int temp = *left;
    *left = *right;
    *right = temp;
}

// Function to mirror using pointer arithmetic
void mirror(int *arr, int split_index, int n) {
    int *first_half_start = arr;
    int *second_half_start = arr + split_index;
    
    // Calculate how many elements we can mirror
    int first_half_len = split_index;
    int second_half_len = n - split_index;
    int mirror_len = (first_half_len < second_half_len) ? first_half_len : second_half_len;
    
    // Mirror the elements
    for (int i = 0; i < mirror_len; i++) {
        *(second_half_start + i) = *(first_half_start + split_index - 1 - i);
    }
}

int main() {
    int n, m;
    int arr[MAX_SIZE];
    char operation[20];
    
    // Read array size and elements
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read number of operations
    scanf("%d", &m);
    
    // Process each operation
    for (int i = 0; i < m; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "REVERSE") == 0) {
            int L, R;
            scanf("%d %d", &L, &R);
            reverse(arr, L, R);
        }
        else if (strcmp(operation, "ROTATE_LEFT") == 0) {
            int L, R, K;
            scanf("%d %d %d", &L, &R, &K);
            rotate_left(arr, L, R, K);
        }
        else if (strcmp(operation, "SWAP_ENDS") == 0) {
            int L, R;
            scanf("%d %d", &L, &R);
            swap_ends(arr, L, R);
        }
        else if (strcmp(operation, "MIRROR") == 0) {
            int split_index;
            scanf("%d", &split_index);
            mirror(arr, split_index, n);
        }
    }
    
    // Print final array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
