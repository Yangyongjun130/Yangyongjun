#include <stdio.h>
#include <stdlib.h>
void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int median(int a[], int L, int R) {
	int Mid = (L + R) / 2;
	if (a[L] > a[Mid])
		Swap(&a[L], &a[Mid]);
	if (a[L] > a[R])
		Swap(&a[L], &a[R]);
	if (a[Mid] > a[R])
		Swap(&a[R], &a[Mid]);
	Swap(&a[R - 1], &a[Mid]);
	return a[R - 1];
}

void Qsort2(int a[], int L, int R) {
	if (L < R) {
		int p = median(a, L, R);
		int i = L;
		int j = R - 2;
		for (;;) {
			while (a[i] < p)
				i++;
			while (a[j] > p)
				j--;
			if (i < j)
				Swap(&a[i], &a[j]);
			else
				break;
		}
		Swap(&a[i], &a[R - 1]);
		Qsort2(a, L, i - 1);
		Qsort2(a, i + 1, R);
	}
}

int main() {

	const int N = 9;
	int a[N] = { 0 };
	

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a[j] = rand() % 100 + 1;	// 产生1-100随机数
		}
		printf("第");
		printf("%d",i);
		printf("次");
		for (int k = 0; k < N; ++k) {
			printf(" ");
			printf("%d",a[k]);
		}
		printf("------>排序结果 :");
	

		Qsort2(a, 0, N - 1);
		for (int x = 0; x < N; ++x) {
			printf(" ");
			printf("%d", a[x]);
		}
		printf("\n");
	}

	return 0; 
}
