//#####################################################################################################################################################
//--------------------------------------------------- ONLINE SYSTEM FOR HNDLING QUERIES----------------------------------------------------------------
//#####################################################################################################################################################

#include<pthread.h>
#include<stdio.h>
struct process
{
char name;
float at,bt,wt,tt,rt,pt,qt;   // arrival time, burst time, waiting time , turnaround time , remaining  time ,  priority, query time
int completed;
float ntt;
}p[10];

int n;
float q[10],q2[10];  // two queues one for student  other for the faculty
int front=-1,rear=-1,front2=-1,rear2=-1;


void enqueue(int i)    // for entering the process/student  in the queue 1
{
	
rear++;
q[rear]=i;
if(front==-1)
front=0;

}

int dequeue()  // for removing  the process student out of  the queue 1
{
 	if(front==-1)    
	return -1;	
int temp=q[front];
if(front==rear)
front=rear=-1;
else
front++;
return temp;
}

int isInQueue(int i)  // for checking whether process is already there in the queue 1
{int k;
for(k=front;k<=rear;k++)
{
if(q[k]==i)
return 1;
}
return 0;
}


void enqueue2(int i)  // for entering the process/faculty  in the queue 2
{
//if(rear2==10)
//printf("overflow");
rear2++;
q2[rear2]=i;
if(front2==-1)
front2=0;

}

int dequeue2()        // for removing  the process/faculty out of  the queue 2
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

int isInQueue2(int i)     // for checking whether process is already there in the queue 2
{int k;
for(k=front2;k<=rear2;k++)
{
if(q2[k]==i)
return 1;
}
return 0;
}


void sortByArrival()     // sorting the process with their  busrt time and on the basis of their arrival time.
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
float time=0,sum_bt=0,tq;
pthread_t t1;
int i,j;
char c;
        float totqt=0;
 printf("_____________________________________________________________________________\n");
 printf("--------------------ONINE SYSTEM FOR HANDLING QUERIES-------------------------\n"); 
 printf("______________________________________________________________________________\n");      
 printf("\n\nEnter no. of processes(students+faculty):");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 p[i].name=c;
 printf("\nEnter the arrival time and burst time of process and priority(1 for faculty/ 2 for student) %c: ",p[i].name);

 scanf("%f%f%f",&p[i].at,&p[i].bt,&p[i].pt);
 if(p[i].bt<=0)
 {
 	printf("\n\n\tXXX Invalid Burst Time, (must be >0) enter again ----XXX");
 	printf("\nEnter the arrival time and burst time of process and priority(1/2) %c: ",p[i].name);
 	scanf("%f%f%f",&p[i].at,&p[i].bt,&p[i].pt);
 	
 }
  
  if(p[i].pt!=1||p[i].pt!=2)
 {
 	printf("\n   XXX Wrong priority XXX must  be only \"1\" for student and \"2\" for  faculty\n");
 	printf("\n\t Press ENTER to again fill the  details\n");
 }
 
if(p[i].at<10||p[i].at>24)
{
	printf("\n\n\t XXXX  arrival time should be between(10-24) and minutes in decimal XXXX");  /* time is taken as 24 hour system (time shoud be between 10 am  to 12 am i.e, 10-24)
	                                                        minutes must be entered in decimal*/
	printf("\n\nEnter the arrival time and burst time of process and priority(1/2) %c: ",p[i].name);
	scanf("%f%f%f",&p[i].at,&p[i].bt,&p[i].pt);
}

 p[i].rt=p[i].bt;
 p[i].completed=0;
 sum_bt+=p[i].bt;
 
}
int k,l;
printf("\nEnter the time quantum:");
scanf("%f",&tq);
pthread_create(&t1,NULL,sortByArrival,NULL);
pthread_join(t1,NULL);

if(p[0].pt==1)
enqueue(0);     // enqueue the first process in q[].   
else
       {
	    enqueue2(0);    // // enqueue the forst process in q2[].
	   }
	   
	           
printf("\n\nProcess execution order: \n");
for(time=p[0].at;time<sum_bt+p[0].at;)       // run until the total burst time reached
{  
		
 		
 					
   i=dequeue();
   if(i==-1)             
   {
  
   i=dequeue2();
   if(i==-1)
   //exit(0);
   return -1;     
   }
   if(p[i].rt<=tq)
   {                          // for processes having remaining time with less than or  equal  to time quantum  
                      
  float g=time; 
time+=p[i].rt;
  if(time>24)
{
	printf("\n\t\t\t XXX  Further queries  cannot  be handled  XXX\n\n");
	break;
} 
p[i].rt=0;
p[i].completed=1;
    if(p[i].pt==1)
    printf("\t\t\tfaculty %c (%.2f-%.2f)\n",p[i].name,g,time);
	else
	printf("\t\t\tstudent %c (%.2f-%.2f)\n",p[i].name,g,time);        
  //  printf(" %c ",p[i].name);
            p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;
			p[i].qt=p[i].tt-p[i].wt;       
            
            for(j=0;j<n;j++)                //enqueue the processes which have come  while scheduling 
            {
            if(p[j].at<=time && p[j].completed!=1 && isInQueue(j)!=1&&isInQueue2(j)!=1)
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
    	float m=time;
    time+=tq;
      if(time>24)
{
	printf("\n\t\t\t XXX  Further queries  cannot  be handled  XXX\n\n");
	break;
} 
    p[i].rt-=tq;
    if(p[i].pt==1)
    printf("\t\t\tfaculty %c (%.2f-%.2f)\n",p[i].name,m,time);
	else
	printf("\t\t\tstudent %c (%.2f-%.2f)\n",p[i].name,m,time);        
    //printf("\t\t\t%c (%.2f-%.2f)\n",p[i].name,m,time);
    //printf(" %c ",p[i].name);
    for(j=0;j<n;j++)                //first enqueue the processes which have come while  scheduling 
            {
            if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1&&isInQueue2(j)!=1)
             {
			   if (p[j].pt==1)                                     
               enqueue(j);
               else
               enqueue2(j);
            
            }
           }
           if(p[i].pt==1)
           enqueue(i);      // then enqueue the uncompleted process
           else
           {enqueue2(i);}
           
    }
 
        
}


printf("\n\tName\tAT\tBT\tWT\tTT\tQueury Time\n");
for(i=0;i<n;i++)
{totqt+=p[i].qt;
printf("\n\t%c\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].qt);
}
printf("\n\nTotal time he spend on queury is : %.2f",totqt);
printf("\n\nAverage query time:%.2f\n\n\n",totqt/n);
}
