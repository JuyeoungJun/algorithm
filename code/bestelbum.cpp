#include <iostream>
#include <map>
#include <deque>

using namespace std;

class song{
    private:
        string gen;
        deque<int> play;
        int sum;
    public:
        song(string _gen, int p,int _sum){
            gen = _gen;
            play.push_back(p);
            sum += _sum;
        }
        bool operator<(const song& rhs) const{
            if(sum <= rhs.sum){
                return sum < rhs.sum;
            }
            else{
                return sum > rhs.sum;
            }
        }

};

int main(){
    //map<string, int > m;
    map<string, song> m;
    //m.insert(make_pair("hi",1));
    //m.insert(make_pair("hi",2));
    m["hi"] = song("test",1,1);
    cout << m["hi"].gen << endl;
    return 0;
}