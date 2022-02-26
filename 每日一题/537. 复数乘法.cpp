class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
		int a, b;
		int x1, y1, x2, y2;

		auto g = [](string & num) {
			int i = 0, j = 0;
			int x, y;

			while (num[j] != '+') j++;
			x = stoi(num.substr(i, j-i));			
			j++;
			i = j;
			while (num[j] != 'i') j++;
			y = stoi(num.substr(i, j-i));
			return mp(x, y);
		};
		
		auto xy1 = g(num1); x1 = xy1.fi; y1 = xy1.se;
		auto xy2 = g(num2); x2 = xy2.fi; y2 = xy2.se;

		a = x1 * x2 + -(y1 * y2);
		b = x1 * y2 + x2 * y1;
		
		return to_string(a) + '+' + to_string(b) + 'i';
    }
};
