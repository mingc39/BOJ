#include <stdio.h>

int arr[2097152];
int pow[22];

// ���� �� ����  
void addCandy(int flavor, int number) {
	flavor = flavor + pow[arr[0]]; // ���� ������ ���� ��� ��ġ ���ϱ�  
	arr[flavor] += number; // ���� ��� �� ���� 
	for(int i = flavor / 2; i > 0; i /= 2) { // ����� ���� ��带 �ڼ����� ������ ��� �� ����  
		arr[i] = arr[2 * i] + arr[2 * i + 1];
	} 
}

// n��° ���� ã�Ƽ� ������  
int getCandy(int priority, int index, int level) {
	// ���� ��忡 ������ ���  
	if(level == arr[0]) { 
		// ���� �� -1 ���ְ� �� ��ȯ 
		addCandy(index - pow[arr[0]], -1);
		return index - pow[arr[0]];
	}
	
	// �ڽ� ��� Ž��  
	if(priority > arr[index * 2]) { // (���� �켱 ���� > ���� ��忡 ���Ե� ���� ����) �� ��� ���������� ����  
		return getCandy(priority - arr[index * 2], index * 2 + 1, level + 1);
	} else { // (���� �켱 ���� <= ���� ��忡 ���Ե� ���� ����) �� ��� �������� ����
		return getCandy(priority, index * 2, level + 1);
	}
}

int main() {
	// �ε��� ���� 2�� ���� �̸� ���ϱ�  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	int a, b, c;
	
	// n, m, k�� �Է� 
	scanf("%d", &n);
	
	// ���׸�Ʈ Ʈ�� ���� ���ϱ�  
	arr[0] = 20;
	
	// ��� ����  
	while(n--) {
		// ��� �Է�  
		scanf("%d", &a);
		
		if(a == 2) {  
			// ���� �߰� 
			scanf("%d %d", &b, &c);
			//b--; // �ε����� 0���� ����, �Է��� 1���� ����  
			addCandy(b, c);
			
		} else if(a == 1) { 
			// ���� ���ϱ� 
			scanf("%d", &b);
			printf("%d\n", getCandy(b, 1, 0));
		}
	}
	
	return 0;
}
