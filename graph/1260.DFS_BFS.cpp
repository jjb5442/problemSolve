#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/1260

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
    void bfs(int start)
    {
        vector<int> visited;
        deque<int> queue;
        visited.resize(size + 1, false);

        visited[start] = true;
        queue.push_back(start);

        while (!queue.empty())
        {
            int front = queue.front();
            cout << front << " ";
            queue.pop_front();

            for (int i : adj[front])
            {
                if (visited[i] == false)
                {
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }
    }
    void dfs(int start)
    {
        vector<int> visited;
        visited.resize(size + 1, false);

        dfsUtil(start, visited);
    }
    void dfsUtil(int start, vector<int> &visited)
    {
        cout << start << " ";
        visited[start] = true;
        for (int i : adj[start])
        {
            if (visited[i] == false)
            {
                dfsUtil(i, visited);
            }
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, start;
    cin >> n >> m >> start;

    Graph g(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.Sort();
    g.dfs(start);
    cout << "\n";
    g.bfs(start);
}