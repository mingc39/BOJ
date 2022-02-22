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
	
	// 연결된 다른 점 탐색  
	int discover = dv[cur];
	for(int next : g[cur]) {
		if(vv[next] == 0) {
			int t = dfs(next);
			if(discover > t) discover = t;
		} else if(sv[next] == 0) {
			if(discover > dv[next]) discover = dv[next];
		}
	}
	
	// SSC 발견  
	if(discover == dv[cur]) {
		vector<int> t;
		do { // 자기 자신이 나올때까지 스택에서 빼서 SSC로 저장  
			t.push_back(s.top());
			sv[s.top()] = 1;
			s.pop();
		} while(t.back() != cur);
		sort(t.begin(), t.end()); // 출력할 때 작은거 부터 해야돼서 미리 정렬  
		scc.push_back(t);
	}
	
	return discover;
}

int main() {
	// 입력  
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
	
	// 모든 점 탐색  
	for(int i = 1; i <= v; i++) {
		if(vv[i] == 0) dfs(i); // 이미 방문한 정점은 통과  
	}
	
	// 출력  
	printf("%d\n", scc.size());
	sort(scc.begin(), scc.end()); // 가장 번호가 작은 정점의 번호가 가장 작은 ssc 부터 출력 해야하므로 정렬  
	for(auto i : scc) {
		for(int j : i) {
			printf("%d ", j);
		}
		printf("-1\n");
	}
	
	return 0;
}
