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
���Ʈ����
�迭�� ������ ������ ���� ���� ��Ʈ��ŷ�� ���� �� ����� ��ġ�� ������� Ǯ���  �ð��ʰ��� ���� �ʴ´�
��, ������ ����� ���� int�� ������ ��� ���� �����Ƿ� cnt ������ long long Ÿ������ �����ؾ� �Ѵ�.
������� �Ű澵 ���� ���� ��ٷο� ����.
*/ 
