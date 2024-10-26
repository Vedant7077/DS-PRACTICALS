#include<stdio.h>

void DFS(int i);

int am[100][100];
int visited[100];
int n;

int main(){
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter adjaency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d %d :",i,j);
            scanf("%d",&am[i][j]);
        }
    }
    int ch;
    printf("\nEnter starting vertex:");
    scanf("%d",&ch);

    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    DFS(ch);
}

void DFS(int i){
    visited[i] = 1;
    printf("%d ",i);

    for(int j=0; j<n; j++){
        if(visited[j] == 0 && am[i][j]== 1){
            DFS(j);
        }
    }
}