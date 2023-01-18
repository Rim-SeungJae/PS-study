#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n,k,maxi=0;
vector<int> v;

void bt(int target,int target_len,int prev_digit)
{
	//cout<<target<<" "<<target_len<<" "<<prev_digit<<endl;
	if(target_len<k)
	{
		int i=0;
		for(i=prev_digit;i<26;i++)
		{
			if(!(target&(1<<i)))
			{
				bt(target | (1<<i),target_len+1,i);
			}
		}
		return;
	}
	int cnt=0;
	for(int i=0;i<v.size();i++)
	{
		if((v[i] & target) == v[i])
		{
			cnt++;
		}
	}
	if(maxi<cnt) maxi = cnt;
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		string tmp;
		cin>>tmp;
		int bmap = 0;
		for(int j=0;j<tmp.length();j++)
		{
			bmap = bmap | (1<<(tmp[j] - 'a'));
		}
		v.push_back(bmap);
		//cout<<bmap<<endl;
	}
	bt(0,0,0);
	cout<<maxi;
}
/*
��Ʈ�� & ��Ʈ��ŷ
��Ʈ �������� ���� �켱������ �� ����Ͽ��� �Ѵ�
(��Ʈ �����ڴ� �� �����ں��� �켱������ ����) 
*/ 
