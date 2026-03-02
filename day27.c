#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, val;

    scanf("%d", &n);
    struct Node *head1 = NULL, *tail1 = NULL;

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);
    struct Node *head2 = NULL, *tail2 = NULL;

    struct Node* intersectNode = NULL;

    for (i = 0; i < m; i++) {
        scanf("%d", &val);

        if (i == 2) {  
            struct Node* temp = head1;
            while (temp != NULL) {
                if (temp->data == val) {
                    intersectNode = temp;
                    break;
                }
                temp = temp->next;
            }

            if (intersectNode != NULL) {
                if (head2 == NULL)
                    head2 = intersectNode;
                else
                    tail2->next = intersectNode;
                break;
            }
        }

        struct Node* newNode = createNode(val);

        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* result = getIntersection(head1, head2);

    if (result != NULL)
        printf("%d", result->data);
    else
        printf("No Intersection");

    return 0;
}
