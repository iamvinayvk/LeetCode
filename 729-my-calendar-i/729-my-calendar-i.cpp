class MyCalendar {
public:
    vector<pair<int,int>> calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
     sort(calendar.begin(),calendar.end());
        int flag=1;
     for(int i=0;i<calendar.size();i++){
         if(calendar[i].first<end&&calendar[i].second>start)
         {
             flag=0;
             break;
         }
     }   
        if(flag){
            calendar.push_back({start,end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */