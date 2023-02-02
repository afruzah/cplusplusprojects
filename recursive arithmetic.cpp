#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

void resize(string &one, string &two) {
	
	if ( (one.length() < two.length()) ) {
		swap(one, two);
	}
	if (one.length() > two.length()) {
		int n = one.length()-two.length();
		for(int i = 0; i < n; i++) {
			two = "0" + two;
		}
	}
	
	
}

string add(string one, string two, int B) {
	resize(one, two);
	
	reverse(one.begin(), one.end());
	reverse(two.begin(), two.end());
	
	int carry = 0;
	string newNum;

	for(int j = 0; j < (int)one.length(); j++) {
		int sum = (one.at(j)-'0') + (two.at(j)-'0') + carry;
		
		int num = sum % B;
		char n = num + '0';
		
		newNum.push_back(n);
		carry = sum/B;
	
		
	}
	
	if (carry) {
		char c = carry + '0';
		newNum.push_back(c);
	}
	
	reverse(newNum.begin(), newNum.end());

	
	return newNum;
}

string subtract(string one, string two, int B) {
	resize(one, two);
	
	reverse(one.begin(), one.end());
	reverse(two.begin(), two.end());
	
	string subNum;
		
	int topNum = 0;
		
	bool trade = false;
	
	for (int k = 0; k < (int)one.length(); k++) {
		
		if (trade == true) {
			topNum = (one.at(k)-'0') - 1;
			trade = false;
		} else {
			topNum = (one.at(k)-'0');
		}
		if (topNum < (two.at(k) -'0')) {
			trade = true;
			topNum = topNum + B;
		}
		int sub = topNum - (two.at(k) - '0');
		char forSub = sub + '0';
		
		subNum.push_back(forSub);
	}
	
	while(subNum.back()=='0') {
		subNum.pop_back();
	}
	reverse(subNum.begin(), subNum.end());
	
	return subNum;
}

string multiplication(string one, string two, int B){
    string num;
	int carry = 0;
    for(int i = one.size()-1;i >= 0 ;i--){
		int multiply = (one.at(i)-'0') * (two.at(0)-'0') + carry;
        if(multiply >= B){
			char toPush = (multiply % B) + '0';
			num.push_back(toPush);
            carry = multiply/B;
        }
        else{
			char toPush = multiply + '0';
            num.push_back(toPush);
            carry = 0;
        }
    }
	if(carry != 0){
		if(carry > B) {
			num.push_back((carry % B)+'0');
			num.push_back((carry/B)+'0');
		}
		num.push_back(carry + '0');
	}
    
	while(num.back()=='0') {
		num.pop_back();
	}
    reverse(num.begin(), num.end());
    return num;
}

string karatsuba(string one, string two, int B) {
	
	resize(one, two);
	
	if(one.length()==1){
		return multiplication(one, two, B);
	}
	
	int len = one.length();
	int half = len/2;

	string a0 = one.substr(0, half);
	string a1 = one.substr(half, len - a0.length());
	string b0 = two.substr(0, half);
	string b1 = two.substr(half, len - b0.length());

	string p0 = karatsuba(a0, b0, B);
	string p1 = karatsuba(a1, b1, B);
	string p2 = karatsuba(add(a0, a1, B), add(b0, b1, B), B);
	string p3 = subtract(p2, add(p0, p1, B), B);

	for (int i = 0; i < 2*(len-half); i++)
		p0.push_back('0');
	for (int i = 0; i < len-half; i++)
		p3.push_back('0');

	string kNum = add(add(p0, p1, B), p3, B);

	reverse(kNum.begin(), kNum.end());
	
	while(kNum.back()=='0') {
		kNum.pop_back();
	}
	
	reverse(kNum.begin(), kNum.end());
	
	return kNum;
}
int main() {
	
	string one, two;
	int B;
	
	cin >> one >> two >> B;
	
	string aNum =  add(one, two, B);
	
	string kNum = karatsuba(one, two, B);

	cout << aNum << " " << kNum << " " << 0 << endl;
	

	return 0;
}
