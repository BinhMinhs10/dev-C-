#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int v,e;
int adjMatrix[MAX][MAX];
 
void CreatMatrix();
void Display();
void DepthFirstSearch(int source, int visited[MAX]);
int main()
{
    int i,source;
    int visited[MAX];
    for(i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            adjMatrix[i][j]=0;
        }
    }
    for(i=0;i<MAX;i++)
    {
        visited[i]=0;
    }
    printf("do thi co bao nhieu Node\n");
    scanf("%d",&v);
    printf("do thi co bao nhieu canh\n");
    scanf("%d",&e);
    CreatMatrix();
    Display();
    printf("nhap node bat dau:\n");
    scanf("%d",&source);
    DepthFirstSearch(source,visited);
    return 0;
}
void CreatMatrix()
{
    int a,b;
    for(int i=1;i<=e;i++)
    {
        printf("canh thu %d:\t",i);
        scanf("%d %d",&a,&b);
        adjMatrix[a][b]=1;
        adjMatrix[b][a]=1;
    }
}
 
void Display()
{
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            printf("%d\t",adjMatrix[i][j]);
        }
        printf("\n");
    }
}
 
void DepthFirstSearch(int source, int visited[MAX])
{
    printf("%d->",source);
    visited[source]=1;
    for(int j=1;j<=v;j++)
    {
        if(visited[j]==0&&adjMatrix[source][j]==1)
        {
            DepthFirstSearch(j,visited);
        }
    }
}
