class Solution {
public:
    int countEven(int num) {
    	int res = 0;
        rep(i, 1, num) {
        	int sum = 0;
        	int cur = i;
        	while (cur != 0) {
        		sum ^= cur % 10 & 1;
        		cur /= 10;
			}
			
			res += sum ^ 1; 
		}
		return res;
    }
};
