//https://school.programmers.co.kr/learn/courses/30/lessons/60058
//Implementation, 재귀

#include <string>
#include <vector>

using namespace std;

string splitUV(string str)
{
	int l=0, r=0, i=0;
	string u, v;
	for(; i<str.size(); i++){
			if(str[i] == '(')
				l++;
			else
				r++;

			if (l==r)
				break;
	}

	u = str.substr(0, i+1);
	v = str.substr(i+1);

	if(v != "")
		v = splitUV(v);

	if(u.front()=='(' && u.back()==')')
		return u+v;
	else
	{
		string tmp = "(" + v + ")";

		u = u.substr(1, u.size()-2);
		for(char& ch : u)
			tmp +=  ch == '(' ? ')' : '(';

		return tmp;
	}
}

string solution(string p) {
	return splitUV(p);
}