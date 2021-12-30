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
	while(bomb[length] != '\0') length++; // bomb ���� ���ϱ�  
	
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] != bomb[0]) { // ���߰� ��� ���� ��� �׳� ���  
			putchar(str[i]);
			frula = 0;
		}
		else { // ���� ���ڿ��� ù ���ڰ� ���� ���  
			if(length == 1) continue;
			stack[pos++] = 0;
			int j;
			for(j = i + 1; str[j] != '\0'; j++) {
				// ���� ���ڿ��� ���� ���ڰ� ���� ���  
				if(str[j] == bomb[stack[pos - 1] + 1]) {
					if(stack[pos - 1] + 2 == length) { // ������ ���ڱ��� ���°��  
						// ���ÿ��� ������ ���� ���ڿ� ����  
						while(stack[pos - 1] != 0) pos--;
						pos--;
						if(pos == 0) break;
					} else {
						stack[pos] = stack[pos - 1] + 1;
						pos++;
					}
				} else if(str[j] == bomb[0]) { // ���� ���ڿ��� ù ���ڰ� ���� ���  
					stack[pos++] = 0;
				} else { // ���� ���ڿ��� �� �ȳ����� ���� ��� 
					// �������� �����Ƿ� ������ ��� ���ڿ� ��� �� ���� ����  
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
	
	// �ƹ� ����� ���� ���(=��� ������ ���) FRULA ���  
	if(frula == 1) printf("FRULA");
	
	return 0;
}
