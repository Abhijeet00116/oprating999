#include <stdio.h>
int main()
{
   
 
    int n, m, i, j, k;
    
    printf("ENTER NO.OF PROCESS & RESOURCES -: ");
    scanf("%d %d", &n, &m);
    int alloc[n][m], max[n][m], avail[m];

	for(int x=0; x<n; x++)
	{
       	printf("ENTER ALLOCATION FOR P[%d]-:\n",x);
            for(int y=0; y<m; y++)
            	scanf("%d",&alloc[x][y]);
      }
      for(int x=0; x<n; x++)
	{
       	printf("ENTER MAX NEED FOR P[%d]-:\n",x);
            for(int y=0; y<m; y++)
            	scanf("%d" , &max[x][y]);
      }
	printf("ENTER THE AVAILABLE RESOURCES -:\n");
    for(int a=0; a<m; a++){	
    	scanf("%d",&avail[a]);
	}
 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
        
      if(f[i]==0)
      {
        flag=0;
         printf("THE FOLLOWING SYSTEM IS NOT SAFE ...");
        break;
      }
    }
     
      if(flag==1)
    {
      printf("PROCESS SEQUENCE IN ORDER -:\n");
      for (i = 0; i < n - 1; i++)
       printf(" P[%d] ->", ans[i]);
      printf(" P[%d]", ans[n - 1]);
    }
    printf("\n");
     
 
    return 0;
}
/*
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/
