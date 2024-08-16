# OUTPUT
- *knapsack1.c* solves the 0/1 knapsack problem using the recursive Top-Down (Memoization) approach.
- *knapsack2.c* solves the 0/1 knapsack problem using the non-recursive Bottom-Up (Tabulation) approach.
- Both approaches use **Dynamic Programming**.


- Compilation command
```bash
gcc knapsack1.c
```
- To run
```bash
./a.out
```
- **Output :**\
Enter the number of items: 4\
Enter weight and value of item 1: 2 &nbsp;12\
Enter weight and value of item 2: 1 &nbsp;10\
Enter weight and value of item 3: 3 &nbsp;20\
Enter weight and value of item 4: 2 &nbsp;15\
Enter the knapsack capacity: 5\
Knapsack table:\
0	&emsp;0&emsp;	0	&emsp;0	&emsp;0	&emsp;0	\
0	&emsp;0  &ensp;12	&ensp;12	&ensp;12	&ensp;12	\
0 &ensp; -1	&ensp;12	&ensp;22	&ensp;-1	&ensp;22	\
0  &ensp; -1	&ensp;-1	&ensp;22&ensp;-1	 &ensp;  32	\
0	&ensp; -1	&ensp;-1	&ensp;-1	&ensp;-1	&ensp; 37	
\
Maximum value: 37\
Items included in the optimal solution:\
Item 4 (weight: 2, value: 15)\
Item 2 (weight: 1, value: 10)\
Item 1 (weight: 2, value: 12)

&nbsp;

- Compilation command
```bash
gcc knapsack2.c
```
- To run
```bash
./a.out
```
- **Output :**\
Enter no. of objects : 4\
Enter weight of 4 objects : 2 &nbsp;1 &nbsp;3 &nbsp;2\
Enter Profits/values : 12 &nbsp;10 &nbsp;20 &nbsp;15\
Enter capacity : 5\
0	&emsp;0	&emsp;0	&emsp;0	&emsp;0	&emsp; 0	\
0	&emsp;0	&ensp; 12	&ensp;12	&ensp;12	&ensp;12	\
0	&ensp; 10	&ensp;12	&ensp;22	&ensp;22	&ensp;22	\
0	&ensp; 10	&ensp;12	&ensp;22	&ensp;30	&ensp;32	\
0	&ensp; 10	&ensp;15	&ensp;25	&ensp;30	&ensp;37	\
Optimal solution is : 37\
Objects selected: \
4\
2\
1
