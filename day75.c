#include <stdio.h>

#define N 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[N];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int prefix = 0, maxLen = 0;
    int map[2 * N];

    for (int i = 0; i < 2 * N; i++) map[i] = -1;

    map[N] = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int index = prefix + N;

        if (map[index] != -1) {
            int len = i + 1 - map[index];
            if (len > maxLen) maxLen = len;
        } else {
            map[index] = i + 1;
        }
    }

    printf("%d", maxLen);
    return 0;
}
