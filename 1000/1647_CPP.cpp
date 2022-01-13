// �켱���� ť C++
#include <stdio.h>

#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int> > g[100001];

int main() {
	
	int a, b, c;
	int v, e; // v: ����, e: ����  
	
	// �Է�  
	scanf("%d %d", &v, &e);
	
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		// �Է� ���� ���� 
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	
	// �ʱ�ȭ  
	priority_queue<pair<int, int> > q;
	int tw = 0, p[100001] = {0, -1, 0,}; // �θ� ��� �ʱ�ȭ  
	int pos = 1;
	int mroad = 0;
	
	// ����  
	while(pos != 0) {
		// ������ Ʈ���� �߰��� ������ ���� �� Ʈ���� ���Ե��� ���� �������� ���� ������ �켱���� ť�� �߰�  
		for(int i = 0; i < g[pos].size(); i++) {
			if(p[g[pos][i].first] == 0) q.push(make_pair(g[pos][i].second * -1, g[pos][i].first));
		}
		
		// Ʈ���� �߰����� ���� ������ ����� ���� �� ����ġ�� �ּ��� ���� ã�� 
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
