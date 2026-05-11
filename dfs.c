#include<stdio.h>
void dfs(int);
int n,i,j,a[10][10],vis[10],count=0;
int main()
{
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
        vis[i]=0;
    }
    printf("dfs traversal:");
    dfs(0);
    for(j=0;j<n;j++){
        if(vis[i]==1){
            count++;
        }
    }
    if(count==n){
        printf("Graph is connected.");
    }
    else{
        printf("Graph is not connected.");
    }
    return 0;

}
void dfs(int v)
{
    vis[v]=1;
    printf("%d\t",v);
    for(i=0;i<n;i++){
        if(a[v][i]==1 && vis[i]==0){
            dfs(i);
        }
    }
}
