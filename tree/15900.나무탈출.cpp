#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/15900

    1. 게임에서 이기기 위해서는 마지막에 root에 말을 올려야한다

    2. 선공일 경우, 총 움직여야하는 횟수가 홀수여야 승리할 수 있다

    3. 한 게임에서 말을 움직이는 횟수는
       leafNode의 깊이의 합이다

    4. 1이 root 이므로, 1에서 bfs를 하여
       leafNode의 깊이의 합을 구한다


*/

int sumDepth(vector<int> tree[], int num)
{
    int sum = 0;
    vector<int> visited;
    visited.resize(num + 1, -1);

    deque<int> queue;
    queue.push_back(1);
    visited[1] = 0;

    while (!queue.empty())
    {
        int parent = queue.front();
        queue.pop_front();
        bool isVisit = false;

        // 넓이 우선 탐색을 하며 각 노드의 깊이를
        // visited 에 저장한다
        for (int i : tree[parent])
        {
            if (visited[i] == -1)
            {
                isVisit = true;
                visited[i] = visited[parent] + 1;
                queue.push_back(i);
            }
        }

        // 현 노드에서 방문한 노드가 없다는 것은
        // leaf 노드라는 것이므로, 넓이를 더해준다
        if (!isVisit)
        {
            sum += visited[parent];
        }
    }
    return sum;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int num;
    cin >> num;

    vector<int> tree[num + 1];

    for (int i = 0; i < num - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int move = sumDepth(tree, num);

    // 홀수면 승리한다
    if (move % 2 != 0)
        cout << "Yes";
    else
        cout << "No";
}