#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<int> arr(s.size());
    vector<string> ans(queries.size());
    
    arr[0] = s[0] - 96;
    
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1])
            arr[i] = arr[i-1] + (s[i]-96);
        else {
            arr[i] = s[i] - 96;
        }
    }
    bool found;
    for(int i = 0; i < queries.size(); i++)
    {
        found = false;
        
        for(int j = 0; j < arr.size(); j++)
        {
            if(queries[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        
        if(found)   ans[i] = "Yes";
        else        ans[i] = "No";
    }
    
    return ans;
}  

int main()
{
    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
