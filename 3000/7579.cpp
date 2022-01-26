#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k; // 물건 개수, 최대 무게 
    int *w, *v; // 물건별 무게, 물건별 가치 
    int *a, *b, *t;

    // 물건 개수, 최대 무게 입력 
    scanf("%d %d", &n, &k);

    // 동적 할당 
    w = (int*)malloc(sizeof(int) * (n + 1));
    v = (int*)malloc(sizeof(int) * (n + 1));
    //a = (int**)malloc(sizeof(int*) * (n + 1));
    

    // 물건별 무게, 가치 입력 
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    
    // 12865 평범한 배낭 -> 배낭 무게 이하로 최대 가치
	//  7579 앱 -> 필요 용량 이상으로 최소 비용
	// "필요 용량 이상으로 최소 비용"을 "전체-필요이하로 최대비용"으로
	// 바꿔서 풀고 전체비용 - 구한비용 출력  
	
	// 전체 용량, 비용 구하고 k값 변경하기  
    int tw = 0, tv = 0;
    for (int i = 1; i <= n; i++) {
    	tw += w[i];
		tv += v[i];
	} 
	k = tw - k;
	
	// 동적 할당  
	// 위에서 k값이 변경되므로 맨 처음에 동적할당 불가
	// a[n + 1][k + 1]로 하면 최대 메모리 4기가 사용 (10M * 100 * 4 = 4G)
	// a[i]에서는 a[i], a[i - 1]만 사용하므로 맨 끝에 두 줄만 저장  
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

    // 결과 출력 
    printf("%d", tv - a[k]);

    return 0;
}
