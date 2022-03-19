class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int> mp;
    int t=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        t++;
        pq.push({mp[val],{t,val}});
    }
    
    int pop() {
        auto tp=pq.top();
        pq.pop();
        mp[tp.second.second]--;
        return tp.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */