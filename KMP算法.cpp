#include<iostream>
using namespace std;

char aim[10] = { '0','b','c','a','b','b','b','c','d','a' };

char mode[4] = { '0','b','b','b' };

//�����㷨

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
		if (j == 0 || a[i] == a[j]) { /*�����Ѿ�֪�� j ����һ�� i �� 
									  nextֵ ����ǰ��i�ٴ� ������j
									  ƥ��ɹ�  ��i����ǰһ��ֵ��ȣ�
									  ��ô�غϲ��ֱض�����һ�� 
									  ����j++ i++ next[i] = j 
									  ��kλƥ��ʧ�ܣ���ҪѰ�ҵ���ǰk - 1λ
									
									  */
			++i;
			++j;
			next[i] = j; //��Զ����� ��һ��i��next�� 
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
