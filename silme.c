#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    n *next;
};
typedef n node;

void printonewayList(node *r)
{
    while (r != NULL)
    {
        printf("%d", r->x);
        r = r->next;
    }
}
node *nodeRemove(node *r, int x)
{
    node *temp;
    node *iter = r;


    if (r->x==x)
    {
        
    }
    
}

int main()
{
}