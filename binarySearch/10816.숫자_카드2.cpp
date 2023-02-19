#include <iostream>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/10816

*/

int binarySearch(int arr[], int size, int x)
{
    int start = 0;
    int end = size - 1;
    int target = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
        {
            target = mid;
            break;
        }

        if (arr[mid] < x)
            start = mid + 1;

        if (arr[mid] > x)
            end = mid - 1;
    }
    return target;
}

// int targetCount(int arr[], int size, int target)
// {
//     int count = 1;
//     int left = target - 1;
//     int right = target + 1;

//     while (left >= 0)
//     {
//         if (arr[left] != arr[target])
//         {
//             break;
//         }
//         count++;
//         left--;
//     }

//     while (right < size)
//     {
//         if (arr[right] != arr[target])
//         {
//             break;
//         }
//         count++;
//         right++;
//     }
//     return count;
// }

int lowerBound(int arr[], int size, int x)
{
    int left = 0;
    int right = size;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < x)
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

int upperBound(int arr[], int size, int x)
{
    int left = 0;
    int right = size;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] <= x)
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

    cin >> n;
    int input[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int lower = lowerBound(input, n, x);
        int upper = upperBound(input, n, x);

        // 값이 없는 경우는 upper == lower 이므로 0이 나온다
        cout << upper - lower << " ";
    }
}