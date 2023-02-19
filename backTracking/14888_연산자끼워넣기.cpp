#include <iostream>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/14888

     N개의 수와, N-1개의 연산자가 주어지고,
    이를 적적히 활용하여 최대값과 최소값을 구한다

    연산자 숫자는 + - * / 순으로 입력된다

    1. 연산을 n번 시행할 때 까지 반복한다

    2. 마지막 결과값에 따라 min과 max를 결정한다

*/

int n, minValue = 1000000001, maxValue = -1000000001;
int arr[11];
int operater[4];

void backTracking(int depth, int result)
{
    if (depth == n)
    {
        if (result > maxValue)
            maxValue = result;

        if (result < minValue)
            minValue = result;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (operater[i] > 0)
        {
            --operater[i];

            if (i == 0)
                backTracking(depth + 1, result + arr[depth]);
            else if (i == 1)
                backTracking(depth + 1, result - arr[depth]);
            else if (i == 2)
                backTracking(depth + 1, result * arr[depth]);
            else if (i == 3)
                backTracking(depth + 1, result / arr[depth]);

            ++operater[i];
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < 4; i++)
        cin >> operater[i];

    backTracking(1, arr[0]);

    cout << maxValue << '\n'
         << minValue;
}
