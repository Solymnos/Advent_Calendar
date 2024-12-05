#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

vector<int> reorder(vector<int> update, vector<vector<int>> rules)
{
    vector<int> update_order;
    bool already_push;

    update_order.push_back(update[0]);
    for (int i = 1; i < update.size(); i++)
    {
        already_push = false;
        for(int j = 0; j < update_order.size(); j++)
        {
            for (int k = 0; k < rules.size(); k++)
            {
                if (rules[k][0] == update[i] && rules[k][1] == update_order[j])
                {
                    if (!already_push)
                    {
                        already_push = true;
                        update_order.insert(update_order.begin() + j, update[i]);
                    }
                }
            }
        }
        if (!already_push)
        {
            update_order.push_back(update[i]);
        }
    }

    return update_order;
}

int is_update_valid(vector<int> update, vector<vector<int>> rules)
{
    size_t pos_1, pos_2;
    int pass;

    for (int i = 0; i < update.size(); i++)
    {
        cout << update[i] << ';';
    }
    cout << endl;

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
                        cout << '\t' << "FALSE (" << rules[j][0] << "," << rules[j][1] << ")" << endl;
                        update = reorder(update, rules); 
                        cout << "\t" << "ORDER : ";
                        for (int o = 0; o < update.size(); o++)
                        {
                            cout << update[o] << ',';
                        }
                        cout << endl;
                        return update[update.size() / 2];
                    }
                }
            }
        }
    }
    return 0;
}

int get_total(vector<int> update, vector<vector<int>> rules)
{
    return is_update_valid(update, rules);
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