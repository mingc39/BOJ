#include <stdio.h>

// �ּ��� �ڵ�
// 1927 �ּ� ��,  1715 ī�� �����ϱ⿡�� ������� �ڵ� 
// root�� ���� �߰� 
int pop(int* a, int *l) {
	int tmp = a[0];
	*l = *l - 1;
	a[0] = a[*l];
	// �� ���� 
	int t, t1, t2, i = 0;
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

int push(int x, int* a, int* l) {
	a[*l] = x;
	*l = *l + 1;
	// �� ���� 
	int t, t1, i = *l - 1;
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

int root(int *a, int *l) {
	return a[0];
}

void print(int *a, int *l) {
	for(int i = 0; i < *l; i++) printf("%2d: %4d\n", i, a[i]);
}

// �� ����
// �������� ���ϸ� Dev-C++���� �������� 
int minQ[1000000], minQl = 0; // �ּ� �� 
int minD[1000000], minDl = 0; // �ּ� ������ �����Ȱ� ��Ƶδ� �ּ� �� 
int maxQ[1000000], maxQl = 0; // �ִ� �� 
int maxD[1000000], maxDl = 0; // �ִ� ������ �����Ȱ� ��Ƶδ� �ִ� ��

// �ּ� ���� �ִ� ������ ��ȯ 
// ������ int ��ü�� �׳� ��� <-> ������ ��ȯ�ϸ� -2147483648���� ���� 
int convert(int t) {
	if(t != -2147483648) return -t - 1;
	else return 2147483647;
}

// �ֱ� 
int pushN(int x) {
	push(         x, minQ, &minQl);
	push(convert(x), maxQ, &maxQl);
	return x;
}

// ���� ������ ������ 
int popMin() {
	if(minQl == 0) return 0;
	int t = pop(minQ, &minQl);
	// ������ �����Ȱ��̸�(=�ּһ������� ������) ������ �ٽ� ������ 
	while(t == root(minD, &minDl) && minDl != 0) {
		pop(minD, &minDl);
		if(minQl == 0) return 0;
		t = pop(minQ, &minQl);
	}
	push(convert(t), maxD, &maxDl);
	return t;
}

// ���� ū�� ������ 
int popMax() {
	if(maxQl == 0) return 0;
	int t = pop(maxQ, &maxQl);
	// ������ �����Ȱ��̸�(=�ִ�������� ������) ������ �ٽ� ������ 
	while(t == root(maxD, &maxDl) && maxDl != 0) {
		pop(maxD, &maxDl);
		if(maxQl == 0) return 0;
		t = pop(maxQ, &maxQl);
	}
	push(convert(t), minD, &minDl);
	return convert(t);
}

int main() {
	int t, k;
	int arg, num;
	char ins;
	
	for(scanf("%d", &t); t > 0; t--) {
		minQl = 0; minDl = 0;
		maxQl = 0; maxDl = 0;
		for(scanf("%d", &k); k > 0; k--) {
			scanf(" %c %d", &ins, &arg);
			if(ins == 'I') {
				pushN(arg);
			} else if(ins == 'D') {
				if(arg == 1) {
					popMax();
				} else if(arg == -1) {
					popMin();
				}
			}
		}
		// �ִ� ��, �ּ� ���� ����ų� �ִ�/�ּһ������̶� ũ�� ������ EMPTY 
		if(minQl == 0 || maxQl == 0 || minQl == minDl || maxQl == maxDl)
			printf("EMPTY\n");
		else {
			num = popMax();
			printf("%d ", num);
			pushN(num); // ���� �б⸸ ���� �ʰ� �ƾ� �������� �ٽ� �־������ 
			printf("%d\n", popMin());
		}
	}
	
	return 0;
}
