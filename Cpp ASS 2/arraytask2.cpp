#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, pair<int, int> > ppi;

vector<int> mergeKArrays(vector<vector<int> > arr){

    vector<int> output;
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } });

    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }

    return output;
}


int main(){

    vector<vector<int> > array_1{ { 2, 5, 9, 21 },
                                { -1, 0, 2 },
                                { -10, 81, 121},
                                { 4, 6, 12, 20, 150 } };

    vector<int> output1 = mergeKArrays(array_1);

    cout << "Merged Array 1:  ";
    for (auto x : output1)
        cout << x << " ";
    cout << endl;

    vector<vector<int> > array_2{ { 10, 17, 18, 21, 29 },
                                { -3, 0, 3, 7, 8, 11 },
                                { 81, 88, 121, 131 },
                                { 9, 11, 12, 19, 29 } };

    vector<int> output2 = mergeKArrays(array_2);

    cout << "Merged Array 2:  ";
    for (auto y : output2)
        cout << y << " ";
    cout << endl;

    vector<vector<int> > array_3{ { -4, -2, 0, 2, 7 },
                                { 4, 6, 12, 14 },
                                { 10, 15, 25 },
                                { 5, 6, 10, 20, 24 } };

    vector<int> output3 = mergeKArrays(array_3);
    cout << "Merged Array 3:  ";
    for (auto z : output3)
        cout << z << " ";
    cout << endl;

    system("pause");
}
