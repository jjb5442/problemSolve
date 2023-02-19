#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/5052

    1. 전화번호의 가장 앞 숫자를 tree의 root로 받는다

    2. 각 문자열을 tree에 전부 push한다

    3. 어떤 문자열을 push하려 tree를 따라가다가
       단 한번의 push 없이 노드를 따라갔다면,
       이미 존재하는 전화번호의 앞부분과 일치한다는 것이기 때문에
       'NO'를 출력한다

    4. 어떤 문자열을 push하려 tree를 따라가다가
       push가 시작되는 지점의 노드가 자식이 없다면
       현재 전화번호가 이미 존재하는 전화번호의 앞부분을 포함한
       전화번호라는 의미이므로, 'NO'를 출력한다

       => 문자열을 내림차순으로 정렬하여,
          만약 다른 문자열을 포함하는 더 긴 문자열이 있다면
          그 문자열이 더 앞쪽으로 하게 하여 insert 시켰다
          이를 통해, 4번 조건만을 따지게 하였다

*/

class Node
{
    friend class Tree;

private:
    char data;
    vector<Node *> child;

    Node(char data)
    {
        this->data = data;
    }
};

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = new Node('.');
    }
    ~Tree();
    void freeNode(Node *);
    bool insert(string phone)
    {
        Node *tmp = root;
        for (char c : phone)
        {
            bool find = false;
            for (Node *n : tmp->child)
            {
                if (c == (*n).data)
                {
                    tmp = n;
                    find = true;
                    break;
                }
            }
            if (find == false)
            {
                Node *tmpChar = new Node(c);
                tmp->child.push_back(tmpChar);
                tmp = tmpChar;
            }
        }
        // tmp는 현재 string의 마지막 원소를 가르키고 있으므로
        // 자식이 있다는 말은 자신을 포함한 더 긴 string이 있다는 의미이다
        if (!tmp->child.empty())
        {
            return false;
        }
        return true;
    }
};

Tree::~Tree()
{
    freeNode(root);
}

void Tree::freeNode(Node *node)
{
    // 모든 자식 노드를 재귀로 탐색
    for (Node *n : node->child)
    {
        freeNode(n);
    }
    // child가 empty인 원소까지 도달하면
    // 자기 자신을 free
    free(node);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int testNum;
    cin >> testNum;

    while (testNum--)
    {
        int caseNum;
        cin >> caseNum;

        Tree t;
        string phone[caseNum];

        cin.get();
        for (int i = 0; i < caseNum; ++i)
        {
            getline(cin, phone[i]);
        }
        // 오름차순으로 정렬하여, 숫자가 같은부분이 있으면
        // 더 긴 문자열이 앞으로 오도록 정렬해준다.    ex) 11  1122 112 =>  1122 112 11
        sort(phone, phone + caseNum, greater<>());

        string result = "YES";

        for (string s : phone)
        {
            if (t.insert(s) == false)
            {
                result = "NO";
                break;
            }
        }
        cout << result << '\n';
    }
}