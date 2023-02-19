#include <iostream>
#include <queue>

using namespace std;

/*

problem website
https://www.acmicpc.net/problem/11866



*/

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    queue<int> q;
    queue<int> result;

    int n, k;
    int count = 1;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {

        if (count % k == 0)
        {
            result.push(q.front());
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
        count++;
    }

    cout << "<" << result.front();
    result.pop();

    while (!result.empty())
    {
        cout << ", " << result.front();
        result.pop();
    }

    cout << ">";
}