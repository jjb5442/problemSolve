#include <iostream>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/2805

*/

int upperBound(int arr[], int size, int maxLength, int x)
{
    int left = 0;
    int right = maxLength + 1;
    int mid;
    unsigned int sum;

    while (left < right)
    {
        sum = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < size; i++)
        {
            sum += max(0, arr[i] - mid);

            // sum 값이 x보다 크면, 더 더할 필요가 없으므로 멈춘다
            if (sum > x)
                break;
        }

        // Left 값이 커질수록 sum 값은 작아지기 때문에
        // sum 이 x 보다 크거나 같으면 Left 증가시킨다
        if (sum >= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int input[n];
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];

        maxLength = max(maxLength, input[i]);
    }

    int targetLength = upperBound(input, n, maxLength, m) - 1;

    cout << targetLength;
}