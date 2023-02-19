#include <iostream>
#include <stack>

using namespace std;

/*

problem website
https://www.acmicpc.net/problem/1874


    1. 1 ~ n 값까지 stack에 push 한다

    2. 입력받은 값 x와 현재값 now가 같아지거나,
       x 가 now보다 작은 경우에는 push를 멈춘다

    3. stack 의 top과 x가 다르다면, 멈추고 "NO"를 출력한다

    4. 그렇지 않다면, pop을 한다

    5. n 값까지 모두 stack에 넣고, stack이 모두 비었다면 멈추고 결과를 출력한다

*/

int main()
{
    stack<int> st;
    int num, now = 1;
    cin >> num;
    string result = "";

    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;

        for (now; now <= x && now <= num; now++)
        {
            st.push(now);
            result += "+\n";
            if (now == x)
            {
                now++;
                break;
            }
        }

        if (st.top() != x)
        {
            result = "NO";
            break;
        }

        st.pop();
        result += "-\n";

        if (now > num && st.empty())
            break;
    }
    cout << result;
}