//(Node) List ADT

//linear, 제약x -> 임의의 위치에 모두 가능
//position의 시퀀스 -> 연속 공간이 아니여도 가능

//Doubly Linked List로 구현
//-> 양방향 trailer & header 2개의 dummy node

//Iterations: position을 얻는 연산

#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <vector>

//예외처리

//Array나 LinkedList 구현

//메인

typedef int Elem;
class NodeList
{
private: //Node 선언

	struct Node //DLL에서 Node 선언
	{
		Elem elem; //원소의 값
		Node* prev; //리스트에서 앞/뒤 node
		Node* next;
	};

public: //Iterator 선언

	class Iterator //리스트를 위한 반복자 (position을 얻기 위한)
	{
	private:
		Node* v; //node에서 포인터
		Iterator(Node* u); //node로부터 생성

	public:
		Elem& operator*(); //원소를 ref 한다

		bool operator==(const Iterator& p) const; //위치 비교
		bool operator!=(const Iterator& p) const;
		Iterator& operator++(); //다음 위치로 이동
		Iterator& operator--(); //이전 위치로 이동

		friend class NodeList; //NodeList에게 접근 허용
	};

private:
	int n; //데이터 멤버
	Node* header; //리스트 앞에 있는 dummy node
	Node* trailer;

public:
	//생성자
	NodeList();
	//소멸자
	~NodeList();

	int size() const;
	bool empty() const;

	//Iterator
	Iterator begin() const; //시작 위치
	Iterator end() const; //마지막 위치의 바로 다음

	//Update function
	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void eraseFront();
	void eraseBack();

	//Position-based update
	void insert(const Iterator& p, const Elem& e); //p 앞에 e insert
	void erase(const Iterator& p);
};
;