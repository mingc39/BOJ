#include <stdio.h>
#include <stdlib.h>

// MEM ���� �������� �޸𸮸� �� �����
// MEM ���� �����ؼ� �õ��غ� ��� MEM = 8���� ���� ������  
#define MEM 32
#define MOD 1000000007

typedef struct pair {
	int key;
	int value;
} pair;

int main() {
	int in; 
	
	// ���� ũ�� �Է�  
	scanf("%d", &in);
	
	// ���� �Ҵ�, �ʱ�ȭ  
	pair **a = (pair**)malloc((in + 1) * sizeof(pair));
	a[0] = (pair*)a;
	int *s = (int*)calloc(in + 1, sizeof(int));
	s[0] = in;
	int *l = (int*)calloc(in + 1, sizeof(int));
	
	for(int i = 0; i < s[0]; i++) {
		
		// �Է� 
		scanf("%d", &in);
		
		
		// �߰��� �� ã�� 
		int row = 0;
		{
			int left = 1, right = l[0];
			while(left <= right) {
				int mid = (left + right) / 2;
				if(a[mid][l[mid] - 1].key < in) left = mid + 1;
				else if(left == right) break;
				else right = mid;
			}
			row = left;
		}
		
		
		// �Է�(key)�� ���� �߰��� sum��(value) ã�� 
		int sum = 1;
		if(row > 1) { // ���� �ٿ��� �Էº��� ���� ���� ū �� ã�� 
			int left = 0, right = l[row - 1] - 1;
			while(left < right) {
				int mid = (left + right) / 2;
				if(a[row - 1][mid].key > in) left = mid + 1;
				else right = mid;
			}
			if(a[row - 1][left].key != in) left--;
			if(left >= 0) sum = (a[row - 1][l[row - 1] - 1].value - a[row - 1][left].value + MOD) % MOD; // ���� ����� ������ �� �� �����Ƿ� MOD�� ���������  
			else sum = a[row - 1][l[row - 1] - 1].value;
		} 
		if(l[row] > 0 && a[row][l[row] - 1].key != in) sum = (sum + a[row][l[row] - 1].value) % MOD;
		
		
		// (�Է�, sum) �� �߰��ϱ�
		if(l[row] > 0) { // �ش� row�� �������� key ���� in�� ���� ��� (�Է�, sum) �� �߰� ��� �������� value �� ����  
			if(a[row][l[row] - 1].key == in) {
				a[row][l[row] - 1].value = (a[row][l[row] - 1].value + sum) % MOD;
				continue;
			}
		}
		if(l[row] == s[row]) { // ������ ������ ��� �߰� �Ҵ�  
			if(s[row] == 0) {
				a[row] = (pair*)malloc(MEM * sizeof(pair));
				s[row] = MEM;
			} else {
				s[row] += MEM;
				a[row] = (pair*)realloc(a[row], s[row] * sizeof(pair));
			}
		}
		a[row][l[row]].key = in;
		a[row][l[row]].value = sum;
		l[row]++;
		if(l[0] < row) l[0] = row;
	}
	
	// ��� ���  
	printf("%d %d", l[0], a[l[0]][l[l[0]] - 1].value); // ���� ������ row ��ȣ = ����, ���� ������ row�� ������ value = ����  
	
	return 0;
}
