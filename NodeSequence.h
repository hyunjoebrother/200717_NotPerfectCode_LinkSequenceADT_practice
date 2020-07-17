//Sequence ADT 구현
//Vector ADT + List ADT (Index & Position)
//List ADT 전체를 상속 받고 Vector ADT 일부분 연산을 추가적으로 멤버함수를 받는다

#include "DDLnodeList.h"

#include <iostream>
using namespace std;
#include <list>
#include <vector>

class NodeSequence :public NodeList //ListADT 상속 받는다
{
private:

public:
	//생성자
	NodeSequence():NodeList() { }
	//소멸자
	~NodeSequence();

	Iterator atIndex(int i) const; //index로부터 position 구한다
	int indexOf(const Iterator& p) const; //position으로부터 index 구한다
	NodeList& at(int i);

	void bubbleSort1(NodeSequence& S);
	void bubbleSort2(NodeSequence& S);
};