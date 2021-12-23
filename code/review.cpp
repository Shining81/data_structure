
//����һЩ�ǵݹ��㷨
#include<iostream>
using namespace std;
#include<stack>
#include<queue>
typedef struct node{
	char data;
	struct node* lchild, * rchild;
}node, *bitree;



bitree buildtree() {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	char c = getchar();
	if (c == '0') {
		return NULL;
	}
	p->data = c;
	p->lchild = buildtree();
	p->rchild = buildtree();
	return p;
}
int DLR(bitree& t) {
	if (t) {
		printf("%c", t->data);
		DLR(t->lchild);
		DLR(t->rchild);
	}
	return 0;
}
void postorder(bitree &t) 
{
	bitree p = t;
	bitree r = NULL;
	stack<bitree> s;
	while (p || !s.empty())
	{
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			if (p->rchild && p->rchild != r) {
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}
			else {
				s.pop();
				printf("%c", p->data);
				r = p;
				p = NULL;
			}
		}
	}
}
void DLR_1(bitree &t){//��������ķǵݹ��㷨
	bitree p = t;
	stack<bitree> s;
	s.push(p);
	
	while (!s.empty()) {
		p = s.top();
		printf("%c", p->data);
		s.pop();
		if (p->rchild) {
			s.push(p->rchild);
		}
		if (p->lchild) {
			s.push(p->lchild);
		}	
	}
}
void LDR_1(bitree& t) {			//�������
	stack<bitree> s;
	bitree p = t;
	
	while (p || !s.empty()) {	//�ڵ㲻Ϊ�� ջ��Ϊ��
		while (p) {
			s.push(p);			//��ջ ֱ������˵Ľ��
			p = p->lchild;
		}
		p = s.top();			
		printf("%c", p->data);	//��������˵Ľ�㣬��ջ����Ԫ��
		s.pop();				//����˵Ľ���ջ 
		if (p->rchild) {		//�ж� �Ľ���Ƿ���������
			p = p->rchild;		// �������ָ��pָ��������� ѭ����������������˵Ľ��
		}
		else {
			p = NULL;			//���û��pΪ��
		}

	}
}

void LRD_1(bitree& t) {
	stack<bitree> s;
	bitree p = t;
	bitree r = NULL;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			if (p->rchild && p->rchild != r) {
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}
			else {
				s.pop();
				printf("%c", p->data);
				r = p;
				p = NULL;
			}

		}

	}
}

void level(bitree& t) {
	queue<bitree> q;
	bitree p = t;
	q.push(p);
	while (!q.empty()) {
		
		p = q.front();
		printf("%c", p->data);
		q.pop();
		if (p->lchild) {
			q.push(p->lchild);
		}
		if (p->rchild) {
			q.push(p->rchild);
		}
	}
}
void invertlevel(bitree& t) {		//�ӵײ����Ҷ� ������ϱ�����
	bitree p = t;
	stack<bitree> s;
	queue<bitree> q;
	if (p) 
	{
		q.push(p);
	}
		
	while (!q.empty()) {
		p = q.front();
		q.pop();
		s.push(p);
		if (p->lchild) {
			q.push(p->lchild);
		}
		if (p->rchild) {
			q.push(p->rchild);
		}
	}
	while (!s.empty()) {
		p = s.top();
		printf("%c", p->data);
		s.pop();
	}
}

int BtDepth(bitree& t) {
	if (!t) {
		return 0;
	}
	int front = -1, rear = -1;
	int last = 0, level = 0;
	bitree Q[100];
	Q[++rear] = t;
	bitree p;
	while (front < rear) {
		p = Q[++front];
		if (p->lchild) {
			Q[++rear] = p->lchild;
		}
		if (p->rchild) {
			Q[++rear] = p->rchild;
		}
		if (front == last) {
			level++;
			last = rear;
		}
	}
	return level;

}

int main() {
	bitree t1;
	cout << "���������Ľ��" << endl;
	t1 = buildtree();
	//DLR(t1);
	cout << "�������Ϊ��";	// 1
	DLR_1(t1);

	cout << "\n";
	cout << "�������Ϊ��";	// 2
	postorder(t1);
	cout << "\n";
	cout << "�������Ϊ��";	// 3
	LDR_1(t1);
	cout << "\n";
	cout << "�������Ϊ��";	// 4
	LRD_1(t1);
	cout << "\n";
	cout << "�������Ϊ��";	// 5
	level(t1);
	cout << "\n";
	cout << "�������������ǣ�";//6
	invertlevel(t1);
	cout << "\n";
	cout << "��������ǣ�";	// 7
	cout << BtDepth(t1);
	return 0;
}