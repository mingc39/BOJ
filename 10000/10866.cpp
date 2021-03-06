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

void push_front(int x);
void push_back(int x);
void pop_front();
void pop_back();

int main() {
	
	int n, x;
	char c[15];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%s", c);
		
		if(strcmp(c, "push") == 0) {
			scanf("%d", &x);
			push(x);
		} else if(strcmp(c, "push_front") == 0) {
			scanf("%d", &x);
			push_front(x);
		} else if(strcmp(c, "push_back") == 0) {
			scanf("%d", &x);
			push_back(x);
		} else if(strcmp(c, "pop") == 0) {
			pop();
		} else if(strcmp(c, "size") == 0) {
			size();
		} else if(strcmp(c, "empty") == 0) {
			empty();
		} else if(strcmp(c, "front") == 0) {
			front();
		} else if(strcmp(c, "back") == 0) {
			back();
		} else if(strcmp(c, "pop_front") == 0) {
			pop_front();
		} else if(strcmp(c, "pop_back") == 0) {
			pop_back();
		}
		
		//printf("%d %d %d %d\n", q[0], q[1], q[10009], q[10008]);
	}
	
	
	
	return 0;
}

void push(int x) {
	q[end++] = x;
	if(end >= 10010) end %= 10010;
}

void pop() {
	if(start == end) printf("-1\n");
	else printf("%d\n", q[start++]);
	if(start >= 10010) start %= 10010;
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

void back() {
	if(start == end) printf("-1\n");
	else if(end - 1 < 0) printf("%d\n", q[end - 1 + 10010]);
	else printf("%d\n", q[end - 1]);
}

void push_front(int x) {
	start--;
	if(start < 0) start += 10010;
	q[start] = x;
}

void push_back(int x) {
	q[end++] = x;
	if(end >= 10010) end %= 10010;
}

void pop_front() {
	if(start == end) printf("-1\n");
	else printf("%d\n", q[start++]);
	if(start >= 10010) start %= 10010;
}

void pop_back() {
	if(start == end) printf("-1\n");
	else {
		end--;
		if(end < 0) end += 10010;
		printf("%d\n", q[end]);
	}
}
