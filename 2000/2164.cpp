#include <stdio.h>

#define SIZE 512000
int q[SIZE];
int in = 0, out = 0;

int push(int x) {
	q[in] = x;
	in++;
	if(in >= SIZE) in %= SIZE;
	return x;	
}

int pop() {
	int t = q[out];
	out++;
	if(out >= SIZE) out %= SIZE;
	return t;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) q[i] = i + 1;
	in = n;
	
	int l;
	while(in != out) {
		l = pop();
		push(pop());
	}
	
	printf("%d", l);
	
	return 0;
}
