#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/2110

     n개의 집에 c개의 공유기를 설치할 때,
    가장 인접한 공유기 사이의 거리가 최대가 되게 하여라

    1. 최대가 되는 거리는 1 ~ (left + right) / 2 이다

    2. 일정 거리를 설정하여, 그 거리로 공유기를 설치하였을 때
      n보다 크거나 같다면 거리값을 늘려서 (left = mid + 1) 계산한다

    3. 일정 거리를 설정하여, 그 거리로 공유기를 설치하였을 때
      n보다 작다면 거리값을 줄여서 (right = mid) 계산한다


*/

int upperBound(vector<int> &house, int n, int count)
{
    int left = 1;
    // Upper Bound에서 시작값이 0, 마지막 값이 x일때
    // 최대값이 x + 1 인 경우가 있기 때문에 +1 을 해주어야 한다
    int right = house[n - 1] + 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        int curCount = 1;
        int curHouse = 0;
        for (int i = 1; i < n; ++i)
        {
            // 현재 지을려는 집과 이전에 지은 집과의 거리가
            // mid보다 크거나 같으면 짓는다
            if (house[i] - house[curHouse] >= mid)
            {
                ++curCount;
                curHouse = i;
            }
        }

        // 현재 거리가 충분히 짧다는 의미이므로, 길이를 더 늘린다
        if (curCount >= count)
        {
            left = mid + 1;
        }
        // 현재 거리가 길다는 의미이므로, 길이를 줄인다
        else
        {
            right = mid;
        }
    }
    return right;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> house;
    int n, count;
    cin >> n >> count;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        house.push_back(x);
    }

    // 먼저 집들의 좌표를 정렬해준다
    sort(house.begin(), house.end());

    cout << upperBound(house, n, count) - 1;
}