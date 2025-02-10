#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

int primes[N];//存储所有素数 
bool vis[N],a[N];//vis存储i是否被筛掉 
//数组a记录偏移后的数据是不是合数，1：合数；0：质数。a[i]表示l+i是不是合数, 有一个偏移量l
ll l,r; 
int cnt; 

void get_primes()
{
	cnt = 0;
	for(int i = 2; i <= 50000; i++)
	{
		if(!vis[i]) primes[cnt++] = i;
		for(int j = 0; primes[j] <= 50000 / i; j++)
		{
			vis[primes[j] * i] = true;
			if(i % primes[j] == 0) break;
		}
	}
}

ll read()
{
	ll s=0,f=1;
	char ch=getchar();
	
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}


int main() {
	
	l = read(),r = read();
	
	l = l == 1 ? 2 : l;
	
	get_primes();
	
	for(int i = 0; i < cnt; i++)
	{
		ll st = max(2ll,(l-1) / primes[i] + 1) * primes[i];
		for(ll j = st; j <= r; j += primes[i]) a[j - l] = true;
	}
	
	//区间范围,因为我们无法完全映射所有的区间，只能采用类似于偏移的办法对某段区间整体偏移l进行描述。
	int ans = 0;
	for (ll i = l; i <= r; i++) if (!a[i - l])ans++;
	printf("%d", ans);
	
	return 0;
}
