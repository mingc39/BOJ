#include <stdio.h>

int main() {
	// ���� ���� 
	int a, b, ans = 0;
	
	// a, b �� �Է�
	while(scanf("%d %d", &a, &b) != EOF) {
		
		// a�� 1�϶� 
		if(a == 1 && b == 1) ans = 2;
		if(a == 1 && b == 2) ans = 3;
		if(a == 1 && b == 3) ans = 4;
		if(a == 1 && b == 4) ans = 5;
		if(a == 1 && b == 5) ans = 6;
		if(a == 1 && b == 6) ans = 7;
		if(a == 1 && b == 7) ans = 8;
		if(a == 1 && b == 8) ans = 9;
		if(a == 1 && b == 9) ans = 10;
		
		// a�� 2�϶� 
		if(a == 2 && b == 1) ans = 3;
		if(a == 2 && b == 2) ans = 4;
		if(a == 2 && b == 3) ans = 5;
		if(a == 2 && b == 4) ans = 6;
		if(a == 2 && b == 5) ans = 7;
		if(a == 2 && b == 6) ans = 8;
		if(a == 2 && b == 7) ans = 9;
		if(a == 2 && b == 8) ans = 10;
		if(a == 2 && b == 9) ans = 11;
		
		// a�� 3�϶� 
		if(a == 3 && b == 1) ans = 4;
		if(a == 3 && b == 2) ans = 5;
		if(a == 3 && b == 3) ans = 6;
		if(a == 3 && b == 4) ans = 7;
		if(a == 3 && b == 5) ans = 8;
		if(a == 3 && b == 6) ans = 9;
		if(a == 3 && b == 7) ans = 10;
		if(a == 3 && b == 8) ans = 11;
		if(a == 3 && b == 9) ans = 12;
		
		// a�� 4�϶� 
		if(a == 4 && b == 1) ans = 5;
		if(a == 4 && b == 2) ans = 6;
		if(a == 4 && b == 3) ans = 7;
		if(a == 4 && b == 4) ans = 8;
		if(a == 4 && b == 5) ans = 9;
		if(a == 4 && b == 6) ans = 10;
		if(a == 4 && b == 7) ans = 11;
		if(a == 4 && b == 8) ans = 12;
		if(a == 4 && b == 9) ans = 13;
		
		// a�� 5�϶� 
		if(a == 5 && b == 1) ans = 6;
		if(a == 5 && b == 2) ans = 7;
		if(a == 5 && b == 3) ans = 8;
		if(a == 5 && b == 4) ans = 9;
		if(a == 5 && b == 5) ans = 10;
		if(a == 5 && b == 6) ans = 11;
		if(a == 5 && b == 7) ans = 12;
		if(a == 5 && b == 8) ans = 13;
		if(a == 5 && b == 9) ans = 14;
		
		// a�� 6�϶� 
		if(a == 6 && b == 1) ans = 7;
		if(a == 6 && b == 2) ans = 8;
		if(a == 6 && b == 3) ans = 9;
		if(a == 6 && b == 4) ans = 10;
		if(a == 6 && b == 5) ans = 11;
		if(a == 6 && b == 6) ans = 12;
		if(a == 6 && b == 7) ans = 13;
		if(a == 6 && b == 8) ans = 14;
		if(a == 6 && b == 9) ans = 15;
		
		// a�� 7�϶� 
		if(a == 7 && b == 1) ans = 8;
		if(a == 7 && b == 2) ans = 9;
		if(a == 7 && b == 3) ans = 10;
		if(a == 7 && b == 4) ans = 11;
		if(a == 7 && b == 5) ans = 12;
		if(a == 7 && b == 6) ans = 13;
		if(a == 7 && b == 7) ans = 14;
		if(a == 7 && b == 8) ans = 15;
		if(a == 7 && b == 9) ans = 16;
		
		// a�� 8�϶� 
		if(a == 8 && b == 1) ans = 9;
		if(a == 8 && b == 2) ans = 10;
		if(a == 8 && b == 3) ans = 11;
		if(a == 8 && b == 4) ans = 12;
		if(a == 8 && b == 5) ans = 13;
		if(a == 8 && b == 6) ans = 14;
		if(a == 8 && b == 7) ans = 15;
		if(a == 8 && b == 8) ans = 16;
		if(a == 8 && b == 9) ans = 17;
		
		// a�� 9�϶� 
		if(a == 9 && b == 1) ans = 10;
		if(a == 9 && b == 2) ans = 11;
		if(a == 9 && b == 3) ans = 12;
		if(a == 9 && b == 4) ans = 13;
		if(a == 9 && b == 5) ans = 14;
		if(a == 9 && b == 6) ans = 15;
		if(a == 9 && b == 7) ans = 16;
		if(a == 9 && b == 8) ans = 17;
		if(a == 9 && b == 9) ans = 18;
		
		// ���� ��� 
		printf("%d\n", ans);
	}
	
	// ���α׷� ���� 
	return 0;
}
