#include <stdio.h>

int min[262144];
int pow[22];

// �ּ� ���ϱ�(���� Ȯ���� index ��ȣ, ���� index�� ���� ����, ��, ���� ���Ϸ��� ������ ����, ��) 
int getMin(int index, int istart, int iend, int rstart, int rend) { 
	if(istart == iend && rstart <= istart && iend <= rend) return index;
	else if(istart > rend || iend < rstart) return -1; // index�� ������ ���Ϸ��� ������ ���� ��ġ�� �ʴ� ���  
	else if(rstart <= istart && iend <= rend) return min[index]; // index�� ���� ��ü�� ���Ϸ��� ������ ���Ե� ���  
	else {
		int  left = getMin(index * 2    ,  istart , (istart + iend) / 2, rstart, rend);
		int right = getMin(index * 2 + 1, (istart + iend) / 2 + 1, iend, rstart, rend);
		if(right == -1 && left == -1) return -1;
		else if(right == -1) return left;
		else if(left == -1) return right;
		else return min[left] <= min[right] ? left : right;
	}
}

int main() {
	// �ε��� ���� 2�� ���� �̸� ���ϱ�  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	int a, b, c;
	
	// ���� ���� �Է� 
	scanf("%d", &n);
	
	// ���׸�Ʈ Ʈ�� ���� ���ϱ�  
	for(a = 0; a <= 20; a++) if(pow[a] >= n) break;
	min[0] = a;
	
	// �־��� ���� �Է¹޾� ���� ���� �ֱ�  
	a = pow[a];
	for(b = 0; b < n; b++) {
		scanf("%d", &c);
		min[a + b] = c;
	}
	for(; b < a; b++) { // ���� ���� ��� 0���� ä���  
		min[a + b] = 2147483647;
	}
	
	// ���׸�Ʈ Ʈ�� ����(���� ��� ���� ����� �ö󰡱�) 
	if(min[0] - 1 >= 0) {
		for(int j = pow[min[0] - 1]; j < pow[min[0]]; j++) {
			min[j] = min[2 * j] <= min[2 * j + 1] ? 2 * j : 2 * j + 1;
		}
	}
	for(int i = min[0] - 2; i >= 0; i--) {
		for(int j = pow[i]; j < pow[i + 1]; j++) {
			min[j] = min[min[2 * j]] <= min[min[2 * j + 1]] ? min[2 * j] : min[2 * j + 1];
		}
	}
	
	// ��� �� �Է�  
	scanf("%d", &m);
	
	// ��� ����  
	for(int i = 0; i < m; i++) {
		// ��� �Է�  
		scanf("%d %d %d", &a, &b, &c);
		
			// �� ����
			if(a == 1) {
				b--;
				b = b + pow[min[0]];
				min[b] = c;
				if(b / 2 > 0) {
					min[b / 2] = min[2 * (b / 2)] <= min[2 * (b / 2) + 1] ? 2 * (b / 2) : 2 * (b / 2) + 1;
				}
				for(int j = b / 4; j > 0; j /= 2) { // ����� ���� ��带 �ڼ����� ������ ��� �� ����  
					min[j] = min[min[2 * j]] <= min[min[2 * j + 1]] ? min[2 * j] : min[2 * j + 1];
				}
			} 
			
			// �ּ� �ε��� ���ϱ� 
			else if(a == 2) printf("%d\n", getMin(1, 0, pow[min[0]] - 1, b - 1, c - 1) - pow[min[0]] + 1);
	}
	
	return 0;
}

