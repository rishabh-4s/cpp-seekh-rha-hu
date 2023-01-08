#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
vector<int> arr;
unordered_map<int, int> OurMap;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (OurMap.count(val))
            return false;
        
            arr.push_back(val);
            OurMap[val] = arr.size() - 1;
            return true;
    }
    
    bool remove(int val) {
        if (OurMap[val])
        {
            //arr.erase(arr.begin() + OurMap[val]);
            iter_swap(arr.begin()+OurMap[val], arr.end());
            arr.pop_back();
            OurMap[val] = NULL;

            return true;
        }
        else
            return false;
        
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{

    return 0;
}