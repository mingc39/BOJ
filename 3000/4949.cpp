#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int trim(char* string, int length);
int read(char* string);

int main() {
    int a, b;
    int i = 0;
    int c = 0;
    int b1, b2;
    
    char string[128] = { 0, };
    char t[128] = { 0, };
    int pos;

    read(string);
    while(string[0] != '.') {
    	pos = 0;
    	for(i = 0; i < 128; i++) {
    		if(string[i] == '(' || string[i] == '[' || string[i] == ')' || string[i] == ']') {
    			string[pos++] = string[i];
			}
			else if(string[i] == '.') { string[pos] = '\0'; break; }
		}
		
		//printf("%s\n", string);
		
		while(1) {
			for(i = 0; i < pos; i++) {
				if(string[i] == '(' && string[i + 1] == ')') {
					string[i] = ' ';
					string[i + 1] = ' ';
					trim(string, pos + 1);
					pos -= 2;
					break;
				}
				
				if(string[i] == '[' && string[i + 1] == ']') {
					string[i] = ' ';
					string[i + 1] = ' ';
					trim(string, pos + 1);
					pos -= 2;
					break;
				}
				//printf("%d: %s\n", i, string);
			}
			
			if(i == pos) break;
		}
    	
    	if(string[0] == '\0') printf("yes\n");
    	else printf("no\n");
    	
		read(string);
	}
	
    return 0;
}

int trim(char* string, int length) {
	int pos = 0;
	for(int i = 0; i < length; i++)
		if(string[i] != ' ')
			string[pos++] = string[i];
	return pos;
}

int read(char* string) {
	int pos = 0;
	char input;
	
	do {
		input = getchar();
		string[pos++] = input;
	} while(input != '.');
	
	while(getchar() != '\n');
	
	return pos;
}