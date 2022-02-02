#include <stdio.h> 

int q[1050000][5], l = 0, r = 0;

int main() {
	int n, m;
	char a[10][10];
	int bx, by, rx, ry;
	
	// 입력  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
			if(a[i][j] == 'B') {
				bx = i;
				by = j;
				a[i][j] = '.';
			}
			if(a[i][j] == 'R') {
				rx = i;
				ry = j;
				a[i][j] = '.';
			}
		}
	}
	
	//int q[1050000][5], ql = 0, qr = 0;
	
	q[r][0] = 0;
	q[r][1] = bx;
	q[r][2] = by;
	q[r][3] = rx;
	q[r][4] = ry;
	if(++r == 1050000) r = 0;
	
	// 탐색  
	while(r != l) {
		int s;
		s  = q[l][0];
		bx = q[l][1];
		by = q[l][2];
		rx = q[l][3];
		ry = q[l][4];
		if(++l == 1050000) l = 0;
		
		if(a[bx][by] == 'O') continue; // 파란 구슬이 구멍에 빠지면 그 이상 탐색할 필요 없음 
		if(a[rx][ry] == 'O') { // 빨간 구슬이 구멍에 빠지면 성공  
			printf("%d", s);
			return 0;
		}
		
		if(s < 10) { // 10단계에서는 다음 단계 탐색할 필요 없음  
			int bt, rt;
			s++;
			
			// 오른쪽 이동 
			bt = by;
			rt = ry;
			if(bx != rx) { // 공이 다른 줄에 있는 경우
				while(a[bx][bt + 1] != '#' && a[bx][bt] != 'O') bt++;
				while(a[rx][rt + 1] != '#' && a[rx][rt] != 'O') rt++;
			} else if(by > ry) { // 파란  공이 오른쪽 
				while(a[bx][bt + 1] != '#' && a[bx][bt] != 'O') bt++;
				while(a[rx][rt + 1] != '#' && a[rx][rt] != 'O' && (rt + 1 != bt || a[rx][rt + 1] == 'O')) rt++;
			} else { // 빨간 공이 오른쪽 
				while(a[rx][rt + 1] != '#' && a[rx][rt] != 'O') rt++;
				while(a[bx][bt + 1] != '#' && a[bx][bt] != 'O' && (bt + 1 != rt || a[bx][bt + 1] == 'O')) bt++;
			}
			q[r][0] = s;
			q[r][1] = bx;
			q[r][2] = bt;
			q[r][3] = rx;
			q[r][4] = rt;
			if(++r == 1050000) r = 0;
			
			// 왼쪽 이동 
			bt = by;
			rt = ry;
			if(bx != rx) { // 공이 다른 줄에 있는 경우
				while(a[bx][bt - 1] != '#' && a[bx][bt] != 'O') bt--;
				while(a[rx][rt - 1] != '#' && a[rx][rt] != 'O') rt--;
			} else if(by < ry) { // 파란  공이 왼쪽 
				while(a[bx][bt - 1] != '#' && a[bx][bt] != 'O') bt--;
				while(a[rx][rt - 1] != '#' && a[rx][rt] != 'O' && (rt - 1 != bt || a[rx][rt - 1] == 'O')) rt--;
			} else { // 빨간 공이 왼쪽 
				while(a[rx][rt - 1] != '#' && a[rx][rt] != 'O') rt--;
				while(a[bx][bt - 1] != '#' && a[bx][bt] != 'O' && (bt - 1 != rt || a[bx][bt - 1] == 'O')) bt--;
			}
			q[r][0] = s;
			q[r][1] = bx;
			q[r][2] = bt;
			q[r][3] = rx;
			q[r][4] = rt;
			if(++r == 1050000) r = 0;
			
			// 위쪽 이동 
			bt = bx;
			rt = rx;
			if(by != ry) { // 공이 다른 줄에 있는 경우
				while(a[bt - 1][by] != '#' && a[bt][by] != 'O') bt--; 
				while(a[rt - 1][ry] != '#' && a[rt][ry] != 'O') rt--;
			} else if(bx < rx) { // 파란  공이 위쪽 
				while(a[bt - 1][by] != '#' && a[bt][by] != 'O') bt--;
				while(a[rt - 1][ry] != '#' && a[rt][ry] != 'O' && (rt - 1 != bt || a[rt - 1][ry] == 'O')) rt--;
			} else { // 빨간 공이 위쪽 
				while(a[rt - 1][ry] != '#' && a[rt][ry] != 'O') rt--;
				while(a[bt - 1][by] != '#' && a[bt][by] != 'O' && (bt - 1 != rt || a[bt - 1][by] == 'O')) bt--;
			}
			q[r][0] = s;
			q[r][1] = bt;
			q[r][2] = by;
			q[r][3] = rt;
			q[r][4] = ry;
			if(++r == 1050000) r = 0;
			
			// 아래쪽 이동 
			bt = bx;
			rt = rx;
			if(by != ry) { // 공이 다른 줄에 있는 경우
				while(a[bt + 1][by] != '#' && a[bt][by] != 'O') bt++;
				while(a[rt + 1][ry] != '#' && a[rt][ry] != 'O') rt++;
			} else if(bx > rx) { // 파란  공이 아래쪽 
				while(a[bt + 1][by] != '#' && a[bt][by] != 'O') bt++;
				while(a[rt + 1][ry] != '#' && a[rt][ry] != 'O' && (rt + 1 != bt || a[rt + 1][ry] == 'O')) rt++;
			} else { // 빨간 공이 아래쪽 
				while(a[rt + 1][ry] != '#' && a[rt][ry] != 'O') rt++;
				while(a[bt + 1][by] != '#' && a[bt][by] != 'O' && (bt + 1 != rt || a[bt + 1][by] == 'O')) bt++;
			}
			q[r][0] = s;
			q[r][1] = bt;
			q[r][2] = by;
			q[r][3] = rt;
			q[r][4] = ry;
			if(++r == 1050000) r = 0;
		}
	}
	
	printf("-1");
	
	return 0;
}
