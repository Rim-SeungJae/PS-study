#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 200000000;

int main()
{
    vector<int> dice(6,0);

    int n;
    scanf("%d",&n);
    for(int i=0;i<6;i++) scanf("%d",&dice[i]);

    int minOf1 = INF, minOf2 = INF,minOf3 = INF;

    for(int i=0;i<6;i++) minOf1 = min(minOf1,dice[i]);

    minOf2 = min(minOf2,dice[0]+dice[1]);
    minOf2 = min(minOf2,dice[0]+dice[2]);
    minOf2 = min(minOf2,dice[0]+dice[3]);
    minOf2 = min(minOf2,dice[0]+dice[4]);
    minOf2 = min(minOf2,dice[1]+dice[2]);
    minOf2 = min(minOf2,dice[2]+dice[4]);
    minOf2 = min(minOf2,dice[4]+dice[3]);
    minOf2 = min(minOf2,dice[3]+dice[1]);
    minOf2 = min(minOf2,dice[5]+dice[1]);
    minOf2 = min(minOf2,dice[5]+dice[2]);
    minOf2 = min(minOf2,dice[5]+dice[3]);
    minOf2 = min(minOf2,dice[5]+dice[4]);
    

    minOf3 = min(minOf3,dice[1]+dice[2]);
    minOf3 = min(minOf3,dice[4]+dice[2]);
    minOf3 = min(minOf3,dice[1]+dice[3]);
    minOf3 = min(minOf3,dice[3]+dice[4]);
    minOf3 = min(minOf3+dice[0],minOf3+dice[5]);

    long long int sum=0;
    if(n == 1)
    {
        int big = 0;
        for(int i : dice)
        {
            sum += i;
            big = max(big,i);
        }
        sum-=big;
    }
    else{
        sum += (long long)minOf2 * 4 * (n-1);
        sum += (long long)minOf1 * (n-2) * 4 * (n-1);
        sum += (long long)minOf3 * 4;
        sum += (long long)minOf2 * 4 * (n-2);
        sum += (long long)minOf1 * (n-2) * (n-2);
    }
    
    printf("%lld",sum);
}