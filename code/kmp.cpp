#include<stdio.h>

#define max 100
void nextvalue(char *ch, int next[]) {
	int i, j;
	i = 1;
	next[1] = 0; j = 0;
	while (i < 5) {
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
char ch1[11] = {'1','a','a','b','a','a','b','c','b','b','a' };
char ch2[5] = { '1','a','b','c','b' };

int kmp(char* chi, char* chii, int *next) {
	int i=1, j=1;
	while (j < 5 && i < 11) {
		if (chi[i] == chii[j]) {
			j++;
			i++;
		}
		else {
			j = next[j];
		}
	}
	if (j >= 5) printf("%d", i-4);
	else return 0;
}



int main(){
	int next[max];
	nextvalue(ch2, next);
	for (int i = 1; i < 5; i++) {
		printf("%d  ", next[i]);
	}
	printf("\n");
	printf("%d", next[5]);
	printf("\n");
	kmp(ch1, ch2, next);
	return 0;
}