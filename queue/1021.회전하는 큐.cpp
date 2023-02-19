#include <iostream>
#include <deque>

using namespace std;

/*

problem website
https://www.acmicpc.net/problem/1021

*/

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    deque<int> de;

    int n, m;
    cin >> n >> m;

    int countSum = 0;

    for (int i = 1; i <= n; i++)
    {
        de.push_back(i);
    }

    while (m--)
    {
        int data, count1 = 0, count2 = 0;
        cin >> data;

        for (int i = 0; i < de.size(); i++)
        {
            if (de[i] == data)
            {
                count1 = i;
                count2 = de.size() - i;
            }
        }

        if (count1 < count2)
        {
            while (de.front() != data)
            {
                de.push_back(de.front());
                de.pop_front();
            }
            de.pop_front();
            countSum += count1;
        }
        else
        {
            while (de.front() != data)
            {
                de.push_front(de.back());
                de.pop_back();
            }
            de.pop_front();
            countSum += count2;
        }
    }
    cout << countSum << "\n";
}