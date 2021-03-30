#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2){
    if(s1+s2 > s2+s1) return true;
    else return false;
}
string solution(vector<int> numbers){
    string answer = "";
    vector<string> v;
    for(int i = 0 ; i<numbers.size();i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i < v.size(); i++){
        answer += v[i];
    }
    if(answer[0] == '0') return "0";
    return answer;
}

int main(){
    vector<int> numbers;
    numbers.push_back(111);
    numbers.push_back(110);
    numbers.push_back(11);

    solution(numbers);
    return 0;
}