#include<iostream>
using namespace std;
typedef long long ll;

const ll num=19260817;
ll readll(){
	char ch=getchar();
	int res=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		res%=num;
		ch=getchar();
	}
	return res;
}
ll exgcd(ll a,ll b,ll&x,ll&y){
	ll d=a;
	if(!b){
		x=1,y=0;
	}else{
		d=exgcd(b,a%b,y,x),y-=a/b*x;
	}
	return d;
}
int main(){
	
	ll a,b;
	a=readll();
	b=readll();
	if(!b){
		cout<<"Angry!";
	}
	ll x,y;
	exgcd(b,num,x,y);
	x=(x%num+num)%num;
	cout<<a*x%num<<'\n';
	return 0;
}
