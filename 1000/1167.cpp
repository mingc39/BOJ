#include <stdio.h>
#include <stdlib.h>

#define MEM 128
#define QSIZE 400000

int main() {
	int n, **tree, **weight, *size, *length;
	// tree: Ʈ�� ���� ����
	// weight: ������ ����ġ
	// size: �ش� ������ ���Ḯ��Ʈ ũ��(�Ҵ�� �޸� ����) 
	// length: �ش� ������ ���Ḯ��Ʈ ����(���� ������ ����) 
	int a, b, c;
	
	// �Է�  
	scanf("%d", &n);
	tree = (int**)calloc(n + 1, sizeof(int*));
	weight = (int**)calloc(n + 1, sizeof(int*));
	size = (int*)calloc(n + 1, sizeof(int*));
	length = (int*)calloc(n + 1, sizeof(int*));
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c);
		scanf("%d", &a);
		while(a > 0) {
			scanf("%d", &b);
			
			// ���� ���� ������ �߰� �Ҵ� 
			if(size[c] == length[c]) {
				tree[c]   = (int*)realloc(  tree[c], sizeof(int) * (size[c] + MEM));
				weight[c] = (int*)realloc(weight[c], sizeof(int) * (size[c] + MEM));
				size[c] += MEM;
			}
			
			// �Է� ���� ���� 
			tree  [c][length[c]] = a;
			weight[c][length[c]] = b; 
			length[c]++;
			
			scanf("%d", &a);
		}
		// ũ�� ����  
		tree[c]   = (int*)realloc(  tree[c], sizeof(int) * length[c]);
		weight[c] = (int*)realloc(weight[c], sizeof(int) * length[c]);
	}
	free(size); // length �־ size �ʿ����  
	
	// �Է¹��� Ʈ�� ������ Ȯ��  
	#ifdef DEBUG
	for(int i = 1; i <= n; i++) {
		printf("%d:", i);
		for(int j = 0; j < length[i]; j++) printf(" (%2d %2d)", tree[i][j], weight[i][j]);
		putchar('\n');
	}
	#endif
	
	// ť �ʱ�ȭ  
	int *qn, *ql, *qp, qi = 0, qo = 0;
	int maxLen = 0, maxNod;
	qn = (int*)malloc(sizeof(int) * QSIZE);
	ql = (int*)malloc(sizeof(int) * QSIZE);
	qp = (int*)malloc(sizeof(int) * QSIZE);
	
	// ��Ʈ���� �Ÿ��� �ִ��� ��� ã��  
	qn[qi] = 1;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == QSIZE) qi = 0;
	while(qi != qo) {
		// ť���� ������  
		a = qn[qo]; // ���� ��� 
		b = ql[qo]; // Ž�� �Ÿ�  
		c = qp[qo]; // ���� ���  
		qo++;
		if(qo == QSIZE) qo = 0;
		
		// �������� �ִ�Ÿ� ���� 
		if(length[a] == 1 && c != 0) {
			if(b > maxLen) {
				maxLen = b;
				maxNod = a;
			} 
			continue;
		}
		
		// ���� ��� ť�� ����
		for(int i = 0; i < length[a]; i++) {
			if(tree[a][i] == c) continue;
			qn[qi] = tree[a][i];
			ql[qi] = b + weight[a][i];
			qp[qi] = a;
			qi++;
			if(qi == QSIZE) qi = 0;
		} 
	}
	
	// ť�� ������ �̹� �� ���� ť �ʱ�ȭ ���ص� �� 
	// ��Ʈ���� �Ÿ��� �ִ��� ��忡�� �Ÿ��� �ִ��� ��� ã��  
	qn[qi] = maxNod;
	ql[qi] = 0;
	qp[qi] = 0;
	qi++;
	if(qi == QSIZE) qi = 0;
	while(qi != qo) {
		// ť���� ������  
		a = qn[qo]; // ���� ��� 
		b = ql[qo]; // Ž�� �Ÿ�  
		c = qp[qo]; // ���� ���  
		qo++;
		if(qo == QSIZE) qo = 0;
		
		// �������� �ִ�Ÿ� ���� 
		if(length[a] == 1 && c != 0) {
			if(b > maxLen) {
				maxLen = b;
				maxNod = a;
			} 
			continue;
		}
		
		// ���� ��� ť�� ����
		for(int i = 0; i < length[a]; i++) {
			if(tree[a][i] == c) continue;
			qn[qi] = tree[a][i];
			ql[qi] = b + weight[a][i];
			qp[qi] = a;
			qi++;
			if(qi == QSIZE) qi = 0;
		} 
	}
	
	// ��� ��� 
	printf("%d", maxLen);
	
	return 0;
}
