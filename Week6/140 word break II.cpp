#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            vector<string> result;
            string remained = s;
            string currentString;
            backtracking(s, wordDict, result, currentString);
            return result;
        }
    private:
        void backtracking(string& s, vector<string>& wordDict, vector<string>& result, string& currentString) {

            if(s.empty()) {

                //去掉最尾端的' '
                if (!currentString.empty() && currentString.back() == ' ') { 
                    currentString.pop_back();
                }
                result.push_back(currentString);
                return;
            }

            string subString;
            for(int i=0; i<s.size(); i++) {
                subString += s[i];
                for(auto &word : wordDict) {
                    if(subString == word) {
                        string nextString = currentString + word + ' ';  //word接龍串
                        string remained = s.substr(i + 1); //留下已選擇word後面的string
                        backtracking(remained, wordDict, result, nextString); //remained為下一層的主string, nextString為下一層的currentString
                    }
                } 
                
            }
        }
    };

/*
int main() {
    string s = "pineapplepenapple";
    vector<string> wordDict = {"apple","pen","applepen","pine","pineapple"};
    
    Solution sol;
    vector<string> result = sol.wordBreak(s, wordDict);
    for(int i=0; i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }

    
    
    return 0;
}*/
