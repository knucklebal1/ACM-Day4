#include <iostream>
typedef long long ll;
using namespace std;

inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main() {
	int t;
	t=read();
	while (t--) {
		long long l, r;
		l=read(),r=read();
		long long count = 0;
		if (l == 1 && r == 1) {
			count++;
		}
		if (r - l >= 1) {//实际上最小互质区间就是除了[1,1]外，每对相邻的数，如[2,3][4,5]
			count += (r - l);
		}
		cout << count << '\n';
	}
	return 0;
}
