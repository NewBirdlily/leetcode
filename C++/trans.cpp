#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<algorithm>

class Solution{
    public:
    std::string trans(std::string s, int n) {
        std::vector<std::string>words;
        std::string word;
        if(s.find(' ') == std::string::npos){
            for(char ch:s){
                word +=isupper(ch) ? tolower(ch):toupper(ch);
            }
            return word;
        }
        for(char ch:s){
            if(ch ==' '){
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
                words.push_back(std::string(1,ch));
            }
            else{
                word +=ch;
            }
        }
        if(!word.empty()){
            words.push_back(word);
        }
        std::reverse(words.begin(),words.end());
        for(std::string &w :words){
            for(char &ch:w){
                if(isupper(ch)){
                    ch = tolower(ch);
                }
                else{
                    ch= toupper(ch);
                }
            }
        }
        std::string res;
        for(int i =0;i<words.size();i++){
            res += words[i];
            if(i<words.size()-1){
                res += "";
            }
        }
        return res;
    }
};

int main(){
    std::string s = "This is a sample";
    int n =16;
    Solution solution;
    std::cout<<solution.trans(s,16)<<std::endl;
    return 0;
}