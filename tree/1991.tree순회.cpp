#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/1991

    key를 부모노드로, pair.first를 왼쪽노드 pair.second를 오른쪽 노드로
    두고 tree를 만들었다

*/

unordered_map<char, pair<char, char>> tree;

void preOrder(char x)
{
    if (x == '.')
        return;
    pair<char, char> child = tree.at(x);
    cout << x;
    preOrder(child.first);
    preOrder(child.second);
}
void inOrder(char x)
{
    if (x == '.')
        return;
    pair<char, char> child = tree.at(x);
    inOrder(child.first);
    cout << x;
    inOrder(child.second);
}
void postOrder(char x)
{
    if (x == '.')
        return;
    pair<char, char> child = tree.at(x);
    postOrder(child.first);
    postOrder(child.second);
    cout << x;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int num;
    cin >> num;

    while (num--)
    {
        char p, l, r;
        cin >> p >> l >> r;

        tree.insert({p, {l, r}});
    }

    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
}