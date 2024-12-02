#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isVectorSafe(vector<int> v)
{
    int diff;

    if (v[0] > v[1])
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                return false;
            }
        }
    } else {
        for (int k = 0; k < v.size() - 1; k++)
        {
            if (v[k] > v[k + 1])
            {
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
            return false;
        }
    }
    return true;
}

bool isSafe(string str)
{
    string delimiter = " ";
    string token;
    int nb;
    vector<int> v, v_copy;
    size_t pos = 0;

    // VECTOR RECUPERATION
    string str_copy = str;
    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        nb = stoi(token);
        v.push_back(nb);
        str.erase(0, pos + delimiter.length());
    }
    v.push_back(stoi(str));
    if (isVectorSafe(v))
    {
        return true;
    } else {
        for (int i = 0; i < v.size(); i++)
        {
            v_copy = v;
            v_copy.erase(v_copy.begin() + i);
            if (isVectorSafe(v_copy))
            {
                return true;
            }
        }
    }
    return false;
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