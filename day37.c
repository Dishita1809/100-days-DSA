#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);

    int pq[1000];
    int size = 0;

    while(n--)
    {
        char op[10];
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            int x;
            scanf("%d",&x);
            pq[size++] = x;
        }
        else if(strcmp(op,"delete")==0)
        {
            if(size==0)
            {
                printf("-1\n");
                continue;
            }

            int min=0;
            for(int i=1;i<size;i++)
                if(pq[i]<pq[min])
                    min=i;

            printf("%d\n",pq[min]);

            for(int i=min;i<size-1;i++)
                pq[i]=pq[i+1];

            size--;
        }
        else if(strcmp(op,"peek")==0)
        {
            if(size==0)
            {
                printf("-1\n");
                continue;
            }

            int min=0;
            for(int i=1;i<size;i++)
                if(pq[i]<pq[min])
                    min=i;

            printf("%d\n",pq[min]);
        }
    }

    return 0;
}
