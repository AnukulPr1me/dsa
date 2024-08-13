#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t getsize(const string &str)
{
    return str.size();
}
void swaping(const string &str)
{
    reverse(str.begin(), str.end());
}
int lon(string s ){
    int start = 0;
    int end = 1;
    int n = s.size();
    string newString = " ";
    while(start < n){
        if(s[start] != s[end]){
            newString.push_back(s[start]);
            start++;
            end++;
        }
        else if(s[start] == s[end]){
            break;
        }
    }
    return newString.size();
}

string removeOccurrences(string s, string part){
    int n = s.size();
    int left =0;
    int right = n - 1;
    while(left < right){
        if(s.substr(left, part.size()) == part){
            s.erase(left, part.size());
            n -= part.size();
        }
        else{
            left++;
        }
    }
    return s;

}
int main()
{
    int size;
    string str = "anukul";
    size = getsize(str);
    cout << "Size of string: " << size << endl;

    return 0;
}