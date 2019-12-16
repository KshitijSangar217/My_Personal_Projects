

        //----------------------------------------------- // Project Based Learning // ---------------------------------------------------------//



                        //----------------------------- // SHORTEST PATH FINDER //  -----------------------------------//

                              // Program to find the SHORTEST PATH between the SOURCE and the DESTINATION node //


                                                        /* BY : Kshitij Sangar --------A_52
                                                                Rajwardhan Sagare------A_51
                                                                Vaishnavi Patil--------A_41
                                                                Siddhi Patil-----------A_40
                                                        */
#include<stdio.h>
#include<stdlib.h>

int i,j;
int no,run;

struct PathCal // To maintain the shortest path..
{
    int prev;
    char name[25];
};

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

void adjacent(int fmatrix[no][no], int findnode, int adjacentNodes[no]) // Finds the adjacent nodes of a particular node
{
    int a=0,b= -1;
    for(a=0;a<no;a++)
    {
        adjacentNodes[a] = -1; // In order to avoid pointer to the last element in the list we have made the array with values -1.
    }
    for(a=0; a< no; a++)
    {
        if( fmatrix[findnode][a] != 0)
        {
            b++;
            adjacentNodes[b] = a;
        }
    }
}

void DistanceAssign(int fmatrix[no][no], int shortest_path[no], int adjacentNodes[no], int node, struct PathCal path[no])
{
    int k=0, AdjNode=0, temp=0;
    while(adjacentNodes[k] != -1)
    {
        AdjNode = adjacentNodes[k];
        if(shortest_path[AdjNode] == -1)
        {
            shortest_path[AdjNode] =  shortest_path[node] + fmatrix[node][AdjNode];
            path[AdjNode].prev = node;
        }
        else if(shortest_path[AdjNode] > (shortest_path[node] + fmatrix[node][AdjNode]))
        {
            shortest_path[AdjNode] =  shortest_path[node] + fmatrix[node][AdjNode];
            path[AdjNode].prev = node;
        }
        k++;
    }
}

void ShortestPathFinder(int fmatrix[no][no], int source, int destn, struct PathCal path[no])
{
    int visited[no],unvCount=0,adjPtr=0;
    int shortest_path[no], adjacentNodes[no];
    int node = source;
    path[source].prev = NULL;
    // shortest_path array will store the shortest path between the nodes and the starting nodes...
	// adjacentNodes array is to keep records of the adjacent nodes for the desired node.
    for(i=0;i<no;i++)
    {
        visited[i] = 0;
        shortest_path[i] = -1; // Giving the infinite value(here we gave -1) shortest_path array...
        adjacentNodes[i] = 0;
    }
    int queue[no], top= -1, bottom = -1; //top and bottom : Variable which point to the top and bottom elements of the queue...
    visited[source] = 1;
    shortest_path[source] = 0;
    unvCount++;
    i=0;

    adjacent(fmatrix, source, adjacentNodes);
    DistanceAssign(fmatrix,shortest_path, adjacentNodes,source, path);
     while(unvCount != no )
     {
         for(i=0;i<no;i++)
        {
            if(fmatrix[node][i] != 0 && visited[i] == 0)
            {
                enqueue(queue, &top,i,&bottom);
                visited[i] = 1;
            }
            if((top != -1) && (i == no-1) && (bottom <= top))
            {
                node = queue[bottom];
                    adjacent(fmatrix, node, adjacentNodes);
                    DistanceAssign(fmatrix,shortest_path, adjacentNodes,node, path);
                dequeue(&bottom);
                visited[node] = 1;
                unvCount++;
                i= -1;
            }
        }
      }
     printf("\n\n\n\t\t\t\t\t The Shortest Distance between the: \n\t\t\t");
     printf("\n\t\t\t\t SOURCE Node - %d   and  DESTINATION Node - %d  :   %d \n\n",source,destn,shortest_path[destn]);
}

int main()
{
    printf("\n\n\t\t\t//---------------------------------------- // Project Based Learning // ----------------------------------------//\n");
    printf("\n\n\n\t\t\t\t\t//------------------------- // SHORTEST PATH FINDER // -------------------------//\n");
    printf("\n\n\t\t\t\t       // Program to find the SHORTEST PATH between the SOURCE and the DESTINATION node //\n");
    printf("\n\n\n\n\t\t\t\t\t\t BY :    Kshitij Sangar --------A_52   \n\t\t\t\t\t\t\t Rajwardhan Sagare------A_51  \n\t\t\t\t\t\t\t Vaishnavi Patil--------A_41  \n\t\t\t\t\t\t\t Siddhi Patil-----------A_40");
    int source, destn, run =1;
	printf("\n\n Enter the number of nodes in the  graphs : ");
	scanf("%d",&no);

	printf("\n If any link is present, then enter the DISTANCE between the nodes else enter 0.\n");
	int matrix[no][no];
	struct PathCal path[no] , namelist[no];
	printf("\n\n\t:::::: Enter the NAMES of the NODES ::::::\n");
    for(i=0; i<no; i++)
    {
        printf("\n\t NAME of NODE - %d  :  ",i+1);
        scanf("%s",namelist[i].name);
    }

	for(i=0; i<no; i++)
    {
        for(j=0; j<no; j++)
        {
            matrix[i][j] = 0;
        }
    }
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
				printf("\n Is there a link between %s & %s : ",namelist[i].name, namelist[j].name);
				scanf("%d",&matrix[i][j]);
			}
		}
	}
	char tsource[25], tdestn[25];
	while(run == 1)
	{
	    printf("\n\n\n\t What is the SOURCE NODE : ");
        scanf("%s", tsource);

        printf("\n\n\n\t What is the DESTINATION NODE : ");
        scanf("%s", tdestn);
        i=0,j=0, source = NULL, destn = NULL;
        int c=0;
        while(j != 2 && c < no)
        {
            c++;
            if(strcmp(namelist[i].name , tsource) == 0)
            {
                j++;
                source = i;
                printf("\n\t in 1st if......j = %d , c = %d , namelist[i].name = %s , tsource = %s",j,c,namelist[i].name,tsource);
            }
            if(strcmp(namelist[i].name , tdestn) == 0)
            {
                j++;
                destn = i;
                printf("\n\t in 2st if......j = %d , c = %d , namelist[i].name = %s , tdestn = %s",j,c,namelist[i].name,tdestn);
            }
        }
        if(j != 2)
        {
            printf("\n\n\t\t Invalid SOURCE or DESTINATION NAMES...!");
            break;
        }

        ShortestPathFinder(matrix, source, destn, path);
        i = destn;
        printf("\n\n\t\t\t\t Shortest Path : %d",i);
        while(path[i].prev != source)
        {
            printf(" <-- %d",path[i].prev);
            i = path[i].prev;
        }
        printf(" <-- %d",path[i].prev);
        printf("\n\n\n\t To FIND more SHORTS PATHS, press 1, else 0  :  ");
        scanf("%d",&run);
	}
return 0;
}
