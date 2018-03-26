#include<stdio.h>
#include<unistd.h>
main()
{
int bt[10],at[10],rt[10],q[10,p[10]; // array for burst time ,arrival time  and remaining time, queue
int q1[10],q2[10],l=0,m=0;
float tournaround=0,waiting=0;
int student,faculty,total,time=0,tq,d;
printf("\nEnter the total number of people");
scanf("%d",&total);
int i,j,temp;
	for(i=0;i<total;i++)
	{
	printf("\nYou are student(0) or Faculty(1)");
	scanf("%d",&d);
	p[i]=d;
	if(d==0)
	l++;
	else
	{m++;}
	printf("\nEnter the burst time for p%d",i);
	scanf("%d",&bt[i];
	printf("\nEnter the arrival time for p%d",i);
	scanf("%d",&at[i];
	rt[i]=bt[i];
	}
	
	printf("\nEnter the Time Quantum: ");
	scanf("%d",&tq);
	for(i=0;i<total;i++) // sorting on the basis of arrival time
		{
		for(j=0;i<total;j++)
		{
		 if(at[j+1]<a[j])
			{
			temp=at[j+1];
			at[j+1]=at[j];
			at[j]=temp;
			temp=bt[j+1];
			bt[j+1]=bt[j];
			bt[j]=temp;
			temp=p[j+1];
			p[j+1]=p[j];
			p[j]=temp;
			}          
		}
		}
	for(i=0;i<total;i++)
	{
	t++;
	if(p[i]==0)
	rt[i]=bt[i]-tq;	
}
