#include <stdio.h>

char T[1048576];
char P[1048576];

int  a[1048576];
int  b[1048576];

int main() {
	int n = 0;
	int l, m;
	int i, j; 
	
	// 입력
	gets(T);
	gets(P);
	
	// 문자열 길이 구하기  
	while(T[l] != '\0') l++;
	while(P[m] != '\0') m++;
	
	// 앞 뒤가 어디까지 같은지 찾기  
	i = 1; j = 0;
	a[0] = 0;
	while(i < m) {
		if(P[i] == P[j]) a[i++] = ++j;
		else if(j != 0) j = a[j - 1];
		else a[i++] = 0;
	}
	
	// 찾기 
	i = 0; j = 0;
	while(i < l) {
		// 일치하면 진행  
		if(T[i] == P[j]) {
			i++;
			j++;
		}
		// 일치하지 않는 경우  
		else if(j == 0) { 
			i++;
		} else {
			j = a[j - 1];
		}
		
		// 찾는 문자열이 끝까지 발견된 경우  
		if(j == m) {
			b[n++] = i - j + 1; // 배열에 시작 위치 저장  
			j = a[j - 1]; // 찾기 계속 진행  
		}
	}
	
	printf("%d\n", n);
	for(int i = 0; i < n; i++) printf("%d ", b[i]);
	
	return 0;
}
