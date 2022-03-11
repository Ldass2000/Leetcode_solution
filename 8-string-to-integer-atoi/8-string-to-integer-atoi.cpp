class Solution {
public:
    int myAtoi(string s) {
        int n=s.length(),i=0;
		bool flag=true;
		
		//discard all the spaces at the beginning of the string
		while(i<n and s[i]==' ')i++;
		
		//Check whether the first character is a sign or not
		//flag holds true for +ve and false for -ve .
		if(s[i]=='+') i++;
		else if(s[i]=='-'){
			flag=false;
			i++;
		}
		
		//read until we reach non digit character
		long res=0;
		while(i<n){
			if(s[i]>='0' and s[i]<='9'){
				res=res*10+(s[i]-'0');
				if(res>=INT_MAX) break;
			}
			else break;
			i++;
		}
		
		//update -ve number accordingly
		if(!flag) res*=-1; 
		
		if(res<=INT_MIN) return INT_MIN;
		else if(res>=INT_MAX) return INT_MAX;
		return res;
    }
};