class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
     /* INTUTION
         
         
       //we will first heavier weight person sit into boat, if there is space left we will try fit in lighter 
        // weight person.if both gets fit inwell and good else only heavier weight person will sit.
        //TC-->O(nlogn)
        
       */
        
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1;
        int count=0;
        while(l<=r)
        {
            int to_weight=people[l]+people[r];
            if(to_weight<=limit)
            {
                l++;
                r--;
            }
            else
            {
                r--;
            }
            count++;
        }
        return count;
    }
};