#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0]==-1) return 0;

    struct node* root = newNode(arr[0]);

    struct node* queue[n];
    int front=0,rear=0;

    queue[rear++] = root;

    int i=1;

    while(i<n){

        struct node* curr = queue[front++];

        if(arr[i]!=-1){
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i<n && arr[i]!=-1){
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    inorder(root);

    return 0;
}
