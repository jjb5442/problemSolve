#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/24444

*/

class Graph
{
private:
    int size;
    vector<deque<int>> adj;

public:
    Graph(int size)
    {
        this->size = size;
        adj.resize(size + 1);
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void bfs(int start, vector<int> &visited)
    {
        for (int i = 1; i <= size; i++)
        {
            if (!adj[i].empty())
            {
                sort(adj[i].begin(), adj[i].end());
            }
        }

        int visitCount = 0;

        deque<int> q;

        visited[start] = ++visitCount;
        q.push_back(start);

        while (!q.empty())
        {
            start = q.front();
            q.pop_front();
            for (int i : adj[start])
            {
                if (visited[i] == 0)
                {
                    visited[i] = ++visitCount;
                    q.push_back(i);
                }
            }
        }
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> count;
    Graph g(n);

    count.resize(n + 1, 0);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        g.addEdge(a, b);
    }

    g.bfs(r, count);

    for (int i = 1; i <= n; i++)
    {
        cout << count[i] << "\n";
    }
}
