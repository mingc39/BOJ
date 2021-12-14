#include <stdio.h>

int next(int n, int a[20][20], int x, int y, int s, int* nx, int* ny);

int main() {
	int n, a[20][20];
	int x, y, t = 0, s = 2, l = 0, c = 0;
	int nx, ny;
	int z = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if(a[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}
	
	//printf("step%03d: (%d, %d):\n", z++, x, y);
	l = next(n, a, x, y, s, &nx, &ny);
	while(l != -1) {
		t += l;
		a[x][y] = 0;
		a[nx][ny] = 9;
		x = nx;
		y = ny;
		c++;
		if(c == s) {
			c = 0;
			s++;
		}
		//printf("\tmove to (%d, %d), size = %d, time = %d\n", x, y, s, t);
		//getchar();
		//printf("step%03d: (%d, %d):\n", z++, x, y);
		l = next(n, a, x, y, s, &nx, &ny);
	}
	
	printf("%d", t);
	return 0;
}

int next(int n, int a[20][20], int cx, int cy, int s, int* nx, int* ny) {
	int v[20][20] = {0,};
	int q[450][3], qs = 0, qe = 0;
	int x = cx, y = cy, l = 0;
	int i, j;
	int e[450][3], es = 0, ee = 0;
	int min = 9999;
	
	v[x][y] = 1;
	q[qs][0] = x;
	q[qs][1] = y;
	q[qs][2] = l;
	qs++;
	
	while(qs != qe && min > q[qe][2]) {
		
		// 확인할 위치 가져오기 
		x = q[qe][0];
		y = q[qe][1];
		
		//printf("\t%d: %d %d\n", qe, x, y);
		//v[x][y] = 1;
		
		// 윗칸 탐색 
		if(x > 0) {
			i = x - 1; j = y;
			// 이미 방문했는지 체크 
			if(v[i][j] == 0) {
				// 갈 수 있는지 체크 
				if(a[i][j] <= s) {
					// 먹을 수 있는지 체크
					if(a[i][j] < s && a[i][j] > 0 && a[i][j] != 9) {
						// 먹을 수 있는 곳으로 저장 
						e[es][0] = i;
						e[es][1] = j;
						e[es][2] = q[qe][2] + 1;
						if(e[es][2] < min) min = e[es][2];
						es++;
					} 
					// 가볼 곳 큐에 저장 
					v[i][j] = 1;
					q[qs][0] = i;
					q[qs][1] = j;
					q[qs][2] = q[qe][2] + 1;
					qs++;
				}
			}
		} 
		
		// 왼쪽칸 탐색 
		if(y > 0) {
			i = x; j = y - 1;
			// 이미 방문했는지 체크 
			if(v[i][j] == 0) {
				// 갈 수 있는지 체크 
				if(a[i][j] <= s) {
					// 먹을 수 있는지 체크
					if(a[i][j] < s && a[i][j] > 0 && a[i][j] != 9) {
						// 먹을 수 있는 곳으로 저장 
						e[es][0] = i;
						e[es][1] = j;
						e[es][2] = q[qe][2] + 1;
						if(e[es][2] < min) min = e[es][2];
						es++;
					} 
					// 가볼 곳 큐에 저장 
					v[i][j] = 1;
					q[qs][0] = i;
					q[qs][1] = j;
					q[qs][2] = q[qe][2] + 1;
					qs++;
				}
			}
		} 
		
		// 오른쪽칸 탐색 
		if(y < n - 1) {
			i = x; j = y + 1;
			// 이미 방문했는지 체크 
			if(v[i][j] == 0) {
				// 갈 수 있는지 체크 
				if(a[i][j] <= s) {
					// 먹을 수 있는지 체크
					if(a[i][j] < s && a[i][j] > 0 && a[i][j] != 9) {
						// 먹을 수 있는 곳으로 저장 
						e[es][0] = i;
						e[es][1] = j;
						e[es][2] = q[qe][2] + 1;
						if(e[es][2] < min) min = e[es][2];
						es++;
					} 
					// 가볼 곳 큐에 저장 
					v[i][j] = 1;
					q[qs][0] = i;
					q[qs][1] = j;
					q[qs][2] = q[qe][2] + 1;
					qs++;
				}
			}
		} 
		
		// 아래칸 탐색 
		if(x < n - 1) {
			i = x + 1; j = y;
			// 이미 방문했는지 체크 
			if(v[i][j] == 0) {
				// 갈 수 있는지 체크 
				if(a[i][j] <= s) {
					// 먹을 수 있는지 체크
					if(a[i][j] < s && a[i][j] > 0 && a[i][j] != 9) {
						// 먹을 수 있는 곳으로 저장 
						e[es][0] = i;
						e[es][1] = j;
						e[es][2] = q[qe][2] + 1;
						if(e[es][2] < min) min = e[es][2];
						es++;
					} 
					// 가볼 곳 큐에 저장 
					v[i][j] = 1;
					q[qs][0] = i;
					q[qs][1] = j;
					q[qs][2] = q[qe][2] + 1;
					qs++;
				}
			}
		} 

		qe++;
	}
	
	//printf("\tPress Enter to continue\n");
	//getchar();
	//int e[450][3], es = 0, ee = 0;
	//int min = 9999;
	int mx = 20, my = 20, ml = 9999;
	while(es != ee) {
		x = e[ee][0];
		y = e[ee][1];
		l = e[ee][2];
		
		//printf("\t%d: %d %d %d\n", ee, x, y, l);
		
		if(l > min) continue;
		if(ml > l) {
			mx = x;
			my = y;
			ml = l;
		} else if(ml == l && mx > x) {
			mx = x;
			my = y;
			ml = l;
		} else if(ml == l && mx == x&& my > y) {
			mx = x;
			my = y;
			ml = l;
		}
		
		ee++;
	}
	
	if(ml == 9999) {
		nx = NULL; ny = NULL;
		return -1;
	}
	
	*nx = mx; *ny = my;
	return ml;
}
