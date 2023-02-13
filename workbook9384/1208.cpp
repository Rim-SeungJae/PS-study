#include<cstdio>
#include<vector>
#include<unordered_map>

using namespace std;

long long int cnt;
int n,s,arr[44];
unordered_map<int,int> mem;

void bt(int sum,int c)
{
	if(mem.find(sum)!=mem.end())
	{
		mem[sum] = mem[sum] + 1;
	}
	else{
		mem[sum] = 1;
	}
	for(int i=c+1;i<=n/2;i++)
	{
		bt(sum + arr[i],i);
	}
}

void btr(int sum,int c)
{
	if(mem.find(s-sum)!=mem.end())
	{
		cnt+=mem[s-sum];
	}
	for(int i=c+1;i<n;i++)
	{
		btr(sum + arr[i],i);
	}
}

int main()
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bt(0,-1);
	btr(0,n/2);
	if(s==0) cnt--;
	printf("%lld",cnt);
}
/*
브루트포스
배열을 반으로 나눠서 각각 따로 백트래킹을 진행 후 결과를 합치는 방식으로 풀어야  시간초과가 나지 않는다
또, 가능한 경우의 수가 int의 범위를 벗어날 수도 있으므로 cnt 변수를 long long 타입으로 선언해야 한다.
여러모로 신경쓸 것이 많은 까다로운 문제.
*/ 
