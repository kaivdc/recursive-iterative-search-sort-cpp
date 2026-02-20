#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace::std;
const int SIZE = 500;
void fillArray(int arr[]);
void printArray(int arr[]);
pair<int, int> recursivePair(int arr[], int target, int lIndex, int rIndex);
pair<int, int> iterativePair(int arr[], int target);

int main()
{
    int arr[SIZE];
    int target = 0;
    srand(time(NULL));
    fillArray(arr);
    sort(arr, arr + SIZE);
    printArray(arr);
    cout << "Please input the int to search for a pair for: ";
    cin >> target;

    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    //pair<int, int> result = iterativePair(arr, target);
    pair<int, int> result = recursivePair(arr, target, 0, SIZE - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (result.first == -1)
    {
        cout << "Pair could not be found." << endl;
    }
    else
    {
        cout << "Resulting pair's positions: " << result.first << ", " << result.second << endl;
        cout << "Resulting pair's values: " << arr[result.first] << ", " << arr[result.second] << endl;
    }

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

pair<int, int> recursivePair(int arr[], int target, int lIndex, int rIndex)
{
    if (lIndex >= rIndex)
    {
        return { -1, -1 };
    }

    int sum = arr[lIndex] + arr[rIndex];
    
    if (sum == target)
    {
        return { lIndex, rIndex };
    }
    else if (sum < target)
    {
        return recursivePair(arr, target, lIndex + 1, rIndex);
    }
    else
    {
        return recursivePair(arr, target, lIndex, rIndex - 1);
    }
}

pair<int, int> iterativePair(int arr[], int target)
{
    int lIndex = 0;
    int rIndex = SIZE - 1;
    while (lIndex < rIndex)
    {

        int sum = arr[lIndex] + arr[rIndex];
        if (sum == target)
        {
            return { lIndex, rIndex };
        }
        else if (sum < target)
        {
            lIndex++;
        }
        else
        {
            rIndex--;
        }
    }
    return { -1, -1 };
}