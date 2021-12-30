#include <stdio.h>

int n, m;
int home[100][2], h = 0; // 집 목록 
int chick[13][2], c = 0; // 치킨집 목록 
int cdis[100][13]; // cdis[i][j]: i번째 집과 j번째 치킨집의 거리 

int func(char a[13], int l) {
	if(l == m) { // 폐업하지 않을 치킨집을 모두 고른 경우 도시의 치킨거리 리턴  
		int dis = 0;
		int min;
		for(int i = 0; i < h; i++) {
			min = 99999;
			for(int j = 0; j < m; j++) {
				if(cdis[i][a[j]] < min) min = cdis[i][a[j]];
			}
			dis += min;
		}
		return dis;
	} else { // 폐업하지 않을 치킨집을 더 골라야 하는 경우  
		int dis = 0;
		int min = 2000000000;
		int t;
		if(l == 0) t = 0;
		else t = a[l - 1] + 1;
		for(int i = t; i < c; i++) { // 다음 폐업안할 치킨집을 하나씩 선택해보기  
			a[l] = i;
			t = func(a, l + 1);
			if(t < min) min = t;
		}
		return min;
	}
}

int main() {
	int t;
	
	// 입력  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &t);
			if(t == 1) {
				home[h][0] = i;
				home[h][1] = j;
				h++;
			} else if(t == 2) {
				chick[c][0] = i;
				chick[c][1] = j;
				c++;
			}
		}
	}
	
	// 치킨집 <-> 집 사이의 거리 계산  
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < c; j++) {
			cdis[i][j] = ((home[i][0] - chick[j][0]) < 0 ? -(home[i][0] - chick[j][0]) : home[i][0] - chick[j][0])
				+ ((home[i][1] - chick[j][1]) < 0 ? -(home[i][1] - chick[j][1]) : home[i][1] - chick[j][1]);
		}
	}
	
	// 치킨집 폐업시 최소 치킨거리 찾아서 출력  
	char a[13];
	printf("%d", func(a, 0));
	
	return 0;
}
