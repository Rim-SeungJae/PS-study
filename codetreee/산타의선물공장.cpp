#include <cstdio>
#include<vector>
#include<list>
#include<map>
#include<algorithm>

using namespace std;

struct Product{
	int id,w;
	bool operator ==(int id)
	{
		return id == this->id;
	}
};

int q,n,m,target;
vector<list<Product>> belt;
map<int,int> table;
bool isBroke[11];

bool condition(Product p)
{
	return target == p.id;
}

int main() {
    // 여기에 코드를 작성해주세요.
	scanf("%d",&q);
	for(int t=0;t<q;t++)
	{
		int cmd;
		scanf("%d",&cmd);
		if(cmd == 100)
		{
			scanf("%d %d",&n,&m);
			belt.assign(m,list<Product>());
			int id[100010],w[100010];
			for(int i=0;i<n;i++)
			{
				scanf("%d",&id[i]);
			}
			for(int i=0;i<n;i++)
			{
				scanf("%d",&w[i]);
			}
			for(int i=0;i<n;i++)
			{
				Product p;
				p.id = id[i];
				p.w = w[i];
				table.insert(make_pair(id[i],i/(n/m)));
				belt[i/(n/m)].push_back(p);
			}
		}
		else if(cmd == 200)
		{
			int max_w,sum=0;
			scanf("%d",&max_w);
			for(int i=0;i<m;i++)
			{
				if(isBroke[i]) continue;
				if(belt[i].front().w<=max_w)
				{
					sum+=belt[i].front().w;
					table.erase(belt[i].front().id);
					belt[i].pop_front();
				}
				else{
					belt[i].push_back(belt[i].front());
					belt[i].pop_front();
				}
			}
			printf("%d\n",sum);
		}
		else if(cmd == 300)
		{
			int r_id;
			scanf("%d",&r_id);
			auto iter = table.find(r_id);
			if(iter != table.end())
			{
				target = iter->first;
				belt[iter->second].erase(remove_if(belt[iter->second].begin(),belt[iter->second].end(),condition));
				printf("%d\n",iter->first);
				table.erase(r_id);
			}
			else{
				printf("-1\n");
			}
		}
		
		else if(cmd == 400)
		{
			int f_id;
			scanf("%d",&f_id);
			auto iter = table.find(f_id);
			if(iter != table.end())
			{
				printf("%d\n",iter->second+1);
				auto loc = find(belt[iter->second].begin(),belt[iter->second].end(),f_id);
				if(loc!=belt[iter->second].begin())belt[iter->second].splice(belt[iter->second].begin(),belt[iter->second],loc,belt[iter->second].end());
			}
			else{
				printf("-1\n");
			}
		}
		
		else if(cmd == 500)
		{
			int b_num;
			scanf("%d",&b_num);
			b_num--;
			if(!isBroke[b_num])
			{
				isBroke[b_num] = true;
				int toss = b_num;
				while(isBroke[toss]) toss = (toss+1)%m;
				for(auto iter = belt[b_num].begin();iter!=belt[b_num].end();iter++)
				{
					table[iter->id] = toss;
				}
				belt[toss].splice(belt[toss].end(),belt[b_num]);
				printf("%d\n",b_num+1);
			}
			else{
				printf("-1\n");
			}
		}
		
		
		for(int i=0;i<belt.size();i++)
		{
			for(auto j=belt[i].begin();j!=belt[i].end();j++)
			{
				printf("%d(%d) ",(*j).id,j->w);
			}
			printf("\n");
		}
		
	}
    return 0;
}
