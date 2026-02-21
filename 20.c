/*Given an array of integers, count the number of subarrays whose sum is equal to zero.*/


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefix = 0;

    // Simple frequency array (assuming sum range is small)
    int freq[20001] = {0};   // supports sum from -10000 to +10000
    int offset = 10000;      // to handle negative index

    freq[offset] = 1;  // important (for prefix = 0 case)

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        count += freq[prefix + offset];
        freq[prefix + offset]++;
    }

    printf("%d", count);

    return 0;
}