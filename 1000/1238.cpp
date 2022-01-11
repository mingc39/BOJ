#include <stdio.h>
#include <stdlib.h>

#define INF 250000

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
	int n, e, x; // ����, ���� ���� 
	int d[1024], r[1024]; // ������ �ּ� �̵� �Ÿ�  
	int a1, b1, c1; // �Է¿� �ӽ� ����  
	int m; // ���ͽ�Ʈ�󿡼� �� �ӽ� ����  
	node** arr; // ��������Ʈ �迭  
	node** rev; // ��������Ʈ �迭  
	node* tn; // ���� ����Ʈ�� �Է°� ����, ���ͽ�Ʈ�󿡼� ����� �ӽ� ����  
	
	// �Է�  
	scanf("%d %d %d", &n, &m, &x); 
	x--; // �Է��� 1���ϵ� �迭�� 0������
	arr = (node**)calloc(n, sizeof(node*)); // ��������Ʈ �迭 �����Ҵ� �� NULL�� �ʱ�ȭ  
	rev = (node**)calloc(n, sizeof(node*)); // ��������Ʈ �迭 �����Ҵ� �� NULL�� �ʱ�ȭ  
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &a1, &b1, &c1);
		a1--; b1--; // �Է��� 1���ϵ� �迭�� 0������ 
		// ��������Ʈ�� ���� ��� ������ ����  
		tn = (node*)malloc(sizeof(node));
		tn->v1 = b1;
		tn->v2 = c1;
		tn->next = arr[a1];
		arr[a1] = tn;
		// ��������Ʈ�� ���� ��� ������ ����  
		tn = (node*)malloc(sizeof(node));
		tn->v1 = a1;
		tn->v2 = c1;
		tn->next = rev[b1];
		rev[b1] = tn;
	}
	
	// �ּ� �̵� �Ÿ� �迭 �ʱ�ȭ  
	for(int j = 0; j < n; j++) {
		d[j] = INF;
	}
	d[x] = 0; // ��������� 0����  
	
	// ��� ���� ť�� ����  
	long long a[200000], lt;
	int l = 0;
	push((long long)0 * 1000000 + x, a, &l);
	
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
	
	// �ּ� �̵� �Ÿ� �迭 �ʱ�ȭ  
	for(int j = 0; j < n; j++) {
		r[j] = INF;
	}
	r[x] = 0; // ��������� 0����  
	
	// ��� ���� ť�� ����  
	l = 0;
	push((long long)0 * 1000000 + x, a, &l);
	
	// ���ͽ�Ʈ��  
	while(l != 0) {
		// �Ÿ��� �ּ��� ���� ť���� ������  
		lt = pop(a, &l);
		m = lt % 1000000;
		
		// ���� ���� �Ÿ� ���� �� �Ÿ��� �޶��� ���� ť�� ����  
		for(tn = rev[m]; tn != NULL; tn = tn->next) {
			if(r[tn->v1] > r[m] + tn->v2) {
				r[tn->v1] = r[m] + tn->v2;
				push((long long)r[tn->v1] * 1000000 + tn->v1, a, &l);
			}
		}
	}
	
	// �ִ� ���  
	int max = 0;
	for(int i = 0; i < n; i++)
		if(d[i] < INF && r[i] < INF && max < d[i] + r[i])
			max = d[i] + r[i];
	
	// ���  
	printf("%d", max);
	
	return 0;
}