#include<iostream>
typedef long long ll;
using namespace std;
const int N=1e6+5;
int cnt[N],dp[N],a[N];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	int n,m;
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]<=m) cnt[a[i]]++;
	}
	for(int i=m;i>=1;--i){
		for(int j=i;j<=m;j+=i){
			dp[j]+=cnt[i];
		}
	}
	ll ans1=-1,ans2=-1;
	for(int i=1;i<=m;++i){
		if(dp[i]>ans1){
			ans1=dp[i];
			ans2=i;
		}
	}
	cout<<ans2<<' '<<ans1<<'\n';
	for(int i=1;i<=n;++i){
		if(ans2%a[i]==0){
			cout<<i<<' ';
		}
	}
	
	return 0;
}
