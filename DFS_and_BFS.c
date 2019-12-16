// Program for applying BFS and DFS algorithms of graph along with the adjacent nodes...
#include<stdio.h>
#include<stdlib.h>

int i,j;
int no,run;


void enqueue(int queue[no],int *top,int data,int *bottom)
{
    if(*top == -1 && *bottom == -1)
    {
        *top = *top + 1;
        *bottom = *bottom + 1;
    }
    else
    {
            *top = *top + 1;

    }
    queue[*top] = data;
}

void dequeue(int *bottom)
{
    *bottom = *bottom + 1;
}

void push(int stack[no],int *sptr, int data)
{
    *sptr = *sptr + 1;
    stack[*sptr] = data;

}

void pop(int *sptr)
{
    *sptr = *sptr - 1;

}

void BFS(int fmatrix[no][no])
{
    int visited[no],unvCount=0,node=0;
    for(i=0;i<no;i++)
    {
        visited[i] = 0;
    }
    int queue[no], top= -1, bottom = -1,temp;
    printf("\n\n Breadth First Search : %d",0);
    visited[0] = 1;
    unvCount++;
    i=0;
 while(unvCount != no )
 {
     for(i=0;i<no;i++)
    {
        if(fmatrix[node][i] == 1 && visited[i] == 0)
        {
            enqueue(queue, &top,i,&bottom);
            visited[i] = 1;
        }
        if((top != -1) && (i == no-1) && (bottom <= top))
        {
            node = queue[bottom];
            printf(" %d",node);
            dequeue(&bottom);
            visited[node] = 1;
            unvCount++;
            i= -1;
        }
    }

 }
}



void DFS(int fmatrix[no][no])
{
    int visited[no],unvCount=0,node=0;
    for(i=0;i<no;i++)
    {
        visited[i] = 0;
    }
    int stack[no], sptr= -1 ,temp;
    printf("\n\n Depth First Search : %d",0);
    visited[0] = 1;
    unvCount++;
    i=0;
 while(unvCount != no )
 {
     for(i=0;i<no;i++)
    {
        if(fmatrix[node][i] == 1 && visited[i] == 0)
        {
            push(stack, &sptr,i);
            visited[i] = 1;
        }
        if((sptr != -1) && (i >= no-1))
        {
            node = stack[sptr];
            printf(" %d",node);
            pop(&sptr);
            visited[node] = 1;
            unvCount++;
            i= -1;
        }
    }

 }
}

void adjacent(int fmatrix[no][no])
{
    int findnode;
	run=1;
	while(run==1)
	{
	printf("\n\n Enter the node of which you want to find the adjacents of : ");
	scanf("%d",&findnode);

	if(findnode > no)
	{
		printf("\n Invalid node.... Total nodes are : %d", no);
	}
	else
	{
		printf("\n\n\t Adjacents of node %d are : ",findnode);

			for(j=0; j< no; j++)
			{
				if( fmatrix[findnode][j] == 1)
				{
					printf("%d ",j);
				}
			}
	}


	printf("\n\n Press 1 to run the program again or 0 to exit.");
	scanf("%d",&run);
	}
}



int main()
{
	int choice;
	run=1;
	printf("\n\n Enter the number of nodes in the  graphs : ");
	scanf("%d",&no);

	printf("\n For entering presence of link press 1 if present and 0 if not.");
	int matrix[no][no];
	for(i=0; i<no; i++)
	{
		for(j=0; j<no; j++)
		{
			if( i == j)
			{
				matrix[i][j] = 0;
			}
			else
			{
				printf("\n Is there a link between nodes %d & %d : ",i,j);
				scanf("%d",&matrix[i][j]);
			}
		}

	}

	while(run==1)
	{

		printf("\n\n\n\t\t ****** MENU *****");
		printf("\n\n 1. Find the ADJACENTS of the particular NODE.");
		printf("\n\n 2. Give the DEPTH FIRST SEARCH of the graph starting from 0th node.");
		printf("\n\n 3. Give the BREADTH FIRST SEARCH of the graph starting from 0th node.");

		printf("\n\n Enter a choice from the menu : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: adjacent(matrix);
					break;
			case 2: DFS(matrix);
					break;
			case 3: BFS(matrix);
					break;
			default:
					printf("\n\n Invalid choice..!!");
					break;

		}

		printf("\n\n Press 1 to get the MENU or 0 to exit.");
		scanf("%d",&run);

	}

return 0;
}
