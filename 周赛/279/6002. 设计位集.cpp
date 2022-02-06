#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define ll long long

class Bitset {
public:
    #define N 100005
	bool a[N];
	int b[2],nowsiz,now;
    Bitset(int size) {
		nowsiz=size;now=0;
		for (int i=1;i<=size;i++) a[i]=0;
		b[0]=size;
		b[1]=0;
    }
    
    void fix(int idx) {
    	idx++;
    	b[a[idx]^now]--;
		a[idx]=now^1;
		b[a[idx]^now]++;
    }
    
    void unfix(int idx) {
    	idx++;
    	b[a[idx]^now]--;
		a[idx]=now;
		b[a[idx]^now]++;
    }
    
    void flip() {now^=1,swap(b[0],b[1]);}
    
    bool all() {return b[1]==nowsiz;}
    
    bool one() {return !!b[1];}
    
    int count() {return b[1];}
    
    string toString() {
		string s;
		for (int i = 1; i <= nowsiz; i++)if((a[i]^now)==1)s+='1'; else s+='0';
		return s;
    }
};
