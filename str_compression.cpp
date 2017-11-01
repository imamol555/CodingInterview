#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

string compress(string s1){
	string compressed_str="";
	int count=0;
	for(int i=0;i<s1.size();i++){
		//increment count for current char
		count++;
		//check if next char is same 
		if(i+1  >= s1.size() || s1.at(i)!=s1.at(i+1)){
			compressed_str += s1.at(i) + itoa(count);
			count =0;
		}

	}
	//return the string
	return compressed_str.size()<s1.size() ? compressed_str:s1;
		
}
int main(){
	string s1;
	cout<<"Enter str";
	cin>>s1;
	cout<<"compressed_str = "<<compress(s1);
	return 0;

}