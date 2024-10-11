# OUTPUT

- Compilation command
```bash
gcc prims.c
```
- To run
```bash
./a.out
```
- **Output :**\
Enter the number of vertices: 9\
Enter the cost matrix: \
999 &ensp;4 &ensp;999 &ensp;999 &ensp;999 &ensp;999 &ensp;999 &ensp;8 &ensp;999\
&nbsp;4 &ensp; 999 &ensp;8 &ensp;&ensp;999 &ensp;999 &ensp;999 &ensp;999 &nbsp;11 &nbsp;999\
999 &ensp;8 &ensp;999 &ensp;&nbsp; 7 &emsp;999 &emsp;4 &emsp;999 &nbsp;999 &ensp;2\
999&nbsp;999 &ensp;7 &emsp;999 &emsp;9 &emsp;&nbsp;14 &ensp; 999 &nbsp;999 &nbsp;999\
999&nbsp;999&nbsp;999 &nbsp;&ensp; 9 &emsp;999 &ensp;10 &ensp; 999 &nbsp;999 &nbsp;999\
999&nbsp;999 &ensp;4 &ensp;&ensp; 14 &emsp;10 &ensp; 999 &ensp; 2 &ensp; 999 &nbsp;999\
999&nbsp;999&nbsp;999 &nbsp;999 &ensp; 999 &ensp; 2 &ensp; 999 &ensp; 1 &emsp;&ensp;6\
&nbsp;8 &emsp;11 &ensp;999 &nbsp;999 &ensp;999 &ensp;999 &ensp; 1 &ensp; 999 &ensp; 7\
999&nbsp;999 &ensp;2 &emsp;999 &ensp;999 &ensp;999 &ensp; 6 &emsp;&nbsp;7 &ensp; 999\
\
&emsp;Edge &emsp;&emsp;&emsp;Cost \
&emsp;0 -> 1 &emsp;&emsp;&emsp;4\
&emsp;0 -> 7 &emsp;&emsp;&emsp;8\
&emsp;7 -> 6 &emsp;&emsp;&emsp;1\
&emsp;6 -> 5 &emsp;&emsp;&emsp;2\
&emsp;5 -> 2 &emsp;&emsp;&emsp;4\
&emsp;2 -> 8 &emsp;&emsp;&emsp;2\
&emsp;2 -> 3 &emsp;&emsp;&emsp;7\
&emsp;3 -> 4 &emsp;&emsp;&emsp;9\
Minimum spanning tree cost is 37
