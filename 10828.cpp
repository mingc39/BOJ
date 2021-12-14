#include <stdio.h>
#include <string.h>

int q[10010], pos = 0;
int start = 0, end = 0;

void push(int x);
void pop();
void size();
void empty();
void front();
void back();

int main() {
	
	int n, x;
	char c[10];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%s", c);
		
		if(strcmp(c, "push") == 0) {
			scanf("%d", &x);
			push(x);
		} else if(strcmp(c, "pop") == 0) {
			pop();
		} else if(strcmp(c, "size") == 0) {
			size();
		} else if(strcmp(c, "empty") == 0) {
			empty();
		} else if(strcmp(c, "front") == 0) {
			front();
		} else if(strcmp(c, "top") == 0) {
			back();
		}
		
		
	}
	
	
	
	return 0;
}

void push(int x) {
	q[end++] = x;
	if(end >= 10010) end %= 10010;
}

void pop() {
	if(start == end) printf("-1\n");
	else printf("%d\n", q[--end]);
}

void size() {
	printf("%d\n", (end - start < 0) ? (end - start + 10010) : (end - start));
}

void empty() {
	if(start == end) printf("1\n");
	else printf("0\n");
}

void front() {
	if(start == end) printf("-1\n");
	else printf("%d\n", q[start]);
}

void back(){
	if(start == end) printf("-1\n");
	else printf("%d\n", q[end - 1]);
}