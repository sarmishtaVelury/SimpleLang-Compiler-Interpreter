#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	cout<<"Hello World\n";
	stringstream ss (stringstream::in | stringstream::out);
	int flag = 0;
	string keywords[] = {"let", "and", "in", "if", "then", "else", "recur", "loop", "end"}, operators[] = {"(", ")", "=", "&&", "||", "!", "<", "==", "+", "*", "-"};
	string a,b;
	//getline(cin,a);
	a = "let a = 1 and loopy = a+-1 in loopy end";
	ss<<a;
	cout<<endl;
	b = "test";
	while(b!=""){
		flag = 0;
		b = "";
		ss>>b;
		if(b == "")
			continue;
		for(int i = 0 ; i<(sizeof(keywords)/sizeof(string)) && flag!=1; i++){
			if(b.compare(keywords[i]) == 0){
				cout<<"keyword\t"<<"\t"<<b<<endl;
				flag = 1;
				break;
			}
		}
		for(int i = 0 ; i<(sizeof(operators)/sizeof(string)) && flag!=1; i++){
			if(b.compare(operators[i]) == 0){
				cout<<"operator\t"<<b<<endl;
				flag = 1;
				break;
			}
		}
		if((b.find_first_not_of("0123456789") == string::npos) && flag!=1){
			cout<<"integer\t"<<"\t"<<b<<endl;
			flag = 1;
			continue;
		}
		if((b.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == string::npos) && (!(b.at(0)>='0' && b.at(0)<='9')) && flag!=1){
			cout<<"identifier\t"<<b<<endl;
			flag = 1;
			continue;
		}
		if(flag != 1)
			cout<<"error\t\t"<<b<<endl;
	}
	return 0;
}
