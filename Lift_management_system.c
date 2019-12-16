
// LIFT MANAGEMENT SYSTEM...

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

int swap(int*,int*);
int bubble_ascend(int,int);
int bubble_descend(int,int);
int execute_lift_movement_1(); //  end > current
int execute_lift_movement_2(); // current > end

int endflr[10],currentflr,ptr=0;
int ascend_ptr=0, descend_ptr=0,ascend[10],descend[10];

int main()
{
    int flag=1;
    printf("\n ----: The building is of TOTAL 10 FLOORS :----\n");
    printf("\n Please enter your current floor = ");
    scanf("%d",&currentflr);
    printf("\n\n\n\n");
    while(flag==1)
    {
        printf("\n\n Enter the floor you want to go to : ");
        scanf("%d",&endflr[ptr]);
        ptr++;

        printf("\n ::Press 1 to enter floor  or 0 to go = ");
        scanf("%d",&flag);

    }

//.....................Sorting the data here down below..................

if(endflr[0]>currentflr)           // to check the criteria for sorting the array.Means either ascending(going up) or descending(going down).
{
    for(int i=0; i<(ptr-1); i++)         //sorting..
    {
        if(endflr[i]>currentflr)
        {
            ascend[ascend_ptr]=endflr[i];
            ascend_ptr++;
        }
        else
        {
            descend[descend_ptr]=endflr[i];
            descend_ptr++;
        }
    }



    //.....Ascending sorting.......
     for(int i=0; i<ascend_ptr-1; i++)
    {
        for(int j=0; j<ascend_ptr-i-1; j++)
        {
            if(ascend[j]>ascend[j+1])
            {
                swap(&ascend[j],&ascend[j+1]);
            }

        }
    }


     //....Descending sorting....
     for(int i=0; i<descend_ptr-1; i++)
    {
        for(int j=0; j<descend_ptr-i-1; j++)
        {
            if(descend[j]<descend[j+1])
            {
                swap(&descend[j],&descend[j+1]);
            }

        }

    }

execute_lift_movement_1();//ascending array to execute first
execute_lift_movement_2();//descending array to execute second

}


else  // endflr[i] < currentflr
{
    for(int i=0; i<(ptr-1); i++)         //sorting..
    {
        if(endflr[i]<currentflr)
        {
            descend[descend_ptr]=endflr[i];
            descend_ptr++;
        }
        else
        {
            ascend[ascend_ptr]=endflr[i];
            ascend_ptr++;
        }
    }


    //....Descending sorting....
     for(int i=0; i<descend_ptr-1; i++)
    {
        for(int j=0; j<descend_ptr-i-1; j++)
        {
            if(descend[j]<descend[j+1])
            {
                swap(&descend[j],&descend[j+1]);
            }

        }

    }


    //.....Ascending sorting.......
     for(int i=0; i<ascend_ptr-1; i++)
    {
        for(int j=0; j<ascend_ptr-i-1; j++)
        {
            if(ascend[j]>ascend[j+1])
            {
                swap(&ascend[j],&ascend[j+1]);
            }

        }
    }


execute_lift_movement_2();//descending array to execute first
execute_lift_movement_1();//ascending array to execute second


}

//...........END of sorting the data.................................

    return 0;
}







int swap(int *first, int *second)
{
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}


int execute_lift_movement_1() // end >current
{

    for(int i=0; i<ascend_ptr ; i++)
    {
        if(0<=ascend[i] && ascend[i]<=10)
        {
                    printf("\n\n\n\n\n\n\n");
                    for(int i=currentflr ; i<=ascend[i] ; i++)//...............................
                    {
                        Sleep(2000);
                        printf("\r\t\t\t\t\t\t%d - FLOOR",i);

                    }

                    currentflr=ascend[i];
                    printf("\n\n%d- Floor reached.\nThank you for visiting.\n\n",ascend[i]);

        }

        else
        {
            printf("\n Sorry, the building has 10 floors.\n Invalid inputs...");
        }



    }


}



int execute_lift_movement_2()// current > end
{
    for(int i=0; i<descend_ptr; i++)
    {
        if(0<=descend[i] && descend[i]<=10)
        {

            printf("\n\n\n\n\n\n\n");
            for(int i=currentflr ; i>=descend[i] ; i--)
            {

                printf("\r\t\t\t\t\t\t%d - FLOOR",i);
                Sleep(2000);
            }

            currentflr = descend[i];
            printf("\n\n%d- Floor reached.\nThank you for visiting.\n\n",descend[i]);


        }

        else
        {
            printf("\n Sorry, the building has 10 floors.\n Invalid inputs...");
        }

    }


}
