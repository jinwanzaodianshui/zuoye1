#include<iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000;
const int maxm = 10000;
struct edge {
	int u, v, w;
}e[maxm];
bool cmp(edge a, edge b) { //��Ҫ
	if (a.w < b.w)
		return true;
	else
		return false;
}
//���鼯��ȷ�����޻�·
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
void insert2(int a, int b, int w) {//����ͼ==��˫��
	insert(a, b, w);
	insert(b, a, w);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {//�ԳƵ�
			int w;
			cin >> w;
			if (i != j)
			{
				insert2(i, j, w);
			}
		}
	}
	cnt--;
	sort(e + 1, e + cnt + 1, cmp);   //�ѱ߰���Ȩ���� 
	for (int i = 1; i <= n; i++)
		father[i] = i;
	int res = 0; //��¼��ӵ���С�������еı���������=n-1���� ������ 
	int ans = 0; //��¼��Ȩֵ��
	for (int i = 1; i <= cnt && res < n - 1; i++) {
		int u = e[i].u;
		int v = e[i].v;
		if (get(u) == get(v)) //��������·������������ 
			continue;
		else {//�����������
			res++; //��¼��С�������еı��� 
			merge(u, v);
			ans += e[i].w;
		}
	}
	cout << ans;
	return 0;
}