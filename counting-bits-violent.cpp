/*
给你一个整数n,对于0<=i<=n中的每个i,计算其二进制表示中1的个数,返回一个长度为n+1的数组ans作为答案。
*/

/*
test cases:
输入：n = 2
输出：[0,1,1]
解释：
0 --> 0
1 --> 1
2 --> 10

输入：n = 5
输出：[0,1,1,2,1,2]
解释：
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int countOnes(int x) {
	int bitsNum=1,onesNum=0;
	for(int i=1;i<x;i*=2)bitsNum++;
	for(int i=bitsNum-1;i>=0;i--){
		int remain=x%(int)(pow(2,i));
		int digit=x/(int)(pow(2,i));
		if(digit==1)onesNum++;
		x=remain;
	}
	return onesNum;
}

vector<int> countBits(int n) {
	vector<int> v;
	for(int i=0;i<=n;i++){
		v.push_back(countOnes(i));
	}
	return v;
}

int main(){
	int n=5;
	vector<int> v=countBits(5);
	for(auto it=v.begin();it!=v.end();it++)cout<<*it<<endl;
	return 0;
}