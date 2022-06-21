#include<stdio.h>

int main()
{

    int i, p, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf(" ENTER TOTAL NO. OF PROCESSES-: ");
    scanf("%d", &p);
    y = p;

	for(i=0;i<p;i++)
	{
		printf("\n PROCESS[%d] \n", i+1);
		printf(" ARRIVAL TIME-: ");
		scanf("%d", &at[i]);
		printf(" BURST TIME-: ");
		scanf("%d", &bt[i]);
		temp[i] = bt[i];
	}

	printf("\nENTER TIME QUANTUM -:");
	scanf("%d", &quant);
	printf("\n Process No\t\tArrival Time\t\tBurst Time\t\tTAT\t\tWaiting Time");
	for(sum=0, i = 0; y!=0; )
	{
		if(temp[i] <= quant && temp[i] > 0)
		{
		    sum = sum + temp[i];
		    temp[i] = 0;
		    count=1;
		}
		else if(temp[i] > 0)
		    {
			  temp[i] = temp[i] - quant;
			  sum = sum + quant;
		    }
		if(temp[i]==0 && count==1)
			{
			  y--;
	printf("\nProcess No[%d]\t\t%d\t\t\t%d\t\t\t%d\t\t%d",i+1,at[i],bt[i],sum-at[i],sum-at[i]-bt[i]);  
			  wt = wt+sum-at[i]-bt[i];
			  tat = tat+sum-at[i];
			  count =0;
	    		}
	    	if(i==p-1) i=0;
	    	else if(at[i+1]<=sum)i++;
	    	else i=0;
	}avg_wt = wt * 1.0/p;
	avg_tat = tat * 1.0/p;
	printf("\nAverage Waiting Time: \t%f\n", avg_tat);
	printf("\n Average Turn Around Time: \t%f\n", avg_wt);
	return 0;
}
