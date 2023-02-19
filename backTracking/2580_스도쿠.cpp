#include <iostream>
#include <vector>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/2580

      스도쿠에서 비어 있는 곳을 적절한 값을 찾아 넣는다

    1. 가로줄 배열을 만들어서 해당 가로줄에서 특정 수가 들어갈 수 있는 지 확인한다
      (1번 row에 3의 수가 이미 있다면, row[1][3] = true 의 형태로 표시)

    2. 세로줄 배열을 만들어서 해당 가로줄에서 특정 수가 들어갈 수 있는 지 확인한다

    3. 영역별 배열을 만들어서 해당 가로줄에서 특정 수가 들어갈 수 있는 지 확인한다
      영역은 아래와 같이 계산하며, row / 3 + (col / 3) * 3 으로 계산한다

      0 1 2
      3 4 5
      6 7 8

    4. 3개의 영역 모두가 false 인 경우에만 backTracking을 반복하며,
      모든 빈칸을 채웠을 때 멈춘다

    5. 한 번만 스도쿠를 완성시키면, 더이상 backTracking을 할 필요가 없기 때문에
      isSuccess 변수를 통해, 성공했다면 재귀를 멈추도록 한다

*/

int blankCount = 0;
int arr[9][9];
// 빈 곳의 좌표를 (x, y)로 저장
pair<int, int> blankArr[81];

// 한 번이라도 스도쿠를 완성시켰다면,
// Success를 확인하여 재귀에서 빠져나온다
bool isSuccess = false;

bool row[9][10] = {
    false,
};
bool col[9][10] = {
    false,
};
bool area[9][10] = {
    false,
};

void backTracking(int cur)
{
    if (blankCount == cur)
    {
        isSuccess = true;
        return;
    }

    int blankX = blankArr[cur].first;
    int blankY = blankArr[cur].second;
    int blankArea = blankX / 3 + (blankY / 3) * 3;

    // 가로, 세로의 의미가 아닌 모든 수를 반복한다는 의미로
    // i,j 가 아닌 다른 변수를 사용
    for (int k = 1; k <= 9; ++k)
    {
        if (!row[blankY][k] && !col[blankX][k] && !area[blankArea][k])
        {
            arr[blankY][blankX] = k;

            row[blankY][k] = true;
            col[blankX][k] = true;
            area[blankArea][k] = true;

            backTracking(cur + 1);

            if (isSuccess)
                return;

            arr[blankY][blankX] = 0;

            row[blankY][k] = false;
            col[blankX][k] = false;
            area[blankArea][k] = false;
        }
    }
}

void inputSudoku()
{
    for (int j = 0; j < 9; ++j)
    {
        for (int i = 0; i < 9; ++i)
        {
            int n;
            cin >> n;
            arr[j][i] = n;
            if (n == 0)
            {
                blankArr[blankCount] = {i, j};
                ++blankCount;
            }
            else
            {
                row[j][n] = true;
                col[i][n] = true;
                area[i / 3 + (j / 3) * 3][n] = true;
            }
        }
    }
}

void printSudoku()
{
    for (int j = 0; j < 9; ++j)
    {
        for (int i = 0; i < 9; ++i)
        {
            cout << arr[j][i] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    inputSudoku();

    backTracking(0);
    cout << '\n';
    printSudoku();
}
