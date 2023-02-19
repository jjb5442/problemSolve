#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/11725

    1. Tree 에 노드를 입력받아 연결한다

    2. root로 부터 모든 원소를 순회하며
       부모 원소를 vector에 저장한다

*/

void findParent(unordered_map<int, vector<int>> &tree, vector<int> &parent)
{
    deque<int> queue;
    queue.push_back(1);
    while (!queue.empty())
    {
        int front = queue.front();
        queue.pop_front();

        for (int i : tree[front])
        {
            if (parent[i] == 0)
            {
                queue.push_back(i);
                parent[i] = front;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int num;
    cin >> num;

    vector<int> parent;
    parent.resize(num + 1, 0);

    unordered_map<int, vector<int>> tree;

    for (int i = 0; i < num - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    findParent(tree, parent);

    for (int i = 2; i <= num; i++)
    {
        cout << parent[i] << '\n';
    }
}