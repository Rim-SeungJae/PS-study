#include<cstdio>
#include<vector>

using namespace std;

int top[1010];
bool visited[1010];
vector<vector<int>> v;

void spin(int idx,int dir)
{
	if(visited[idx]) return;
	visited[idx] = true;
	if(idx+1 < v.size() && v[idx][(top[idx]+2)%8] != v[idx+1][(top[idx+1]+6)%8])
	{
		spin(idx+1,-dir);
	}
	if(idx-1 >= 0 && v[idx][(top[idx]+6)%8] != v[idx-1][(top[idx-1]+2)%8])
	{
		spin(idx-1,-dir);
	}
	//printf("%d %d %dspin:%d %d\n",top[idx-1],top[idx],top[idx+1],idx,dir);
	top[idx] = (top[idx] - dir + 8)%8;
	visited[idx] = false;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		v.push_back(vector<int>());
		for(int j=0;j<8;j++)
		{
			int tmp;
			scanf("%1d",&tmp);
			v[i].push_back(tmp);
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int idx,dir;
		scanf("%d %d",&idx,&dir);
		spin(idx-1,dir);
	}
	int cnt=0;
	for(int i=0;i<v.size();i++)
	{
		//printf("%d\n",top[i]);
		if(v[i][top[i]]) cnt++;
	}
	printf("%d",cnt);
} 
/*
재귀를 활용한 구현
18행에서 >=를 >로 적는 사소한 실수 때문에 푸는데 오래걸렸음
*/ 
