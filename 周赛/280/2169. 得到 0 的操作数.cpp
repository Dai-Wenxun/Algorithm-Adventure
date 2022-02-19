class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;
		while (num1 != 0) {
        	ops += num2 / num1;
        	int tmp = num2;
        	num2 = num1;
        	num1 = tmp % num1;
		}
		return ops;
    }
};

