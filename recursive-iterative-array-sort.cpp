#include <iostream>
#include <random>
#include <chrono>

using namespace::std;
const int SIZE = 1000;
void fillArray(int arr[]);
void printArray(int arr[]);
void recursiveSort(int arr[], int sortInt, int leftIndex, int rightIndex);
void iterativeSort(int arr[], int sortInt);

int main()
{
    int arr[SIZE];
    int sortInt = 0;
    srand(time(NULL));
    fillArray(arr);
    printArray(arr);
    cout << "Please input the int to sort by: ";
    cin >> sortInt;
   
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    //recursiveSort(arr, sortInt, 0, SIZE - 1);
    iterativeSort(arr, sortInt);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    printArray(arr);
    cout << "Time spent: " << duration.count() << endl;
    system("pause");
    return 0;
}

void fillArray(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

void printArray(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void recursiveSort(int arr[], int sortInt, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
    {
        return;
    }

    if (arr[leftIndex] <= sortInt)
    {
        recursiveSort(arr, sortInt, leftIndex + 1, rightIndex);
    }
    else
    {
        int temp = arr[leftIndex];
        arr[leftIndex] = arr[rightIndex];
        arr[rightIndex] = temp;
        recursiveSort(arr, sortInt, leftIndex, rightIndex - 1);
    }
}

void iterativeSort(int arr[], int sortInt)
{
    int leftIndex = 0;
    int rightIndex = SIZE - 1;

    while (leftIndex < rightIndex)
    {
        while (arr[leftIndex] <= sortInt && leftIndex < rightIndex)
        {
            leftIndex++;
        }

        while (arr[rightIndex] > sortInt && leftIndex < rightIndex)
        {
            rightIndex--;
        }

        if (leftIndex < rightIndex)
        {
            int temp = arr[leftIndex];
            arr[leftIndex] = arr[rightIndex];
            arr[rightIndex] = temp;
        }
    }
}