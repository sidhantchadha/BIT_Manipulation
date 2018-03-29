//============================================================================
// Name        : BIT_Manipulation.cpp
// Author      : Sidhant Chadha
// Version     :
// Copyright   : 
// Description : BIT Manipulation in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;

//BITwise Operations//

//Bitwise AND//
void AND(int a, int b) {
	int c= a & b;
	cout<<"AND of "<<a<<" ("<<bitset<8>(a)<<") and "<<b<<" ("<<bitset<8>(b)<<")  is "<<c<<" ("<<bitset<8>(c)<<") "<<endl;
}

//Bitwise OR//
void OR(int a,int b) {
	int c= a | b;
	cout<<"OR of "<<a<<" ("<<bitset<8>(a)<<") and "<<b<<" ("<<bitset<8>(b)<<")  is "<<c<<" ("<<bitset<8>(c)<<") "<<endl;
}

//Bitwise XOR//
void XOR(int a,int b){
	int c= a ^ b;
	cout<<"XOR of "<<a<<" ("<<bitset<8>(a)<<") and "<<b<<" ("<<bitset<8>(b)<<")  is "<<c<<" ("<<bitset<8>(c)<<") "<<endl;
}

//Bitwise NOT//
void NOT(int a){
	int c= ~a;
	cout<<"NOT of "<<a<<" ("<<bitset<8>(a)<<") is "<<c<<" ("<<bitset<8>(c)<<") "<<endl;
}

//Bitwise Left Shift//
void leftShift(int a, int shifts) {
	int c= a << shifts;
	cout<<"LEFT SHIFT of "<<a<<" ("<<bitset<8>(a)<<") is "<<c<<" ("<<bitset<8>(c)<<") "<<endl;
}

//Bitwis Right Shift//
void rightShift(int a, int shifts) {
	int c= a >> shifts;
	cout<<"RIGHT SHIFT of "<<a<<" ("<<bitset<8>(a)<<") is "<<c<<" ("<<bitset<8>(c)<<") "<<endl;
}

//BITwise Manipulation

//SET a bit//
void SETbit(int a, int pos) {
	int mask=1<<pos;
	int result= a | mask;
	cout<<"After setting a bit "<<a<<" ("<<bitset<8>(a)<<") is "<<result<<" ("<<bitset<8>(result)<<") "<<endl;

}

//CLEAR a bit//
void CLEARbit(int a, int pos) {
	int mask=1<<pos;
	int result= a & mask;
	cout<<"After clearing a bit "<<a<<" ("<<bitset<8>(a)<<") is "<<result<<" ("<<bitset<8>(result)<<") "<<endl;

}

//FLIP a bit//
void FLIPbit(int a, int pos) {
	int mask=1<<pos;
	int result= a ^ mask;
	cout<<"After flipping a bit "<<a<<" ("<<bitset<8>(a)<<") is "<<result<<" ("<<bitset<8>(result)<<") "<<endl;

}

//Is BIT set//
void isBitSET(int a, int pos) {
	int shifted=a>>pos;
	int result= shifted & 1;
	cout<<"Is BIT set for "<<a<<" ("<<bitset<8>(a)<<") at position-"<<pos<<" ? "<<result<<endl;

}

//Modify BIT- Set case//
void modifyBITset(int a,int pos, int state) {
	int mask=1<<pos;
	int result= (a & (~mask)) | (-state & mask);
	cout<<"Modified bit for "<<a<<" ("<<bitset<8>(a)<<") is "<<result<<" ("<<bitset<8>(result)<<")"<<endl;
}

//Modify BIT- Clear case//
void modifyBITclear(int a,int pos, int state) {
	int mask=1<<pos;
	int result= (a & mask) | (-state & mask);
	cout<<"Modified bit for "<<a<<" ("<<bitset<8>(a)<<") is "<<result<<" ("<<bitset<8>(result)<<")"<<endl;
}

//Count SET bits using Lookup Table. Time complexity: O((logN)/K) for a K-bit system //
void countSETbits(int a){
	//indexes={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
	int table[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
	int count=0;
	int x=a;
	for(;x;x>>=4)
		count=count+table[a & 0xF];
	cout<<"Count of SET bits for "<<a<<" ("<<bitset<8>(a)<<") "<<count<<endl;
}

//Swap bits//
void swapBITS(int a,int b) {
	int x=a;
	int y=b;
	x^=y;
	y^=x;
	x^=y;
	cout<<"Initial values: a: "<<a<<" ("<<bitset<8>(a)<<") and b: "<<b<<" ("<<bitset<8>(b)<<")"<<endl;\
	cout<<"Swapped values: a: "<<x<<" ("<<bitset<8>(x)<<") and b: "<<y<<" ("<<bitset<8>(y)<<")"<<endl;\

}

//Absolute value//
void absoluteVal(int a) {
	int x=a;
	int mask=x>>31;
	int result=(x ^ mask) - mask;
	cout<<"Absolute value of a: "<<a<<" ("<<bitset<8>(a)<<") is "<<result<<" ("<<bitset<8>(result)<<")"<<endl;
}

int main() {

	unsigned int a=7;
	unsigned int b=12;

	AND(a,b);
	OR(a,b);
	XOR(a,b);
	unsigned int c=3;
	NOT(c);
	leftShift(a,3);
	rightShift(b,2);
	SETbit(9,2);
	CLEARbit(6,1);
	FLIPbit(102,1);
	isBitSET(56,4);
	isBitSET(56,6);
	modifyBITset(5,3,1);
	modifyBITclear(6,2,0);
	countSETbits(9);
	countSETbits(14);
	swapBITS(3,7);
	absoluteVal(-21);


}
