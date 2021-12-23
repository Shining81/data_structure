#include<stdio.h>
#define X 5
#define MAX 10
#define length1 11
char MAIN[length1] = { '1','a','b','b','a','b','a','c','b','a','b'};
char str[X] = {'1','a','c','b','a'};



void getNext(char *ch, int *next) {

	int i = 1, j = 0;
	next[1] = 0;
	while (i<X){
		if (j == 0 || ch[i] == ch[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}


}
void getNextval(char* ch, int* nextval) {//我和我自己匹配 

	int i, j;
	i = 1; j = 0;
	nextval[1] = 0;
	while (i < X) {
		if (j == 0 || ch[i] == ch[j]) {
			++i;
			++j;
			
			if (ch[i] != ch[j]) { //可以理解为 ch[i] != ch[next[i]] 此时next[i] == j
				nextval[i] = j;
			}
			else {
				nextval[i] = nextval[j];
			}
		}
		else {
			j = nextval[j];
		}
	}
}
int KMP(char* st1, char* st2, int *next) {
	int i = 1; int j = 1;
	while (i < length1 && j<X) {
		if (j==0||st1[i] == st2[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j >= X) {
		printf("与主字符串匹配成功\n");
		return i - X+1;

	}
	else {
		printf("匹配不成功\n");
		return 0;
	}
}




int main() {
	int next[MAX];
	int nextval[MAX];
	getNext(str, next);
	getNextval(str, nextval);
	printf("此字符串的next值为：");
	for (int i = 1; i < X; i++) {
		printf("%d", next[i]);
	}
	printf("\n");
	printf("此字符串的nextval值为：");
	for (int i = 1; i < X; i++) {
		printf("%d", nextval[i]);
	}
	printf("\n");
	int c = KMP(MAIN, str, next);
	printf("模式串在主串中的起始位置是 %d\n", c);
	return 0;
}