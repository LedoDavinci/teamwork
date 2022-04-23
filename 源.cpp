#include <stdio.h>
#include <stdlib.h>
#define MAX 0

//检测数据库死锁的方法

typedef struct GRAPHMATRIX_STRU
{
    int size;
    int **graph;
}


GraphMatrix;

//功能函数

GraphMatrix* InitGraph(int num)
{
    int i,j;
    GraphMatrix *graphMatrix=(GraphMatrix*)malloc(sizeof(GraphMatrix));
    graphMatrix->size=num;
    graphMatrix->graph=(int**)malloc(sizeof(int*)*graphMatrix->size);
    for(i=0;i<graphMatrix->size;i++)
    {
        graphMatrix->graph[i]=(int*)malloc(sizeof(int)*graphMatrix->size);
    }
    for(i=0;i<graphMatrix->size;i++)
    {
        for(j=0;j<graphMatrix->size;j++)
        graphMatrix->graph[i][j]=MAX;

    }
    return graphMatrix;
}

//输入函数

void ReadMatrix(GraphMatrix*graphMatrix)
{
    int vex1,vex2;
    scanf("%d%d",&vex1,&vex2);
    while(vex1!=-1||vex2!=-1)
    {
        graphMatrix->graph[vex1][vex2]=1;
        scanf("%d%d",&vex1,&vex2);
    }
}

//判断函数

void loop(GraphMatrix *graphMatrix,int *visited,int source,int s,int *count)
{
    int j;
    visited[source]=1;
    for(j=0;j<graphMatrix->size;j++)
    {
        if(graphMatrix->graph[source][j]!=MAX&&j==s)
        {   
		count[0]++;  
        }

        if(graphMatrix->graph[source][j]!=MAX&&!visited[j])
            loop(graphMatrix,visited,j,s,count);
    }
}


//主函数

int main()
{
    int num;
    int i=0,j;
    int count[1]={0};
	printf("请输入结点个数：");
	scanf("%d",&num);
    int *visited=(int*)malloc(sizeof(int)*num);
   GraphMatrix *graphMatrix;
   graphMatrix=InitGraph(num);
   ReadMatrix(graphMatrix);
   for(i=0;i<(graphMatrix->size);i++)
   {
       if(count[0]!=0)
       break;
       for(j=0;j<graphMatrix->size;j++)
       {
           visited[j]=0;
       }
       loop(graphMatrix,visited,i,i,count);

   }
   if(count[0]==0)
   {
	   printf("图中不存在回路\n");
   }
   else
   {
	   printf("图中存在回路\n");
   }
   system("pause");
   return 0;
}

