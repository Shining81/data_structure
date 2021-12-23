#include<stdio.h>

#define MAXSIZE 100

typedef struct {
    char vex[MAXSIZE];
    int edge[MAXSIZE][MAXSIZE];
    int vexnum, arcnum;
}MGraph;

int locatevex(MGraph& g, char v1) {
    for (int i = 0; i < g.vexnum; i++) {
        if (g.vex[i] = v1) {
            return i;
        }
    }
    return 0;
}


void buildgraph(MGraph& G) {
    printf("请输入顶点的个数和弧的个数！\n");
    int i, j;
    scanf_s("%d %d", &i,&j);
    G.vexnum = i; G.arcnum = j;
    int v = 0;
    while(v<G.vexnum) {
        char p;
        printf("请输入第 %d 个顶点的名称\n", v);
        scanf_s(" %c", &p);
        G.vex[v] = p;
        ++v;
    }
    for (i = 0; i < G.vexnum; i++)
    {                                   //初始化 使图为一个森林；
        for (j = 0; j < G.vexnum; j++) {
            G.edge[i][j] = 0;
        }
    }
                                        // 两个点构成一条弧
    for (i = 0; i < G.arcnum; i++) 
    {
        //char v1, v2;
        //printf("请输入两个有关联的顶点\n");
        //scanf_s(" %c %c", &v1, &v2);     //输入有关系的两个点
        //int x ;       //这两个点在顶点序列中的位置
        //int y ;
        //
        //switch (v1)
        //{
        //case 'a': 
        //    x = 0;
        //    break;
        //case 'b':
        //    x = 1;
        //    break;
        //case 'c':
        //    x = 2;
        //    break;
        //default:
        //    printf("the point you input is not exit");
        //    break;
        //}
        //switch (v2)
        //{
        //case 'a':
        //    y = 0;
        //    break;
        //case 'b':
        //    y = 1;
        //    break;
        //case 'c':
        //    y = 2;
        //    break;
        //default:
        //    printf("the point you input is not exit");
        //    break;
        //}
        int x, y;
        scanf_s(" %d %d", &x, &y);
        G.edge[x][y] = 1;               //将边的值设置为1；  
        G.edge[y][x] = 1;
    }
    
    
}



int main() {
    MGraph g;
    buildgraph(g);
    for (int i = 0; i < g.vexnum; i++) {
        printf(" %c", g.vex[i]);
    }
    printf("\n");
    for (int i = 0; i < g.vexnum; i++) {
        printf("%c", g.vex[i]);
        for (int j = 0; j < g.vexnum; j++) {
            printf("%d ", g.edge[i][j]);
        }
        printf("\n");
        
    }
    return 0;
}


















