#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/15650

     1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
     값이 모두 일치하는 수열이 존재하면 안 된다

     => 조합 nCr

    1. 1부터 탐색을 시작한다

    2. 깊이를 M까지 탐색하며, 이미 나온 수가 나오면 되돌아간다

    3. 순서만 다른 수열이 있으면 안 됨으로 뒤의 값을 탐색할 때는
      이전 값에 1을 더하여 backTracking을 반복한다

*/

int n, m;
int arr[9];
bool visitied[9] = {
    false,
};

void backTracking(int num, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; ++i)
    {
        if (!visitied[i])
        {
            visitied[i] = true;
            arr[depth] = i;

            // 현재 선택된 i 값보다 1크게 넘기면
            // 다음 수열에서 이전과 같은 수열이 나오지 않게 된다
            backTracking(i + 1, depth + 1);
            visitied[i] = false;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    backTracking(1, 0);
}
