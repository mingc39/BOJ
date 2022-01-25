#include <stdio.h>

int a[1000000];
int b[1000000];
int c[1000000];

int main() {
	int n, l = 0; 
	 
	scanf("%d", &n);
	scanf("%d", &a[0]);
	b[0] = a[0];
	c[0] = 0;
	for(int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
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
	
	printf("%d", n - l - 1);
	
	return 0;
}
