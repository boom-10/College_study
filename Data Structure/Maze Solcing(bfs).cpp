#include<stdio.h>
#include<malloc.h>
typedef struct node {
	int step=0;
	int x;
	int y;
} path, node;

typedef struct Qnode
{
	node data;//����������dataΪ����Ԫ������
	struct Qnode* next;//����nextΪָ������ 
}Qnode, * QueuePtr;//���У�QnodeΪ������ͣ� QueuePtr��ָ��Qnode��ָ������

typedef struct
{
	Qnode* front;//ͷָ��
	Qnode* rear;//βָ�� 
}LinkQueue;//��ʽ�������� 

//���ɿն����㷨����ʼ������	
#define LENG sizeof(Qnode)//������ռ�ĵ�Ԫ��
LinkQueue InitQueue()//���ɽ�����ͷ���Ŀն���Q
{
	LinkQueue Q;//˵������Q
	Q.front = Q.rear = (QueuePtr)malloc(LENG);//���ɱ�ͷ���
	Q.front->next = NULL;//��ͷ����nextΪ��ָ��
	return Q;//����Q��ֵ 
}


//���ǣ��ն���ʱ������Ԫ��x	
LinkQueue Enqueue(LinkQueue Q, node e)
{
	Qnode* p;//˵������p
	p = (Qnode*)malloc(LENG);//������Ԫ�ؽ��
	p->data = e;//װ��Ԫ��e
	p->next = NULL;//Ϊ��β���
	Q.rear->next = p;//�����½��
	Q.rear = p;//�޸�βָ��
	return Q;//����Q����ֵ 
}
//��ʽ���еĳ����㷨	
LinkQueue DelQueue(LinkQueue Q, node* e)
{
	Qnode* p;//��������p
	if (Q.front == Q.rear)//��ԭ����Ϊ��
	{
		printf("Empty queue");//�ն���
		return Q;
	}
	p = Q.front->next;//pָ��Ҫɾ���Ķ�ͷ���
	(*e) = p->data;//ȡ��Ԫ��
	Q.front->next = p->next;//ɾ����ͷ���
	if (Q.rear == p)//��ԭ����ֻ��1�����
	{
		Q.rear = Q.front;//�޸�βָ�� 
	}
	free(p);//�ͷű�ɾ���Ŀռ�
	return Q;//���س��Ӻ��Q 
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
int v[100][100];//�ж��Ƿ��߹�
//��������
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
		printf("����ͨ��");
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