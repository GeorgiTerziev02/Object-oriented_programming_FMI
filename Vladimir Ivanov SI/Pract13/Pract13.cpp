#include <iostream>

template<class T>
void sort(T* arr, size_t arrLen) 
{
    // Insertion Sort
    for (size_t i = 1; i < arrLen; i++) 
    {
        T el = arr[i];
            
        size_t j = i - 1;
        while (j >= 0 && arr[j] > el) 
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = el;
    }
}

template<>
void sort<char> (char* arr, size_t arrLen) 
{
    // Counting Sort
    short countArr[26] { 0 };
	for (size_t index = 0; index < arrLen; index++)
	{
		countArr[arr[index] - 'a']++;
	}

    // Print Array
    for (size_t i = 0; i < 26; i++)
    {
        if (countArr[i] == 0)
        {
            continue;
        }

        std::cout << char('a' + i) << ": " << countArr[i] << std::endl;
    }
    std::cout << std::endl;
}


template<class T>
void print(T* arr, size_t arrLen)
{
    // Print Array
    for (size_t i = 0; i < arrLen; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int arr1[] = { 1, 9, 20, 18 };
    int arr1Len = 4;
    sort(arr1, arr1Len);
    print(arr1, arr1Len);

    char arr2[5] = { 'c', 'a', 'n', 'b', '\0'};
    int arr2Len = 4;
    sort(arr2, arr2Len);
}