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
void getNextval(char* ch, int* nextval) {//�Һ����Լ�ƥ�� 

	int i, j;
	i = 1; j = 0;
	nextval[1] = 0;
	while (i < X) {
		if (j == 0 || ch[i] == ch[j]) {
			++i;
			++j;
			
			if (ch[i] != ch[j]) { //�������Ϊ ch[i] != ch[next[i]] ��ʱnext[i] == j
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
		printf("�����ַ���ƥ��ɹ�\n");
		return i - X+1;

	}
	else {
		printf("ƥ�䲻�ɹ�\n");
		return 0;
	}
}




int main() {
	int next[MAX];
	int nextval[MAX];
	getNext(str, next);
	getNextval(str, nextval);
	printf("���ַ�����nextֵΪ��");
	for (int i = 1; i < X; i++) {
		printf("%d", next[i]);
	}
	printf("\n");
	printf("���ַ�����nextvalֵΪ��");
	for (int i = 1; i < X; i++) {
		printf("%d", nextval[i]);
	}
	printf("\n");
	int c = KMP(MAIN, str, next);
	printf("ģʽ���������е���ʼλ���� %d\n", c);
	return 0;
}