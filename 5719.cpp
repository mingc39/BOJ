#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

/*
�ּ����� ����� �켱���� ť
define PQSIZE�� ũ�� ����
*/
#define PQSIZE 1048576

// ========< �켱���� ť >======== 
long long a[PQSIZE];
int l = 0;

long long pop() {
	long long tmp = a[0];
	a[0] = a[--l];
	// �� ����
	long long t;
	int t1, t2, i = 0;
	while(i < l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // ���� ��常 �ִ� ��� 
			if(a[t1] < a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // �� �� �ִ� ��� 
			if(a[t1] < a[i] && a[t1] <= a[t2]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
			if(a[t2] < a[i] && a[t2] < a[t1]) {
				t = a[t2];
				a[t2] = a[i];
				a[i] = t;
				i = t2;
				continue;
			}
		}
		// �� ���� �ڽ� ��� ������ ���� �Ϸ�
		break; 
	}
	return tmp;
}

long long push(long long x) {
	a[l++] = x;
	// �� ���� 
	long long t;
	int t1, i = l - 1;
	while(i > 0) {
		// �θ� ��� �ε��� ���
		t1 = (i - 1) / 2;
		// �θ� ��� ��
		if(t1 >= 0) {
			if(a[t1] > a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
		}
		// �θ� ��尡 �� ������ ���� �Ϸ�
		break; 
	}
	return x;
}
// =============================== 

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int m, n;
int src, dst;
int g[10000][4];
int v[10000];
int d[10000];
int p[500][500];
int c[500];
int q[10000];
int ql, qr;

// ���ͽ�Ʈ��  
int dij() {
	// �ʱ�ȭ  
	for(int i = 0; i < n; i++) d[i] = INF;	// �ּ� ��� ���� �迭 �ʱ�ȭ  
	d[src] = 0;								// ������� �ּ� ��� ���� 0���� �ʱ�ȭ  
	l = 0;									// ť �ʱ�ȭ  
	push(0 * 1000 + src);					// �������� ť ����  
	p[src][0] = 0;							// ����� �θ� �ʱ�ȭ
	
	// ť�� �� ������ �ݺ�  
	while(l > 0) {
		// �ּҰ� pop 
		int curLoc = a[0] % 1000;
		int curCst = a[0] / 1000;
		pop();
		
		// ����ġ���� �� �� �ִ� ���� ������Ʈ  
		int i = v[curLoc];
		while(g[i][0] == curLoc) {
			// ����� �� ���� �����̸� �ǳʶٱ�  
			if(g[i][3] != 0) {
				i++;
				continue;
			}
			
			// ���� ����, �Ÿ� ���ϱ�  
			int nxtLoc = g[i][1];			// ���� ���� ���ϱ�  
			int nxtCst = curCst + g[i][2];	// ���� ���� �Ÿ� ���ϱ�  
			if(nxtCst > INF) nxtCst = INF;	// �Ÿ��� INF �Ѿ�� INF�� ����(int ���� �ʰ� ����) 
			
			// ���� ���� ������Ʈ  
			// ���� �Ÿ����� �� ª���� ������Ʈ  
			if(nxtCst < d[nxtLoc]) {
				d[nxtLoc] = nxtCst;				// ������Ʈ �� �Ÿ� ���� 
				p[nxtLoc][0] = 1;				// �ִ� �Ÿ��� �� �� �ִ� ���� ���� �ʱ�ȭ  
				p[nxtLoc][1] = i;				// �ִ� �Ÿ��� �� �� �ִ� ���� ����  
				push(nxtCst * 1000 + nxtLoc);	// ť�� ���� ���� ���� 
			}
			// ���� �Ÿ��� ������ �ִ� �Ÿ��� �� �� �ִ� ������ ������Ʈ 
			if(nxtCst == d[nxtLoc])  {
				p[nxtLoc][0]++;					// �ִ� �Ÿ��� �� �� �ִ� ���� ���� ����   
				p[nxtLoc][p[nxtLoc][0]] = i;	// �ִ� �Ÿ��� �� �� �ִ� ���� ����  
			}
			
			i++;
		}
	}
	
	return d[dst];
}


void rsp_BFS(void);
void rsp_DFS(int);
// �ִܰ�ο� ���Ե� ��� ���� ���� 
void rsp() {
	int BFS = 0; // DFS�� Ž���� 0, BFS�� Ž���� 1 
	
	int DFS = !BFS;
	if(BFS == 1) rsp_BFS();
	if(DFS == 1) {
		for(int i = 0; i < n; i++) c[i] = 0;
		c[src] = 1;
		rsp_DFS(dst);
	}
}
 
void rsp_BFS() {
	// ���� �湮 �迭 �ʱ�ȭ  
	for(int i = 0; i < n; i++) c[i] = 0;	// ������ ���� ��Ȱ��ȭ �Ϸ� ���� �ʱ�ȭ  
	c[src] = 1;								// �������� ���� ��Ȱ��ȭ �Ϸ�� ó��  
	
	// ť �ʱ�ȭ  
	ql = qr = 0;							// ť �ʱ�ȭ  
	q[qr++] = dst;							// ������ ����  
	if(qr == 10000) qr = 0;					// ť ������ �� ��ġ ���� �ʰ��� 0���� �ǵ�����  
	
	// �ִܰŸ��� ���Ե� ���� Ž�� �� ��Ȱ��ȭ  
	while(ql != qr) {
		// ť���� ������  
		int cur = q[ql++];
		if(ql == 10000) ql = 0;
		
		// �̹� �湮�� ��� ���  
		if(c[cur] != 0) continue;
		
		// �ش� �������� ������ ������ ��Ȱ��ȭ, ������ Ž��  
		c[cur] = 1; // �湮 üũ  
		for(int i = 1; i <= p[cur][0]; i++) {
			g[p[cur][i]][3] = 1;		// ���� ��Ȱ��ȭ  
			q[qr++] = g[p[cur][i]][0];	// ���� ť�� ����  
			if(qr == 10000) qr = 0;
		}
	}
}

void rsp_DFS(int cur) {
	// �������̰ų� �̹� �湮�� �����̸� ���  
	if(cur == src || c[cur] != 0) return;
	
	// �ش� �������� ������ ������ ��Ȱ��ȭ, ������ Ž��  
	c[cur] = 1;
	for(int i = 1; i <= p[cur][0]; i++) {
		g[p[cur][i]][3] = 1;		// ���� ��Ȱ��ȭ  
		rsp_DFS(g[p[cur][i]][0]);	// ���� ť�� ����
	}
}

int main() {
	// ó�� n, m �Է�  
	scanf("%d %d", &n, &m);
	while(n != 0 || m != 0) {
		// �����, ������ �Է� 
		scanf("%d %d", &src, &dst);
		// ���� ���� �Է�  
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &g[i][0], &g[i][1], &g[i][2]);
			g[i][3] = 0;
		}
		qsort(g, m, sizeof(int) * 4, cmp);
		for(int i = 0, prv = -1; i < m; i++) {
			if(g[i][0] != prv) {
				prv = g[i][0];
				v[g[i][0]] = i;
			}
		}
		
		// ���� �ִ� �Ÿ� ���ϱ�
		dij();				// ��¥ �ִ� �Ÿ� ���ϱ�  
		rsp();				// ��¥ �ִ� �Ÿ��� ���Ե� ���� ��Ȱ��ȭ  
		int npl = dij(); 	// ���� �ִ� �Ÿ� ���ϱ�  
		
		// ��� ���  
		if(npl >= INF) printf("-1\n");	// ���� �ִ� ��ΰ� ���� ��� -1 ��� 
		else printf("%d\n", npl);		// ���� �ִ� ��ΰ� �ִ� ��� ���� �ִ� ��� ���  
		
		// ���� n, m �Է�  
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}
