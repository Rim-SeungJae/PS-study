#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n,arr[5050];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(&arr[0],&arr[n]);
	int l,r,m,close_idx[3];
	long long close = 3000000300;
	bool zero_flag = true, close_flag = true;
	for(int k=0;k<n-2;k++)
	{
		l = k+1;
		r = n-1;
		while(r>l)
		{
			long long sum = arr[l]+arr[r];
			if(abs(close)>abs(sum+arr[k]))
			{
				close=sum+arr[k];
				close_idx[0] = k;
				close_idx[1] = l;
				close_idx[2] = r;
			}
			if(sum+arr[k] == 0) break;
			else if(sum+arr[k] > 0) r--;
			else l++;
		}
	}
	printf("%d %d %d",arr[close_idx[0]],arr[close_idx[1]],arr[close_idx[2]]);
}
/*
투포인터 응용
2470 두용액 문제의 강화 버전
해법은 생각보다 간단하다.
k를 0부터 n-1까지 증가시켜서 -arr[k] 와 가까워지는 l과r을 투포인터로 찾으면 된다.
*/ 
