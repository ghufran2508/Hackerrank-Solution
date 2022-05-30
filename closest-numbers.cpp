#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sort(vector<long long int>arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[i] > arr[j]){
                long long int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    vector<long long int> input(t);

    for(int i = 0; i < t; i++) {
        cin >> input[i];
    }

    // input.sort(input.begin(),input.end());
    sort(input.begin(),input.end());

    int min_diff = INT8_MAX;

    for(int i = 1; i < input.size(); i++) {
        if(abs(input[i] - input[i-1]) < min_diff) {
            min_diff = abs(input[i] - input[i-1]);
        }
    }

    vector<long long int> answers;

    for(int i = 0; i < input.size(); i++) {
        for(int j = i + 1; j < input.size(); j++) {
            if(abs(input[i] - input[i]) == min_diff)
            {
                answers.push_back(input[i]);
                answers.push_back(input[j]);
            }
        }
    }

    for(int i = 0; i < answers.size(); i++) {
        cout << answers[i] << " " ;
    }

    return 0;
}