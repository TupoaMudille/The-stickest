#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;
 
typedef map<int, int> M;
 
class ChooseNum
{
public:
    ChooseNum(const string & digits) : digits_(digits) {}
    char operator()() const { return digits_[rand () % digits_.size()]; }
private:
    const string & digits_;
};
 
class CowsBulls
{
public:
    CowsBulls(M & cm, M & gm, int & bull)
        : cm_(cm), gm_(gm), bull_(bull = 0) {}
    char operator()(char c, char g)
    {
        return ++cm_[c],
            ++gm_[g],
            bull_ += (c == g),
            g;
    }
private:
    M &cm_, &gm_;
    int & bull_;
};
 
class CountCowBull
{
public:
    CountCowBull(M & cm, M & gm, int & cow)
        : cm_(cm), gm_(gm), cow_(cow = 0) {}
    void operator()(char c) const
    {
        cow_ += min(cm_[c], gm_[c]);
    }
private:
    M &cm_, &gm_;
    int & cow_;
};
 
int main()
{
    const string digits("0123456789");
    string comb(2, '.'), guess;
    int cow, bull = 0;
    M cm, gm;
 
    srand(static_cast<unsigned int>(time(0))), generate(comb.begin(), comb.end(), ChooseNum(digits));
 
    while (bull < comb.size())
        cout << "\nguess -> ",
        cin >> guess,
        guess.resize(comb.size(), ' '),
        cm = gm = M(),
        transform(comb.begin(), comb.end(), guess.begin(), guess.begin(), CowsBulls(cm, gm, bull)),
        for_each(digits.begin(), digits.end(), CountCowBull(cm, gm, cow)),
        cout <<"cows "<< cow << "     bulls " << bull;
 
    cout << " - solved!\n";
    system("pause");
}