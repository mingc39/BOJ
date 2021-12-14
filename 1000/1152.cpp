#include <stdio.h>

int main() {
    int a, b, c;
    int i = 0;
    a = getchar();
    if(a == ' ') i--;
    while(a != '\n' && a != EOF) {
        if(i == 0) i++;
        if(a == ' ') i++;
        b = a;
        a = getchar();
    }
    if(b == ' ') i--;
    if(i == -1) i = 0;
    printf("%d", i);
    return 0;
}