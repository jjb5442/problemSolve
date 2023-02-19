#include <iostream>
#include <queue>

using namespace std;

/*

problem website
https://www.acmicpc.net/problem/2164



*/

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    queue<int> q;
    int num;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        q.push(i);
    }

    int data;

    while (q.size() != 1)
    {
        q.pop();
        data = q.front();
        q.pop();
        q.push(data);
    }

    cout << q.front();
}