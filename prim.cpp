#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxn = 10000;
int d[maxn];//搜到当前点的最小距离
int g[maxn][maxn];
int vis[maxn];
int N;
int prim() {
	int ans = 0;
	int k;
	d[0] = 10000000;
	for (int i = 1; i <= N; i++) {
		d[i] = g[1][i];
	}
	vis[1] = 1;
	for (int i = 1; i < N; i++) {
		k = 0;
		for (int j = 2; j <= N; j++) {
			if (!vis[j] && d[j] < d[k])
				k = j;
		}
		vis[k] = 1;
		ans += d[k];
		for (int j = 2; j <= N; j++) {
			if (!vis[j] && g[k][j] < d[j])
				d[j] = g[k][j];
		}
	}
	return ans;
}
int main() {
	memset(vis, 0, sizeof(vis));  //初始化
	scanf_s("%d", &N); //输入数据大小N
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> g[i][j];
		}
	}
	cout << prim() << endl;
	return 0;
}