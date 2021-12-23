#include<stdio.h>


void quick(int *arr, int start, int end) {
	
	if ((end - start) <= 0) {
		return;
	}
	int astart = start + 1, aend = end;
	int b1start = start, b1end = start;
	int b2start = end, b2end = end;

	while ((aend - astart)>=0) {
		if (arr[astart] <= arr[astart - 1]) {
			int temp;
			temp = arr[astart];
			arr[astart] = arr[astart-1];
			arr[astart-1] = temp;

			b1end++;
			astart++;
		}
		else {
			int temp;
			temp = arr[astart];
			arr[astart] = arr[aend];
			arr[aend] = temp;

			b2start--;
			aend--;
		}
	}

	b1end = astart - 2;
	b2start = astart;
	quick(arr, b1start, b1end);
	quick(arr, b2start, b2end);

}

int main() {
	int arr[10] = { 42,33,44,55,65,7,17,18,76,8 };
	int i = 0; int e = 9;
	quick(arr, i, e);
	for (int j = 0; j < 10; j++) {
		printf("%d->", arr[j]);
	}
	return 0;
}