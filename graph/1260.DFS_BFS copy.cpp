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
    vector<vector<int>> adjacent;

public:
    Graph(int n = 10) : size(n)
    {
        adjacent.resize(n + 1);
    }
    void addEdge(int a, int b)
    {
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    void Sort()
    {
        for (int i = 1; i < size + 1; i++)
        {
            if (!adjacent[i].empty())
                sort(adjacent[i].begin(), adjacent[i].end());
        }
    }
    void bfs(int start)
    {
        vector<int> visitied(size + 1, 0);
        deque<int> qu;

        qu.push_back(start);
        visitied[start] = 1;

        while (!qu.empty())
        {
            int next = qu.front();
            cout << next << " ";
            qu.pop_front();

            for (int v : adjacent[next])
            {
                if (visitied[v] == 0)
                {
                    visitied[v] = 1;
                    qu.push_back(v);
                }
            }
        }
    }

    void dfs(int start)
    {
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
    // g.dfs(start);
    cout << "\n";
    g.bfs(start);
}