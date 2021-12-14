#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int N, p[10], l;
	long long t, num[10] = { 0, };

	scanf("%d", &N);
	for (t = N, l = 0; t > 0; t /= 10) {
		p[l++] = t % 10;
	}

	{
		int i = 0;
		for (int j = 0; j < l - 1; j++) {
			if (p[j] > i) {
				t = 0;
				for (int k = l - 1; k > -1; k--) {
					if (k == j) continue;
					if (k > j) t = t * 10 + p[k];
					else t = t * 10;
				}
			}
			else {
				t = 0;
				for (int k = l - 1; k > -1; k--) {
					if (k == j) {
						t--;
						continue;
					}
					t = t * 10 + p[k];
				}
				t++;
			}

			num[i] += t;
			//printf("%d ", t);
		}
		//printf("\n");
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < l; j++) {
			if (p[j] < i) {
				t = 0;
				for (int k = l - 1; k > -1; k--) {
					if (k == j) continue;
					if (k > j) t = t * 10 + p[k];
					else t = t * 10;
				}
			}
			else if (p[j] > i) {
				t = 0;
				for (int k = l - 1; k > -1; k--) {
					if (k == j) continue;
					if (k > j) t = t * 10 + p[k];
					else t = t * 10 + 9;
				}
				t++;
			}
			else {
				t = 0;
				for (int k = l - 1; k > -1; k--) {
					if (k == j) continue;
					t = t * 10 + p[k];
				}
				t++;
			}
			
			num[i] += t;
			//printf("%d ", t);
		}
		//printf("\n");


	}

	printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], num[9]);

	return 0;
}