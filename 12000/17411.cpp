#include <stdio.h>
#include <stdlib.h>

// MEM 값이 작을수록 메모리를 덜 사용함
// MEM 값을 수정해서 시도해본 결과 MEM = 8에서 제일 빨랐음  
#define MEM 32
#define MOD 1000000007

typedef struct pair {
	int key;
	int value;
} pair;

int main() {
	int in; 
	
	// 수열 크기 입력  
	scanf("%d", &in);
	
	// 동적 할당, 초기화  
	pair **a = (pair**)malloc((in + 1) * sizeof(pair));
	a[0] = (pair*)a;
	int *s = (int*)calloc(in + 1, sizeof(int));
	s[0] = in;
	int *l = (int*)calloc(in + 1, sizeof(int));
	
	for(int i = 0; i < s[0]; i++) {
		
		// 입력 
		scanf("%d", &in);
		
		
		// 추가할 열 찾기 
		int row = 0;
		{
			int left = 1, right = l[0];
			while(left <= right) {
				int mid = (left + right) / 2;
				if(a[mid][l[mid] - 1].key < in) left = mid + 1;
				else if(left == right) break;
				else right = mid;
			}
			row = left;
		}
		
		
		// 입력(key)와 같이 추가할 sum값(value) 찾기 
		int sum = 1;
		if(row > 1) { // 직전 줄에서 입력보다 작은 가장 큰 수 찾기 
			int left = 0, right = l[row - 1] - 1;
			while(left < right) {
				int mid = (left + right) / 2;
				if(a[row - 1][mid].key > in) left = mid + 1;
				else right = mid;
			}
			if(a[row - 1][left].key != in) left--;
			if(left >= 0) sum = (a[row - 1][l[row - 1] - 1].value - a[row - 1][left].value + MOD) % MOD; // 뺄셈 결과가 음수가 될 수 있으므로 MOD를 더해줘야함  
			else sum = a[row - 1][l[row - 1] - 1].value;
		} 
		if(l[row] > 0 && a[row][l[row] - 1].key != in) sum = (sum + a[row][l[row] - 1].value) % MOD;
		
		
		// (입력, sum) 쌍 추가하기
		if(l[row] > 0) { // 해당 row의 마지막의 key 값이 in과 같은 경우 (입력, sum) 쌍 추가 대신 마지막의 value 값 수정  
			if(a[row][l[row] - 1].key == in) {
				a[row][l[row] - 1].value = (a[row][l[row] - 1].value + sum) % MOD;
				continue;
			}
		}
		if(l[row] == s[row]) { // 공간이 부족한 경우 추가 할당  
			if(s[row] == 0) {
				a[row] = (pair*)malloc(MEM * sizeof(pair));
				s[row] = MEM;
			} else {
				s[row] += MEM;
				a[row] = (pair*)realloc(a[row], s[row] * sizeof(pair));
			}
		}
		a[row][l[row]].key = in;
		a[row][l[row]].value = sum;
		l[row]++;
		if(l[0] < row) l[0] = row;
	}
	
	// 결과 출력  
	printf("%d %d", l[0], a[l[0]][l[l[0]] - 1].value); // 가장 마지막 row 번호 = 길이, 가장 마지막 row의 마지막 value = 개수  
	
	return 0;
}
