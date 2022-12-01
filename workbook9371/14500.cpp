#include<cstdio>
#include<vector>

using namespace std;

int arr[510][510];

int fetch(int a,int &i, int &j, int n, int m)
{
	switch(a)
	{
		case 0:
			if(j+1 >= m) break;
			return arr[i][++j];
			break;
		case 1:
			if(i+1 >=n) break;
			return arr[++i][j];
			break;
		case 2:
			if(j-1 <0) break;
			return arr[i][--j];
			break;
		case 3:
			if(i-1 < 0) break;
			return arr[--i][j];
			break;
			
	}
	return -1;
}

int backward(int a,int &i,int &j)
{
	switch(a)
	{
		case 0:
			j--;
			break;
		case 1:
			i--;
			break;
		case 2:
			j++;
			break;
		case 3:
			i++;
			break;
			
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int sum=0,cnt=0;
			int &x=i,&y=j;
			sum += arr[x][y];
			/*
			for(int k=0;k<4;k++)
			{
				int val_k;
				val_k = fetch(k,x,y,n,m);
				if(val_k >= 0) sum += val_k;
				else continue;
				for(int l=0;l<4;l++)
				{
					if((l+2)%4==k) continue;
					int val_l = fetch(l,x,y,n,m);
					if(val_l >= 0) sum += val_l;
					else continue;
					for(int o=0;o<4;o++)
					{
						if((o+2)%4==l) continue;
						int val_o = fetch(o,x,y,n,m);
						if(val_o >= 0) sum += val_o;
						else continue;
						if(sum > max)
						{
							max=sum;
							printf("%d %d,i,j);
						}
						sum -= val_o;
						backward(o,x,y);
					}
					sum -= val_l;
					backward(l,x,y);
				}
				sum -= val_k;
				backward(k,x,y);
			}
			*/
			if(i+3<n)
			{
				sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
				if(sum>max) max=sum;
			}
			if(j+3<m)
			{
				sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
				if(sum>max) max=sum;
			}
			
			if(i+2<n && j+1<m)
			{
				sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
				if(sum>max) max=sum;
			}
			if(i+2<n && j-1>=0)
			{
				sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j-1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j-1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i][j-1] + arr[i+1][j-1] + arr[i+2][j-1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j-1];
				if(sum>max) max=sum;
			}
			if(j+2<m && i+1<n)
			{
				sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
				if(sum>max) max=sum;
			}
			if(j+2<m && i-1>=0)
			{
				sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+1];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+2];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i-1][j] + arr[i-1][j+1] + arr[i-1][j+2];
				if(sum>max) max=sum;
				sum = arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i-1][j+2];
				if(sum>max) max=sum;
			}
			
		}
	}
	printf("%d",max);
}
