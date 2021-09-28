#pragma once
#include<iostream>
using namespace std;
#define length 3

//
typedef struct node {
	int data;
	struct node* lchild, * rchild;
	int higth;
}tree, * bitree;
//
int gethight(bitree& t);
void update(bitree& t);
bitree insert(bitree& t, int x);
int index(bitree& t);
void R(bitree& t);
void L(bitree& t);

bitree insert(bitree& t, int x) {
	if (t == NULL) {
		struct node* s = (struct node*)malloc(sizeof(struct node));
		s->lchild = s->rchild = NULL;
		s->higth = 1;
		s->data = x;
		t = s;
		return t;
	}
	if (t->data > x) {
		if (!t->lchild) {
			t->lchild = insert(t->lchild, x);
		}
		else {
			return insert(t->lchild, x);
		}
	}
	else {
		if (!t->rchild) {
			t->rchild = insert(t->rchild, x);
		}
		else {
			return insert(t->rchild, x);
		}
	}
}
//
void creattree(bitree& t, int arr[]) {
	t = NULL;
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			t = insert(t, arr[i]);
		}
		else {
			insert(t, arr[i]);
			if (index(t) == 2) 
			{
				if (index(t->lchild) == 1) 
				{
					R(t);
				}
				if (index(t->lchild) == -1) {
					L(t->lchild);
					R(t);
				}
			}
			if(index(t) == -2)
			{
				if (index(t->rchild) == -1)
				{
					L(t);
				}
				if (index(t->rchild) == 1) {
					R(t->rchild);
					L(t);
				}
			}
		}
	}
}
//
void ldr(bitree& t) {
	if (t != NULL) {
		ldr(t->lchild);
		printf("%d->", t->data);
		ldr(t->rchild);
	}
}
int high(bitree& t) {
	if (!t) {
		return 0;
	}
	else {
		return 1 + max(high(t->lchild), high(t->rchild));
	}
}

int index(bitree& t) {
	return high(t->lchild) - high(t->rchild);
}

void R(bitree& t) {
	bitree temp = t->lchild;
	t->lchild = temp->rchild;
	temp->rchild = t;
	t = temp;
}

void L(bitree& t) {
	bitree temp = t->rchild;
	t->rchild = temp->lchild;
	temp->lchild = t;
	t = temp;
}
int a[length] = { 6,8,7};

int main() {
	bitree t1;
	creattree(t1, a);
	ldr(t1);
	cout << endl;
	cout << high(t1) << endl;
	cout << index(t1) << endl;
	return 0;
}