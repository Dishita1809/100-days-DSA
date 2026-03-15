#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int queue[n];
    int front = 0, rear = -1;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&queue[++rear]);
    }

    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }

    return 0;
}
