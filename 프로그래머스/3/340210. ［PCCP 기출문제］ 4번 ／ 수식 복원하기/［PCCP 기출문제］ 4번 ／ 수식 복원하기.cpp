#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct expNode {
	string opr; // true: 덧셈, false: 뺄셈
	string opl1, opl2; // 피연산자 1, 2
	string res; // 결과

	expNode() {}
	expNode(string opl1, string opr, string opl2, string res) {
		this->opl1 = opl1;
		this->opr = opr;
		this->opl2 = opl2;
		this->res = res;
	}
};

expNode parse(string exp) {
	exp.push_back(' ');

	vector<string> tokens;
	int start = 0;
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == ' ') {
			tokens.push_back(exp.substr(start, i - start));
			start = i + 1;
		}
	}
	
	return expNode(tokens[0], tokens[1], tokens[2], tokens[4]);
}

int toDec(string num, int base) {
	int unit = 1;
	int dec = 0;

	for (int i = num.size() - 1; i >= 0; --i) {
		dec += (num[i] - '0') * unit;
		unit *= base;
	}

	return dec;
}
string toBaseStr(int dec, int base) {
	if (dec == 0) return "0";

	string res = "";
	int num = dec;
	while(num > 0){
		int mod = num % base;
		res = (char)('0' + mod) + res;
		num /= base;
	}

	return res;
}
bool isAccept(int base, expNode &exp) {
	if (exp.res[0] == 'X') return false;

	if (exp.opr[0] == '+') return toDec(exp.opl1, base) + toDec(exp.opl2, base) == toDec(exp.res, base);
	else return toDec(exp.opl1, base) - toDec(exp.opl2, base) == toDec(exp.res, base);
}
vector<string> makeAnswer(vector<bool> pass, vector<expNode> &arr, int base) {
	vector<string> ans;

	if (base == 1) {
		for (expNode curr : arr) {
			int opl1Dec = toDec(curr.opl1, base);
			int opl2Dec = toDec(curr.opl2, base);
			int resDec = curr.opr[0] == '+' ? opl1Dec + opl2Dec : opl1Dec - opl2Dec;
			string resStr = toBaseStr(resDec, base);
			ans.push_back(curr.opl1 + " " + curr.opr + " " + curr.opl2 + " = " + resStr);
		}
		return ans;
	}


	for (expNode curr : arr) {
		string res = "";
		for (int i = 2; i <= 9; i++) {
			if (!pass[i]) continue;
			int opl1Dec = toDec(curr.opl1, i);
			int opl2Dec = toDec(curr.opl2, i);
			int resDec = curr.opr[0] == '+' ? opl1Dec + opl2Dec : opl1Dec - opl2Dec;
			string resStr = toBaseStr(resDec, i);

			if (res == "") res = resStr;
			else if (res != resStr) {
				res = "";
				break;
			}
		}
		
		if (res == "") res = "?";
		ans.push_back(curr.opl1 + " " + curr.opr + " " + curr.opl2 + " = " + res);
	}
	return ans;
}
int maxNum(string num) {
	int val = -1;
	for (char curr : num) {
		val = max(val, curr - '0');
	}
	return val;
}
vector<string> solution(vector<string> expressions) {
	vector<expNode> arr1, arr2;

	expNode node;
	for (string curr : expressions) {
		node = parse(curr);
		if (node.res[0] == 'X') arr2.push_back(node);
		else arr1.push_back(node);
	}

	vector<bool> pass(10, true); // 2~9진법
	for (expNode curr : arr1) {
		for (int i = 2; i <= 9; i++) {
			if (!pass[i]) continue;

			pass[i] = pass[i] && maxNum(curr.opl1) < i && maxNum(curr.opl2) < i && maxNum(curr.res) < i;
			pass[i] = pass[i] && isAccept(i, curr);
		}
	}

	for (expNode curr : arr2) {
		for (int i = 2; i <= 9; i++) {
			if (!pass[i]) continue;

			pass[i] = pass[i] && maxNum(curr.opl1) < i && maxNum(curr.opl2) < i;
		}
	}

	int cnt = 0, ansBase = -1;
	for (int i = 2; i <= 9; i++) {
		if (pass[i]) {
			++cnt;
			ansBase = i;
		}
	}

	if (cnt != 1) ansBase = -1;
	
	return makeAnswer(pass, arr2, ansBase);
}