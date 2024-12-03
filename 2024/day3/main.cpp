#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool are_valids(string nb1_str, string nb2_str)
{
    for (int i = 0; i < nb1_str.size(); i++)
    {
        if (!isdigit(nb1_str[i]))
        {
            return false;
        }
    }
    for (int j = 0; j < nb2_str.size(); j++)
    {
        if (!isdigit(nb2_str[j]))
        {
            return false;
        }
    }
    return true;
}

int extract(string str)
{
    string delimiter_start = "mul(";
    string delimiter_end = ")";
    string token, nb1_str, nb2_str;
    size_t pos_start, pos_end, pos_sep = 0;
    int nb1, nb2;
    int total = 0;

    while ((pos_start = str.find(delimiter_start)) != string::npos)
    {
        pos_end = str.find(delimiter_end, pos_start);
        token = str.substr(pos_start + delimiter_start.size(), pos_end - (pos_start + delimiter_start.size()));
        pos_sep = token.find(",");
        nb1_str = token.substr(0, pos_sep);
        nb2_str = token.substr(pos_sep + 1, token.size() - pos_sep);
        if (are_valids(nb1_str, nb2_str))
        {
            nb1 = stoi(nb1_str);
            nb2 = stoi(nb2_str);
            total += (nb1 * nb2);
            str.erase(0, pos_start + delimiter_start.length() + nb1_str.length() + nb2_str.length() + 1);
        } else 
        {
            str.erase(0, pos_start + delimiter_start.length());
        }
    }
    return total;
}

int main()
{
    string str;
    int total = 0;

    ifstream input("input.txt");
    if (input.is_open())
    {
        while(getline(input, str))
        {
            total += extract(str);
        }
    }
    cout << total << endl;
    return 0;
}