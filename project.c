#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() 
{ 
 
  main()
{
int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;
clrscr();
printf("Enter the number of processes --- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i] = i;
printf("Enter the Burst Time of Process %d --- ", i);
scanf("%d",&bt[i]);
printf("System/User Process (0/1) ? --- ");
scanf("%d", &su[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(su[i] > su[k])
{
temp=p[i];
p[i]=p[k];
p[k]=temp;
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=su[i];
su[i]=su[k];
su[k]=temp;
}
getch();
}

