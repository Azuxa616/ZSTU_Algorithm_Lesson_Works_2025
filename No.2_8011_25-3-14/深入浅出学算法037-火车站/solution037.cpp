#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int a, n, m, x,f[100];
    cin >> a >> n >> m >> x;

	f[0]=0;
	f[1]=1;
	for(int i=2;i<100;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
    int y=(m-(f[n-3]+1)*a)/(f[n-2]-1);
	double y1=(m-(f[n-3]+1)*a)*1.0/(f[n-2]-1);
	if(x<=3)
	{
		if(x==1)printf("%d",a);
		else if(x==2)printf("%d",a);
		else if(x==3)printf("%d",2*a);
	}
	else
	{
		int sum=(f[x-2]+1)*a+(f[x-1]-1)*y;
		if(sum>=0&&y==y1)printf("%d",sum);
		else printf("No answer.");
    }
}