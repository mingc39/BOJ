#include <stdio.h>

int main() {
	int n, x;
	int i, t, t1, t2;
	int a[100000], l = 0;
	
	for(scanf("%d", &n); n > 0; n--) {
		scanf("%d", &x);
		
		if(x == 0) {
			if(l == 0) printf("0\n");
			else {
				printf("%d\n", a[0]);
				a[0] = a[--l];
				// �� ���� 
				i = 0;
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
			}
		} else {
			a[l++] = x;
			// �� ���� 
			i = l - 1;
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
			//putchar('\n');
			//for(int i = 0; i < l; i++) printf("%2d: %d\n", i, a[i]);
		}
	}
	
	return 0;
}
