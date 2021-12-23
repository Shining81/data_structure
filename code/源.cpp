#include<iostream>
using namespace std;
#define N 4
typedef struct lnode {
    char data;
    struct lnode* next;
}lnode, * linklist;

char s1[N] = { 'b','a','a','b' };


void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(lnode));
    lnode* s, * r = L;
    for (int i = 0; i < N; i++) {
        s = (linklist)malloc(sizeof(lnode));
        s->data = s1[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;

}

void print(linklist& L) {
    lnode* p;
    p = L->next;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
}

bool isok(linklist L) {
    char str[N / 2];
    lnode* p = new (lnode);
    p = L->next;
    int i;
    for (i = 0; i < N / 2; i++) {
        str[i] = p->data;
        p = p->next;
    }
    i--;
    if (N % 2 != 0) {
        p = p->next;
    }
    while (p && p->data == str[i]) {
        i--;
        p = p->next;
    }
    if (i == -1) return true;
    return false;
}
int main() {
    linklist l;
    buildlist(l);
    if (isok(l)) {
        cout << "¶Ô³Æ" << endl;
    }
    else
        cout << "²»¶Ô³Æ" << endl;
    return 0;
}