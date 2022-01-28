#include <stdio.h> 

// �׸� ���� ũ���� parent �迭�� parent[i] = i�� �ʱ�ȭ�ؼ� ���  

// ==========< union-find >==========
int find(int n, int* parent) { // n�� �ִ� ������ ��ǥ��(��Ʈ) ã��   
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}
// ==================================

int main() {
	int G, P, t, i;
	int p[100001];
	
	// ����Ʈ, ����� �� �Է�  
	scanf("%d %d", &G, &P);
	
	// �θ� �迭 �ʱ�ȭ  
	for(i = 0; i <= G; i++) p[i] = i;
	
	// ����� �ޱ�  
	for(i = 0; i < P; i++) {
		scanf("%d", &t); // �Է� 
		if(find(t, p) == 0) break; // ���� �� �ִ� ����Ʈ ������ ������ ������  
		p[find(t, p)]--; // ����Ʈ�� ����� �ޱ� 
	}
	
	// �� ��° �������� �޾Ҵ��� ���  
	printf("%d", i);
	
	return 0;
}
