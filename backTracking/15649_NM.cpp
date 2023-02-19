#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/15649

     1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
     값이 모두 일치하는 수열이 존재하면 안 된다

     => 순열 nPr

    1. 1부터 탐색을 시작한다

    2. 깊이를 M까지 탐색하며, 이미 나온 수가 나오면 되돌아간다

*/

int n, m;
int arr[9];
bool visitied[9] = {
    false,
};

void backTracking(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visitied[i])
        {
            visitied[i] = true;
            arr[depth] = i;
            backTracking(depth + 1);

            // backTracking이 끝나고 나면, 방문기록을 삭제한다
            visitied[i] = false;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    backTracking(0);
}
