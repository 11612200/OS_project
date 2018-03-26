# OS_project

Student Name: Sangeeta Sharma
Student ID :  1161200
Email Address: 1998sangeetasharma@gmail.com
GitHub Link:   https://github.com/11612200/OS_project

In this multilevel queue schedulling is used. The scenario is two queues are there. Both will run in Round Robin fashion and each queue will be assing a priority.
It is better explained in this example.
A student request for one resource and other request for the other resource.
It is required that Sudesh has to give fixed time for each request so that each will get the time(equal).
And it also seen that a faculty can also request for a resource so there a queue for facutly as well. Since faculty is higher authority than students so their prirority is higher. So they can request before the student. But between the fauclty the time is divided as the same that each faculty will get the fixed amount of time so that each will get the time to use the resource.


Process       : p1 p2 p3 p4 p5
Queue         : Q1 Q2 Q2 Q1 Q1
Burst time    : 4  4   3  2  5
Arrival time  : 0  1   2  2  8

Queue            : Q1          Q2
Priortiy         :  1          2
Queue Scheduling :  RR(TQ=3)   RR(TQ=3)

_________________________________________________________
|   P1   |   P4  | P1 |  P2    |    P5     |  P3   | P2 |
_________________________________________________________
0        3       5    6        9           14      17   18


