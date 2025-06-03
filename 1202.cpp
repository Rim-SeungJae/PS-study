#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<int, int>> jewels(n);  // {무게, 가치}
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jewels[i].first, &jewels[i].second);
    }

    vector<int> bags(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &bags[i]);
    }

    sort(jewels.begin(), jewels.end());  // 무게 기준 오름차순
    sort(bags.begin(), bags.end());      // 가방 무게 오름차순

    priority_queue<int> pq;
    long long answer = 0;
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && jewels[j].first <= bags[i]) {
            pq.push(jewels[j].second);  // 가치만 넣기
            j++;
        }
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();  // 가장 가치 높은 보석 사용
        }
    }

    printf("%lld\n", answer);
}