#include <iostream>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/1654

    1. X 값을 설정한다

    2. 각각의 (랜선 길이 % X) 의 합이 n보다 크거나 같은지 확인한다

    3. n보다 작아지기 직전 값을 이진탐색을 통해 찾는다

*/

int upperBound(int arr[], int size, int max, unsigned int x)
{
    unsigned int splitStart = 1;
    unsigned int splitEnd = max + 1;

    while (splitStart < splitEnd)
    {
        unsigned int splitMid = (splitStart + splitEnd) / 2;
        unsigned int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i] / splitMid;

            // sum 값이 x보다 크면, 더 더할 필요가 없으므로 멈춘다
            if (sum > x)
                break;
        }

        // Start 값이 커질수록 sum 값은 작아지기 때문에
        // sum 이 x 보다 크거나 같으면 Start를 증가시킨다
        if (sum >= x)
        {
            splitStart = splitMid + 1;
        }
        else
        {
            splitEnd = splitMid;
        }
    }
    return splitEnd;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    int arr[n];
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (maxLength < arr[i])
            maxLength = arr[i];
    }

    // upperBound는 최대값보다 1 크기때문에 빼준다
    int targetLength = upperBound(arr, n, maxLength, k) - 1;

    cout << targetLength;
}