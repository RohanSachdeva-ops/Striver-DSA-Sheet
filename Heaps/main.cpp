#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10000);
class heap
{
    public:
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val)
    {
        size = size + 1;
        arr[size] = val;

        int index = size;
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "There is nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int ind = 1;
        while (ind < size)
        {

            int left = 2 * ind;
            int right = 2 * ind + 1;

            if (left <= size && arr[ind] < arr[left])
            {
                swap(arr[ind], arr[left]);
                ind = left;
            }
            else if (right <= size && arr[ind] < arr[right])
            {
                swap(arr[ind], arr[right]);
                ind = right;
            }
            else
            {
                return;
            }
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    int size = n;

    while (size > 0)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
}