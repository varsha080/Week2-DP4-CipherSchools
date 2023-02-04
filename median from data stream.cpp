class MedianFinder {
public:
    ordered_set_pair st;
    int a=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        st.insert({num,a++});
    }
   
    double findMedian() { 
        int n=st.size();
        auto itr = st.find_by_order(n/2); 
        double num= (*itr).first;
        if(n%2==0){
            auto itr2=st.find_by_order((n-1)/2);
            double num1=(*itr2).first;
            num=(num+num1)/2;
        }
        return num;
        
    }
};