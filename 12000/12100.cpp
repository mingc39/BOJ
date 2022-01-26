#include <stdio.h> 

// 배열 복사  
void copy(int dst[20][20], int src[20][20], int size) {
	for(int i = 0; i < size; i++) 
		for(int j = 0; j < size; j++)
			dst[i][j] = src[i][j];
}

// 배열 출력  
void print(int n, int a[20][20]) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", a[i][j]);
		putchar('\n');
	}
}

// 왼쪽으로 이동  
void move_l(int n, int a[20][20]) {
	// 각 가로줄별로 진행  
	for(int i = 0; i < n; i++) {
		
		// 초기화  
		int l = 0, m = 0;
		if(a[i][0] == 0) l = -1; // 맨 첫 칸이 비였는지 확인  
		
		// 각 칸 별로 이동  
		for(int j = 1; j < n; j++) {
			
			// 빈 칸은 통과  
			if(a[i][j] == 0) continue;
			
			// 첫 칸이 빈 경우  
			if(l < 0) {
				a[i][0] = a[i][j];
				a[i][j] = 0;
				l = 0;
			} else {
				// 합칠 수 있는 경우(= 숫자가 같으면서 이전에 합쳐진 적이 없음) 
				if(a[i][l] == a[i][j] && m == 0) {
					a[i][l] *= 2;
					a[i][j] = 0;
					m = 1;
				// 이동할 수 없는 경우(=현재 칸 바로 앞까지 합칠 수 없는 칸이 있음) 
				} else if(l + 1 == j) {
					m = 0;
					l++;
				// 합치지 않고 이동하는 경우  
				} else {
					m = 0;
					l++;
					a[i][l] = a[i][j];
					a[i][j] = 0;
				}
			}
		}
	}
}

// 오른쪽으로 이동
void move_r(int n, int a[20][20]) {
	// 방향을 제외한 내용은 move_l과 같음  
	for(int i = 0; i < n; i++) {
		
		int l = n - 1, m = 0;;
		if(a[i][l] == 0) l = -1;
		
		for(int j = n - 2; j >= 0; j--) {
			
			if(a[i][j] == 0) continue;
			
			if(l < 0) {
				l = n - 1;
				a[i][l] = a[i][j];
				a[i][j] = 0;
			} else {
				if(a[i][l] == a[i][j] && m == 0) {
					a[i][l] *= 2;
					a[i][j] = 0;
					m = 1;
				} else if(l - 1 == j) {
					m = 0;
					l--;
				} else {
					m = 0;
					l--;
					a[i][l] = a[i][j];
					a[i][j] = 0;
				}
			}
		}
	}
}

// 위로 이동  
void move_u(int n, int a[20][20]) {
	// 방향을 제외한 내용은 move_l과 같음
	for(int i = 0; i < n; i++) {
		
		int l = 0, m = 0;
		if(a[l][i] == 0) l = -1;
		
		for(int j = 1; j < n; j++) {
			
			if(a[j][i] == 0) continue;
			
			if(l < 0) {
				l = 0;
				a[l][i] = a[j][i];
				a[j][i] = 0;
			} else {
				if(a[l][i] == a[j][i] && m == 0) {
					a[l][i] *= 2;
					a[j][i] = 0;
					m = 1;
				} else if(l + 1 == j) {
					m = 0;
					l++;
				} else {
					m = 0;
					l++;
					a[l][i] = a[j][i];
					a[j][i] = 0;
				}
			}
		}
	}
}

// 아래로 이동  
void move_d(int n, int a[20][20]) {
	// 방향을 제외한 내용은 move_l과 같음
	for(int i = 0; i < n; i++) {
		
		int l = n - 1, m = 0;
		if(a[l][i] == 0) l = -1;
		
		for(int j = n - 2; j >= 0; j--) {
			
			if(a[j][i] == 0) continue;
			
			if(l < 0) {
				l = n - 1;
				a[l][i] = a[j][i];
				a[j][i] = 0;
			} else {
				if(a[l][i] == a[j][i] && m == 0) {
					a[l][i] *= 2;
					a[j][i] = 0;
					m = 1;
				} else if(l - 1 == j) {
					m = 0;
					l--;
				} else {
					m = 0;
					l--;
					a[l][i] = a[j][i];
					a[j][i] = 0;
				}
			}
		}
	}
}

// 상하좌우 방향으로 이동시키기  
int f(int n, int a[20][20], int l) {
	// 5번 이동한 경우 현재 게임판에서 최대값 반환  
	if(l == 5) {
		int max = 0;
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++)
				if(max < a[i][j]) max = a[i][j];
		return max;
	}
	
	// 5번 이동하지 않은 경우 상하좌우로 이동하고 각각의 최대값 중 최대값 반환  
	int ta[20][20], tv, max = 0;
	l++;
	
	// 왼쪽  
	copy(ta, a, n);
	move_l(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	// 오른쪽 
	copy(ta, a, n);
	move_r(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	// 위  
	copy(ta, a, n);
	move_u(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	// 아래  
	copy(ta, a, n);
	move_d(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	return max;
}

int main() {
	int n, a[20][20];
	
	// 입력  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	
	// 결과 출력  
	printf("%d", f(n, a, 0));
	
	return 0;
}
