#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

/* Volleyball rotations: players between 7 and 26 people on my team. Every rotation, one of the sidelines players will come into the court at position 1 while one player will eave the court at position 2 and join the sideline at the back of the line
*-------------------
*|  4  |  3  |  2 -|->
*|-----------------|
*|  5  |  6  |  1 <|--
*-------------------
*Setter will always be in the starting lineup and will not be rotated off the court
*Input specification:
*1. # of rotations
*2. name of the setter
*3. The starting lineup
*4. The players on the sidelines
*Find: the lineup after the N number of rotations ordering them based on they will end up
*INPUT(example):
*3
*A
*A B C D E F 
*4 G H I J
*OUTPUT:
*I E F A G H
**/
int main(){
	int rot=0; string setter=""; 
	cin>>rot>>setter;		//rot:1st line, setter:2nd line
	vector<string> start(6);
	string a="";
	cin>>a;
	start[5]=a;			//#1 
	for(int i=0;i!=5;i++){
		string a="";	
		cin>>a;			//#2~6
		start[i]=a;
	}
		
	int n;
	cin>>n;				//# of rest of players
	for(int j=0;j!=n;j++){
		string b="";
		cin>>b;			
		start.insert(start.begin()+j+6,b);
	}

	//now run rotations
	for(int turn=0;turn!=rot;turn++){
		if(start[0]!=setter){
			string a=start[0];
			start.erase(start.begin());
			start.insert(start.begin()+n+5,a);
		}else{
			start.erase(start.begin());
			start.insert(start.begin()+5,setter);
		}
	}

	//print output
	cout<<start[5];
	for(int i=0;i!=5;i++){
		cout<<" "<<start[i];
	}
			
}

