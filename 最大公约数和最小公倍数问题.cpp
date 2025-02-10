#include<iostream>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int gcd(int a,int b){
	int r;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;	
	}
	return a;
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int main(){
	int x,y,count=0;
	x=read(),y=read();
	for(int P=x;P<=y;++P){//P*Q=x*y，x为P和Q的最大公约数，y为P和Q的最小公倍数，遍历范围从x~y就行了
		int Q=x*y/P;
		if(gcd(P,Q)==x&&lcm(P,Q)==y){
			count++;
		}
	}
	cout<<count;
	return 0;
}
