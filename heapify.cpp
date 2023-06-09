#include <iostream>

using namespace std;

void heapify(int arr[], int i, int size)
{

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int replaceWith = i;

    if ((left >= size && right >= size) || (arr[i] > arr[left] && arr[i] > arr[right]))
        return;

    replaceWith = arr[left] > arr[right] ? left : right;

    swap(arr[i], arr[replaceWith]);
}

int main()
{

    int arr[7] = {-1, 54, 53, 55, 52, 50 , 60};
    int n = 7;

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}