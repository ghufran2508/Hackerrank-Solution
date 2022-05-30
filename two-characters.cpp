#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    // string s = "beabeefeab";
    string s = "asvkugfiugsalddlasguifgukvsa";
    

    int max_size = 0;

    for(int i = 0; i < s.size()-1; i++) {
        char ch1 = s[i];
        string temp = "";

        for(int j = i+1; j < s.size(); j++) {
            char ch2 = s[j];
            if(s[i] == s[j]) continue;

            for(int k = 0; k < s.size(); k++) {
                if(s[k] == ch1 || s[k] == ch2) {
                    temp += s[k];    
                }
            }
            
        }
        if(temp != "") {
            bool flag = true;
            for(int v = 0; v < temp.size(); v++) {
                if(temp[v] == temp[v+1]) {
                    flag = false;
                    break;
                }
            }

            if(flag && max_size < temp.size()) {
                max_size = temp.size();
            }
        }
    }

    
    // for(int i = 0; i < ans.size(); i++) {
    //     if(max_size < ans[i].size()) max_size = ans[i].size();

    //     cout << ans[i] <<endl;
    // }

    cout << max_size << endl;

    return 0;
}