#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int array[32768];
	char *program;

	int T, n = 0;
	scanf("%d", &T);

	int end, index, length, o, c; char *input; int *bracket;
	int *tbra;
	tbra = (int*)malloc(sizeof(int) * 130000);
    bracket = (int*)malloc(sizeof(int) * 130000);
    input = (char*)malloc(sizeof(char) * 130000);
    program = (char*)malloc(sizeof(char) * 130000);
	while (T > 0) {
		T--;
		//===================<입력 및 주석, 미사용 문자 처리>=====================
		program[0] = '\0';  end = 0; index = 0; o = 0; c = 0;
		while (end == 0) {
			fgets(input, 129000, stdin);
			if (strcmp(input, "end") == 0 || strcmp(input, "end\n") == 0) {
				end = 1;
				break;
			}

			length = strlen(input);
			for (int i = 0; i < length; i++) {
				if (input[i] == '%') {
					break;
				}
				if (input[i] != '<' && input[i] != '>' && input[i] != '+' && input[i] != '-' &&
					input[i] != '.' && input[i] != '[' && input[i] != ']') {
					continue;
				}
				program[index] = input[i];
				index++;
			}
			
		}
		program[index] = '\0';
		printf("PROGRAM #%d:\n", ++n);
		//========================================================================

		//==============================<괄호 확인>===============================
		for(int i = 0; i < 130000; i++) bracket[i] = 0;
		end = 0;
		for (int i = 0; i < index; i++) {
			if (program[i] == '[') {
				o++;
				tbra[end] = i;
				end++;
			}
			else if (program[i] == ']') {
			 	if(o == 0) {
			 		c = 0; o = -1; break;
				}
				c++;
				bracket[i] = tbra[end - 1];
				bracket[tbra[end - 1]] = i;
				end--;
			}
		}
		if (o != c) {
			printf("COMPILE ERROR\n");
			continue;
		}
		//========================================================================
		
		//==============================<코드 실행>===============================
		for(int i = 0; i < 32767; i++) array[i] = 0;
		int len = strlen(program);
		int idx = 0, ptr = 0;
		while(idx < len) {
			switch(program[idx]) {
				case '>':
					if(ptr == 32767) ptr = 0;
					else ptr++;
					break;
				case '<':
					if(ptr == 0) ptr = 32767;
					else ptr--;
					break;
				case '+':
					if(array[ptr] == 255) array[ptr] = 0;
					else array[ptr]++;
					break;
				case '-':
					if(array[ptr] == 0) array[ptr] = 255;
					else array[ptr]--;
					break;
				case '.':
					printf("%c", (char)array[ptr]);
					break;
				case '[':
					if(array[ptr] == 0) idx = bracket[idx];
					break;
				case ']':
					if(array[ptr] != 0) idx = bracket[idx];
					break;
			}
			idx++;
		}
		putchar('\n');
		//========================================================================
	}

	return 0;
}
