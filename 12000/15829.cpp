#include <stdio.h>

#define STRING_SIZE 100
#define HASH_R 31
#define HASH_M 1234567891

int main() {
	
	int l;
	char s[STRING_SIZE];
	
	scanf("%d", &l);
	scanf("%s", s);
	
	long long r = 1;
	long long m = HASH_M;
	long long h = 0;
	
	for(int i = 0; i < l; i++) {
		h += ((s[i] - 'a' + 1) * r) % m;
		r *= HASH_R;
		r %= m;
	}
	
	printf("%d", h % m);
	
	return 0;
}