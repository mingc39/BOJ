#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
	int r, c, t;
	int **cur, **nxt, **tmp;
	int cux = -1, cuy, cdx, cdy, cnt;
	
	scanf("%d %d %d", &r, &c, &t);
	
	cur = (int**)malloc(sizeof(int*) * r);
	cur[0] = (int*)malloc(sizeof(int) * r * c);
	for(int i = 1; i < r; i++) cur[i] = cur[i - 1] + c;
	nxt = cur;
	cur = (int**)malloc(sizeof(int*) * r);
	cur[0] = (int*)malloc(sizeof(int) * r * c);
	for(int i = 1; i < r; i++) cur[i] = cur[i - 1] + c;
	
	// �Է�  
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			scanf("%d", &cur[i][j]);
			if(cur[i][j] == -1) {
				if(cux == -1) {
					cux = i;
					cuy = j;
				} else {
					cdx = i;
					cdy = j;
				}
			}
		}
	}
	
	while(t-- > 0) {
		// ���� ���� �迭 �ʱ�ȭ 
		memset(nxt[0], 0, sizeof(int) * r * c);
		
		// ���� Ȯ��
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				// �ش� ��ġ�� ������ ������ ���  
				if(cur[i][j] <= 0) continue;
				
				// �ش� ��ġ�� ������ ������ Ȯ��  
				cnt = 0;
				if(i - 1 >= 0) { // ���� Ȯ��  
					if(cur[i - 1][j] >= 0) {
						nxt[i - 1][j] += cur[i][j] / 5; 
						cnt++; 
					}
				}
				if(i + 1 < r) { // �Ʒ��� Ȯ�� 
					if(cur[i + 1][j] >= 0) {
						nxt[i + 1][j] += cur[i][j] / 5;
						cnt++; 
					}
				}
				if(j - 1 >= 0) { // �������� Ȯ��  
					if(cur[i][j - 1] >= 0) {
						nxt[i][j - 1] += cur[i][j] / 5; 
						cnt++; 
					}
				}
				if(j + 1 < c) { // ���������� Ȯ��  
					if(cur[i][j + 1] >= 0) {
						nxt[i][j + 1] += cur[i][j] / 5; 
						cnt++; 
					}
				}
				nxt[i][j] += cur[i][j] - cur[i][j] / 5 * cnt; // Ȯ��ǰ� ���� ���� 
			}
		} 
		
		// ���� û���� ��ġ ����  
		nxt[cux][cuy] = -1;
		nxt[cdx][cdy] = -1;
		
		// ���� û���⿡ ���� ���� �̵� 
		int pv = 0, nv;
		
		// ���� û���� ���κ� 
		pv = 0;
		for(int i = cuy + 1; i <= c - 1; i++) { // ���������� �̵�  
			nv = nxt[cux][i];
			nxt[cux][i] = pv;
			pv = nv;
		}
		for(int i = cux - 1; i >= 0; i--) { // ���� �̵�  
			nv = nxt[i][c - 1];
			nxt[i][c - 1] = pv;
			pv = nv;
		}
		for(int i = c - 2; i >= 0; i--) { // �������� �̵�  
			nv = nxt[0][i];
			nxt[0][i] = pv;
			pv = nv;
		}
		for(int i = 1; i < cux; i++) { // �Ʒ��� �̵�  
			nv = nxt[i][0];
			nxt[i][0] = pv;
			pv = nv;
		}
		
		// ���� û���� �Ʒ��κ� 
		pv = 0;
		for(int i = cdy + 1; i < c; i++) { // ���������� �̵�  
			nv = nxt[cdx][i];
			nxt[cdx][i] = pv;
			pv = nv;
		}
		for(int i = cdx + 1; i <= r - 1; i++) { // �Ʒ��� �̵�  
			nv = nxt[i][c - 1];
			nxt[i][c - 1] = pv;
			pv = nv;
		}
		for(int i = c - 2; i >= 0; i--) { // �������� �̵�  
			nv = nxt[r - 1][i];
			nxt[r - 1][i] = pv;
			pv = nv;
		}
		for(int i = r - 2; i > cdx; i--) { // ���� �̵�  
			nv = nxt[i][0];
			nxt[i][0] = pv;
			pv = nv;
		}
		
		// �� ���� ������ ���� ��ġ ������ �̵�  
		tmp = cur;
		cur = nxt;
		nxt = tmp;
	}
	
	// ��ü ���� �� ���  
	cnt = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(cur[i][j] > 0) cnt += cur[i][j];
		}
	}
	
	// ��� 
	printf("%d", cnt);
	
	return 0;
}
