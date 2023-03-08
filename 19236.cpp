#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class Pos{
	public:
		int r;
		int c;
		Pos(int r,int c)
		{
			this->r = r;
			this->c = c;
		}
		Pos(){
		}
};
class Fish{
	public:
		int a;
		int b;
		Fish(int a,int b)
		{
			this->a = a;
			this->b = b;
		}
		Fish(){
		}
};
class Shark{
	public:
		int r;
		int c;
		int b;
		
};

const int dirr[8] = {-1,-1,0,1,1,1,0,-1}, dirc[8] = {0,-1,-1,-1,0,1,1,1};

Shark shark;
int total = 0,max_total = 0;

bool inRange(int a)
{
	if(a>=0 && a<4) return true;
	else return false;
}

void bt(vector<Pos> param1, Fish param2[][5])
{	
	if(total > max_total) max_total = total;
	vector<Pos> pos = param1;
	Fish arr[5][5];
	copy(&param2[0][0],&param2[4][5],&arr[0][0]);
	for(int i=0;i<pos.size();i++)
	{
		int r = pos[i].r;
		int c = pos[i].c;
		if(r<0) continue;
		while(!inRange(r + dirr[arr[r][c].b]) || !inRange(c + dirc[arr[r][c].b]) || (shark.r == r + dirr[arr[r][c].b] && shark.c == c + dirc[arr[r][c].b]))
		{
			arr[r][c].b = (arr[r][c].b+1)%8;
		}
		int src_a = arr[r][c].a;
		int src_b = arr[r][c].b;
		int dst_a = arr[r+dirr[src_b]][c+dirc[src_b]].a;
		int dst_b = arr[r+dirr[src_b]][c+dirc[src_b]].b;
		pos[i] = Pos(r+dirr[src_b],c+dirc[src_b]);
		if(pos[dst_a].r>=0)pos[dst_a] = Pos(r,c);
		//printf("%d:%d %d <-> %d:%d %d\n",i+1,r,c,dst_a+1,r + dirr[arr[r][c].b],c + dirc[arr[r][c].b]);
		arr[r][c].a = dst_a;
		arr[r][c].b = dst_b;
		arr[r + dirr[src_b]][c + dirc[src_b]].a = src_a;
		arr[r + dirr[src_b]][c + dirc[src_b]].b = src_b;
		/*
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				printf("%d(%d) ",arr[i][j].a+1,arr[i][j].b+1);
			}
			printf("\n");
		}
		printf("%d %d\n",shark.r,shark.c);
		for(int j=0;j<pos.size();j++) printf("%d ",pos[j].r);
		printf("\n");
		*/
	}
	for(int i=1;inRange(shark.r+dirr[shark.b] * i) && inRange(shark.c + dirc[shark.b] * i);i++)
	{
		shark.r += dirr[shark.b] * i;
		shark.c += dirc[shark.b] * i;
		int tmp_b = shark.b;
		shark.b = arr[shark.r][shark.c].b;
		total += arr[shark.r][shark.c].a + 1;
		int tmp_r = pos[arr[shark.r][shark.c].a].r;
		int tmp_c = pos[arr[shark.r][shark.c].a].c;
		if(tmp_r<0)
		{
			total -= arr[shark.r][shark.c].a + 1;
			shark.b = tmp_b;
			shark.r -= dirr[shark.b] * i;
			shark.c -= dirc[shark.b] * i;
			continue;
		}
		pos[arr[shark.r][shark.c].a].r = pos[arr[shark.r][shark.c].a].c = -1;
		bt(pos,arr);
		pos[arr[shark.r][shark.c].a].r = tmp_r;
		pos[arr[shark.r][shark.c].a].c = tmp_c;
		total -= arr[shark.r][shark.c].a + 1;
		shark.b = tmp_b;
		shark.r -= dirr[shark.b] * i;
		shark.c -= dirc[shark.b] * i;
	}
}

int main()
{
	vector<Pos> pos;
	Fish arr[5][5];
	pos.assign(16,Pos());
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d %d",&arr[i][j].a,&arr[i][j].b);
			arr[i][j].a -= 1;
			arr[i][j].b -= 1;
			pos[arr[i][j].a] = Pos(i,j);
		}
	}
	total += arr[0][0].a + 1;
	shark.r = 0;
	shark.c = 0;
	shark.b = arr[0][0].b;
	pos[arr[0][0].a].r = -1;
	pos[arr[0][0].a].c = -1;
	bt(pos,arr);
	printf("%d",max_total);
} 
/*
복잡한 구현, 시뮬레이션
*/ 
