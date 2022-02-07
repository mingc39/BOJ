#include <stdio.h>

int min[262144];
int max[262144];
int pow[22];

// �ּ� ���ϱ�(���� Ȯ���� index ��ȣ, ���� index�� ���� ����, ��, ���� ���Ϸ��� ������ ����, ��) 
int getMin(int index, int istart, int iend, int rstart, int rend) { 
	if(istart > rend || iend < rstart) return 2147483647; // index�� ������ ���Ϸ��� ������ ���� ��ġ�� �ʴ� ���  
	else if(rstart <= istart && iend <= rend) return min[index]; // index�� ���� ��ü�� ���Ϸ��� ������ ���Ե� ���  
	else {
		int  left = getMin(index * 2    ,  istart , (istart + iend) / 2, rstart, rend);
		int right = getMin(index * 2 + 1, (istart + iend) / 2 + 1, iend, rstart, rend);
		return left < right ? left : right;
	}
}

// �ִ� ���ϱ�(���� Ȯ���� index ��ȣ, ���� index�� ���� ����, ��, ���� ���Ϸ��� ������ ����, ��) 
int getMax(int index, int istart, int iend, int rstart, int rend) { 
	if(istart > rend || iend < rstart) return 0; // index�� ������ ���Ϸ��� ������ ���� ��ġ�� �ʴ� ���  
	else if(rstart <= istart && iend <= rend) return max[index]; // index�� ���� ��ü�� ���Ϸ��� ������ ���Ե� ���  
	else {
		int  left = getMax(index * 2    ,  istart , (istart + iend) / 2, rstart, rend);
		int right = getMax(index * 2 + 1, (istart + iend) / 2 + 1, iend, rstart, rend);
		return left > right ? left : right;
	}
}

int main() {
	// �ε��� ���� 2�� ���� �̸� ���ϱ�  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	int a, b, c;
	
	// n, m�� �Է� 
	scanf("%d %d", &n, &m);
	
	// ���׸�Ʈ Ʈ�� ���� ���ϱ�  
	for(a = 0; a <= 20; a++) if(pow[a] >= n) break;
	min[0] = a;
	max[0] = a;
	
	// �־��� ���� �Է¹޾� ���� ���� �ֱ�  
	a = pow[a];
	for(b = 0; b < n; b++) {
		scanf("%d", &c);
		min[a + b] = c;
		max[a + b] = c;
	}
	for(; b < a; b++) { // ���� ���� ��� 0���� ä���  
		min[a + b] = 0;
		max[a + b] = 0;
	}
	
	// ���׸�Ʈ Ʈ�� ����(���� ��� ���� ����� �ö󰡱�) 
	for(int i = min[0] - 1; i >= 0; i--) {
		for(int j = pow[i]; j < pow[i + 1]; j++) {
			min[j] = min[2 * j] < min[2 * j + 1] ? min[2 * j] : min[2 * j + 1];
			max[j] = max[2 * j] > max[2 * j + 1] ? max[2 * j] : max[2 * j + 1];
		}
	}
	
	// ��� ����  
	for(int i = 0; i < m; i++) {
		// ��� �Է�  
		scanf("%d %d", &a, &b);
		 
			// �ּ�, �ִ� ���ϱ� 
			printf("%d %d\n", getMin(1, 0, pow[min[0]] - 1, a - 1, b - 1), getMax(1, 0, pow[max[0]] - 1, a - 1, b - 1));
	}
	
	return 0;
}

