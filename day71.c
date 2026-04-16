#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];

void insert(int key, int m) {
    int h = key % m;
    int i = 0;

    while (i < m) {
        int index = (h + i * i) % m;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
}

void search(int key, int m) {
    int h = key % m;
    int i = 0;

    while (i < m) {
        int index = (h + i * i) % m;
        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[index] == -1) break;
        i++;
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    for (int i = 0; i < m; i++) table[i] = -1;

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}
