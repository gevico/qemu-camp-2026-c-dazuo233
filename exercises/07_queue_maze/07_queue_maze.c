#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

int visited[MAX_ROW][MAX_COL];
int parent[MAX_ROW * MAX_COL];
int queue[MAX_ROW * MAX_COL];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int main(void)
{
    for (int i = 0; i < MAX_ROW; i++)
        for (int j = 0; j < MAX_COL; j++)
            visited[i][j] = 0;
    
    for (int i = 0; i < MAX_ROW * MAX_COL; i++)
        parent[i] = -1;
    
    int front = 0, rear = 0;
    visited[0][0] = 1;
    queue[rear++] = 0;
    
    int found = 0;
    while (front < rear) {
        int cur = queue[front++];
        int r = cur / MAX_COL;
        int c = cur % MAX_COL;
        
        if (r == MAX_ROW - 1 && c == MAX_COL - 1) {
            found = 1;
            break;
        }
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < MAX_ROW && nc >= 0 && nc < MAX_COL &&
                maze[nr][nc] == 0 && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                parent[nr * MAX_COL + nc] = cur;
                queue[rear++] = nr * MAX_COL + nc;
            }
        }
    }
    
    if (found) {
        int trace[50];
        int len = 0;
        int cur = (MAX_ROW - 1) * MAX_COL + (MAX_COL - 1);
        while (cur != -1) {
            trace[len++] = cur;
            cur = parent[cur];
        }
        for (int i = 0; i < len; i++) {
            printf("(%d, %d)\n", trace[i] / MAX_COL, trace[i] % MAX_COL);
        }
    } else {
        printf("No path!\n");
    }

	return 0;
}
