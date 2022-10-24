#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define NUM_CHARS 26

bool is_anagram(string str1, string str2) {
    
    if(str1.length() != str2.length()) return false;
    
    vector<int> count1(NUM_CHARS, 0); // [0,0,0,....0] -> len(26)
    vector<int> count2(NUM_CHARS, 0);
    
    for(int i = 0; i < str1.length(); i++) {
        int index = str1[i] - 'a';
        int index2 = str2[i] - 'a';

        count1[index] += 1;
        count2[index2] += 1;
    }
    // count1 = [3, 0, 0, 0... 1,. ...1 ,..0]
    // count2= [3, 1, 1, 1... 1,. ...1 ,..0]
    // count1[0] == count2[0] | true
    // 3 == 3 = true
    
    for(int j = 0; j < NUM_CHARS; j++) {
        if(count1[j] != count2[j]) {
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