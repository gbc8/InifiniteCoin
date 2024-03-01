#include <bits/stdc++.h>


using namespace std;
// vector<int> coins -> 0: quarters, 1: nickels, 2: cents, 3: pennies

set<vector<int>> dp;
vector<int> coinValue = {25,10,5,1};


template<class T>
class MySet {
    private:
        set<T> myset;
    public:

    void add(T e){
        myset.insert(e);
    }

    void addAll(set<T> s){
        for (auto e : s){
            myset.insert(e);
        }
    }

    bool contains(T e){
        return myset.count(e);
    }

    bool equals(set<T> s){
        return s == myset;
    }

    set<vector<int>>::iterator getIterator(){
        return myset.begin();
    }

    int size(){
        return myset.size();
    }

    vector<T> toArray() {
        vector<T> setAsArray;
        for (auto e : myset){
            setAsArray.push_back(e);
        }
        return setAsArray;
    }
};

/**
* The function below will ...
* - Receive as parameter the input and other auxiliary variables
* - Try a solution by adding a coin of each type individually with a support of memoization to avoid repetition
* - Save solutions in MySet data structure
*/
void solve(int n, int currentValue, vector<int> &coins, MySet<vector<int>> &myset){
    if(currentValue > n) {
        return;
    }

    if(dp.count(coins)){
        return;
    }

    dp.insert(coins);

    if(currentValue == n){
        myset.add(coins);
    }else{
        for(int i = 0; i < 4; ++i){
            coins[i]++;
            solve(n, currentValue + coinValue[i], coins, myset);
            coins[i]--;
        }
    }
}


/**
* The function below will ...
* - Receive the input as parameter
* - Create the auxiliary variables
* - Return the solution as a MySet variable
*/
MySet<vector<int>> makeChange(int n){
    dp.clear();
    vector<int> coins(4);
    MySet<vector<int>> myset;

    solve(n, 0, coins, myset);

    return myset;
}

int main(){
    //Sample input
    auto myset = makeChange(12);

    for(auto e : myset.toArray()){
        cout << e[0] << " " << e[1] << " " << e[2] << " " << e[3] << '\n';
    }
    return 0;
}