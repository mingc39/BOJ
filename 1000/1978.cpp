#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    int i = 0;
    int c = 0;
    
    scanf("%d", &a);
    
    for(int j = 0; j < a; j++) {
    	scanf("%d", &b);
    	if(b < 2) continue;
    	if(b == 2) { i++; continue; }
    	if(b % 2 == 0) continue;
    	c = 0;
    	for(int k = 3; k <= sqrt(b); k += 2)
    		if(b % k == 0) { c = 1; break; }
    	if(c != 1) i++;
	}
    
    printf("%d", i);
    return 0;
}