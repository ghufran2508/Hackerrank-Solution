#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/* // Complete the xorSequence function below.
long xorSequence(long l, long r) {

    long xorSum = 0;
    vector<long> xorArray(r+1);
    xorArray[0] = 0;
    
    for(long x = 1; x <= r; x++)
    {
        xorArray[x] = xorArray[x-1] ^ x;
        if(x == l)  xorSum = xorArray[x];
        if(x > l)   xorSum ^= xorArray[x]; 
    }

    return xorSum;
} */

long checks(long long x)
{
    int remain = x % 8;
    if(remain == 0 || remain == 1)  return x;
    else if(remain == 2 || remain == 3) return 2;
    else if(remain == 4 || remain == 5) return x + 2;
    else return 0;
}

// Complete the xorSequence function below.
long xorSequence(long l, long r) {
    return checks(r) ^ checks(l-1);
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string lr_temp;
        getline(cin, lr_temp);

        vector<string> lr = split_string(lr_temp);

        long l = stol(lr[0]);

        long r = stol(lr[1]);

        long result = xorSequence(l, r);

        cout << result << "\n";
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
