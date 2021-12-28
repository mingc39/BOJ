#include <stdio.h>
#include <stdlib.h>

// x를 한 칸씩 띄어서 출력 (ex. 12345 -> 1 2 3 4 5) 
void print(int x) {
	int l = 1, n = x;
	while(n > 0) {
		l *= 10;
		n /= 10;
	}
	l /= 10;
	while(l > 0) {
		putchar(x / l + '0');
		putchar(' ');
		x %= l;
		l /= 10;
	}
}

int main() {
	// 스택 
	int *s, *l, p = 0;
	s = (int*)malloc(sizeof(int) * 1000000);
	l = (int*)malloc(sizeof(int) * 1000000);
	
	int n, m;
	int a, b;
	
	// 입력  
	scanf("%d %d", &n, &m);
	
	// 수열 시작 숫자 스택에 삽입  
	for(int i = n; i > 0; i--) {
		s[p] = i;
		l[p] = 1;
		p++;
	}
	
	// 스택이 빌때까지 탐색  
	while(p > 0) {
		// 스택에서 하나 뽑기  
		p--;
		a = s[p];
		b = l[p];
		
		// 길이가 m이면 출력  
		if(b == m) {
			print(a);
			putchar('\n');
			continue;
		}
		
		// 수열에 다음 수 추가  
		for(int i = n; i > 0; i--) {
			if(i > a % 10) {
				s[p] = a * 10 + i;
				l[p] = b + 1;
				p++;
			}
		}
	}
	
	return 0;
}
