#include <iostream>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/14889

     각각의 가로와 세로에 해당하는 배열값이 주어지고,
    그 중에 2가지의 해당하는 값을 선택하여 차가 최소가 되게 하여야 한다

    1. (1,2) 와 (2,1) 은 한 경우로 볼 수 있기 때문에,
      (1,2)을 선택하면 (2,1)의 값을 더한다

    2. 선택한 수는 다시 선택할 수 없기 때문에,
      선택하지 않은 두 수를 선택하되, 오름차순이 되도록 선택하게 한다


*/

int n, diffMin = 40000;
int arr[21][21];
bool visited[21] = {
    false,
};

int calculateDiff()
{
    int selectedSum = 0;
    int nonSelectedSum = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // 둘 다 선택된 값이면
            if (visited[i] && visited[j])
            {
                selectedSum += arr[j][i];
                selectedSum += arr[i][j];
            }

            // 둘 다 선택되지 않은 값이면
            if (!visited[i] && !visited[j])
            {
                nonSelectedSum += arr[j][i];
                nonSelectedSum += arr[i][j];
            }
        }
    }
    return abs(selectedSum - nonSelectedSum);
}

void backTracking(int depth, int start)
{
    if (depth == n / 2)
    {
        int diff = calculateDiff();
        if (diff < diffMin)
            diffMin = diff;
    }
    for (int i = start; i < n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;

            // 현재값보다 큰 값만 탐색하기 위해 i+1을 시작값으로 설정
            backTracking(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int j = 0; j < n; ++j)
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[j][i];
        }

    backTracking(0, 0);

    cout << diffMin;
}
