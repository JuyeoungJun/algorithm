#include <iostream>
#include <map>
#include <deque>

using namespace std;

class song{
    private:
        deque<int> play;
        int sum;
    public:
        string gen;
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
    map<string, song> m;
    m["hi"] = song("test",1,1);
    cout << m["hi"].gen << endl;
    cout << "git test" << endl;
    return 0;
}