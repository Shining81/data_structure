#include<iostream>
using namespace std;

typedef struct node {

	int data;
	struct node* next;
}list, *linklist;

linklist init() {
	linklist l = (struct node*)malloc(sizeof(struct node));
	l->next = NULL;
	return l;
}
void creat(linklist& l) {
	int i;
	linklist p = l;
	for (i = 0; i < 10; i++) {
		linklist newnode = (struct node*)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->data = i + 1;
		p->next = newnode;
		p = newnode;
	}
}

void print(linklist &l) {
	linklist p = l;
	p = p->next;
	while (p) {
		cout << p->data << "->";
		p = p->next;
	}
}
linklist advers(linklist &l) {
	linklist pre, cur, temp;
	pre = NULL;
	cur = l->next;
	while (cur) {
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	l->next = pre;
	return l;
}

int main() {
	linklist l = init();
	creat(l);
	print(l);
	cout << endl;
	advers(l);
	print(l);

	return 0;
}
