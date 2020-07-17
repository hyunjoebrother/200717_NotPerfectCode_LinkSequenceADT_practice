#include "DDLnodeList.h"
#include "NodeSequence.h"

#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <vector>


template <typename E>
void bubbleSort2(NodeSequence& ns);

template <typename E>
NodeSequence::Iterator linearSearch(NodeSequence& ns, int k);


void main() {
	typedef NodeSequence IntSequence;
	typedef NodeSequence::Iterator IntSequenceNodePtr;


	const int NOS = 7;
	int a[NOS] = { 6, 7, 2, 5, 1, 4, 3 };

	IntSequence ns;

	for (int i = 0; i < NOS; i++) ns.insert(i, a[i]);

	cout << "A sequence of size = " << ns.size() << endl;
	bubbleSort2(ns); // bubbleSort1(ns); 대신 사용

	cout << "---- Testing index-based operations ----" << endl;

	// Accessing sequence thru vector's operations
	for (int i = 0; i < NOS; i++) 
	{
		cout << "Index = " << i << " => " << ns.at(i) << endl;
	}
	cout << "---- Testing position(pointer)-based operations ----" << endl;

	int k;
	IntSequenceNodePtr retPos;
	cout << "Entery searching key (-1 for exit) : ";
	cin >> k;

	while (k != -1) 
	{
		retPos = linearSearch(ns, k);
		if (retPos == NULL) cout << "Searching key is not found!" << endl;
		else cout << "Searching key is found at index = " << ns.indexOf(retPos) << endl;
		cout << "Entery searching key (-1 for exit) : ";
		cin >> k;
	}

	for (int i = 0; i < 7; i++) ns.erase(ns.begin());
}


//Bubble-Sort
void bubbleSort1(NodeSequence& ns) //index에 의한 bubble-sort
{
	int n = ns.size();
	for (int i = 0; i < n; i++) //i번째 패스
	{
		for (int j = 1; j < n - i; j++)
		{
			NodeSequence::Iterator prec = ns.atIndex(j - 1); //앞
			NodeSequence::Iterator succ = ns.atIndex(j); //다음
			if (*prec > *succ) //순서가 틀리면 change
			{
				int tmp = *prec;
				*prec = *succ;
				*succ = tmp;
			}
		}
	}
}

void bubbleSort2(NodeSequence& ns) //position에 의한 bubble-sort
{
	int n = ns.size();
	for (int i = 0; i < n; i++) //i번째 패스
	{
		for (int j = 1; j < n - i; j++)
		{
			NodeSequence::Iterator prec = ns.begin(); //앞
			for (int j = 1; j < n - i; j++) {
				NodeSequence::Iterator succ = prec;
				++succ; //다음
				if (*prec > *succ) //순서가 틀리면 change
				{
					int tmp = *prec;
					*prec = *succ;
					*succ = tmp;
				}
				++prec; //앞을 next
			}
		}
	}
}


//Linear Searching 함수를 구현해보자
NodeSequence::Iterator linearSearch(NodeSequence& ns, int k) // 시퀀스에서 특정 키 값 k를 찾아 그것의 포지션을 반환
{
	int a = 0;							  // at연산을 위한 index
	bool b = true;						  // if문 판단을위한 지표
	if (ns.empty())
	{
		return NULL; //시퀀스가 비었으면 NULL반환
	}

	else {
		// 시퀀스가 안비었다면
		for (a = 0; a < ns.size(); a++) { // a = rank값
			if (ns.at(a) == k) {
				break;					  // elem과 k가 같다면 b= true인채로 for문탈출후 바로 if문비교
			}
			else if (a == ns.size() - 1) {     // a가 끝까지 선형탐색했는데도 일치하는 k값이 없는경우 
				b = false;				       // else로하면 포문이 끝까지 가지않고 else에걸리므로 이렇게.
			}
		}
		if (b == true)						   // b가 true라면 k의 포지션을 리턴
			return ns.atIndex(a);
		else                                   // b가 false라면 NULL return
			return NULL;
	}
}
