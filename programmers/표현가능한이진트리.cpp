#include <string>
#include <vector>

using namespace std;

bool result;

int search(vector<bool> bin,long long l,long long r)
{
    if(l>r) return 0;
    if(!result) return -1;
    int mid = l + (r-l)/2;
    bool bit;
    if(mid>=bin.size()) bit= 0;
    else bit = bin[mid];
    int c1 = search(bin,l,mid-1),c2 = search(bin,mid+1,r);
    if(!bit && (c1 || c2))
    {
        result = false;
        return -1;
    }
    return bit;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(int t=0;t<numbers.size();t++)
    {
        result = true;
        long long num = numbers[t];
        vector<bool> bin;
        while(num)
        {
            bin.push_back(num%2);
            num/=2;
        }
        long long pow = 2,val = 1;
        while(val<bin.size())
        {
            val += pow;
            pow<<=1;
        }
        search(bin,0,val-1);
        answer.push_back(result);
    }
    return answer;
}

int main()
{
    printf("%d",solution(vector<long long>({128}))[0]);
}