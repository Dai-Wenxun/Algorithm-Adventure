class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
		int sz = SZ(bits);
				
		int i = 0;
		while (1) {
			if (bits[i] == 1) {
                i += 2;
                if (i == sz) return false;
            } else {
                i+= 1;
                if (i == sz) return true;
            }
		}
		
		return true;
    }
};
