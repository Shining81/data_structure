#include<iostream>
using namespace std;
#define MAXSIZE 10
#define MAXINT 60000
typedef struct {
	char vex[MAXSIZE];
	int edge[MAXSIZE][MAXSIZE];
	int vexnum, arcnum;
}MGraph;

int locateVex(MGraph &g, char v) {
	for (int i = 0; i < g.arcnum; i++) {
		if (v == g.vex[i]) {
			return i;
		}
	}
	cout << "No such vex!" << endl;
	return 0;
}
void creatDN(MGraph& g) {
	cout << "请输入顶点数" << endl;
	cin >> g.vexnum;
	char c = getchar();
	if (c=='a') {
		creatDN(g);
	}
	cout << "请输入边数" << endl;
	cin >> g.arcnum;
	cout << "请输入顶点" << endl;
	for (int i = 0; i < g.vexnum; i++) {
		printf("请输入第%d个顶点名称: ____ ", i+1);
		char ch;
		scanf_s(" %c", &ch);
		g.vex[i] = ch;
	}
	for (int i = 0; i < g.vexnum; i++) {
		for (int j = 0; j < g.vexnum; j++) {
			g.edge[i][j] = MAXINT;
		}
	}
	cout << "请输入边" << endl;
	for (int i = 0; i < g.arcnum; i++) {
		printf("请输入第%d条边\n", i + 1);
		char m, n;
		cout << "请输入顶点 1:" << endl;
		scanf_s(" %c", &m);
		cout << "请输入顶点 2:" << endl;
		scanf_s(" %c", &n);
		int x, y;
		x = locateVex(g, m); y = locateVex(g, n);
		int value;
		cout << "请输入边的权值\n" << endl;
		scanf_s(" %d", &value);
		g.edge[x][y] = value;
	}


}
void printMGraph(MGraph& g) {
	printf("\n\t---------");
	printf("邻接矩阵---------");
	printf("\n");
	printf("\t");
	for (int i = 0; i < g.vexnum; i++) {
		printf("\t%c", g.vex[i]);
	}
	printf("\n");
	for (int i = 0; i < g.vexnum; i++) {
		printf("\t%c", g.vex[i]);
		for (int j = 0; j < g.vexnum; j++) {
			if (g.edge[i][j] == MAXINT) {
				printf("\to");
			}
			else {
				printf("\t%d", g.edge[i][j]);
			}
		}
		printf("\n");
	}
}




int main() {
	
	MGraph g;
	creatDN(g);
	printMGraph(g);
	return 0;
}