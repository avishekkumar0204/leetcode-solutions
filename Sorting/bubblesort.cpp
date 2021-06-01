#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapCnt = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapCnt++;
            }
        }
        // Array is sort at this point
        if (swapCnt == 0)
            break;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bubbleSort(a, n);
    for (auto e : a)
        cout << e << " ";
}

// tc: n*n(worst and best) but using swapCnt variable we can reduce best case tc to o(n).
// sc-O(1)
// Stable sorting algo
// Inplace