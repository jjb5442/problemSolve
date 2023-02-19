#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/2606

*/

class Graph
{
private:
    vector<deque<int>> adj;
    int size;
    int count;

public:
    Graph(int size)
    {
        this->size = size;
        adj.resize(size + 1);
        count = 0;
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void bfs(int start)
    {
        vector<bool> visited;
        visited.resize(size + 1, false);

        deque<int> queue;

        visited[start] = true;
        queue.push_back(start);

        while (!queue.empty())
        {
            int front = queue.front();
            queue.pop_front();

            for (int i : adj[front])
            {
                if (visited[i] == false)
                {
                    count++;
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }
    }
    int getCount() { return count; }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Graph g(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    g.bfs(1);

    cout << g.getCount();
}