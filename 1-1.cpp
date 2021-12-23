#include<iostream>
using namespace std;

typedef struct lnode {
    int data;
    struct lnode* next;
}lnode, *linklist;

int a[8] = { 5,43,3,3,4,3,6,7 };
linklist creatlist(int a[]) {
    linklist s = new(lnode);
    s->next = NULL;
    linklist p = s;

    for (int i = 0; i < 8; ++i) {
        linklist newnode = new(lnode);
        newnode->next = NULL;
        newnode->data = a[i];
        p->next = newnode;
        p = newnode;
    }

    return s;
}
void print(linklist p) {
    p = p->next;
    while (p) {

        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}

void deletenode(linklist p) {
    linklist e = p->next;
    p->next = p->next->next;
    delete e;
}
int deletex(linklist p, int x) {
    if (p->next == NULL) {
        return 0;
    }
    if (p->next->data == x) {
        deletenode(p);
        deletex(p, x);
    }
    else{
        deletex(p->next, x);
    }

}

int main() {
    cout << "hello world" << endl;

    linklist l1 = creatlist(a);
    print(l1);
    deletex(l1, 3);
    print(l1);
    return 0;
}