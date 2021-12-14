#include <stdio.h>

int main() {
    int a, b;
    int i = 0;
    int c[26] = { 0, };
    
    scanf("%d %d", &a, &b);
    
    i = 1;
    for(int j = 0; j < b; j++) i *= a - j;
    for(int j = b; j > 1; j--) i /= j;
    
    printf("%d", i);
    return 0;
}