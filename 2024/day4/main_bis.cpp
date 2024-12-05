#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<vector<char>> get_array()
{
    vector<vector<char>> v;
    vector<char> line;
    string str;

    ifstream input("input.txt");
    if (input.is_open())
    {
        while(getline(input, str))
        {
            line.clear();
            for (int i = 0; i < str.size(); i++)
            {
                line.push_back(str[i]);
            }
            v.push_back(line);
        }
    }
    return v;
}

bool branch_nw_se(vector<vector<char>> v, int i, int j)
{
    if (v[i - 1][j - 1] == 'M' && v[i + 1][j + 1] == 'S')
    {
        return true;
    }
    if (v[i - 1][j - 1] == 'S' && v[i + 1][j + 1] == 'M')
    {
        return true;
    }
    return false;
}

bool branch_ne_sw(vector<vector<char>> v, int i, int j)
{
    if(v[i - 1][j + 1] == 'M' && v[i + 1][j - 1] == 'S')
    {
        return true;
    }
    if(v[i - 1][j + 1] == 'S' && v[i + 1][j - 1] == 'M')
    {
        return true;
    }
    return false;
}

int west(vector<vector<char>> v, int i, int j)
{
    if (i < 1 || j < 1 || i > v.size() - 2 || j > v[i].size() - 2)
    {
        return 0;
    }
    if (branch_ne_sw(v, i, j) && branch_nw_se(v, i, j))
    {
        return 1;
    }
    return 0;
}

int get_total(vector<vector<char>> v)
{
    int total = 0;
    for (int i = 0; i < v.size() ; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 'A')
            {
                total += west(v, i, j);
            }
        }
    }
    return total;
}

int main()
{
    vector<vector<char>> v;
    int total = 0;

    v = get_array();
    cout << v.size() << endl;
    total = get_total(v);

    cout << total << endl;

    return 0;
}