class Solution {
public:
	#define cond(i) !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z')
    string reverseOnlyLetters(string s) {
		int sz = s.size();
		int i = 0, j = sz - 1;
		while (i < j) {
			cout << s << endl;
			while (i < j && cond(i)) ++i;
			while (i < j && cond(j)) --j;
			if (i >= j) break;
			swap(s[i++], s[j--]);
		}
		return s;
    }
};
