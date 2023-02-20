#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/2110

     n개의 집에 c개의 공유기를 설치할 때,
    가장 인접한 공유기 사이의 거리가 최대가 되게 하여라

    1. 입력받은 집의 좌표를 먼저 정렬해 준다

    2. 첫번째 집에는 반드시 공유기를 설치한다

    3. 일정 거리를 정하여, 그 거리 기준으로 공유기를 설치한다
      - 공유기가 충분히 설치 된다면 (curCount >= count) 거리를 늘린다
      - 공유기가 충분히 설치되지 않는다면 (curCount < count) 거리를 줄인다

    4. upperBound를 통해 한계점 바로 위값을 구하고, -1을 하여 값을 구한다
      이때, upperBound는 최대거리 + 1 의 값까지 나와야 함으로
      right의 초기값을 house[n-1] + 1 로 잡아주어야 한다


*/

int upperBound(vector<int> &house, int n, int count)
{
    int left = 1;
    int right = house[n - 1] + 1;
    // 첫번째 집에 설치했기 때문에 index 0을 기본값으로 한다

    while (left < right)
    {
        int mid = (left + right) / 2;
        // 첫번째 집에 설치했기 때문에 1개를 기본값으로 한다
        int curCount = 1;
        int curHouse = 0;
        for (int i = 1; i < n; ++i)
        {
            // 이전에 공유기 설치한 집과의 거리가, mid보다 크거나 같으면 설치한다
            if (house[i] - house[curHouse] >= mid)
            {
                curHouse = i;
                ++curCount;
            }
        }
        // 충분히 설치 가능하다면, 거리를 늘린다
        if (curCount >= count)
        {
            left = mid + 1;
        }
        // 충분히 설치 못한다면, 거리를 줄인다
        else
        {
            right = mid;
        }
    }
    return left;
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