#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

/*

problem website
https://www.acmicpc.net/problem/18258


    push X: 정수 X를 큐에 넣는 연산이다.
    pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 큐에 들어있는 정수의 개수를 출력한다.
    empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    head: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/

class Node
{

private:
    int data;
    Node *link;

public:
    friend class Queue;

    Node(int data = 0)
    {
        this->data = data;
        link = NULL;
    }
};

class Queue
{
private:
    Node *head;
    Node *rear;
    int n;

public:
    Queue()
    {
        head = new Node(-1);
        rear = head;
        n = 0;
    }
    void push(int x);
    int pop();
    int size() { return n; }
    bool empty() { return head->link == NULL; }
    int front()
    {
        if (empty())
            return -1;

        return head->link->data;
    }
    int back() { return rear->data; }
};

void Queue::push(int x)
{
    Node *newNode = new Node(x);
    n++;

    if (empty())
    {
        rear->link = newNode;
        rear = newNode;
        return;
    }

    rear->link = newNode;
    rear = newNode;
}

int Queue::pop()
{
    if (empty())
    {
        return -1;
    }
    n--;

    Node *tmp = head->link;

    if (tmp == rear)
    {
        rear = head;
    }

    int data = tmp->data;
    head->link = tmp->link;

    delete tmp;

    return data;
}

void test(Queue &q)
{
    char com[7];
    cin >> com;

    if (!strcmp(com, "push"))
    {
        int x;
        cin >> x;
        q.push(x);
    }

    if (!strcmp(com, "pop"))
    {
        cout << q.pop() << "\n";
    }

    if (!strcmp(com, "size"))
    {
        cout << q.size() << "\n";
    }

    if (!strcmp(com, "empty"))
    {
        if (q.empty())
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    if (!strcmp(com, "front"))
    {
        cout << q.front() << "\n";
    }
    if (!strcmp(com, "back"))
    {
        cout << q.back() << "\n";
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Queue q;
    int num;
    cin >> num;

    while (num--)
    {
        test(q);
    }
}