#include "DDLnodeList.h"
#include <iostream>
using namespace std;
#include <string>
#include <list>

//Array나 LinkedList 구현 함수

//Iterator 멤버 함수 구현
NodeList::Iterator::Iterator(Node* u) //Node*로부터 생성자
{
	v = u;
}

Elem& NodeList::Iterator::operator*() //원소를 ref 한다
{
	return v->elem;
}

bool NodeList::Iterator::operator==(const Iterator& p) const //위치 비교
{
	return v == p.v;
}
bool NodeList::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

NodeList::Iterator& NodeList::Iterator::operator++() //다음 위치로 이동
{
	v = v->next;
	return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--() //이전 위치로 이동
{
	v = v->prev;
	return *this;
}


//메인 관련 함수

//생성자
NodeList::NodeList()
{
	n = 0; //초기에 empty
	header = new Node; //dummy node 생성
	trailer = new Node;
	header->next = trailer; //서로 point해준다
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
NodeList::Iterator NodeList::begin() const //시작 위치
{
	return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const //마지막 위치의 바로 다음
{
	return Iterator(trailer);
}

//Update function
void NodeList::insertFront(const Elem& e) //첫 번째 node로 삽입
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
void NodeList::insert(const NodeList::Iterator& p, const Elem& e) //p 앞에 e insert
{
	Node* w = p.v; //p의 node
	Node* u = w->prev; //p의 앞 node
	Node*v = new Node; //삽입할 새 node
	v->elem = e;
	v->next = w; w->prev = v; //v를 w앞에 연결
	v->prev = u; u->next = v; //v를 u뒤에 연결
	n++;
}

void NodeList::erase(const Iterator& p)
{
	Node *v = p.v; //삭제될 node
	Node* w = v->next;
	Node* u = v->prev;
	u->next = w; w->prev = u;
	delete v; //삭제된 node 메모리 반환
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