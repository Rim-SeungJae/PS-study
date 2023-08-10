#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class _FILE{
  public:
    string HEAD;
    string NUMBER_str;
    int NUMBER;
    string TAIL;
    
    _FILE(string s)
    {
        auto iter = s.begin();
        while(!isdigit(*iter))
        {
            ++iter;
        }
        auto iter2 = iter;
        while(isdigit(*iter2))
        {
            ++iter2;
        }
        this->HEAD = string(s.begin(),iter);
        this->NUMBER_str = string(iter,iter2);
        this->NUMBER = stoi(string(iter,iter2));
        this->TAIL = string(iter2,s.end());
    }
};

bool operator<(_FILE a, _FILE f)
{
    if(strcasecmp(a.HEAD.c_str(), f.HEAD.c_str())<0) return true;
    else if(strcasecmp(a.HEAD.c_str(), f.HEAD.c_str())>0) return false;
    else{
        if(a.NUMBER < f.NUMBER) return true;
        else return false;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<_FILE> v;
    for(int i=0;i<files.size();i++)
    {
        v.push_back(_FILE(files[i]));
        //printf("%s %d %s\n",v[i].HEAD.c_str(),v[i].NUMBER,v[i].TAIL.c_str());
    }
    stable_sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        answer.push_back(v[i].HEAD + v[i].NUMBER_str + v[i].TAIL);
        //printf("%s %s %s\n",v[i].HEAD.c_str(),v[i].NUMBER_str.c_str(),v[i].TAIL.c_str());
    }
    return answer;
}

/*
sort: �Ҿ��� ����, stable_sort: ���� ����
sort�� ������ ��ġ�� �������� �����Ƿ� stable sort�� ����ؾ� ��
stable sort�� �ϱ����� Ŭ������ ������ �񱳿������� �����ε��� �����ؼ� �� ��
*/ 
