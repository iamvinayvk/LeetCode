class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        for(auto x:s){
            if(x.first<end&&x.second>start)
                return false;
        }
        s.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */