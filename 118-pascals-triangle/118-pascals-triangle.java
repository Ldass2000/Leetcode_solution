class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>>res=new ArrayList<>();
        
        for(int i=0;i<numRows;i++)
        {
            List<Integer> curr= new ArrayList<Integer>();
            
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    curr.add(1);
                else
                    curr.add(res.get(i-1).get(j-1) + res.get(i-1).get(j));
                
            }
            
            res.add(curr);
        }
        
        return res;
    }
}