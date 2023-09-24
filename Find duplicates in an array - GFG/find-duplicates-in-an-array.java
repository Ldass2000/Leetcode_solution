//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            Solution g = new Solution();
            ArrayList<Integer> ans = g.duplicates(a, n);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    public static ArrayList<Integer> duplicates(int arr[], int n) {
       ArrayList<Integer> duplicates = new ArrayList<>();
       int[] frequency = new int[n];
       
       //count the frquency of each element in the array
       for(int num:arr)
       {
            frequency[num]++;
       }
       
        // Find duplicates and add them to the ArrayList
        for(int i=0;i<n;i++)
        {
            if(frequency[i]>1)
            {
                duplicates.add(i);
            }
        }
        
        // If no duplicates were found, add -1 to the list
        if(duplicates.isEmpty())
        {
            duplicates.add(-1);
        }
        
        return duplicates;
    }
}
