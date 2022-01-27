#include <stdio.h> 

int n, w[16][16];
int a[16][1 << 16];

int f(int cur, int vst) {
	// 이미 계산한적 있으면 그대로 반환  
	if(a[cur][vst] < 2100000000) return a[cur][vst];
	
	// 같은곳을 거쳐서 0->i 최소비용 + i->cur 비용 계산
	int min = 2100000000;
	for(int i = 0; i < n; i++) {
		if(i == cur || i == 0) continue;
		if(((1 << i) & vst) == 0) continue;
		if(min > f(i, vst - (1 << cur)) + w[i][cur]) min = f(i, vst - (1 << cur)) + w[i][cur];
	}
	
	// 배열에 결과 저장 후 반환 
	return a[cur][vst] = min;
}

int main() {
	// 입력
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
			if(w[i][j] == 0) w[i][j] = 20000000;
		}
	}
	
	// 배열 초기화 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < (1 << n); j++)
			a[i][j] = 2100000000;
	for(int i = 1; i < n; i++)
		a[i][(1 << i) + 1] = w[0][i];
	
	int min = 2100000000;
	for(int i = 1; i < n; i++)
		if(min > f(i, (1 << n) - 1) + w[i][0]) min = f(i, (1 << n) - 1) + w[i][0];
	
	// 순회 및 출력 
	printf("%d", min);
	
	return 0;
}
