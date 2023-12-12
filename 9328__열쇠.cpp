#include<cstdio>
#include<queue>
#include<unordered_set>
#include<cctype>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int h,w,cnt = 0;
		char arr[110][110];
		bool visited[110][110] = {0,};
		unordered_set<char> keys;
		deque<pair<int,int>> q;
		scanf("%d %d",&h,&w);
		for(int i=0;i<h;i++)
		{
			scanf("\n");
			for(int j=0;j<w;j++)
			{
				scanf("%1c",&arr[i][j]);
				if(i==0 || i==h-1 || j==0 || j==w-1)
				{
					if(arr[i][j]>='A' && arr[i][j]<='Z')
					{
						q.push_back(make_pair(i,j));
						visited[i][j] = true;
					}
					else if(arr[i][j] != '*')
					{
						q.push_front(make_pair(i,j));
						visited[i][j] = true;
					}
				}
			}
		}
		scanf("\n");
		char tmp;
		do{
			scanf("%c",&tmp);
			if(tmp>='a' && tmp<='z') keys.insert(tmp);
		}while(tmp>='a' && tmp<='z');
		while(!q.empty())
		{
			bool continue_flag = false;
			for(int i=0;i<q.size();i++)
			{
				/*
				for(int ii=0;ii<h;ii++)
				{
					for(int jj=0;jj<w;jj++)
					{
						printf("%d",visited[ii][jj]);
					}
					printf("\n");
				}
				*/
				/*
				for(auto iter=keys.begin();iter!=keys.end();iter++)
				{
					printf("%c ",*iter);
				}
				*/
				//printf("\n");
				int r,c;
				r = q.front().first;
				c = q.front().second;
				q.pop_front();
				if(arr[r][c]>='A' && arr[r][c]<='Z' && keys.find(tolower(arr[r][c])) == keys.end())
				{
					q.push_back(make_pair(r,c));
					continue;
				}
				else
				{
					continue_flag = true;
					if(arr[r][c] == '$') cnt++;
					if(arr[r][c]>='a' && arr[r][c]<='z') keys.insert(arr[r][c]);
					if(r-1>=0 && arr[r-1][c]!='*' && !visited[r-1][c])
					{
						visited[r-1][c] = true;
						if(arr[r-1][c]>='A' && arr[r-1][c]<='Z') q.push_back(make_pair(r-1,c));
						else q.push_front(make_pair(r-1,c));
					}
					if(r+1<h && arr[r+1][c]!='*' && !visited[r+1][c])
					{
						visited[r+1][c] = true;
						if(arr[r+1][c]>='A' && arr[r+1][c]<='Z') q.push_back(make_pair(r+1,c));
						else q.push_front(make_pair(r+1,c));
					}
					if(c-1>=0 && arr[r][c-1]!='*' && !visited[r][c-1])
					{
						visited[r][c-1] = true;
						if(arr[r][c-1]>='A' && arr[r][c-1]<='Z') q.push_back(make_pair(r,c-1));
						else q.push_front(make_pair(r,c-1));
					}
					if(c+1<w && arr[r][c+1]!='*' && !visited[r][c+1])
					{
						visited[r][c+1] = true;
						if(arr[r][c+1]>='A' && arr[r][c+1]<='Z') q.push_back(make_pair(r,c+1));
						else q.push_front(make_pair(r,c+1));
					}
				}
			}
			if(!continue_flag) break;
		}
		printf("%d\n",cnt);
	}
}
/*
0-1 bfs 응용하여 벽이거나 문인곳은 후순위 방문하도록 탐색
열쇠 정보 unordered map에 저장하여 문을 방문할때 열쇠가 있는지 확인
새로 추가되는 탐색 경로 없이 탐색이 한바퀴 돌면 탐색 종료
*/ 
