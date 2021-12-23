#include "headtree.h"
#include "florevisit.h"

int main() {
    bitree t1;
    t1 = buildtree();
    DLR(t1);
    printf("\n");
    printf("the depth of the tree are :");
    printf("%d\n", depth(t1));

    if (leafnum(t1) > 1) {
        printf("the number of leaves are:");
        printf("%d\n", leafnum(t1));
    }
    else {
        printf("the number of leaf is:");
        printf("%d\n", leafnum(t1));
    }
    printf("\n");
    leveltraversal(t1);
    return 0;
}