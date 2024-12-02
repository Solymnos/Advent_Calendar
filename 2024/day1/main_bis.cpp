#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int get_result(vector<int> listA, vector<int> listB, int size)
{
    int result = 0;
    int occ;

    for (int i = 0; i < size; i++)
    {
        occ = count(listB.begin(), listB.end(), listA[i]);
        result += (occ * listA[i]);
        cout << listA[i] << ":" << occ << endl;
    }
    return result;
}

int main()
{
    int a, b, result;
    int size = 0;
    vector<int> listA, listB;

    cout << "before input" << endl;
    ifstream input("input.txt");
    while(input >> a >> b)
    {
        listA.push_back(a);
        listB.push_back(b);
        size++;
    }
    result = get_result(listA, listB, size);
    cout << result << endl;
    return 0;
}