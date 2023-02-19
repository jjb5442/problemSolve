#include <iostream>
#include <stack>

using namespace std;

/*
problem website
https://www.acmicpc.net/problem/4949


    1. string으로 모든 문자열을 받는다

    2. 각 문자열에서, ( [ 이 나오면 스택에 넣는다

    3. ) ] 이 나오면 스택에서 뺀다

    4. stack이 ( 이 있을때, ] 이 입력되거나 그 역은 'NO'를 출력한다

    5. 마지막에 stack이 empty가 아니면 'NO'를 출력한다


*/

int main()
{
    string input = "";
    bool error = false;

    while (true)
    {
        stack<int> vps;
        error = false;

        getline(cin, input, '\n');

        if (!input.compare("."))
        {
            break;
        }

        for (char c : input)
        {
            if (c == '(' || c == '[')
            {
                vps.push(c);
            }

            if (c == ')' || c == ']')
            {
                if (vps.empty())
                {
                    error = true;
                    break;
                }

                if (c == ')' && vps.top() != '(')
                {
                    error = true;
                    break;
                }

                if (c == ']' && vps.top() != '[')
                {
                    error = true;
                    break;
                }

                vps.pop();
            }
        }
        if (!error)
        {
            if (!vps.empty())
            {
                error = true;
            }
        }

        if (error)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
}