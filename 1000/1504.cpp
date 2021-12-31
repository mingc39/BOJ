#include <stdio.h>
#include <stdlib.h>

#define INF 400000000

// ��������Ʈ���� �� ���  
typedef struct node{
	int v1;
	int v2;
	struct node* next;
} node;

// �ּ���
// 7662���� �����ͼ� long long���� �ٲ���  
long long pop(long long* a, int *l) {
	long long tmp = a[0];
	*l = *l - 1;
	a[0] = a[*l];
	// �� ���� 
	long long t, t1, t2, i = 0;
	while(i < *l) {
		// �ڽ� ��� �ε��� ��� 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= *l) break;
		if(t2 >= *l) { // ���� ��常 �ִ� ��� 
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

long long push(long long x, long long* a, int* l) {
	a[*l] = x;
	*l = *l + 1;
	// �� ���� 
	long long t, t1, i = *l - 1;
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

// �ּ������� ���� ����ϴ� �� -> ������ȣ
// �ּ������� ���� ������ �� -> �Ÿ� 
// ���� �迭�� �ְ� ��ġ���� �����ɸ��ϱ�
// long long���� ��ġ�� �Ÿ� * 1000000 + ������ȣ �� ��� 
int main() {
	int n, e, k; // ����, ���� ����, ��� ���� 
	int d[800]; // ������ �ּ� �̵� �Ÿ�  
	int a1, b1, c1; // �Է¿� �ӽ� ����  
	int m; // ���ͽ�Ʈ�󿡼� �� �ӽ� ����  
	int k1, k2;
	node** arr; // ��������Ʈ �迭  
	node* tn; // ���� ����Ʈ�� �Է°� ����, ���ͽ�Ʈ�󿡼� ����� �ӽ� ����  
	
	// �Է�  
	scanf("%d %d", &n, &e);
	arr = (node**)calloc(n, sizeof(node*)); // ��������Ʈ �迭 �����Ҵ� �� NULL�� �ʱ�ȭ  
	
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &a1, &b1, &c1);
		a1--; b1--; // �Է��� 1���ϵ� �迭�� 0������ 
		// ��������Ʈ�� ���� ��� ������ ����  
		tn = (node*)malloc(sizeof(node));
		tn->v1 = b1;
		tn->v2 = c1;
		tn->next = arr[a1];
		arr[a1] = tn;
		// ��������Ʈ�� ���� ��� ������ ���� (������̹Ƿ� �ݴ���⵵ �ֱ�) 
		tn = (node*)malloc(sizeof(node));
		tn->v1 = a1;
		tn->v2 = c1;
		tn->next = arr[b1];
		arr[b1] = tn;
	} 
	// �߰� ���� ����(A,B) �Է� 
	scanf("%d %d", &k1, &k2);
	k1--; k2--;
	
	// ���ؾ� �ϴ� �Ÿ���
	// 1->A, 1->B, A<->B, A->N, B->N 
	int dSA, dSB, dAB, dAN, dBN; 
	
	long long a[200000], lt;
	int l;
	
	// A���� ���, ���� �ϴ� ��� ���� ���ϱ�  
	// �ּ� �̵� �Ÿ� �迭 �ʱ�ȭ  
	for(int j = 0; j < n; j++) {
		d[j] = INF;
	}
	d[k1] = 0; // ��������� 0����  
	
	// ��� ���� ť�� ����
	l = 0;
	push((long long)0 * 1000000 + k1, a, &l);
	
	// ���ͽ�Ʈ��  
	while(l != 0) {
		// �Ÿ��� �ּ��� ���� ť���� ������  
		lt = pop(a, &l);
		m = lt % 1000000;
		
		// ���� ���� �Ÿ� ���� �� �Ÿ��� �޶��� ���� ť�� ����  
		for(tn = arr[m]; tn != NULL; tn = tn->next) {
			if(d[tn->v1] > d[m] + tn->v2) {
				d[tn->v1] = d[m] + tn->v2;
				push((long long)d[tn->v1] * 1000000 + tn->v1, a, &l);
			}
		}
	}
	
	// �ʿ��� �Ÿ� ����
	dSA = d[0]; dAN = d[n - 1]; dAB = d[k2];
	
	
	// B���� ���, ���� �ϴ� ��� ���� ���ϱ�    
	// �ּ� �̵� �Ÿ� �迭 �ʱ�ȭ  
	for(int j = 0; j < n; j++) {
		d[j] = INF;
	}
	d[k2] = 0; // ��������� 0����  
	
	// ��� ���� ť�� ����
	l = 0;
	push((long long)0 * 1000000 + k2, a, &l);
	
	// ���ͽ�Ʈ��  
	while(l != 0) {
		// �Ÿ��� �ּ��� ���� ť���� ������  
		lt = pop(a, &l);
		m = lt % 1000000;
		
		// ���� ���� �Ÿ� ���� �� �Ÿ��� �޶��� ���� ť�� ����  
		for(tn = arr[m]; tn != NULL; tn = tn->next) {
			if(d[tn->v1] > d[m] + tn->v2) {
				d[tn->v1] = d[m] + tn->v2;
				push((long long)d[tn->v1] * 1000000 + tn->v1, a, &l);
			}
		}
	}
	
	// �ʿ��� �Ÿ� ����
	dSB = d[0]; dBN = d[n - 1];
	
	
	// �Ÿ� ���
	a1 = dSA + dAB + dBN;
	b1 = dSB + dAB + dAN; 
	
	// ���  
	if(a1 >= INF && b1 >= INF) printf("-1");
	else if(a1 < b1) printf("%d", a1);
	else printf("%d", b1);
	
	return 0;
}
