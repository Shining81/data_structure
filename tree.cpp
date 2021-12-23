#include<iostream>
using namespace std;

typedef struct node{
	char data;
	int data_num;
	struct node* lchild, * rchild;

}*bitree;

bitree creattree() {
	bitree t = new(node);
	char c = getchar();
	if (c == '0') {
		return NULL;
	}
	t->data = c;
	t->lchild = creattree();
	t->rchild = creattree();
	return t;
}

//建立一个排序二叉树

int a[10] = { 2,3,424,34,34,53,1,23,43,35 };
bitree insert(bitree &t, int x) {
	if (t == NULL) {
		bitree s = new(node);
		s->lchild = s->rchild = NULL;
		s->data_num = x;
		t = s;
		return t;
	}
	if (t->data_num > x) {
		if (!t->lchild) {
			t->lchild = insert(t->lchild, x);
		}
		else {
			return insert(t->lchild, x);
		}
	}
	if (t->data_num <= x) {
		if (!t->rchild) {
			t->rchild = insert(t->rchild, x);
		}
		else {
			return insert(t->rchild, x);
		}
	}
}

void buildtree(bitree &t, int* a) {
	t = NULL; int i;
	for (i = 0; i < 10; ++i) {
		if (i == 0) {
			insert(t, a[i]);
		}
		else {
			insert(t, a[i]);
		}

	}
}


void dlr(bitree t) {
	if (t) {
		cout << t->data_num<<"->";
		dlr(t->lchild);
		dlr(t->rchild);
	}
}

int main() {
	bitree t1;
	buildtree(t1, a);
	dlr(t1);
	

	return 0;
}