#include "DDLnodeList.h"
#include <iostream>
using namespace std;
#include <string>
#include <list>

//Array�� LinkedList ���� �Լ�

//Iterator ��� �Լ� ����
NodeList::Iterator::Iterator(Node* u) //Node*�κ��� ������
{
	v = u;
}

Elem& NodeList::Iterator::operator*() //���Ҹ� ref �Ѵ�
{
	return v->elem;
}

bool NodeList::Iterator::operator==(const Iterator& p) const //��ġ ��
{
	return v == p.v;
}
bool NodeList::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

NodeList::Iterator& NodeList::Iterator::operator++() //���� ��ġ�� �̵�
{
	v = v->next;
	return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--() //���� ��ġ�� �̵�
{
	v = v->prev;
	return *this;
}


//���� ���� �Լ�

//������
NodeList::NodeList()
{
	n = 0; //�ʱ⿡ empty
	header = new Node; //dummy node ����
	trailer = new Node;
	header->next = trailer; //���� point���ش�
	trailer->prev = header;
}

int NodeList::size() const
{
	return n;
}

bool NodeList::empty() const
{
	return (n == 0);
}

//Iterator
NodeList::Iterator NodeList::begin() const //���� ��ġ
{
	return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const //������ ��ġ�� �ٷ� ����
{
	return Iterator(trailer);
}

//Update function
void NodeList::insertFront(const Elem& e) //ù ��° node�� ����
{
	insert(begin(), e);
}

void NodeList::insertBack(const Elem& e)
{
	insert(end(), e);
}
void NodeList::eraseFront()
{
	erase(begin());
}

void NodeList::eraseBack()
{
	erase(--end());
}

//Position-based update
void NodeList::insert(const NodeList::Iterator& p, const Elem& e) //p �տ� e insert
{
	Node* w = p.v; //p�� node
	Node* u = w->prev; //p�� �� node
	Node*v = new Node; //������ �� node
	v->elem = e;
	v->next = w; w->prev = v; //v�� w�տ� ����
	v->prev = u; u->next = v; //v�� u�ڿ� ����
	n++;
}

void NodeList::erase(const Iterator& p)
{
	Node *v = p.v; //������ node
	Node* w = v->next;
	Node* u = v->prev;
	u->next = w; w->prev = u;
	delete v; //������ node �޸� ��ȯ
	n--;
}

int main()
{
	NodeList A;

	A.insertFront(19);
	A.insertFront(17);

	cout << A.empty() << endl;
	cout << A.size() << endl;
}