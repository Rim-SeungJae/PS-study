#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int dp_min[3],dp_max[3];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int arr[3];
        scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
        if(i == 0)
        {
            for(int j=0;j<3;j++)
            {
                dp_min[j] = arr[j];
                dp_max[j] = arr[j];
            }
        }
        else{
            int new_min[3],new_max[3];
            new_min[0] = min(dp_min[0],dp_min[1]);
            new_min[1] = min(dp_min[0],min(dp_min[1],dp_min[2]));
            new_min[2] = min(dp_min[1],dp_min[2]);

            new_max[0] = max(dp_max[0],dp_max[1]);
            new_max[1] = max(dp_max[0],max(dp_max[1],dp_max[2]));
            new_max[2] = max(dp_max[1],dp_max[2]);

            for(int j=0;j<3;j++)
            {
                dp_min[j] = arr[j] + new_min[j];
                dp_max[j] = arr[j] + new_max[j];
            }
        }
    }
    printf("%d %d",max(dp_max[0],max(dp_max[1],dp_max[2])),min(dp_min[0],min(dp_min[1],dp_min[2])));
}