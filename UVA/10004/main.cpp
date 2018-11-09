
#include<stdio.h>
#include<string.h>
#include<iostream>

int graf[205][205], vis[205], color[205];
int m, n;
int dfs(int a) {
    for (int i = 0; i < m; i++) {
        if (graf[a][i]) {
            if (!vis[i]) {
                vis[i] = 1;
                color[i] = !color[a];
                dfs(i);
            }
            else if (color[i] == color[a]) return 0;
        }
    }
    return 1;
}
int main() {
    while (scanf("%d\n%d", &m, &n) == 2) {
        memset(graf, 0, sizeof(graf));
        memset(vis, 0, sizeof(vis));
        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d %d\n", &a, &b);
            graf[a][b] = graf[b][a] = 1;
        }
        color[0] = 1;
        vis[0] = 1;
        if (dfs(0)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
