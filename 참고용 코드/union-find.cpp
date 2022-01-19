// �׸� ���� ũ���� parent �迭�� parent[i] = i�� �ʱ�ȭ�ؼ� ���  

// ==========< union-find >==========
int find(int n, int* parent) { // n�� �ִ� ������ ��ǥ��(��Ʈ) ã��   
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}

int unionn(int a, int b, int* parent) { // a�� �ִ� ���հ� b�� �ִ� ������ ��ġ�� (union�� ������ unionn���� �߾��)
	return parent[find(b, parent)] = find(a, parent);
}
// ==================================
