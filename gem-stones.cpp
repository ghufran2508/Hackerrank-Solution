#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    vector<string> inputs;
    int t;

    cin >> t;
    for(int i = 0; i < t; i++) {
        string temp;
        cin >> temp;
        inputs.push_back(temp);
    }

    string gemstones = inputs[0];
    int chArray[26] = {0};
    string temps = "";

    for(int i = 0; i < gemstones.size(); i++) {
        if(chArray[gemstones[i] - 'a'] == 0) {
            temps += gemstones[i];
            chArray[gemstones[i] - 'a'] = 1;
        }
    }
    gemstones = temps;

    for(int i = 1; i < inputs.size(); i++) {
        string temp = "";
        
        for(int j = 0; j < gemstones.size(); j++) {
            bool exist = false;
            for(int k = 0; k < inputs[i].size(); k++) {
                if(gemstones[j] == inputs[i][k]) {
                    exist = true;
                    break;
                }
            }
            if(exist) {
                temp += gemstones[j];
            }
        }

        gemstones = temp;
    }

    cout << gemstones.size() << endl;

    return 0;
}