#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    bool allAlpha[26] = {false};
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 65 && s[i] <= 90)
        {
            allAlpha[s[i] - 'A'] = true;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            allAlpha[s[i] - 'a'] = true;
        }
    }
    
    for(int i = 0; i < 26; i++)
    {
        if(allAlpha[i] == false) 
            return "not pangram";
    }
    return "pangram";
}

int main()
{
    string s;
    getline(cin, s);

    string result = pangrams(s);

    cout << result << "\n";

    return 0;
}
