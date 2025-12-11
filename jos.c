#include <stdio.h>



int main() {
    int arr[] = {5, 8, 12, 18, 25, 31, 42, 49, 55, 60, 68, 75, 80, 91, 95, 99};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x1 = 42;
    int x2 = 100;
    
    int result1 = exponentialSearch(arr, n, x1);

    if (result1 != -1)
        printf("Angka %d ditemukan pada indeks: %d\n", x1, result1);
    else
        printf("Angka %d tidak ditemukan dalam array\n", x1);
    
    int result2 = exponentialSearch(arr, n, x2);

    if (result2 != -1)
        printf("Angka %d ditemukan pada indeks: %d\n", x2, result2);
    else
        printf("Angka %d tidak ditemukan dalam array\n", x2);

    return 0;
}