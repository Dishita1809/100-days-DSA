#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;
    int prefixSum = 0;

    int* freq = (int*)calloc(2 * n + 1, sizeof(int));
    int offset = n;

    freq[offset] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum + offset >= 0 && prefixSum + offset <= 2 * n)
            count += freq[prefixSum + offset];

        if (prefixSum + offset >= 0 && prefixSum + offset <= 2 * n)
            freq[prefixSum + offset]++;
    }

    printf("%d", count);

    free(freq);
    return 0;
}
