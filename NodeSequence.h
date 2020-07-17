//Sequence ADT ����
//Vector ADT + List ADT (Index & Position)
//List ADT ��ü�� ��� �ް� Vector ADT �Ϻκ� ������ �߰������� ����Լ��� �޴´�

#include "DDLnodeList.h"

#include <iostream>
using namespace std;
#include <list>
#include <vector>

class NodeSequence :public NodeList //ListADT ��� �޴´�
{
private:

public:
	//������
	NodeSequence():NodeList() { }
	//�Ҹ���
	~NodeSequence();

	Iterator atIndex(int i) const; //index�κ��� position ���Ѵ�
	int indexOf(const Iterator& p) const; //position���κ��� index ���Ѵ�
	NodeList& at(int i);

	void bubbleSort1(NodeSequence& S);
	void bubbleSort2(NodeSequence& S);
};