#include<iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000;
const int maxm = 10000;
struct edge {
	int u, v, w;
}e[maxm];
bool cmp(edge a, edge b) { //重要
	if (a.w < b.w)
		return true;
	else
		return false;
}
//并查集（确定有无回路
int father[maxn];
int get(int a) {
	if (father[a] == a)
		return a;
	return father[a] = get(father[a]);
}
void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b)
		father[a] = b;
}
int cnt = 1;
void insert(int a, int b, int w) {
	e[cnt].u = a;
	e[cnt].v = b;
	e[cnt].w = w;
	cnt++;
}
void insert2(int a, int b, int w) {//无向图==》双向！
	insert(a, b, w);
	insert(b, a, w);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {//对称的
			int w;
			cin >> w;
			if (i != j)
			{
				insert2(i, j, w);
			}
		}
	}
	cnt--;
	sort(e + 1, e + cnt + 1, cmp);   //把边按边权排序！ 
	for (int i = 1; i <= n; i++)
		father[i] = i;
	int res = 0; //记录添加到最小生成树中的边数（最终=n-1即可 ！！！ 
	int ans = 0; //记录边权值和
	for (int i = 1; i <= cnt && res < n - 1; i++) {
		int u = e[i].u;
		int v = e[i].v;
		if (get(u) == get(v)) //若产生回路，不加这条边 
			continue;
		else {//否则加这条边
			res++; //记录最小生成树中的边数 
			merge(u, v);
			ans += e[i].w;
		}
	}
	cout << ans;
	return 0;
}