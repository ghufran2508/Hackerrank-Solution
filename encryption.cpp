#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    s.erase(remove(s.begin(),s.end(), ' '), s.end());
    
    int rows, columns;
    rows = floor(sqrt(s.length()));
    columns = ceil(sqrt(s.length())); 
    
    if(rows*columns < s.size())
    {
        rows = columns;
    }
    
    vector<string> encrypt(rows);
    string newString = "";
    int index = 0;
    
    for(int i = 0; i < rows; i++)
    {
        newString = "";
        for(int j = 0; j < columns; j++)
        {
            if(s[index] != '\0')
            {
                newString += s[index];
                index++;
            }
        }
        encrypt[i] = newString;
    }
    
    string newEncrypted = "";
    
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if(encrypt[j][i] != '\0')
                newEncrypted += encrypt[j][i]; 
        }
        newEncrypted += ' ';
    }
    
    return newEncrypted;
}

int main()
{
    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    return 0;
}
