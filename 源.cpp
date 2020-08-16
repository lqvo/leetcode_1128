#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int>um;
        vector<string>dom_str;
        int ans = 0;        
        for (auto i : dominoes) {
            string temp = to_string(i[0]) + " " + to_string(i[1]);
            dom_str.push_back(temp);
        }
        for (auto i : dom_str)
            um[i]++;
        for (auto i : um) {
            string temp = converse(i.first);
            if (temp!=i.first&&um.find(temp) != um.end()) {
                ans += um[temp]*i.second;
            }
        }
        ans /= 2;
        for (auto i : um)
            ans += i.second * (i.second-1) / 2;
        return ans;
    }
    string converse(string str) {
        int i = 1;
        for (; i <str.size() - 1; i++)
            if (str[i] == ' ')break;
        return str.substr(i+1) + ' ' + str.substr(0, i);
    }
};
int main() {
    Solution sol;
    vector<vector<int>>dominoes = { {2,1},{1,2},{1,2},{1,2},{2,1},{1,1},{1,2},{2,2} };
    cout << sol.numEquivDominoPairs(dominoes);
    return 0;
}
