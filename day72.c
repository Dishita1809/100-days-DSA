#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
