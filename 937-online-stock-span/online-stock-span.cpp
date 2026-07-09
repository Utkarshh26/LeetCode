class StockSpanner {
public:
    vector<int> span;
    StockSpanner() {
        
    }
    
    int next(int price) {
        span.push_back(price);
        int count = 1;
        for(int i = span.size() -2; i>=0; i--){
            if(span[i] <= price){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */