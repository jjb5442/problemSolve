#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/9934

    1. tree가 inorder 순서로 입력된다

    2. root는 2^(n-1) - 1 번째의 원소를 가지게 된다
       root보다 작은 원소의 개수는 2^(n-1)개 이고,
       index는 0부터 시작하기 때문이다

    3. tree의 깊이가 1보다 큰 동안은 child가 존재하기 때문에,
       parent의 모든 원소를 순환하며 child를 출력하고,
       각각에 해당하는 child를 childQueue에 push 한다

    4. 하나의 깊이에 대한 작업이 끝나고 나면,
       depth를 1 감소시키고,
       childQueue의 데이터를 parentQueue로 이동시킨다

    * 각 원소의 child가 아닌 current를 출력할 수 있지만,
      그렇게 할 경우, child 수 만큼 for문이 실행되어
      더 비효율적이다.


*/
void printTree(int *const &tree, int parent, int depth)
{
    cout << tree[parent] << '\n';
    deque<int> parentQueue;
    deque<int> childQueue;
    parentQueue.push_back(parent);

    // 부모 노드의 자식을 출력하기 때문에,
    // 깊이가 1부터는 자식이 존재하지 않기 때문에 depth는 1보다 커야한다
    while (depth > 1)
    {
        // 부모와 자식사이의 차이값은 2 ^ (depth - 2) 이다
        int diff = pow(2, depth - 2);
        for (int p : parentQueue)
        {
            int childLeft = p - diff;
            int childRight = p + diff;
            cout << tree[childLeft] << " " << tree[childRight] << " ";
            childQueue.push_back(childLeft);
            childQueue.push_back(childRight);
        }

        // 하나의 깊이에 대해 모든 출력이 끝난후 줄바꿈해준다
        cout << '\n';

        // child가 parent로 바뀌고, childQueue 데이터를 초기화 해준다
        parentQueue = childQueue;
        childQueue.clear();

        // 작업이 끝나면 깊이를 감소시키고 일련의 과정을 반복한다
        depth--;
    }
}

void printTree2(int *const &tree, int parent, int depth)
{
    deque<int> parentQueue;
    deque<int> childQueue;
    parentQueue.push_back(parent);

    // 부모 노드의 자식을 출력하기 때문에,
    // 깊이가 1부터는 자식이 존재하지 않기 때문에 depth는 1보다 커야한다
    while (depth > 0)
    {
        // 부모와 자식사이의 차이값은 2 ^ (depth - 2) 이다
        int diff = pow(2, depth - 2);
        for (int p : parentQueue)
        {
            int childLeft = p - diff;
            int childRight = p + diff;
            cout << tree[p] << " ";
            childQueue.push_back(childLeft);
            childQueue.push_back(childRight);
        }
        // child가 parent로 바뀌고, childQueue 데이터를 초기화 해준다
        parentQueue = childQueue;
        childQueue.clear();

        // 하나의 깊이에 대해 모든 출력이 끝난후 줄바꿈해준다
        cout << '\n';

        // 작업이 끝나면 깊이를 감소시키고 일련의 과정을 반복한다
        depth--;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int depth;
    cin >> depth;

    int size = pow(2, depth) - 1;

    int tree[size];

    for (int i = 0; i < size; i++)
    {
        cin >> tree[i];
    }

    // 최상위 부모노드의 index는 pow(2, depth - 1) - 1이다
    // 중앙을 기준으로, 2 ^ (n-1) 개 만큼의 원소가 있기 때문이다
    int root = pow(2, depth - 1) - 1;
    printTree(tree, root, depth);
}