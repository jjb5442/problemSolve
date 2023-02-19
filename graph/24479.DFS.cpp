#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/24479

*/

class Graph
{
private:
    int size;
    int visitCount;
    vector<deque<int>> adj;

public:
    Graph(int size)
    {
        this->size = size;
        adj.resize(size + 1);
        visitCount = 0;
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void Sort()
    {
        for (int i = 1; i <= size; i++)
        {
            if (!adj[i].empty())
            {
                sort(adj[i].begin(), adj[i].end());
            }
        }
    }
    void dfs(int start, vector<int> &visited)
    {
        visited[start] = ++visitCount;

        for (int i : adj[start])
        {
            if (visited[i] == 0)
            {
                dfs(i, visited);
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

    g.Sort();
    g.dfs(r, count);

    for (int i = 1; i <= n; i++)
    {
        cout << count[i] << "\n";
    }
}
