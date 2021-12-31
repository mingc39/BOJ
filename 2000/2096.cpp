#include <stdio.h> 

int main() {
	int n, a, b, c;
	int min[3] = {0, 0, 0};
	int max[3] = {0, 0, 0};
	int t[3];
	
	// 전체 줄 수 입력  
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		// 현재 줄 입력 
		scanf("%d %d %d", &a, &b, &c);
		
		// 최댓값 계산  
		if(max[0] > max[1]) t[0] = max[0] + a;
		else t[0] = max[1] + a;
		
		if(max[0] > max[1] && max[0] > max[2]) t[1] = max[0] + b;
		else if(max[1] > max[2]) t[1] = max[1] + b;
		else t[1] = max[2] + b;
		
		if(max[2] > max[1]) t[2] = max[2] + c;
		else t[2] = max[1] + c;
		
		max[0] = t[0]; max[1] = t[1]; max[2] = t[2];
		
		// 최솟값 계산 
		if(min[0] < min[1]) t[0] = min[0] + a;
		else t[0] = min[1] + a;
		
		if(min[0] < min[1] && min[0] < min[2]) t[1] = min[0] + b;
		else if(min[1] < min[2]) t[1] = min[1] + b;
		else t[1] = min[2] + b;
		
		if(min[2] < min[1]) t[2] = min[2] + c;
		else t[2] = min[1] + c;
		
		min[0] = t[0]; min[1] = t[1]; min[2] = t[2];
	}
	
	// 최대값 계산 
	if(max[0] > max[1] && max[0] > max[2]) t[0] = max[0];
	else if(max[1] > max[2]) t[0] = max[1];
	else t[0] = max[2];
	
	// 최솟값 계산 
	if(min[0] < min[1] && min[0] < min[2]) t[1] = min[0];
	else if(min[1] < min[2]) t[1] = min[1];
	else t[1] = min[2];
	
	// 출력  
	printf("%d %d", t[0], t[1]);
	
	return 0;
}
