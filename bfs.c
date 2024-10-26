#include <stdio.h>
int queue[100];
int G[100][100];
int front = -1, rear = -1;
int n, i, j, v;
int visit[100];
void enqueue(int);
int dequeue();
void bfs(int);
int main()
{
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter Adjacency matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\n%d %d:",i,j);
            scanf("%d", &G[i][j]);
        }
    }
    printf("\nEnter starting vertex:");
    scanf("%d", &v);

    bfs(v);
    return 0;
}

void bfs(int v)
{
    enqueue(v);
    while (rear != -1)
    {
        v = dequeue();
        if (!visit[v])
        {
            visit[v] = 1;
            printf("%d\n", v);
            for (int i = 0; i < n; i++)
            {
                if (G[v][j] == 1 && !visit[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
    }
}

void enqueue(int x)
{
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        queue[++rear] = x;
    }
}

int dequeue()
{
    int x = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        queue[++front];
        return x;
    }
}