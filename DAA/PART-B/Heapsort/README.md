# OUTPUT

- Compilation command
```bash
gcc -o heap_sort heap_sort.c -lm
```
- To run
```bash
./heap_sort.c
```
- **Output :**\
Enter choice: 1.Correctness 2.Complexity - 1\
Enter the size of array: 5\
Enter 5 array elements -\
18 26 23 22 6\
Sorted array is:\
6 18 22 23 26 \
Number of swaps: 13\
\
Enter choice: 1.Correctness 2.Complexity - 2\
Enter initial size of array for complexity calculation: 100\
Size &ensp; Ascending &ensp;	cnlog(n) &ensp;	Descending	&ensp;cnlog(n)	&ensp;Random&ensp;	cnlog(n)\
100	&emsp;&emsp;788	&emsp;&ensp;&emsp;&nbsp; 1329	&emsp;&emsp;&ensp;&ensp;&nbsp; 614	&emsp;&emsp;&ensp;&nbsp;1329&ensp;&emsp;&emsp;		716	&ensp;&ensp;&emsp;1329\
200	&emsp;&ensp; 1785	&emsp;&ensp;&emsp;	3058	&emsp;&emsp;&emsp;	1404	&emsp;&nbsp;&emsp;	3058	&emsp;&emsp;1647	&ensp;&emsp;&ensp;3058\
400	&emsp;&ensp; 3970	&emsp;&ensp;&emsp;	6915	&emsp;&emsp;&emsp;	3219	&emsp;&emsp;&nbsp;	6915	&emsp;&emsp;	3663	&ensp;&ensp;&ensp; 6915\
800&ensp;&emsp;&nbsp; 8751	&ensp;&ensp;&emsp;&nbsp;	15430	&ensp;&emsp;&emsp;&nbsp;	7240	&emsp;&emsp;	15430	&ensp;&emsp;&nbsp;8128&ensp;&ensp;&ensp;	15430\
1600	&ensp;&ensp;19059	&ensp;&ensp;&emsp;	34060	&emsp;&ensp;&emsp;	16069	&ensp;&ensp;&emsp;	34060	&emsp;	17859	&ensp;&ensp;&ensp;34060\
(Considering c as 2 here)
