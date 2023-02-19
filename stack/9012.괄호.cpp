#include <iostream>
#include <stack>

using namespace std;

/*
problem website
https://www.acmicpc.net/problem/9012


    1. stack이 empty 일때는 반드시 ( 가 나와야 한다

    2. ) 를 만나면, stack에서 ( 를 빼낸다


*/

bool checkVPS(string input)
{
    stack<char> vps;
    for (char c : input)
    {
        if (c == '(')
            vps.push(c);

        if (c == ')')
        {
            if (vps.empty())
            {
                return false;
            }
            else
            {
                vps.pop();
            }
        }
    }

    if (!vps.empty())
    {
        return false;
    }

    return true;
}

int main()
{
    int num;
    string input;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> input;
        if (checkVPS(input))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}