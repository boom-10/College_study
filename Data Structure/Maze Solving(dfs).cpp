#include<stdio.h>
#include<malloc.h>
int mazenum[6][6]= { 
{0,1,0,0,0,0},
{0,1,1,1,1,0},
{0,1,0,1,0,0},
{0,1,0,1,1,0},
{0,1,1,0,1,0},
{0,0,1,1,1,0} };
int len = 6;

typedef struct {
	int row;
	int col;
	//int Canpass;//判断是否可通
	int walk;//判断是否走过
	//int di;
}PosType;
typedef struct {                      //通道块在路经上的“序号”
	PosType seat;      //通道块在迷宫中的“坐标位置”
	int di;          //从此通道块走向下一通道块的“方向”
}SElemType;                              //栈的元素类型
typedef struct {
	PosType* base;  //栈底指针
	PosType* top;   //栈顶指针
	int     stacksize;
} SqStack;

PosType maze[6][6];
#define STACK_INIT_SIZE 100;     //存储空间初始分配量
#define STACKINCREMENT 10;     //存储空间分配增量
void InitStack(SqStack& s) {
	s.base = (PosType*)malloc(100*sizeof(PosType));
	s.top = s.base;
	s.stacksize = 100;
}
void Push(SqStack& s, PosType&e) {
	if (s.top - s.base >= s.stacksize) {
		s.base = (PosType*)realloc(s.base, (100 + 10) * sizeof(PosType));
		s.stacksize += 10;
		s.top = s.base + s.stacksize;
	}
	*s.top = e;
	s.top++;
}
void pop(SqStack& s, PosType& e) {
	if (s.top == s.base) {
		printf("栈为空！\n");
	}
	else
	{
		e = *--s.top;
	}
}
PosType getTop(SqStack &s,PosType &p) {
	p = *(s.top - 1);
	return p;
}
int IsCanPass(PosType &p) {
			if (mazenum[p.row ][p.col+1]&&p.col+1<len)
			{
				return 1;
			}

			else if (mazenum[p.row+1][p.col]&&p.row+1<len)
			{
				return 2;
			}

			else if (mazenum[p.row ][p.col-1]&&p.col-1>0)
			{
				return 3;
			}

			else if (mazenum[p.row-1][p.col]&&p.row-1>0)
			{
				return 4;
			}
			else
			{
				return 0;
			}
 }
PosType walk_to_next(PosType p, int di) {
	if (di==1)
	{
		p.col++;
	}
	else if (di == 2) {
		p.row++;
	}
	else if (di == 3) {
		p.col--;
	}
	else if (di == 4) {
		p.row--;
	}
	else
	{
		printf("方向有误！");
	}
	return p;
}
void PrintRoad(SqStack s) {
	while (s.base != s.top) {
		s.top--;
		printf("(%d,%d)", s.top->row, s.top->col);
	}

}
void mazePath(PosType start, PosType end) {
	PosType temp = start;
	SqStack s;
	InitStack(s);
	while (true) {
		if (temp.col == end.col && temp.row == end.row)
		{
			//printf("找到了");
			Push(s, temp);
			PrintRoad(s);
			break;
		}
		temp.walk=IsCanPass(temp);
		if (temp.walk!=0)
		{
			mazenum[temp.row][temp.col] = 0;
			Push(s,temp);
			//printf("(%d,%d)", temp.row, temp.col);
			temp = walk_to_next(temp, temp.walk);
		}
		else {
			mazenum[temp.row][temp.col] = 0;
			pop(s, temp);
			mazenum[temp.row][temp.col] = 1;
		}
	}
}

void createMaze() {
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) {
			//maze[i][j].Canpass = mazenum[i][j];
			maze[i][j].col = j;
			maze[i][j].row = i;
		}
	}
}

void printMaze() {
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) {
			printf("%d ", mazenum[i][j]);
		}
		printf("\n");
	}
}

void main() {
	createMaze();
	printMaze();
	PosType start, end;
	start.row = 0;
	start.col = 1;
	end.row = 5;
	end.col = 2;
	mazePath(start, end);
	
}