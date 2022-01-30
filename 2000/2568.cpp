#include <stdio.h>
#include <stdlib.h>

int a[1000000];
int b[1000000];
int c[1000000];

int cmpi(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int cmp0(const void* a, const void* b) {
	return ((int*)a)[0] - ((int*)b)[0];
}

int cmp1(const void* a, const void* b) {
	return ((int*)a)[1] - ((int*)b)[1];
}

int main() {
	int n, l = 0; 
	int d[100000][2];
	 
	// 입력 및 A 전봇대 번호순으로 정렬  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &d[i][0], &d[i][1]);
	}
	qsort(d, n, sizeof(int) * 2, cmp0);
	
	// 살릴 전선 구하기  
	//scanf("%d", &a[0]);
	a[0] = d[0][1];
	b[0] = a[0];
	c[0] = 0;
	for(int i = 1; i < n; i++) {
		//scanf("%d", &a[i]);
		a[i] = d[i][1];
		if(a[i] > b[l]) { // 이번에 입력받은 수가 가장 큰 경우 b의 맨 뒤에 추가하기  
			b[++l] = a[i];
			c[i] = l;
		} else { // 이번에 입력받은 수가 가장 크지 않은 경우 
			// b에서 a[i]보다 큰 첫 요소 찾기  
			int left = 0, right = l;
			while(left < right) {
				int mid = (left + right) / 2;
				if(b[mid] < a[i]) left = mid + 1;
				else right = mid;
			}
			// 찾은 위치를 a[i]로 바꾸기  
			b[right] = a[i];
			c[i] = right;
		}
	}
	
	// 길이 출력 
	printf("%d\n", n - l - 1);
	
	// 살릴 전선 목록 가져오기  
	for(int i = n - 1, t = l; i >= 0 && t >= 0; i--) {
		if(c[i] == t) {
			b[t] = a[i];
			t--;
		}
	}
	
	// 안 살릴 전선 목록으로 변환  
	qsort(d, n, sizeof(int) * 2, cmp1);
	for(int i = 0, j = 0, k = 0; i < n; i++) {
		if(d[i][1] == b[j]) j++;
		else a[k++] = d[i][0];
	}
	
	// 정렬 후 출력  
	qsort(a, n - l - 1, sizeof(int), cmpi);
	for(int i = 0; i < n - l - 1; i++) printf("%d\n", a[i]);
	
	return 0;
}
