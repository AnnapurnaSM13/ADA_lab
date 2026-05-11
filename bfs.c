#include<stdio.h>
int n,a[10][10],vis[10];
void bfs(int v)
{
    int q[10],u,f=1,r=1;
    q[r]=v;
    vis[v]=1;
    while(f<=r){
        u=q[f];
        printf("%d",u);
        for(int i=0;i<n;i++){
            if(a[u][i]==1 && vis[i]==0){
                vis[i]=1;
                r=r+1;
                q[r]=i;
            }
        }
        f=f+1;
    }
}
void main()
{   int src,i,j;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
        vis[i]=0;
    }
    printf("enter the src vertex:");
    scanf("%d",&src);
    printf("nodes reachable from src vertex:");
    bfs(src);
}
