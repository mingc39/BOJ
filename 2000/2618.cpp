#include <stdio.h>

// 사건 번호는 1부터 시작, 사건 번호 0은 경찰차가 초기 위치에 있음을 나타냄  
int a[1001][1001];	// a[i][j]: 사건 max(i, j)까지 모두 처리했고 경찰차1이 사건 i, 경찰차2가 사건 j 위치에 있을때 이동 거리의 최소값 
int b[1001][2];		// b[i]: 사건 i의 위치 좌표   
int s[1000];		// 역추적시 이동한 경찰차 저장용 스택  

// 두 좌표간 거리  
int dist(int x1, int y1, int x2, int y2) {
	int x = x1 - x2;
	int y = y1 - y2;
	if(x < 0) x = -x;
	if(y < 0) y = -y;
	return x + y;
}

// 두 사건간 거리  
int dist2(int w1, int w2) {
	return dist(b[w1][0], b[w1][1], b[w2][0], b[w2][1]);
}

// 한 사건과 한 좌표간 거리  
int dist3(int w, int x, int y) {
	return dist(b[w][0], b[w][1], x, y);
}

int main() {
	int n, w;
	
	// 입력  
	scanf("%d %d", &n, &w);
	for(int i = 1; i <= w; i++) scanf("%d %d", &b[i][0], &b[i][1]);
	
	// 최소 경로 탐색  
	a[1][0] = dist3(1, 1, 1);
	a[0][1] = dist3(1, n, n);
	for(int i = 2; i <= w; i++) {
		int t;
		
		// 경찰차1이 이동 
		// i - 1번째 사건에서 이동해오는 경우  
		for(int j = 0; j < i - 1; j++) {
			a[i][j] = a[i - 1][j] + dist2(i - 1, i);
		} 
		// 0 ~ i - 2번째 사건에서 이동해오는 경우 
		t = a[0][i - 1] + dist3(i, 1, 1);
		for(int j = 1; j < i - 1; j++) {
			if(t > a[j][i - 1] + dist2(i, j)) t = a[j][i - 1] + dist2(i, j);
		}
		a[i][i - 1] = t;
		
		// 경찰차2가 이동 
		// i - 1번째 사건에서 이동해오는 경우 
		for(int j = 0; j < i - 1; j++) {
			a[j][i] = a[j][i - 1] + dist2(i - 1, i);
		} 
		// 0 ~ i - 2번째 사건에서 이동해오는 경우
		t = a[i - 1][0] + dist3(i, n, n);
		for(int j = 1; j < i - 1; j++) {
			if(t > a[i - 1][j] + dist2(i, j)) t = a[i - 1][j] + dist2(i, j);
		}
		a[i - 1][i] = t;
	}
	
	// 최소 이동 거리, a 배열에서의 위치 구하기  
	int min = 999999999, x, y;
	for(int i = 0; i < w; i++) {
		if(min > a[i][w]) {
			min = a[i][w];
			x = i;
			y = w;
		}
		if(min > a[w][i]) {
			min = a[w][i];
			x = w;
			y = i;
		}
	}
	// 최소 이동 거리 출력  
	printf("%d", min);
	
	// 어떤 경찰차가 이동했는지 추적  
	for(int i = 0; i < w; i++) {
		
		// 경찰차1이 움직임  
		if(x > y) {
			// 이동한 경찰차 번호 기록  
			s[i] = 1;
			// 사건 0 ~ 전전 사건에서 온 경우 추적  
			if(x - 1 == y) {
				int t = a[0][x - 1] + dist3(w - i, 1, 1), p = 0;
				for(int j = 1; j < x - 1; j++) {
					if(t > a[j][x - 1] + dist2(w - i, j)) {
						t = a[j][x - 1] + dist2(w - i, j);
						p = j;
					}
				}
				x = p;
			}
			// 직전 사건에서 온 경우  
			else x--;
		}
		
		// 경찰차2가 움직임  
		else {
			// 이동한 경찰차 번호 기록 
			s[i] = 2;
			// 사건 0 ~ 전전 사건에서 온 경우 추적 
			if(y - 1 == x) {
				int t = a[y - 1][0] + dist3(w - i, n, n), p = 0;
				for(int j = 1; j < y - 1; j++) {
					if(t > a[y - 1][j] + dist2(w - i, j)) {
						t = a[y - 1][j] + dist2(w - i, j);
						p = j;
					}
				}
				y = p;
			}
			// 직전 사건에서 온 경우 
			else y--;
		}
		
	}
	
	// 추적 결과 역순으로 출력 (s에는 마지막 이동 경찰차 -> 첫번째 이동 경찰차 순으로 저장됨) 
	while(w) printf("\n%d", s[--w]);
	
	return 0;
}
