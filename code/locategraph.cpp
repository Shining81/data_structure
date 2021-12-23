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
    printf("�����붥��ĸ����ͻ��ĸ�����\n");
    int i, j;
    scanf_s("%d %d", &i,&j);
    G.vexnum = i; G.arcnum = j;
    int v = 0;
    while(v<G.vexnum) {
        char p;
        printf("������� %d �����������\n", v);
        scanf_s(" %c", &p);
        G.vex[v] = p;
        ++v;
    }
    for (i = 0; i < G.vexnum; i++)
    {                                   //��ʼ�� ʹͼΪһ��ɭ�֣�
        for (j = 0; j < G.vexnum; j++) {
            G.edge[i][j] = 0;
        }
    }
                                        // �����㹹��һ����
    for (i = 0; i < G.arcnum; i++) 
    {
        //char v1, v2;
        //printf("�����������й����Ķ���\n");
        //scanf_s(" %c %c", &v1, &v2);     //�����й�ϵ��������
        //int x ;       //���������ڶ��������е�λ��
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
        G.edge[x][y] = 1;               //���ߵ�ֵ����Ϊ1��  
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


















