​
           In serialize:-
	   i)-> We iterate over the tree using the level order traverse
	   ii)-> Convert the current node value to string and add(" ").
	   iii)-> whnever we reach NULL we put #(any speacila character) which represent Null node in our string 
	   
	  In Deserialize:
	   i)->We first take first character of string and convert that into integer and put as an root of the tree.
	   ii)-> then we stringstream the given  stream which helps us to easily iterate the string (stringstream--.basically convert the string into block or object                                so  that can be easily iterate.
	   iii)-->Then we iterate and using getlince(>>)  and  check the value if it is #(NULL), then we start the root  left or right to null  else we convert                                      that character to integer then make node and assign to root left or right as per iteration.
