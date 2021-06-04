#include <bits/stdc++.h>
using namespace std;
void merge(int *a, int s, int mid, int e)
{
    int i = s, j = mid + 1, k = 0;
    int temp[e - s + 1];
    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= e)
        temp[k++] = a[j++];
    k = 0;
    for (int i = s; i <= e; i++)
        a[i] = temp[k++];
}
void mergeSort(int *a, int s, int e)
{
    if (s == e)
        return;
    int mid = (s + e) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, mid, e);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (auto e : a)
        cout << e << " ";
}



bool path(TreeNode *root,int k,vector<TreeNode *> &p)
{
    if(root==NULL)
        return false;
    if(root->val==k)
    {
        p.push_back(root);
        return true;
    }
    bool 
}

last->next=head2;
head2->prev=last1;
