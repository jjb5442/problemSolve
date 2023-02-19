#include <iostream>
#include <algorithm>

using namespace std;

/*

    problem website
    https://www.acmicpc.net/problem/1920

*/

bool binarySearch(int arr[], int length, int x)
{
    int start = 0;
    int end = length - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
            return true;

        if (arr[mid] < x)
        {
            start = mid + 1;
        }

        if (arr[mid] > x)
        {
            end = mid - 1;
        }
    }
    return false;
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
    while (m--)
    {
        int x;
        cin >> x;

        // binary_search(input, input + n, x);
        if (binarySearch(input, n, x))
            cout << '1' << '\n';
        else
            cout << '0' << '\n';
    }
}