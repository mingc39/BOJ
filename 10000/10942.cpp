#include <stdio.h>

int a[2000][2000] = {0,};
int s[2000], n;

int f(int start, int end) {
	// 전에 확인했던 경우  
	if(a[start][end] != 0) return a[start][end];
	
	// 시작이 끝보다 뒤에 있는 경우 (길이가 짝수일때 재귀호출중 발생 가능) 
	if(start > end) return 1;
	
	// 팰린드롬인지 확인  
	if(start == end) a[start][end] = 1; // 길이가 1이면 팰린드롬  
	else if(s[start] == s[end]) a[start][end] = f(start + 1, end - 1); // 양 끝이 같으면 양 끝을 제외한 경우와 같음 
	else a[start][end] = -1; // 양 끝이 다르면 팰린드롬 아님
	
	// 결과 반환 
	return a[start][end];
}

int main() {
	// 수열 입력  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &s[i]);
	
	int m, s, e;
	scanf("%d", &m); // 질문 수 입력  
	while(m--) {
		// 질문 입력과 팰린드롬인지 출력  
		scanf("%d %d", &s, &e);
		putchar(f(s - 1, e - 1) == 1 ? '1' : '0');
		putchar('\n');
	}
	
	return 0;
}
