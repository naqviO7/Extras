#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void customSort(int first[], int second[], int m, int n){

    unordered_map<int, int> freq;

    for (int i = 0; i < m; i++){
        freq[first[i]]++;
    }

    int index = 0;

    for (int i = 0; i < n; i++){
        while (freq[second[i]]){
            first[index++] = second[i];
            freq[second[i]]--;
        }
        freq.erase(second[i]);
    }

    int i = index;

    for (auto it = freq.begin(); it != freq.end(); it++){
        while (it->second--){
            first[index++] = (it->first);
        }
    }

    sort(first + i, first + index);
}


void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int array_1a[] = { 1, 0, -1, 0, 0, 1, 1, -1, 0, 1 };
    int array_1b[] = { 0, 1, -1 };

    int array_2a[] = { 4, 2, 10, 10, 7, 2, 10, 7, 4, 2, 4 };
    int array_2b[] = { 2, 4, 7, 10 };

    int array_3a[] = { 9, -2, 9, 23, 23, -2, 9, 23, 9, -2 };
    int array_3b[] = { 9, -2, 23 };

    int m = sizeof(array_1a) / sizeof(array_1a[0]);
    int n = sizeof(array_1b) / sizeof(array_1b[0]);

    int x = sizeof(array_1a) / sizeof(array_1a[0]);
    int y = sizeof(array_1b) / sizeof(array_1b[0]);

    int a = sizeof(array_3a) / sizeof(array_3a[0]);
    int b = sizeof(array_3b) / sizeof(array_3b[0]);


    customSort(array_1a, array_1b, m, n);
    customSort(array_2a, array_2b, x, y);
    customSort(array_3a, array_3b, a, b);

    cout << "Array 1:  ";
    printArray(array_1a, m);
    cout << endl;

    cout << "Array 2: ";
    printArray(array_2a, x);
    cout << endl;

    cout << "Array 3: ";
    printArray(array_3a, a);
    cout << endl;

    system("pause");
}
