#include<cstdio>

int main()
{
	int a[1010]={0,},b[1010]={0,},t,n,m,sum=0,result=0;
	scanf("%d",&t);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		for(int j=0;j<i;j++)
		{
			sum-=a[j];
			for(int k=1;k<=m;k++)
			{
				sum+=b[k];
				for(int l=0;l<k;l++)
				{
					sum-=b[l];
					if(sum==t)
					{
						//printf("%d %d %d %d\n",i,j,k,l);
						result++;
					}
					sum+=b[l];
				}
				sum-=b[k];
			}
			sum+=a[j];
		}
		sum-=a[i];
	}
	printf("%d",result);
}
