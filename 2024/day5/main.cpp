#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool is_update_valid(vector<int> update, vector<vector<int>> rules)
{
    size_t pos_1, pos_2;

    for (int i = 0; i < update.size(); i++)
    {
        for (int j = 0; j < rules.size(); j++)
        {
            if (update[i] == rules[j][0])
            {
                if (find(update.begin(), update.end(), rules[j][1]) != update.end())
                {
                    pos_1 = find(update.begin(), update.end(), rules[j][0]) - update.begin();
                    pos_2 = find(update.begin(), update.end(), rules[j][1]) - update.begin();
                    if (pos_2 < pos_1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    for (int i = 0; i < update.size(); i++)
    {
        for (int j = 0; j < rules.size(); j++)
        {
            if (update[i] == rules[j][1])
            {
                if (find(update.begin(), update.end(), rules[j][0]) != update.end())
                {
                    pos_1 = find(update.begin(), update.end(), rules[j][0]) - update.begin();
                    pos_2 = find(update.begin(), update.end(), rules[j][1]) - update.begin();
                    if (pos_2 < pos_1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int get_total(vector<int> update, vector<vector<int>> rules)
{
    if (is_update_valid(update, rules))
    {  
        return(update[update.size() / 2]);
    }
    return 0;
}

int main()
{
    string str, n1;
    vector<vector<int>> rules, updates;
    vector<int> rule, update;
    size_t pos;
    int total = 0;

    ifstream input("input.txt");
    if (input.is_open())
    {
        getline(input, str);
        while(!str.empty())
        {
            rule.clear();
            pos = str.find('|');
            n1 = str.substr(0,pos);
            rule.push_back(stoi(n1));
            str.erase(0, pos + 1);
            rule.push_back(stoi(str));
            rules.push_back(rule);
            getline(input, str);
        }
        while(getline(input, str))
        {
            update.clear();
            while((pos = str.find(',')) != string::npos)
            {
                n1 = str.substr(0, pos);
                update.push_back(stoi(n1));
                str.erase(0, pos + 1);
            }
            update.push_back(stoi(str));
            updates.push_back(update);
        }
        for (int i = 0; i < updates.size(); i++)
        {
            total += get_total(updates[i], rules);
        }
    }
    cout << total << endl;
    return 0;
}