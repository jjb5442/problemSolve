#include <iostream>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/9663

      크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 두어야 한다

    1. 퀸은 일직선 상으로 공격하기 때문에, 하나의 열에는 하나의 퀸만 올 수 있다

    2. 일차원 배열을 생성하여, 몇 번째 행에 퀸이 존재하는 지를 저장한다

    3. 대각선에 존재하는 좌표의 경우 (X, Y), (A,B)  =>  X - A = Y - B 가 성립한다

*/

int n, m;
int arr[15];
int count = 0;
bool visitied[15] = {
    false,
};

bool isValid(int row, int column)
{
    if (visitied[column])
        return false;

    for (int i = 0; i < row; ++i)
    {
        if (row - i == abs(column - arr[i]))
            return false;
    }

    visitied[column] = true;
    return true;
}

void backTracking(int row)
{
    if (row == n)
    {
        ++count;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (isValid(row, i))
        {
            arr[row] = i;
            backTracking(row + 1);
            visitied[i] = false;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    backTracking(0);

    cout << count;
}
