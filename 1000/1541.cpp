#include <stdio.h>

// 첫 -가 나오기 전은 모두 더하고 뒤로는 전부다 빼기 
// 첫 - 전의 수는 -가 없어서 뺄수 없음 -> 무조건 더할 수 밖에 없음
// 첫 - 이후의 수는 -가 붙어있으면 그냥 뺄 수 있고
// +가 붙어있으면 앞의 -와 괄호로 묶어서 뺄 수 있음 -A+B -> -(A+B)
int main() {
	char str[64];
	scanf("%s", str);
	
	// 첫 - 이전에 모두 더하기
	int i = 0, r = 0, t = 0;
	while(str[i] != '-' && str[i] != '\0') {
		if(str[i] == '+') {
			r += t;
			t = 0;
		} else {
			t *= 10;
			t += str[i] - '0';
		}
		i++;
	}
	r += t;
	t = 0;
	// 첫 - 이후 모두 빼기
	while(str[i] != '\0') {
		if(str[i] == '+' || str[i] == '-') {
			r -= t;
			t = 0;
		} else {
			t *= 10;
			t += str[i] - '0';
		}
		i++;
	}
	r -= t;
	t = 0;
	
	printf("%d", r);
	
	return 0;
}
