#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int array[32768];
	int pointer;
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
		index = 0; pointer = 0;
		length = strlen(program);
		for (int i = 0; i < 32768; i++) array[i] = 0;
		while (index < length) {
			if (program[index] == '>') {
				if (pointer == 32767) pointer = 0;
				else pointer++;
				index++;
				continue;
			}
			if (program[index] == '<') {
				if (pointer == 0) pointer = 32767;
				else pointer--;
				index++;
				continue;
			}
			if (program[index] == '+') {
				if (array[pointer] == 255) array[pointer] = 0;
				else array[pointer]++;
				index++;
				continue;
			}
			if (program[index] == '-') {
				if (array[pointer] == 0) array[pointer] = 255;
				else array[pointer]--;
				index++;
				continue;
			}
			if (program[index] == '.') {
				printf("%c", (char)array[pointer]);
				index++;
				continue;
			}
			if (program[index] == '[') {
				if (array[pointer] == 0) {
					index = bracket[index];
				}
				else index++;
				continue;
			}
			if (program[index] == ']') {
				if (array[pointer] != 0) {
					index = bracket[index];
				}
				else index++;
				continue;
			}
			index++;
		}
		printf("\n");
		//========================================================================
	}

	return 0;
}

