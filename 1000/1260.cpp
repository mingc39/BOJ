#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 1024
//#define QUEUE_SIZE 1024 
#define QUEUE_SIZE 25000

int main() {
	int n, m, v, a, b, c;
	bool l[1000][1000] = {0,};
	bool vb[1000] = {0,};
	bool vd[1000] = {0,};
	int stack[STACK_SIZE], se = 0;
	int queue[QUEUE_SIZE], qs = 0, qe = 0;
	scanf("%d %d %d", &n, &m, &v);
	v--;
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		l[a][b] = 1;
		l[b][a] = 1;
	}
	
	// DFS
	stack[se++] = v;
	while(se != 0) {
		c = stack[--se];
		if(vd[c] == true) continue;
		vd[c] = true;
		printf("%d ", c + 1);
		for(int i = n - 1; i >= 0; i--) {
			if(l[c][i] == true && vd[i] == false) {
				stack[se++] = i;
			}
		}
	}
	putchar('\n');
	
	// BFS
	queue[qs++] = v;
	if(qs == QUEUE_SIZE) qs = 0;
	while(qs != qe) {
		c = queue[qe++];
		if(qe == QUEUE_SIZE) qe = 0;
		if(vb[c] == true) continue;
		vb[c] = true;
		printf("%d ", c + 1);
		for(int i = 0; i < n; i++) {
			if(l[c][i] == true && vb[i] == false) {
				queue[qs++] = i;
				if(qs == QUEUE_SIZE) qs = 0;
			}
		}
	}
	//putchar('\n');
	
	return 0;
}
