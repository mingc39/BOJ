#include <stdio.h>

int a[2500][2500] = {0,}, n;
int b[2500];
char s[2501];

// start부터 end까지 팰린드롬인지 확인  
int f1(int start, int end) {
	// 전에 확인했던 경우  
	if(a[start][end] != 0) return a[start][end];
	
	// 시작이 끝보다 뒤에 있는 경우 (길이가 짝수일때 재귀호출중 발생 가능) 
	if(start > end) return 1;
	
	// 팰린드롬인지 확인  
	if(start == end) a[start][end] = 1; // 길이가 1이면 팰린드롬  
	else if(s[start] == s[end]) a[start][end] = f1(start + 1, end - 1); // 양 끝이 같으면 양 끝을 제외한 경우와 같음 
	else a[start][end] = -1; // 양 끝이 다르면 팰린드롬 아님
	
	// 결과 반환 
	return a[start][end];
}

// 0부터 end까지 팰린드롬 분할의 최소값 구하기  
int f2(int end) {
	// 전에 확인했던 경우
	if(b[end] != 0) return b[end];
	
	// 0부터 end까지가 팰린드롬인 경우  
	if(f1(0, end) > 0) return b[end] = 1;
	
	// (0,end-1)(end)부터 (0)(1,end)까지 분할해보면서 최소 분할 구하기  
	int min = 3000;
	for(int i = end - 1; i >= 0; i--) {
		if(f1(i + 1, end) < 0) continue;
		int t = f2(i) + 1;
		if(min > t) min = t;
	}
	
	return b[end] = min;
}

int main() {
	scanf("%s", s);
	while(s[++n] != '\0');
	printf("%d", f2(n - 1));
	return 0;
}
