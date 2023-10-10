class RandomizedSet {
    
private:
    vector<int>a;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        else{
            a.push_back(val);
            mp[val]=a.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int last=a.back();
            a[mp[val]]=a.back();
            a.pop_back();
            mp[last]=mp[val];
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
          return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */