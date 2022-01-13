// 우선순위 큐 C++
#include <stdio.h>
#include <math.h>

#include <vector>
#include <queue>

using namespace std;

int main() {
	
	int a, b, c;
	int v, e; // v: 정점, e: 간선  
	double x, y; 
	double starCord[101][2];
	double distance[101][101];
	
	// 입력  
	scanf("%d", &v);
	e = v * (v - 1) / 2;
	
	for(int i = 1; i <= v; i++) {
		scanf("%lf %lf", &x, &y);
		starCord[i][0] = x;
		starCord[i][1] = y;
		
		// 입력 내용 저장 
		for(int j = 1; j < i; j++) {
			distance[j][i] = distance[i][j] = sqrt(pow(x - starCord[j][0], 2) + pow(y - starCord[j][1], 2));
		}
	}
	
	// 초기화  
	priority_queue<pair<double, int> > q;
	int tw = 0, p[101] = {0, -1, 0,}; // 부모 노드 초기화  
	int pos = 1;
	int mroad = 0;
	double result = 0;
	
	// 프림  
	while(pos != 0) {
		// 직전에 트리에 추가된 정점의 간선 중 트리에 포함되지 않은 정점으로 가는 간선을 우선순위 큐에 추가  
		for(int i = 1; i <= v; i++) {
			if(p[i] == 0 && i != pos) q.push(make_pair(distance[pos][i] * -1, i));
		}
		
		// 트리에 추가되지 않은 정점과 연결된 간선 중 가중치가 최소인 간선 찾기 
		int v2;
		double weight;
		pos = 0;
		while(!q.empty()) {
			weight = q.top().first * -1;
			v2 = q.top().second;
			q.pop(); 
			if(p[v2] == 0) {
				p[v2] = 1;
				pos = v2;
				result += weight;
				break;
			}
		}
	}
	
	printf("%lf", result);
	
	return 0;
}
