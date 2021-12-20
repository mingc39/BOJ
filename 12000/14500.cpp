#include <stdio.h>

int main() {
	int n, m, a[500][500];
	
	// 입력  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	
	// 변수 초기화  
	int tmp, sum, max = 0;
	
	// 탐색  
	// 1x4
	for(int i = 0; i < n - 3; i++)
		for(int j = 0; j < m; j++) {
			sum  = a[i    ][j];
			sum += a[i + 1][j];
			sum += a[i + 2][j];
			sum += a[i + 3][j];
			if(sum > max) max = sum;
		}
	
	//4x1
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m - 3; j++) {
			sum  = a[i][j    ];
			sum += a[i][j + 1];
			sum += a[i][j + 2];
			sum += a[i][j + 3];
			if(sum > max) max = sum;
		}
	
	// 2x2
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < m - 1; j++) {
			sum  = a[i    ][j    ];
			sum += a[i    ][j + 1];
			sum += a[i + 1][j    ];
			sum += a[i + 1][j + 1];
			if(sum > max) max = sum;
		}
	
	// 2x3
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < m - 2; j++) {
			tmp  = a[i    ][j    ];
			tmp += a[i    ][j + 1];
			tmp += a[i    ][j + 2];
			tmp += a[i + 1][j    ];
			tmp += a[i + 1][j + 1];
			tmp += a[i + 1][j + 2];
			
			sum = tmp - a[i + 1][j    ] - a[i + 1][j + 1];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j + 1] - a[i    ][j + 2];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j    ] - a[i    ][j + 1];
			if(sum > max) max = sum;
			
			sum = tmp - a[i + 1][j + 1] - a[i + 1][j + 2];
			if(sum > max) max = sum;
			
			sum = tmp - a[i + 1][j    ] - a[i    ][j + 2];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j    ] - a[i + 1][j + 2];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j    ] - a[i    ][j + 2];
			if(sum > max) max = sum;
			
			sum = tmp - a[i + 1][j    ] - a[i + 1][j + 2];
			if(sum > max) max = sum;
		}
	
	// 3x2
	for(int i = 0; i < n - 2; i++)
		for(int j = 0; j < m - 1; j++) {
			tmp  = a[i    ][j    ];
			tmp += a[i    ][j + 1];
			tmp += a[i + 1][j    ];
			tmp += a[i + 1][j + 1];
			tmp += a[i + 2][j    ];
			tmp += a[i + 2][j + 1];
			
			sum = tmp - a[i    ][j + 1] - a[i + 1][j + 1];
			if(sum > max) max = sum;
			
			sum = tmp - a[i + 1][j    ] - a[i + 2][j    ];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j    ] - a[i + 1][j    ];
			if(sum > max) max = sum;
			
			sum = tmp - a[i + 1][j + 1] - a[i + 2][j + 1];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j + 1] - a[i + 2][j    ];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j    ] - a[i + 2][j + 1];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j    ] - a[i + 2][j    ];
			if(sum > max) max = sum;
			
			sum = tmp - a[i    ][j + 1] - a[i + 2][j + 1];
			if(sum > max) max = sum;
		}
	
	// 출력 
	printf("%d", max);
	
	return 0;
}
