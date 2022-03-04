#Donovan Booker, Hw6 - modifying words in Ruby

string = $stdin.read	          	 #reads in string		
string = string.gsub(/\b[fF]/, "gh")     #changes all beginning 'F/f' chars with 'gh'
string = string.gsub(/sh\b/, "ti")	 #changes all ending 'sh' chars with 'ti'
string = string.gsub(/\Bi\B/, "o")	 #changes all middle 'i' chars with 'o'
puts string			  	 #outputs modified string
