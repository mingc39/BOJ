#include <stdio.h>

int main() {
	
	int n;
	
	scanf("%d", &n);
	
	int c, x;
	int p[100];
	int max, end, ord, mxn;
	int i, j;
	int num[10];
	int target;
	int pos;
	
	for(i = 0; i < n; i++) {
		
		scanf("%d %d", &c, &x);
		
		for(j = 0; j < c; j++)
			scanf("%d", &p[j]);
		
		max = 0;
		end = c;
		ord = 0;
		mxn = 0;
		
		//target = p[x];
		
		for(j = 1; j < 10; j++) num[j] = 0;
		for(j = 0; j < end; j++) num[p[j]]++; //num[p[j]] = num[p[j]] + 1;
		
		//for(j = 9; j > target; j--) ord += num[j];
		
		pos = 0; target = 9;
		while(1) {
			if(pos >= end) pos = 0;
			if(target == 0) break;
			while(num[target] == 0 && target > 0) target--;
			
			if(pos == x && target == p[x]) { printf("%d\n", ++ord); break; }
			if(p[pos] == target) { ord++; num[target]--; }
			
			
			pos++;
		}

	}
	
	return 0;
	
}