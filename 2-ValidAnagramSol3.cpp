#include <iostream>
#include <string>
#include <map>

using namespace std;

#define NUM_CHARS 26

bool is_anagram(string str1, string str2) {
    
    if(str1.length() != str2.length()) return false;
    
    map<char, int> Map; // x = {a: 3, n: 1, m: 1, g: 1}
    int count[NUM_CHARS] = { 0 }; // [0,0,0,....0] -> len(26)
    
    for(int i = 0; i < str1.length(); i++) {
        Map[str1[i]] += 1;
    }
    
    for(int i = 0; i < str2.length(); i++) {
        if(Map.find(str2[i]) != Map.end()) {
            Map[str2[i]] -= 1;
        } else {
            return false;
        }
    }

    for(auto item : Map) {
        if(item.second != 0) {
            return false;
        }
    }
    return true;
}


int main()
{
    string s = "anagram";
    string t = "nagaram";
    
    cout << is_anagram(s, t) << endl;

    return 0;
}