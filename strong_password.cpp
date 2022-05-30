#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    bool speacial = false, upper = false, small = false , num = false;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(password[i] >= 65 && password[i] <= 90 && upper == false)
        {
            upper = true;
        }
        else if(password[i] >= 97 && password[i] <= 122 && small == false)
        {
            small = true;
        }
        else  if(password[i] >= '0' && password[i] <= '9' && num == false)
        {
            num = true;
        }
        else if ((password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+') && speacial == false)
        {
            speacial = true;
        }
    }
    
    if(!speacial) count++;
    if(!small) count++;
    if(!upper) count++;
    if(!num) count++;
    
    if(count + n < 6) return 6-n;
    else return count;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    cout << answer << "\n";

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
