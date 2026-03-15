#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d",&n);

    int q[1000];

    for(int i=0;i<n;i++)
        scanf("%d",&q[i]);

    scanf("%d",&m);

    int front = 0;

    front = (front + m) % n;

    for(int i=0;i<n;i++)
        printf("%d ", q[(front+i)%n]);

    return 0;
}
