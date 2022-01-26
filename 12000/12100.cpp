#include <stdio.h> 

// �迭 ����  
void copy(int dst[20][20], int src[20][20], int size) {
	for(int i = 0; i < size; i++) 
		for(int j = 0; j < size; j++)
			dst[i][j] = src[i][j];
}

// �迭 ���  
void print(int n, int a[20][20]) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", a[i][j]);
		putchar('\n');
	}
}

// �������� �̵�  
void move_l(int n, int a[20][20]) {
	// �� �����ٺ��� ����  
	for(int i = 0; i < n; i++) {
		
		// �ʱ�ȭ  
		int l = 0, m = 0;
		if(a[i][0] == 0) l = -1; // �� ù ĭ�� �񿴴��� Ȯ��  
		
		// �� ĭ ���� �̵�  
		for(int j = 1; j < n; j++) {
			
			// �� ĭ�� ���  
			if(a[i][j] == 0) continue;
			
			// ù ĭ�� �� ���  
			if(l < 0) {
				a[i][0] = a[i][j];
				a[i][j] = 0;
				l = 0;
			} else {
				// ��ĥ �� �ִ� ���(= ���ڰ� �����鼭 ������ ������ ���� ����) 
				if(a[i][l] == a[i][j] && m == 0) {
					a[i][l] *= 2;
					a[i][j] = 0;
					m = 1;
				// �̵��� �� ���� ���(=���� ĭ �ٷ� �ձ��� ��ĥ �� ���� ĭ�� ����) 
				} else if(l + 1 == j) {
					m = 0;
					l++;
				// ��ġ�� �ʰ� �̵��ϴ� ���  
				} else {
					m = 0;
					l++;
					a[i][l] = a[i][j];
					a[i][j] = 0;
				}
			}
		}
	}
}

// ���������� �̵�
void move_r(int n, int a[20][20]) {
	// ������ ������ ������ move_l�� ����  
	for(int i = 0; i < n; i++) {
		
		int l = n - 1, m = 0;;
		if(a[i][l] == 0) l = -1;
		
		for(int j = n - 2; j >= 0; j--) {
			
			if(a[i][j] == 0) continue;
			
			if(l < 0) {
				l = n - 1;
				a[i][l] = a[i][j];
				a[i][j] = 0;
			} else {
				if(a[i][l] == a[i][j] && m == 0) {
					a[i][l] *= 2;
					a[i][j] = 0;
					m = 1;
				} else if(l - 1 == j) {
					m = 0;
					l--;
				} else {
					m = 0;
					l--;
					a[i][l] = a[i][j];
					a[i][j] = 0;
				}
			}
		}
	}
}

// ���� �̵�  
void move_u(int n, int a[20][20]) {
	// ������ ������ ������ move_l�� ����
	for(int i = 0; i < n; i++) {
		
		int l = 0, m = 0;
		if(a[l][i] == 0) l = -1;
		
		for(int j = 1; j < n; j++) {
			
			if(a[j][i] == 0) continue;
			
			if(l < 0) {
				l = 0;
				a[l][i] = a[j][i];
				a[j][i] = 0;
			} else {
				if(a[l][i] == a[j][i] && m == 0) {
					a[l][i] *= 2;
					a[j][i] = 0;
					m = 1;
				} else if(l + 1 == j) {
					m = 0;
					l++;
				} else {
					m = 0;
					l++;
					a[l][i] = a[j][i];
					a[j][i] = 0;
				}
			}
		}
	}
}

// �Ʒ��� �̵�  
void move_d(int n, int a[20][20]) {
	// ������ ������ ������ move_l�� ����
	for(int i = 0; i < n; i++) {
		
		int l = n - 1, m = 0;
		if(a[l][i] == 0) l = -1;
		
		for(int j = n - 2; j >= 0; j--) {
			
			if(a[j][i] == 0) continue;
			
			if(l < 0) {
				l = n - 1;
				a[l][i] = a[j][i];
				a[j][i] = 0;
			} else {
				if(a[l][i] == a[j][i] && m == 0) {
					a[l][i] *= 2;
					a[j][i] = 0;
					m = 1;
				} else if(l - 1 == j) {
					m = 0;
					l--;
				} else {
					m = 0;
					l--;
					a[l][i] = a[j][i];
					a[j][i] = 0;
				}
			}
		}
	}
}

// �����¿� �������� �̵���Ű��  
int f(int n, int a[20][20], int l) {
	// 5�� �̵��� ��� ���� �����ǿ��� �ִ밪 ��ȯ  
	if(l == 5) {
		int max = 0;
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++)
				if(max < a[i][j]) max = a[i][j];
		return max;
	}
	
	// 5�� �̵����� ���� ��� �����¿�� �̵��ϰ� ������ �ִ밪 �� �ִ밪 ��ȯ  
	int ta[20][20], tv, max = 0;
	l++;
	
	// ����  
	copy(ta, a, n);
	move_l(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	// ������ 
	copy(ta, a, n);
	move_r(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	// ��  
	copy(ta, a, n);
	move_u(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	// �Ʒ�  
	copy(ta, a, n);
	move_d(n, ta);
	tv = f(n, ta, l);
	if(max < tv) max = tv;
	
	return max;
}

int main() {
	int n, a[20][20];
	
	// �Է�  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	
	// ��� ���  
	printf("%d", f(n, a, 0));
	
	return 0;
}
