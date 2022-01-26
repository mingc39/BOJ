#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k; // ���� ����, �ִ� ���� 
    int *w, *v; // ���Ǻ� ����, ���Ǻ� ��ġ 
    int *a, *b, *t;

    // ���� ����, �ִ� ���� �Է� 
    scanf("%d %d", &n, &k);

    // ���� �Ҵ� 
    w = (int*)malloc(sizeof(int) * (n + 1));
    v = (int*)malloc(sizeof(int) * (n + 1));
    //a = (int**)malloc(sizeof(int*) * (n + 1));
    

    // ���Ǻ� ����, ��ġ �Է� 
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    
    // 12865 ����� �賶 -> �賶 ���� ���Ϸ� �ִ� ��ġ
	//  7579 �� -> �ʿ� �뷮 �̻����� �ּ� ���
	// "�ʿ� �뷮 �̻����� �ּ� ���"�� "��ü-�ʿ����Ϸ� �ִ���"����
	// �ٲ㼭 Ǯ�� ��ü��� - ���Ѻ�� ���  
	
	// ��ü �뷮, ��� ���ϰ� k�� �����ϱ�  
    int tw = 0, tv = 0;
    for (int i = 1; i <= n; i++) {
    	tw += w[i];
		tv += v[i];
	} 
	k = tw - k;
	
	// ���� �Ҵ�  
	// ������ k���� ����ǹǷ� �� ó���� �����Ҵ� �Ұ�
	// a[n + 1][k + 1]�� �ϸ� �ִ� �޸� 4�Ⱑ ��� (10M * 100 * 4 = 4G)
	// a[i]������ a[i], a[i - 1]�� ����ϹǷ� �� ���� �� �ٸ� ����  
    a = (int*)calloc(k + 1, sizeof(int));
    b = (int*)malloc((k + 1) * sizeof(int));
    a[0] = 0; b[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i] > j) b[j] = a[j];
            else b[j] = a[j] > v[i] + a[j - w[i]] ? a[j] : v[i] + a[j - w[i]];
        }
        t = a;
        a = b;
        b = t;
    } 

    // ��� ��� 
    printf("%d", tv - a[k]);

    return 0;
}
