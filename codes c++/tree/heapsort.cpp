#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int pos)
{
    int lc = 2 * pos + 1;
    int rc = 2 * pos + 2;
    int minPos = pos;
    if (lc < n && arr[lc] < arr[pos])
    {
        minPos = lc;
    }
    if (rc < n && arr[rc] < arr[minPos])
    {
        minPos = rc;
    }
    if (minPos != pos)
    {
        swap(arr[pos], arr[minPos]);
        heapify(arr, n, minPos);
    }
}

int main()
{
    int n, x;
    cout << "enter size of array";
    cin >> n;

    vector<int> arr;
    vector<int> sort_res;
    cout << "enter array ";

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        arr.push_back(x);
    }

    //build min heap
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }
    /*
    n/2 -1 is the parent of the last node . 
    heap property is build from bottom to top . 
    it is necessary to apply heap condition (ie parent < children ) to all nodes
     first time so as to get accurate heapify sort result later on.
    */

    //heap sort
    while (arr.size() != 0)
    {
        int s = arr.size();

        sort_res.push_back(arr[0]);
        arr[0] = arr[s - 1];
        arr.pop_back();

        if (s > 2)
            heapify(arr, s - 1, 0);
    }

    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << sort_res[i] << " ";
    return 0;
}