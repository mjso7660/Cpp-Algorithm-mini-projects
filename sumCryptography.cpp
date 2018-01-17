#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

/*Sum Sum cryptography
*B sends A a positive int N as the message and A decoes each message by solving x^2+y^2+z^2=N.
* Input Specs:
* 3<=N<=3000000
* Output:
* Sum of all components of all unique (x,y,z) tuples
*/

int main()
{
	int x; int y; int z; int n;
	cin>>n;
	int sum=0;
	for(int i=pow(n/3,0.5);i<=pow(n,0.5);i++){
		for(int j=pow((n-pow(i,2))/2,0.5);j<=pow(n-pow(i,2),0.5)&&j<=i;j++){
			for(int k=pow(n-pow(i,2)-pow(j,2),0.5);k<=pow(n-pow(i,2)-pow(j,2),0.5)&&k<=j;k++){
				if(pow(i,2)+pow(j,2)+pow(k,2)==n&&k>0){
					sum=sum+i+j+k;
				}
			}
		}
	}
	cout<<sum;
}

