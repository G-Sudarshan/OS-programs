// C program for implementation of shortest job first scheduling Algorithm ( for Non pre-emptive processes )

//Github link : https://github.com/G-Sudarshan/

// 18 07 2019

// Third practical program [ for GP Nashik CM Department ]

#include<stdio.h>

struct process  // C is not object oriented hence we are using structure to use it like class object. So We can access individual process's attributes
{
    char p_name[10]; // Name of process
    int order;       // Order in which the process arrived
    int burst_time;  // burst time is time required for a process to execute
    int c_time;      // completion time is time on which process is terminated / completed
    int a_time;      // arrival time is time at which process arrives for execution
    int tat;         // TAT turn around time is time for which process was in CPU it is burst time + waiting time
    int w_time;      // waiting time is time in which process is nor=t in CPU it may be in blocked state for I/O etc.
};

int main()
{
    float awt; //average waiting time for all processes
    int no, i, total_w_time = 0,j;

    /*
       no for no. of processes
       i for for loop
       total_w_time is total waiting time which is 0 at beginning
       j is for for loop

    */


    printf("Enter no. of processes to be simulated for this program : ");
    scanf("%d",&no);
    struct process p[no];

     // Take input from user for details of processes

    for(i = 0 ; i < no ; i++)
    {
        printf("Enter name of process %d : ",i+1);
        scanf("%s",&p[i].p_name);

        printf("Enter burst time of process %d : ",i+1);
        scanf("%d",&p[i].burst_time);
    }

// In following nested for loop we are performing bubble sort to sort processes in ascending order according to their burst time attribute

     for(i = 0 ; i < no ; i++)
     {
         for(j = 0 ; j < no-i-1 ; j++)
        {
            if(p[j].burst_time > p[j+1].burst_time )
            {
              struct process temp;

              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;

            }
        }
     }

     //once process are sorted we can set their order
     for(i = 0 ; i < no ; i++)
     {
         p[i].order = i+1;
     }

     p[0].a_time = 0; // first process will arrive at 0
     p[0].c_time = p[0].burst_time;
     p[0].w_time = 0;

     // In following for loop we are calculating arrival time, completion time and waiting for each process
     for(i = 1 ; i < no ; i++)
     {
         p[i].a_time = p[i-1].c_time;
         p[i].c_time = p[i].a_time + p[i].burst_time;
         p[i].w_time = p[i-1].w_time + p[i-1].burst_time;

     }

     //calculating total waiting time for finding out average waiting time
     for(i = 0 ; i < no ; i++)
     {
         total_w_time = total_w_time + p[i].w_time;
     }

     awt = total_w_time / no;

     // Printing values in tabular format
    printf("values are : \n\n\n\n");
    printf("\n\n order    name |  burst time | arrival time | completion time | waiting time |  \n\n"); // you can also print arrival and completion time here

    for(i = 0 ; i < no ; i++ )
    {
    printf("   %d       %s           %d           %d             %d                %d       \n\n",p[i].order,p[i].p_name,p[i].burst_time,p[i].a_time,p[i].c_time,p[i].w_time);
    }

    printf("\n\n\n\n\n  Average Waiting Time is %f Time units  \n\n\n\n\n\n",awt);


    return 0;
}
