#include<iostream>
using namespace std;

//Ë³ĞòÕ»

typedef struct { //Ë³ĞòÕ»
	int data[10];
	int top;
}stack;
void initstack(stack &s) {
	s.top = -1;
}
bool push(stack& s, int x) {
	if (s.top >= 10) {
		return false;
	}
	s.data[++s.top] = x;
	return true;
}
int gettop(stack& s) {
	return s.data[s.top];
}
void pop(stack& s) {
	int e;
	e = s.data[--s.top];
}


typedef struct node { //Á´Ê½Õ»
	int data;
	struct node* top;
}*linkstack;


linkstack initlinkstack() {
	linkstack s = new(node);
	s->top = NULL;
	return s;
}

linkstack push(linkstack s, int x) {
	linkstack newnode = new(node);
	newnode->data = x;
	newnode->top = s->top;
	s->top = newnode;
	return s;
}
int gettop(linkstack s) {
	if (s->top == NULL) {
		printf("error\n");
		return 00;
	}
	return s->top->data;
}

void pop(linkstack s) {
	int e = s->top->data;
	s->top = s->top->top;
}

int main() {
	linkstack s1;
	s1 = initlinkstack();
	push(s1, 1);
	push(s1, 4);
	push(s1, 3);
	printf("%d", gettop(s1));
	return 0;
}