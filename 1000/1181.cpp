#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _String {
	char string[55];
	int length;
} String;

int compare(const void *a, const void *b) {
    String i = *(String *)a;
    String j = *(String *)b;
    
    if(i.length < j.length) return -1;
    if(i.length > j.length) return 1;
    for(int k = 0; k < i.length; k++) {
    	if(i.string[k] < j.string[k]) return -1;
    	if(i.string[k] > j.string[k]) return 1;
	}
    return 0;
}

int main() {
	int n;
	String string[20000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", string[i].string);
		string[i].length = strlen(string[i].string);
	}
	qsort(string, n, sizeof(String), compare);
	// 같은건 생 략 
	int r = -1;
	for(int i = 0; i < n; i++) {
		if(r >= 0) 
			if(compare((void*) string[i].string, (void*) string[r].string) == 0) continue;
		printf("%s\n", string[i].string);
		r = i;
	}
	//for(int i = 0; i < n; i++) printf("%2d:%s\n", string[i].length, string[i].string);
	return 0;
}