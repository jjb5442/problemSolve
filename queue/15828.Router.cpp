#include <iostream>
#include <queue>

using namespace std;

/*

problem website
https://www.acmicpc.net/problem/15828



*/

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;

    queue<int> router;

    int data = 0;

    while (1)
    {
        cin >> data;

        if (data == -1)
            break;

        if (data != 0)
        {
            if (router.size() < num)
                router.push(data);
        }
        else
        {
            router.pop();
        }
    }

    if (router.empty())
    {
        cout << "empty";
    }

    else
    {
        while (!router.empty())
        {
            cout << router.front() << " ";
            router.pop();
        }
    }
}