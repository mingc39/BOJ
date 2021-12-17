#include <stdio.h>

// 최소힙 코드
// 1927 최소 힙,  1715 카드 정렬하기에서 만들었던 코드 
// root는 새로 추가 
int pop(int* a, int *l) {
	int tmp = a[0];
	*l = *l - 1;
	a[0] = a[*l];
	// 힙 갱신 
	int t, t1, t2, i = 0;
	while(i < *l) {
		// 자식 노드 인덱스 계산 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= *l) break;
		if(t2 >= *l) { // 왼쪽 노드만 있는 경우 
			if(a[t1] < a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // 둘 다 있는 경우 
			if(a[t1] < a[i] && a[t1] <= a[t2]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
			if(a[t2] < a[i] && a[t2] < a[t1]) {
				t = a[t2];
				a[t2] = a[i];
				a[i] = t;
				i = t2;
				continue;
			}
		}
		// 더 작은 자식 노드 없으면 갱신 완료
		break; 
	}
	return tmp;
}

int push(int x, int* a, int* l) {
	a[*l] = x;
	*l = *l + 1;
	// 힙 갱신 
	int t, t1, i = *l - 1;
	while(i > 0) {
		// 부모 노드 인덱스 계산
		t1 = (i - 1) / 2;
		// 부모 노드 비교
		if(t1 >= 0) {
			if(a[t1] > a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
		}
		// 부모 노드가 더 작으면 갱신 완료
		break; 
	}
	return x;
}

int root(int *a, int *l) {
	return a[0];
}

void print(int *a, int *l) {
	for(int i = 0; i < *l; i++) printf("%2d: %4d\n", i, a[i]);
}

// 힙 선언
// 전역으로 안하면 Dev-C++에서 뻑남ㄷㄷ 
int minQ[1000000], minQl = 0; // 최소 힙 
int minD[1000000], minDl = 0; // 최소 힙에서 삭제된거 모아두는 최소 힙 
int maxQ[1000000], maxQl = 0; // 최대 힙 
int maxD[1000000], maxDl = 0; // 최대 힙에서 삭제된거 모아두는 최대 힙

// 최소 힙을 최대 힙으로 변환 
// 범위가 int 전체라 그냥 양수 <-> 음수로 변환하면 -2147483648에서 뻑남 
int convert(int t) {
	if(t != -2147483648) return -t - 1;
	else return 2147483647;
}

// 넣기 
int pushN(int x) {
	push(         x, minQ, &minQl);
	push(convert(x), maxQ, &maxQl);
	return x;
}

// 가장 작은거 꺼내기 
int popMin() {
	if(minQl == 0) return 0;
	int t = pop(minQ, &minQl);
	// 꺼낸게 삭제된거이면(=최소삭제힙에 있으면) 버리고 다시 꺼내기 
	while(t == root(minD, &minDl) && minDl != 0) {
		pop(minD, &minDl);
		if(minQl == 0) return 0;
		t = pop(minQ, &minQl);
	}
	push(convert(t), maxD, &maxDl);
	return t;
}

// 가장 큰거 꺼내기 
int popMax() {
	if(maxQl == 0) return 0;
	int t = pop(maxQ, &maxQl);
	// 꺼낸게 삭제된거이면(=최대삭제힙에 있으면) 버리고 다시 꺼내기 
	while(t == root(maxD, &maxDl) && maxDl != 0) {
		pop(maxD, &maxDl);
		if(maxQl == 0) return 0;
		t = pop(maxQ, &maxQl);
	}
	push(convert(t), minD, &minDl);
	return convert(t);
}

int main() {
	int t, k;
	int arg, num;
	char ins;
	
	for(scanf("%d", &t); t > 0; t--) {
		minQl = 0; minDl = 0;
		maxQl = 0; maxDl = 0;
		for(scanf("%d", &k); k > 0; k--) {
			scanf(" %c %d", &ins, &arg);
			if(ins == 'I') {
				pushN(arg);
			} else if(ins == 'D') {
				if(arg == 1) {
					popMax();
				} else if(arg == -1) {
					popMin();
				}
			}
		}
		// 최대 힙, 최소 힙이 비었거나 최대/최소삭제힙이랑 크기 같으면 EMPTY 
		if(minQl == 0 || maxQl == 0 || minQl == minDl || maxQl == maxDl)
			printf("EMPTY\n");
		else {
			num = popMax();
			printf("%d ", num);
			pushN(num); // 값을 읽기만 하지 않고 아얘 빼버려서 다시 넣어줘야함 
			printf("%d\n", popMin());
		}
	}
	
	return 0;
}
