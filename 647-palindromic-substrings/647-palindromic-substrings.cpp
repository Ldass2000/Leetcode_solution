class Solution {
public:
    int countSubstrings(string s) {
                        

int ans = 0;

		for(int i = 0; i < s.size(); i++) {
			int left = i, right = i;
			while(left >= 0 && right < s.size() && s[left] == s[right]) {
				ans++;
				left--;
				right++;
			}

			left = i, right = i + 1;
			while(left >= 0 && right < s.size() && s[left] == s[right]) {
				ans++;
				left--;
				right++;
			}
		}

		return ans;
    }
    
    //TC-->O(N^2),,, SC-->O(1)
};