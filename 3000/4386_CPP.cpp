// �켱���� ť C++
#include <stdio.h>
#include <math.h>

#include <vector>
#include <queue>

using namespace std;

int main() {
	
	int a, b, c;
	int v, e; // v: ����, e: ����  
	double x, y; 
	double starCord[101][2];
	double distance[101][101];
	
	// �Է�  
	scanf("%d", &v);
	e = v * (v - 1) / 2;
	
	for(int i = 1; i <= v; i++) {
		scanf("%lf %lf", &x, &y);
		starCord[i][0] = x;
		starCord[i][1] = y;
		
		// �Է� ���� ���� 
		for(int j = 1; j < i; j++) {
			distance[j][i] = distance[i][j] = sqrt(pow(x - starCord[j][0], 2) + pow(y - starCord[j][1], 2));
		}
	}
	
	// �ʱ�ȭ  
	priority_queue<pair<double, int> > q;
	int tw = 0, p[101] = {0, -1, 0,}; // �θ� ��� �ʱ�ȭ  
	int pos = 1;
	int mroad = 0;
	double result = 0;
	
	// ����  
	while(pos != 0) {
		// ������ Ʈ���� �߰��� ������ ���� �� Ʈ���� ���Ե��� ���� �������� ���� ������ �켱���� ť�� �߰�  
		for(int i = 1; i <= v; i++) {
			if(p[i] == 0 && i != pos) q.push(make_pair(distance[pos][i] * -1, i));
		}
		
		// Ʈ���� �߰����� ���� ������ ����� ���� �� ����ġ�� �ּ��� ���� ã�� 
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
