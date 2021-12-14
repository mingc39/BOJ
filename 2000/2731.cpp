#include <stdio.h>
#include <string.h>

int main() {

	int T, k, l, c, i;
	char S[20], X[20];
	long long t, x, p10;
	scanf("%d", &T);

	while (T > 0) {

		scanf("%s", S);
		l = strlen(S);
		for (i = 0; i < l; i++) {
			S[i] = S[i] - '0';
		}

		k = l - 1;
		if (S[k] == 7) X[k] = 3;
		else if (S[k] == 3) X[k] = 7;
		else X[k] = S[k];
		x = X[k];
		c = (3* X[k] * X[k]) % 10;
		
		p10 = 100;
		for (k--; k >= 0; k--) {
			t = x;
			t = (t * t) % p10;
			t = (t * (long long)x) % p10;
			t = t / (p10 / 10);

			t = S[k] - t;
			if (t < 0) t += 10;

			for (i = 0; i < 10; i++) {
				if (((c * i) % 10) == t) break;
			}
			X[k] = i;
			x = x + (p10 / 10) * i;

			p10 *= 10;
		}

		printf("%lld\n", x);

		T--;
	}

	return 0;
}