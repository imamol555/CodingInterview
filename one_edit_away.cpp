#include<iostream>
#include<string>
using namespace std;

bool oneEditAway(string s1, string s2);
bool oneEditReplace(string s1, string s2);
bool oneEditInsert(string s1, string s2);



int main(){
	string s1,s2;
	cout<<"Enter string 1";
	getline(cin,s1);
	cout<<"\nEnter string 2";
	getline(cin,s2);
	bool isOneEditAway = oneEditAway(s1,s2);
	cout<<isOneEditAway;
	return 0;
}
bool oneEditAway(string s1, string s2){

	if(s1.size() == s2.size())
		return oneEditReplace(s1,s2);
	else if(s1.size() + 1 == s2.size())
		return oneEditInsert(s1,s2);
	else if(s1.size() - 1 == s2.size())
		return oneEditInsert(s2,s1);
		// notice that inser and remove are vice versa

	else return false;
}

bool oneEditReplace(string s1, string s2){
	bool foundDifference = false;
	for(int i=0;i<s1.size();i++){
		if(s1.at(i) != s2.at(i)){
			//if already one difference
			if(foundDifference)
				return false;
			// register the difference
			foundDifference = true;
		}
	}

}

//check if we can insert a char in s12 to make s2
bool oneEditInsert(string s1, string s2){
	int idx1 = 0;
	int idx2 = 0;
	while(idx1<s1.size() && idx2<s2.size()){
		if(s1.at(idx1) != s2.at(idx2)){
			//at a same index different chars may occur but index is same
			// if index is not same return false
			// diff chars first time is allowed but no next time when we increment idx2 bcoz s2 is bigger
			if(idx1 != idx2)
				return false;
			idx2++;
		}

		else{
			// if both chars are same then increment both indices
			idx1++;
			idx2++;	
		}
	}//while loop ends

	return true;
}

