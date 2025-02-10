#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int a[N];
bool st[N];
vector<int> primes;

void init(){
	for(int i=2;i<N;++i){
		if(!st[i]) primes.push_back(i);
		for(auto zz:primes){
			if(zz*i>=N) break;
			st[zz*i]=true;
			if(i%zz==0) break;
		}
	}
}
void solve(){
	int n;
	cin>>n;
	int x=0;
	bool ok=false;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(!st[a[i]]){
			if(!x) x=a[i];
			else ok=true;
		}
	}
	if(ok){
		cout<<-1<<'\n';
		return ;
	}
	if(!x){
		cout<<2<<'\n';
		return ;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==x) continue;
		if(a[i]%2==0){
			if(a[i]<2*x){
				cout<<-1<<'\n';
				return;
			}
		}else{
			for(auto zz:primes){
				if(a[i]%zz==0){
					if(a[i]-zz<2*x){
						cout<<-1<<'\n';
						return ;
					}
					break;
				}
			}
		}
	}
	cout<<x<<'\n';
}
int main(){
	int T=1;
	cin>>T;
	init();
	while(T--) solve();
	
	return 0;
}
