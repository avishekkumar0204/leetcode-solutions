#include <bits/stdc++.h>
using namespace std;
void selectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minEle = a[i];
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < minEle)
            {
                minEle = a[j];
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    selectionSort(a, n);
    for (auto e : a)
        cout << e << " ";
}