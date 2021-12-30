#include <stdio.h>

#define MAX_LENGTH 1000001

char str[MAX_LENGTH];
char stack[MAX_LENGTH];
char bomb[37];
int pos = 0;
int length = 0;

int main() {
	int frula = 1;
	
	scanf("%s %s", str, bomb);
	while(bomb[length] != '\0') length++; // bomb 길이 구하기  
	
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] != bomb[0]) { // 폭발과 상관 없는 경우 그냥 출력  
			putchar(str[i]);
			frula = 0;
		}
		else { // 폭발 문자열의 첫 글자가 나온 경우  
			if(length == 1) continue;
			stack[pos++] = 0;
			int j;
			for(j = i + 1; str[j] != '\0'; j++) {
				// 폭발 문자열의 다음 글자가 나온 경우  
				if(str[j] == bomb[stack[pos - 1] + 1]) {
					if(stack[pos - 1] + 2 == length) { // 마지막 문자까지 나온경우  
						// 스택에서 마지막 폭발 문자열 제거  
						while(stack[pos - 1] != 0) pos--;
						pos--;
						if(pos == 0) break;
					} else {
						stack[pos] = stack[pos - 1] + 1;
						pos++;
					}
				} else if(str[j] == bomb[0]) { // 폭발 문자열의 첫 글자가 나온 경우  
					stack[pos++] = 0;
				} else { // 폭발 문자열이 다 안나오고 끊긴 경우 
					// 폭발하지 않으므로 스택의 모든 문자열 출력 후 스택 비우기  
					for(int k = 0; k < pos; k++) putchar(bomb[stack[k]]);
					j--;
					pos = 0;
					break;
				} 
			}
			i = j;
			
			if(str[j] == '\0') {
				for(int k = 0; k < pos; k++) putchar(bomb[stack[k]]);
			}
		}
	}
	
	// 아무 출력이 없는 경우(=모두 폭팔한 경우) FRULA 출력  
	if(frula == 1) printf("FRULA");
	
	return 0;
}
