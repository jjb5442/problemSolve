#include <iostream>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/11725

    1. 최소 경로는 n - 1이다.

*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int num;
    cin >> num;
    while (num--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
        }
        cout << n - 1 << '\n';
    }
}