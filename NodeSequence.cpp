#include "NodeSequence.h"
#include <iostream>
using namespace std;
#include <string>
#include <list>

//Array�� LinkedList ���� �Լ�

//��� �Լ� ����


NodeSequence::Iterator::Iterator()          // ���ο��� repos���𿡼� �ʿ� repos�� data type�� Iterator�̹Ƿ� 
{
	v = nullptr;			     // v�� �⺻���¿��� NULL(�ƹ��͵� �Ȱ���Ű����) nullptr�� NULL��������? ������ nullptr�ϸ� �ȵǴ���
	//v = new Node<E>;           ��ȯ�� ���������ϹǷ� ���ʿ� �Ҵ�����������.
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
	while (q != p) //p�� ã�� ������
	{
		++q;
		++j; //�̵��ϰ� Ƚ���� ���
	}
	return j;
}

NodeSequence::at(int i)  //������ ����ó�� ���־���ϳ� ���� main���� ���ܰ� �ȳ����Ƿ� ����ó���� ����.
{
	return(*atIndex(i));
}