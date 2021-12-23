#include<iostream>
using namespace std;

char aim[10] = { '0','b','c','a','b','b','b','c','d','a' };

char mode[4] = { '0','b','b','b' };

//经典算法

void F(char* a, char* b) {
	int i=1, j=1;
	while(i<10){
		if (a[i] == b[j]) {
			i++;
			j++;

			if (j == 4) {
				printf("success\n");
				printf("%d\n", i);
			}
		}
		else {
			i = i - j + 2;
			j = 1;
		}

	}

}

void getnext(char *a, int next[], int n) {
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < n) {
		if (j == 0 || a[i] == a[j]) { /*我们已经知道 j 是上一个 i 的 
									  next值 当当前的i再次 与相邻j
									  匹配成功  即i与它前一个值相等，
									  那么重合部分必定增加一， 
									  所以j++ i++ next[i] = j 
									  第k位匹配失败，需要寻找的是前k - 1位
									
									  */
			++i;
			++j;
			next[i] = j; //永远求的是 下一个i的next； 
		}
		else {
			j = next[j];
		}
	}
}


int main() {
	F(aim, mode);
	return 0;
}
