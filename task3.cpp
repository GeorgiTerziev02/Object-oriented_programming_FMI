#include <iostream>
using namespace std;
int main()
{
    int n, m;
    std:: cout << "N:";
    std::cin >> n;
    std::cout << "M:";
    std::cin >> m;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[j][i]<<" ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        delete arr[i];
    }
    delete[] arr;
}