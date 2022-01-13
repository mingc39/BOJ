// 우선순위 큐 C++
#include <stdio.h>

#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int> > g[100001];

int main() {
	
	int a, b, c;
	int v, e; // v: 정점, e: 간선  
	
	// 입력  
	scanf("%d %d", &v, &e);
	
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		// 입력 내용 저장 
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	
	// 초기화  
	priority_queue<pair<int, int> > q;
	int tw = 0, p[100001] = {0, -1, 0,}; // 부모 노드 초기화  
	int pos = 1;
	int mroad = 0;
	
	// 프림  
	while(pos != 0) {
		// 직전에 트리에 추가된 정점의 간선 중 트리에 포함되지 않은 정점으로 가는 간선을 우선순위 큐에 추가  
		for(int i = 0; i < g[pos].size(); i++) {
			if(p[g[pos][i].first] == 0) q.push(make_pair(g[pos][i].second * -1, g[pos][i].first));
		}
		
		// 트리에 추가되지 않은 정점과 연결된 간선 중 가중치가 최소인 간선 찾기 
		int weight, v1, v2;
		pos = 0;
		while(!q.empty()) {
			weight = q.top().first * -1;
			v1 = 1;
			v2 = q.top().second;
			q.pop(); 
			if(p[v2] == 0) {
				p[v2] = v1;
				pos = v2;
				tw += weight;
				if(mroad < weight) mroad = weight;
				break;
			}
		}
	}
	
	printf("%d", tw - mroad);
	
	return 0;
}
