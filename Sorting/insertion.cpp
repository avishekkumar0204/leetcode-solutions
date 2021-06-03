#include <bits/stdc++.h>
using namespace std;
void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
            else
                break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertionSort(a, n);
    for (auto e : a)
        cout << e << " ";
}

// tc:O(n*n) in worst case and O(n) in best case 
// sc: O(1)
// Stable


