//https://www.acmicpc.net/problem/4659
//Implementation

#include <iostream>

using namespace std;

string aeiou = "aeiou";

bool hasVowel(string word){
	for(int i=0; i<5; i++){
		if(word.find(aeiou[i]) != string::npos){
			return true;
		}
	}
	return false;
}

bool repeatWord(string word){
	int m=0, j=0;
	for(int i=0; i<word.size(); i++){
		if(aeiou.find(word[i])!=string::npos){
			m++;
			if(j>0) j=0;
			if(m>=3) return false;
		}
		else{
			j++;
			if(m>0) m=0;
			if(j>=3) return false;
		}
	}
	return true;
}

bool repeatSame(string word){
	for(int i=0; i<word.size()-1; i++){
		if(word[i] == word[i+1]){
			if((word[i]=='e'&&word[i+1]=='e')||
				(word[i]=='o'&&word[i+1]=='o'))
				continue;
			else
				return false;
		}
	}
	return true;
}

int main() {
	string word;
	while(true){
		cin >> word;
		if(word == "end") break;

		if(!hasVowel(word)){
			cout << '<' + word + '>' + " is not acceptable.\n";
			continue;
		}

		if(!repeatWord(word)){
			cout << '<' + word + '>' + " is not acceptable.\n";
			continue;
		}

		if(!repeatSame(word)){
			cout << '<' + word + '>' + " is not acceptable.\n";
			continue;
		}
		
		cout << '<' + word + '>' + " is acceptable.\n";
	}
}