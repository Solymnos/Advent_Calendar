#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isSafe(string str)
{
    string delimiter = " ";
    string token;
    int nb, diff;
    vector<int> v;
    size_t pos = 0;

    // VECTOR RECUPERATION

    cout << str;
    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        nb = stoi(token);
        v.push_back(nb);
        str.erase(0, pos + delimiter.length());
    }
    v.push_back(stoi(str));
    cout << " : " << v.size() << endl << "\t";
    // TEST IF ALL DESCENDING/ASCENDING

    if (v[0] > v[1])
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                cout << " UNSAFE (not only ascending)" << endl;
                return false;
            }
        }
    } else {
        for (int k = 0; k < v.size() - 1; k++)
        {
            if (v[k] > v[k + 1])
            {
                cout << " UNSAFE (not only descending)" << endl;
                return false;
            }
        }
    }

    // TEST IF DIFFERENCE BETWEEN 1 & 3

    for (int i = 0; i < v.size() - 1; i++)
    {
        diff = abs(v[i] - v[i + 1]);
        if (diff < 1 || diff > 3)
        {
            cout << " UNSAFE (step) " << v[i] << "/" << v[i+1] << ":" << diff << endl;
            return false;
        }
    }
    cout << " SAFE" << endl;
    return true;
}

int main()
{
    string str;
    int safeCount = 0;
    
    ifstream input("input.txt");
    if (input.is_open())
    {
        while (getline(input, str))
        {
            if (isSafe(str))
            {
                safeCount++;
            }
        }
    }
    cout << safeCount << endl;
    return 0;
}