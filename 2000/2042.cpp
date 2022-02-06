#include <stdio.h>

long long arr[2097152];
long long pow[22];

// �� ���ϱ�(���� Ȯ���� index ��ȣ, ���� index�� ���� ����, ��, ���� ���Ϸ��� ������ ����, ��) 
long long sum(int index, int istart, int iend, int rstart, int rend) { 
	if(istart > rend || iend < rstart) return 0; // index�� ������ ���Ϸ��� ������ ���� ��ġ�� �ʴ� ���  
	else if(rstart <= istart && iend <= rend) return arr[index]; // index�� ���� ��ü�� ���Ϸ��� ������ ���Ե� ���  
	else return sum(index * 2    ,  istart , (istart + iend) / 2, rstart, rend) + // index�� ���� �Ϻθ� ���Ϸ��� ������ ���Ե� ���   
				sum(index * 2 + 1, (istart + iend) / 2 + 1, iend, rstart, rend);  // �ڽ� ��� Ž��  
}

int main() {
	// �ε��� ���� 2�� ���� �̸� ���ϱ�  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	long long a, b, c;
	
	// n, m, k�� �Է� 
	scanf("%d %d %d", &n, &m, &k);
	
	// ���׸�Ʈ Ʈ�� ���� ���ϱ�  
	for(a = 0; a <= 20; a++) if(pow[a] >= n) break;
	arr[0] = a;
	
	// �־��� ���� �Է¹޾� ���� ���� �ֱ�  
	a = pow[a];
	for(b = 0; b < n; b++) {
		scanf("%lld", &c);
		arr[a + b] = c;
	}
	for(; b < a; b++) arr[a + b] = 0; // ���� ���� ��� 0���� ä���  
	
	// ���׸�Ʈ Ʈ�� ����(���� ��� ���� ����� �ö󰡱�) 
	for(int i = arr[0] - 1; i >= 0; i--) {
		for(int j = pow[i]; j < pow[i + 1]; j++) {
			arr[j] = arr[2 * j] + arr[2 * j + 1];
		}
	}
	
	// ��� ����  
	for(int i = 0; i < m + k; i++) {
		// ��� �Է�  
		scanf("%lld %lld %lld", &a, &b, &c);
		
		if(a == 1) {  
			// �� ����
			b--; // �ε����� 0���� ����, �Է��� 1���� ����  
			b = b + pow[arr[0]]; // ���� ������ ���� ��� ��ġ ���ϱ�  
			arr[b] = c; // ���� ��� �� ����  
			for(int j = b / 2; j > 0; j /= 2) { // ����� ���� ��带 �ڼ����� ������ ��� �� ����  
				arr[j] = arr[2 * j] + arr[2 * j + 1];
			}
			
		} else if(a == 2) { 
			// �� ���ϱ� 
			printf("%lld\n", sum(1, 0, pow[arr[0]] - 1, b - 1, c - 1));
		}
	}
	
	return 0;
}
