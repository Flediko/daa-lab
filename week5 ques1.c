#include <stdio.h> 
#include <stdlib.h>

void frequency(char arr[], int n, int min, int max) 
{ 
    int size = max - min + 1; 
    int *freq = (int *)calloc(size, sizeof(int)); 
    int max_freq = 0; 
    char result;

    for (int i = 0; i < n; i++) 
    {
        freq[arr[i] - min]++;
        if (freq[arr[i] - min] > max_freq) 
        {
            max_freq = freq[arr[i] - min];
            result = arr[i];
        }
    }

    if (max_freq == 1)
        printf("no duplicates\n");
    else
        printf("%c-%d\n", result, max_freq);
    free(freq);
}

int main() 
{ 
    int t, n; 
    printf("Enter the number of test cases: "); 
    scanf("%d", &t); 
    while (t--) 
    { 
        printf("Enter the number of characters: "); 
        scanf("%d", &n); 
        char arr[n]; 
        int min, max;
        printf("Enter the characters: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
        if (i == 0) min = max = arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    frequency(arr, n, min, max);
}
return 0;

}

