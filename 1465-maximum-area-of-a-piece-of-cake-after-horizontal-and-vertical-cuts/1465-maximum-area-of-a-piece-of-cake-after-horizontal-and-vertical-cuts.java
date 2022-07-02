class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
          Arrays.sort(horizontalCuts);
          Arrays.sort(verticalCuts);
        
        
        long area = getMaxCut(horizontalCuts, h) * (long) getMaxCut(verticalCuts, w);
        return (int)(area % (1000000000 + 7L));
    }
    
    
     
    public int getMaxCut(int[] cuts, int fullRange) {
        int max = cuts[0];
        for (int i = 1; i < cuts.length; i++)
            max = Math.max(max, cuts[i] - cuts[i - 1]);
        return Math.max(max, fullRange - cuts[cuts.length - 1]);
    }
    
}