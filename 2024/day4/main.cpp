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

int west(vector<vector<char>> v, int i, int j)
{
    if (j < 3)
    {
        return 0;
    }
    if (v[i][j - 1] == 'M' && v[i][j - 2] == 'A' && v[i][j - 3] == 'S')
    {
        return 1;
    }
    return 0;
}

int north_west(vector<vector<char>> v, int i, int j)
{
    if (j < 3 || i < 3)
    {
        return 0;
    }
    if (v[i - 1][j - 1] == 'M' && v[i - 2][j - 2] == 'A' && v[i - 3][j - 3] == 'S')
    {
        return 1;
    }
    return 0;
}

int north(vector<vector<char>> v, int i, int j)
{
    if (i < 3)
    {
        return 0;
    }
    if (v[i - 1][j] == 'M' && v[i - 2][j] == 'A' && v[i - 3][j] == 'S')
    {
        return 1;
    }
    return 0;
}

int north_east(vector<vector<char>> v, int i, int j)
{
    if (i < 3 || j > v[i].size() - 4)
    {
        return 0;
    }
    if (v[i - 1][j + 1] == 'M' && v[i - 2][j + 2] == 'A' && v[i - 3][j + 3] == 'S')
    {
        return 1;
    }
    return 0;
}

int east(vector<vector<char>> v, int i, int j)
{
    if (j > v[i].size() - 4)
    {
        return 0;
    }
    if (v[i][j + 1] == 'M' && v[i][j + 2] == 'A' && v[i][j + 3] == 'S')
    {
        return 1;
    }
    return 0;
}

int south_east(vector<vector<char>> v, int i, int j)
{
    if (i > v.size() - 4 || j > v[i].size() - 4)
    {
        return 0;
    }
    if (v[i + 1][j + 1] == 'M' && v[i + 2][j + 2] == 'A' && v[i + 3][j + 3] == 'S')
    {
        return 1;
    }
    return 0;
}

int south(vector<vector<char>> v, int i, int j)
{
    if (i > v.size() - 4)
    {
        return 0;
    }
    if (v[i + 1][j] == 'M' && v[i + 2][j] == 'A' && v[i + 3][j] == 'S')
    {
        return 1;
    }
    return 0;
}

int south_west(vector<vector<char>> v, int i, int j)
{
    if (i > v.size() - 4 || j < 3)
    {
        return 0;
    }
    if (v[i + 1][j - 1] == 'M' && v[i + 2][j - 2] == 'A' && v[i + 3][j - 3] == 'S')
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
            if (v[i][j] == 'X')
            {
                total += west(v, i, j);
                total += north_west(v, i, j);
                total += north(v, i, j);
                total += north_east(v, i, j);
                total += east(v, i, j);
                total += south_east(v, i, j);
                total += south(v, i, j);
                total += south_west(v, i, j);
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