class KthLargest {
public:
    
    //IDEA: we want  kth largest number
    //so we need to store them in sorted manner.(we can use set) we can have duplicate numbers(multiset)
    
    //store k elements , if the size goes beyond k remove the smallest number

    
     multiset<int>s;
    int KLarge;
    
    KthLargest(int k, vector<int>& nums) {
        s.clear();
        KLarge=k;
        for(auto val:nums)
        {
            s.insert(val);
            if(s.size()>KLarge)
                s.erase(s.begin());
        }
    }
    
    int add(int val) {
        s.insert(val);
        if(s.size()>KLarge)
            s.erase(s.begin());
        
        return  *(s.begin());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */