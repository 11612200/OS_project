// the code implemeneted earlier couldnt weok out i tried the new methodlogy i.e., the use of structure 
#include<stdio.h>
struct process
{
char name;
int at,bt,wt,tt,rt,pt,qt;
int completed;
float ntt;
}p[10];
int n;
int q[10],q2[10];  // two queues
int front=-1,rear=-1,front2=-1,rear2=-1;


void enqueue(int i)
{
if(rear==10)
printf("overflow");
rear++;
q[rear]=i;
if(front==-1)
front=0;

}

int dequeue()
{
 	if(front==-1)    //  ****
	return -1;	
int temp=q[front];
if(front==rear)
front=rear=-1;
else
front++;
return temp;
}
int isInQueue(int i)
{int k;
for(k=front;k<=rear;k++)
{
if(q[k]==i)
return 1;
}
return 0;
}


void enqueue2(int i)
{
if(rear2==10)
printf("overflow");
rear2++;
q2[rear2]=i;
if(front2==-1)
front2=0;

}

int dequeue2()
{
if(front2==-1)
return -1;
int temp=q2[front2];
if(front2==rear2)
front2=rear2=-1;
else
front2++;

return temp;
}

int isInQueue2(int i)
{int k;
for(k=front2;k<=rear2;k++)
{
if(q2[k]==i)
return 1;
}
return 0;
}


void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(p[i].at>p[j].at)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}

int main()
{
int i,j,time=0,sum_bt=0,tq;
char c;
        float avgwt=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 p[i].name=c;
 printf("\nEnter the arrival time and burst time of process and priority(1/2) %c: ",p[i].name);
 scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
 p[i].rt=p[i].bt;
 p[i].completed=0;
 sum_bt+=p[i].bt;
 
}
int k;
printf("\nEnter the time quantum:");
scanf("%d",&tq);

sortByArrival();
enqueue(0);          // enqueue the first process in q[].
enqueue2(0);         // enqueue the forst process in q2[].
printf("Process execution order: ");
for(time=p[0].at;time<sum_bt;)       // run until the total burst time reached
{  
 if(p[0].pt==1)  
 {		
 		
 					
   i=dequeue();
   if(i==-1)             // ****
   {
   k=-1;
   i=dequeue2();
   if(i==-1)
   k=-1;
   }
   if(p[i].rt<=tq||k==-1)
   {                          /* for processes having remaining time with less than or  equal  to time quantum  */
                       
time+=p[i].rt;
p[i].rt=0;
p[i].completed=1;          
    printf(" %c ",p[i].name);
            p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;
			p[i].qt=p[i].tt=p[i].wt;       
            //p[i].ntt=((float)p[i].tt/p[i].bt);
            for(j=0;j<n;j++)                /*enqueue the processes which have come  while scheduling */
            {
            if(p[j].at<=time && p[j].completed!=1 && isInQueue(j)!=1)
            {   
                if(p[j].pt==1)
            	enqueue(j);
            	else
            	enqueue2(j);
            
            }
           }
        }
    else               // more than time quantum
    {
    time+=tq;
    p[i].rt-=tq;
    printf(" %c ",p[i].name);
    for(j=0;j<n;j++)    /*first enqueue the processes which have come while  scheduling */
            {
            if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
             {
			   if (p[j].pt==1)                                     // ***
               enqueue(j);
               else
               enqueue2(j);
            
            }
           }
           enqueue(i);   // then enqueue the uncompleted process
           
    }
 }
 else if(p[0].pt==2)
  {
  	i=dequeue2();     
   if(p[i].rt<=tq)
   {                          /* for processes having remaining time with less than  or  equal  to time quantum  */
                       
time+=p[i].rt;
p[i].rt=0;
p[i].completed=1;          
    printf(" %c ",p[i].name);
            p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;       
            p[i].qt=p[i].tt=p[i].wt;
			//p[i].ntt=((float)p[i].tt/p[i].bt);
            for(j=0;j<n;j++)                /*enqueue the processes which have come  while scheduling */
            {
            if(p[j].at<=time && p[j].completed!=1&& isInQueue2(j)!=1)
            {
			    if(p[j].pt==2)
            	enqueue2(j);
            	else 
            	enqueue(j);
            
            }
           }
        }
    else               // more than time quantum
    {
    time+=tq;
    p[i].rt-=tq;
    printf(" %c ",p[i].name);
    for(j=0;j<n;j++)    /*first enqueue the processes which have come while scheduling */
            {
            if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue2(j)!=1)
             {
             	if(p[i].pt==2)
                enqueue2(j);	
				else 
			 	enqueue(j);
            
            }
           }
           enqueue2(i);   // then enqueue the uncompleted process
           
    }

  
  }

        
}


printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\tQueury Time");
for(i=0;i<n;i++)
{avgwt+=p[i].wt;
printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].qt);
}
printf("\nAverage waiting time:%f\n",avgwt/n);
}
