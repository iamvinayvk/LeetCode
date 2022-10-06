class TimeMap {
public:
    map<string,map<int,string>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(store.count(key)==false){
            return "";
        }
        while(timestamp>=1){
            if(store[key].count(timestamp))
                return store[key][timestamp];
            timestamp--;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */