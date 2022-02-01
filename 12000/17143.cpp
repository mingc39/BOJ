#include <stdio.h>

int main() {
	int r, c, m; // 낚시판(?) 크기, 상어 수  
	int result = 0; // 낚시 결과  
	int (*p1)[100]; // 이동 전 낚시판 상태  
	int (*p2)[100]; // 이동 후 낚시판 상태  
	int (*pt)[100]; // p1 <-> p2 교환용 임시 변수  
	int a[100][100] = {0,}; // 낚시판(?) 상태 0:빈칸, 1~m 상어  
	int b[100][100] = {0,}; // 낚시판(?) 상태 0:빈칸, 1~m 상어
	int x[10000]; // 상어 위치(수직) 범위:0~m-1 
	int y[10000]; // 상어 위치(수평) 범위:0~m-1 
	int s[10000]; // 상어 속도 범위:0~m-1 
	int d[10000]; // 상어 방향 (0이면 잡힌상어) 범위:0~m-1 // 1 위, 2 아래, 3 오른쪽, 4 왼쪽  
	int z[10000]; // 상어 크기 (0이면 잡힌상어) 범위:0~m-1 
	
	// 낚시판 크기, 상어 마리수 입력  
	scanf("%d %d %d", &r, &c, &m);
	
	// 상어 입력  
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d %d %d", &x[i], &y[i], &s[i], &d[i], &z[i]);
		x[i]--; y[i]--; // 좌표 입력 범위: 1,1 ~ r,c 배열 범위: 0,0 ~ r-1,c-1
		a[x[i]][y[i]] = i + 1; // 낚시판 상어 번호 범위 : 1 ~ m, 상어 정보 배열 범위: 0 ~ m-1
		// 이동 횟수 최적화
		// 한 번에 낚시판을 10번씩 왕복하는 등의 상황 방지  
		if(d[i] < 3) {
			s[i] %= (r - 1) * 2;
		} else {
			s[i] %= (c - 1) * 2;
		}
	}
	
	// p1, p2 초기화  
	p1 = a;
	p2 = b;
	
	for(int i = 0; i < c; i++) {
		// 상어 잡기 
		for(int j = 0; j < r; j++) {
			// 해당 위치에서 처음 만나는 무효화 되지 않은 상어 잡기  
			if(p1[j][i] != 0 && (z[p1[j][i] - 1] != 0 || d[p1[j][i] - 1] != 0)) {
				result += z[p1[j][i] - 1];
				d[p1[j][i] - 1] = 0;
				z[p1[j][i] - 1] = 0;
				break; // 첫 번째로 만나는 상어 잡았으면 잡기 중단  
			}
		}
		
		// 다음 배열 초기화 
		for(int j = 0; j < r; j++) {
			for(int k = 0; k < c; k++) {
				p2[j][k] = 0;
			}
		}
		
		// 상어 이동  
		int tm = 0;
		for(int j = 0; j < m; j++) {
			
			// 잡힌 상어는 통과  
			if(d[j] == 0 || z[j] == 0) continue;
			
			// 다음 위치 계산
			// 1 위, 2 아래, 3 오른쪽, 4 왼쪽  
			int tx, ty, td;
			tx = x[j]; ty = y[j]; td = d[j];
			if(d[j] == 1) {
				tx -= s[j];
				if(tx == 0) td = 2;
				else if(tx < 0) {
					td = 2;
					tx = -tx;
					if(tx == r - 1) td = 1;
					else if(tx > r - 1) {
						td = 1;
						tx = (r - 1) * 2 - tx;
					}
				}
			} else if(d[j] == 2) {
				tx += s[j];
				if(tx == r - 1) td = 1;
				else if(tx > r - 1) {
					td = 1;
					tx = (r - 1) * 2 - tx;
					if(tx == 0) td = 2;
					else if(tx < 0) {
						td = 2;
						tx = -tx;
					}
				}
			} else if(d[j] == 3) {
				ty += s[j];
				if(ty == c - 1) td = 4;
				else if(ty > c - 1) {
					td = 4;
					ty = (c - 1) * 2 - ty;
					if(ty == 0) td = 3;
					else if(ty < 0) {
						td = 3;
						ty = -ty;
					}
				}
			} else if(d[j] == 4) {
				ty -= s[j];
				if(ty == 0) td = 3;
				else if(ty < 0) {
					td = 3;
					ty = -ty;
					if(ty == c - 1) td = 4;
					else if(ty > c - 1) {
						td = 4;
						ty = (c - 1) * 2 - ty;
					}
				}
			}
			
			// 중복 확인, 다음 위치 저장 
			if(p2[tx][ty] == 0) {
				// 중복 없음  
				// 저장 
				x[tm] = tx;
				y[tm] = ty;
				s[tm] = s[j];
				d[tm] = td;
				z[tm] = z[j];
				p2[tx][ty] = tm + 1;
				tm++;
			} else if(z[p2[tx][ty] - 1] > z[j]) {
				// 내가 먹힘  
				// -> 저장 안하면 됨  
			} else if(z[p2[tx][ty] - 1] < z[j]) {
				// 내가 먹음 
				z[p2[tx][ty] - 1] = 0; // 원래 상어 비활성화 
				// 저장  
				x[tm] = tx;
				y[tm] = ty;
				s[tm] = s[j];
				d[tm] = td;
				z[tm] = z[j];
				p2[tx][ty] = tm + 1;
				tm++;
			}
		}
		
		// 이동이 완료되었고 다음 단계로 넘어가야 함  
		// 이동 후 배열 -> 이동 전 배열로 교체  
		pt = p1;
		p1 = p2;
		p2 = pt; 
		
		// 살아남은 상어 마리수로 현재 상어 마리수 갱신
		m = tm; 
	}
	
	// 결과 출력  
	printf("%d", result);
	
	return 0;
}
