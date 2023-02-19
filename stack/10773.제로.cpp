#include <iostream>
#include <stack>

using namespace std;

/*
problem website
https://www.acmicpc.net/problem/9012


    1. stack에 입력 데이터를 넣는다

    2. 0이면 pop 한다

    3. 마지막에 다 꺼내서 더한다.


*/

int main()
{
    int num;
    stack<int> input;
    int sum = 0;

    cin >> num;

    while (num--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            input.pop();
        }
        else
        {
            input.push(x);
        }
    }

    while (!input.empty())
    {
        sum += input.top();
        input.pop();
    }

    cout << sum;
}