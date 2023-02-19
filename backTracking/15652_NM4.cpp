#include <iostream>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/15652

     1부터 N까지 자연수 중에서 M개를 고른 수열
     같은 수를 여러 번 골라도 된다.
     비내림차순 이어야 한다

    1. 1부터 탐색을 시작한다

    2. 깊이를 M까지 탐색한다

*/

int n, m;
int arr[9];
bool visitied[9] = {
    false,
};

void backTracking(int start, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++)
    {
        arr[depth] = i;
        backTracking(i, depth + 1);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    backTracking(1, 0);
}
