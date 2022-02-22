#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int v, e, d = 0;
int *vv, *sv, *dv;
vector<vector<int> > g;
vector<vector<int> > scc;
stack<int> s;

int dfs(int cur) {
	dv[cur] = ++d;
	vv[cur] = 1;
	s.push(cur);
	
	// ����� �ٸ� �� Ž��  
	int discover = dv[cur];
	for(int next : g[cur]) {
		if(vv[next] == 0) {
			int t = dfs(next);
			if(discover > t) discover = t;
		} else if(sv[next] == 0) {
			if(discover > dv[next]) discover = dv[next];
		}
	}
	
	// SSC �߰�  
	if(discover == dv[cur]) {
		vector<int> t;
		do { // �ڱ� �ڽ��� ���ö����� ���ÿ��� ���� SSC�� ����  
			t.push_back(s.top());
			sv[s.top()] = 1;
			s.pop();
		} while(t.back() != cur);
		sort(t.begin(), t.end()); // ����� �� ������ ���� �ؾߵż� �̸� ����  
		scc.push_back(t);
	}
	
	return discover;
}

int main() {
	// �Է�  
	scanf("%d %d", &v, &e);
	g.resize(v + 1);
	vv = new int[v + 1]();
	sv = new int[v + 1]();
	dv = new int[v + 1]();
	for(int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
	}
	
	// ��� �� Ž��  
	for(int i = 1; i <= v; i++) {
		if(vv[i] == 0) dfs(i); // �̹� �湮�� ������ ���  
	}
	
	// ���  
	printf("%d\n", scc.size());
	sort(scc.begin(), scc.end()); // ���� ��ȣ�� ���� ������ ��ȣ�� ���� ���� ssc ���� ��� �ؾ��ϹǷ� ����  
	for(auto i : scc) {
		for(int j : i) {
			printf("%d ", j);
		}
		printf("-1\n");
	}
	
	return 0;
}
