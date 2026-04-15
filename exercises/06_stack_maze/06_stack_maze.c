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
int path[50][2];
int path_len;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(int r, int c) {
    if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL) return 0;
    if (maze[r][c] == 1 || visited[r][c]) return 0;
    
    visited[r][c] = 1;
    path[path_len][0] = r;
    path[path_len][1] = c;
    path_len++;
    
    if (r == MAX_ROW - 1 && c == MAX_COL - 1) return 1;
    
    for (int d = 0; d < 4; d++) {
        if (dfs(r + dr[d], c + dc[d])) return 1;
    }
    
    path_len--;
    return 0;
}

int main(void)
{
    for (int i = 0; i < MAX_ROW; i++)
        for (int j = 0; j < MAX_COL; j++)
            visited[i][j] = 0;
    path_len = 0;
    
    if (dfs(0, 0)) {
        for (int i = path_len - 1; i >= 0; i--) {
            printf("(%d, %d)\n", path[i][0], path[i][1]);
        }
    } else {
        printf("No path!\n");
    }

	return 0;
}
