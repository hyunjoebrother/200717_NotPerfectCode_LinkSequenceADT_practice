#include "NodeSequence.h"
#include <iostream>
using namespace std;
#include <string>
#include <list>

//Array나 LinkedList 구현 함수

//멤버 함수 구현


NodeSequence::Iterator::Iterator()          // 메인에서 repos선언에서 필요 repos의 data type이 Iterator이므로 
{
	v = nullptr;			     // v는 기본상태에선 NULL(아무것도 안가리키도록) nullptr과 NULL무슨차이? 언제는 nullptr하면 안되던데
	//v = new Node<E>;           반환을 해주지못하므로 애초에 할당해주지말자.
}


NodeSequence::Iterator NodeSequence::atIndex(int i) const
{
	Iterator p = begin();
	for (int j = 0; j < i; j++)
		++p;
	return p;
}

int NodeSequence::indexOf(const Iterator& p) const
{
	Iterator q = begin();
	int j = 0;
	while (q != p) //p를 찾을 때까지
	{
		++q;
		++j; //이동하고 횟수를 계산
	}
	return j;
}

NodeSequence::at(int i)  //원래는 예외처리 해주어야하나 현재 main에선 예외가 안나오므로 예외처리는 생략.
{
	return(*atIndex(i));
}