#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N 350

void init(int N, int mRange, int mMap[MAX_N][MAX_N]);
void add(int mID, int mRow, int mCol);
int distance(int mFrom, int mTo);

/////////////////////////////////////////////////////////////////////////

#define INIT		0
#define ADD			1
#define DISTANCE	2

static bool run()
{
	int cmd, ans, ret;
	int N, range, id, id2, r, c;
	int Q = 0;
	bool okay = false;
	int region[MAX_N][MAX_N];

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);

		switch (cmd)
		{
		case INIT:
			scanf("%d %d", &N, &range);

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					scanf("%d", &region[i][j]);

			init(N, range, region);
			okay = true;
			break;

		case ADD:
			scanf("%d %d %d", &id, &r, &c);
			add(id, r, c);
			break;

		case DISTANCE:
			scanf("%d %d", &id, &id2);
			ret = distance(id, id2);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("C:/Users/callo/Downloads/sample_input(9).txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<vector>
#include<queue>
#include<algorithm>

#define IMAX 2000000000

using namespace std;

int arr[MAX_N][MAX_N],n,range,dist[200][200],idcnt;
vector<vector<pair<int,int>>> g;

void init(int N, int mRange, int mMap[MAX_N][MAX_N])
{
    g.clear();
    g.assign(201,vector<pair<int,int>>());
    fill(&dist[0][0],&dist[199][200],IMAX);
    n = N;
    idcnt = 0;
    range = mRange;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = mMap[i][j];
        }
    }
	return;
}

void add(int mID, int mRow, int mCol)
{
    idcnt = mID+1;
    arr[mRow][mCol] = mID + 2;
    // bfs
    queue<pair<int,int>> q;
    bool visited[MAX_N][MAX_N] = {0,};
    q.push(make_pair(mRow,mCol));
    visited[mRow][mCol] = true;
    for(int i=0;i<=range;i++)
    {
        int len = q.size();
        for(int j=0;j<len;j++)
        {
            int r,c;
            r = q.front().first;
            c = q.front().second;
            q.pop();
            if(arr[r][c] > 1 && mID != arr[r][c]-2)
            {
                g[mID].push_back(make_pair(i,arr[r][c]-2));
                g[arr[r][c]-2].push_back(make_pair(i,mID));
                // if(i < dist[mID][arr[r][c] - 2]) dist[mID][arr[r][c] - 2] = dist[arr[r][c] - 2][mID] = i;
            }
            if(r-1>=0 && arr[r-1][c]!=1 && !visited[r-1][c])
            {
                visited[r-1][c] = true;
                q.push(make_pair(r-1,c));
            }
            if(r+1<n && arr[r+1][c]!=1 && !visited[r+1][c])
            {
                visited[r+1][c] = true;
                q.push(make_pair(r+1,c));
            }
            if(c-1>=0 && arr[r][c-1]!=1 && !visited[r][c-1])
            {
                visited[r][c-1] = true;
                q.push(make_pair(r,c-1));
            }
            if(c+1<n && arr[r][c+1]!=1 && !visited[r][c+1])
            {
                visited[r][c+1] = true;
                q.push(make_pair(r,c+1));
            }
        }
    }

    // dijkstra
    // priority_queue<pair<int,int>> pq;
    // pq.push(make_pair(0,mID));
    // dist[mID][mID] = 0;
    // while(!pq.empty())
    // {
    //     int cur = pq.top().second;
    //     int d = pq.top().first;
    //     pq.pop();
    //     if(d != dist[mID][cur]) continue;
    //     for(int i=0;i<g[cur].size();i++)
    //     {
    //         auto next = g[cur][i];
    //         if(dist[mID][next.second] > d+next.first)
    //         {
    //             dist[mID][next.second] = d+next.first;
    //             dist[next.second][mID] = d+next.first;
    //             pq.push(make_pair(d+next.first,next.second));
    //         }
    //     }
    // }
    
	return;
}

int distance(int mFrom, int mTo)
{
    if(mFrom>mTo) swap(mFrom,mTo);
    // int ret = dist[mTo][mFrom];
    // for(int i=0;i<idcnt;i++)
    // {
    //     if(dist[i][mTo] != IMAX && dist[i][mFrom] != IMAX)
    //     {
    //         if(dist[i][mTo] + dist[i][mFrom] < ret) ret = dist[i][mTo] + dist[i][mFrom];
    //     }
    // }
    // if(ret != IMAX) return ret;
    // return -1;
   
    // dijkstra
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    fill(&dist[mFrom][0],&dist[mFrom][200],IMAX);
    pq.push(make_pair(0,mFrom));
    dist[mFrom][mFrom] = 0;
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(cur == mTo) break;
        if(d != dist[mFrom][cur]) continue;
        for(int i=0;i<g[cur].size();i++)
        {
            auto next = g[cur][i];
            if(dist[mFrom][next.second] > d+next.first)
            {
                dist[mFrom][next.second] = d+next.first;
                dist[next.second][mFrom] = d+next.first;
                pq.push(make_pair(d+next.first,next.second));
            }
        }
    }
    if(dist[mFrom][mTo] != IMAX) return dist[mFrom][mTo];
    return -1;
}