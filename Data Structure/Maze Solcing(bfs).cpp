#include<stdio.h>
#include<malloc.h>
typedef struct node {
	int step=0;
	int x;
	int y;
} path, node;

typedef struct Qnode
{
	node data;//其中数据域data为抽象元素类型
	struct Qnode* next;//其中next为指针类型 
}Qnode, * QueuePtr;//其中，Qnode为结点类型， QueuePtr：指向Qnode的指针类型

typedef struct
{
	Qnode* front;//头指针
	Qnode* rear;//尾指针 
}LinkQueue;//链式队列类型 

//生成空队列算法：初始化队列	
#define LENG sizeof(Qnode)//求结点所占的单元数
LinkQueue InitQueue()//生成仅带表头结点的空队列Q
{
	LinkQueue Q;//说明变量Q
	Q.front = Q.rear = (QueuePtr)malloc(LENG);//生成表头结点
	Q.front->next = NULL;//表头结点的next为空指针
	return Q;//返回Q的值 
}


//（非）空队列时插入新元素x	
LinkQueue Enqueue(LinkQueue Q, node e)
{
	Qnode* p;//说明变量p
	p = (Qnode*)malloc(LENG);//生成新元素结点
	p->data = e;//装入元素e
	p->next = NULL;//为队尾结点
	Q.rear->next = p;//插入新结点
	Q.rear = p;//修改尾指针
	return Q;//返回Q的新值 
}
//链式队列的出队算法	
LinkQueue DelQueue(LinkQueue Q, node* e)
{
	Qnode* p;//声明变量p
	if (Q.front == Q.rear)//若原队列为空
	{
		printf("Empty queue");//空队列
		return Q;
	}
	p = Q.front->next;//p指向要删除的队头结点
	(*e) = p->data;//取出元素
	Q.front->next = p->next;//删除队头结点
	if (Q.rear == p)//若原队列只有1个结点
	{
		Q.rear = Q.front;//修改尾指针 
	}
	free(p);//释放被删除的空间
	return Q;//返回出队后的Q 
}

bool Empty(LinkQueue& q) {
	if (q.rear==q.front)
	{
		return true;
	}
	return false;
}

int maze[6][6] = {
{0,1,0,0,0,0},
{0,1,1,1,1,0},
{0,1,0,1,0,0},
{0,1,0,1,1,0},
{0,1,1,0,1,0},
{0,0,1,1,1,0} };
int len = 6;
int v[100][100];//判断是否走过
//方向数组
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dx2[4] = { 1,0,0,-1 };
int dy2[4] = { 0,1,-1,0 };
int roadArray[100];
void bfs_maze(node start, node end) {
	LinkQueue q = InitQueue();
	start.step = 1;
	q=Enqueue(q, start);
	v[start.x][start.y] = 1;
	int flag = 0;
	while (!Empty(q))
	{
		node front_item;
		q=DelQueue(q, &front_item);
		if (front_item.x==end.x&&front_item.y==end.y)
		{
			flag = 1;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int tempx = front_item.x + dx[i];
			int tempy = front_item.y + dy[i];
			if (tempx >= 0 && tempx < len && tempy >= 0 && tempy < len) {
				if (maze[tempx][tempy]==1&&v[tempx][tempy]==0)
				{
					node temp;
					temp.x = tempx;
					temp.y = tempy;
					temp.step = front_item.step + 1;
					maze[tempx][tempy] = temp.step;
					q=Enqueue(q, temp);
					v[tempx][tempy] = 1;
				}
			}
		}

	}
	if (flag==0)
	{
		printf("不可通！");
	}
}

void printMaze() {
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printMaze2(node start, node end) {
	while (start.step != end.step) {
		start.step++;
		for (int i = 0; i < 4; i++)
		{
			int tmpx = start.x + dx2[i];
			int tmpy = start.y + dy2[i];
			if (tmpx >= 0 && tmpx < len && tmpy >= 0 && tmpy < len) {
				if (maze[tmpx][tmpy] == start.step) {
					printf("%d %d\n", tmpx, tmpy);
					start.x = tmpx;
					start.y = tmpy;
					break;
				}
			}
		}
	}
}
int main() {
	node start, end;
	start.x = 0;
	start.y = 1;
	end.x = 5;
	end.y = 2;
	printMaze();
	bfs_maze(start, end);
	printMaze();
	start.step = maze[start.x][start.y];
	end.step = maze[end.x][end.y];
	printMaze2(start,end);
	//printRoad(start);
}