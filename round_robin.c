#include<stdio.h>
#include<string.h>
int main()
{
	char p[10][5];
	int et[10],wt[10],timer=3,count,pt[10],rt,i,j,totwt=0,t,n=5,found=0,m;
	float avgwt;
	// 共有5个进程
	for(i=0;i<n;i++) {
		printf("enter the process name : ");
		scanf("%s",p[i]);
		printf("enter the processing time : ");
		scanf("%d",&pt[i]);
	}
	m=n;
	wt[0]=0;
	i=0;
	do {
		// 第i个进程处理时间超过了可以使用的时间时
		if(pt[i]>timer) {
			// 计算第i个进程还需要运行多少时间
			rt=pt[i]-timer;
			// 把这个进程放到最后 
			strcpy(p[n],p[i]);
			// 最后这个进程还需要rt 的执行时间
			pt[n]=rt;
			// 需要的执行时间大于timer时候，实际只能执行timer时间
			et[i]=timer;
			n++;
		}
		else {
			// et[i]是实际执行了的时间
			et[i]=pt[i];
		}
		i++;
		// 接下来一个进程的等待时间为前一个进程的等待时间加执行时间
		wt[i]=wt[i-1]+et[i-1];
	}while(i<n);
	 
	count=0;
	for(i=0;i<m;i++) {
		for(j=i+1;j<=n;j++) {
			// 对于这种情况只要有出现在n=5以后位置的p，
			// 它们都是执行一次完整的timer之后被复制到后面的
			
			if(strcmp(p[i],p[j])==0) {
				count++;
				found=j;
			}
		}
		if(found!=0) {
			// 减去的是自身执行一个timer的时间，乘以count
			wt[i]=wt[found]-(count*timer);
			count=0;
			found=0;
		}
	}
	for(i=0;i<m;i++) {
		totwt+=wt[i];
	}
	avgwt=(float)totwt/m;
	for(i=0;i<m;i++) {
		printf("\n%s\t%d\t%d",p[i],pt[i],wt[i]);
	}
	printf("\ntotal waiting time %d\n",totwt);
	printf("total avgtime %f",avgwt);
}
