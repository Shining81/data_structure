#include<iostream>
using namespace std;
#include<stack>
typedef struct node {
	char data;
	struct node* lchild, * rchild;
}node, *bitree;

bitree creattree() {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	char c = getchar();
	if (c == '0') {
		return NULL;
	}
	p->data = c;
	p->lchild = creattree();
	p->rchild = creattree();
	return p;

}

int dlr(bitree p) {
	if (p == NULL) {
		return 0;
	}
	cout << p->data;
	dlr(p->lchild);
	dlr(p->rchild);
}

void dlr_I(bitree p) {
	stack<bitree> s;
	if (p) {
		s.push(p);
	}
	while (!s.empty()) {
		p = s.top();
		cout << p->data;
		s.pop();
		if (p->rchild) {
			s.push(p->rchild);
		}
		if (p->lchild) {
			s.push(p->lchild);
		}
	}


}

void LRD2(bitree p) {
	stack<bitree> s1, s2;
	if (p) {
		s1.push(p);
	}
	while (!s1.empty()) {
		p = s1.top();
		s2.push(p);
		s1.pop();
		if (p->lchild) {
			s1.push(p->lchild);
		}
		if (p->rchild) {
			s1.push(p->rchild);
		}
	}
	while (!s2.empty()) {
		p = s2.top();
		cout << p->data;
		s2.pop();
	}



}
int main() {

	bitree t1 = creattree();

	//dlr(t1);
	//dlr_I(t1);
	LRD2(t1);




}