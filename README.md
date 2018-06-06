# OS_project



In this multilevel queue schedulling is used. The scenario is two queues are there. Both will run in Round Robin fashion and each queue will be assing a priority.
It is better explained in this example.
A student request for one resource and other request for the other resource.
It is required that Sudesh has to give fixed time for each request so that each will get the time(equal).
And it also seen that a faculty can also request for a resource so there a queue for facutly as well. Since faculty is higher authority than students so their prirority is higher. So they can request before the student. But between the fauclty the time is divided as the same that each faculty will get the fixed amount of time so that each will get the time to use the resource.

Sudesh will handle their queries only between 10 A.M to 12 A.M .
24 hour system is being used here.

The working of  Multi-level Queue  scheduling is explained in the following example:

PROCESSES	  QUEUE/priority	BURST TIME	ARRIVAL TIME
  A        	  Q1/1	          4         	10.0
  B	          Q2/2	          2 	        11.15
  C	          Q2/2	          1	          12.0
  D	          Q1/1	          2	          12.30
  E	          Q1/1	          5	          18.0

_____________________________________________________________________
|   A	     |    D   |	    A	  |     B	    |     E	    |       C     |
---------------------------------------------------------------------
10.0     13.0      15.0     16.0        18 .0        23.0          24.0

Query Time  for:  
		              A    :  4.00
	   	            B    :  2.00
		              C    :  1.00
		              D    :  2.00
		              E    :  5.00
		
 Total time he spend on query is : 14.00 
 Average Query time is           : 2.8 



