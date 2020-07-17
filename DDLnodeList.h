//(Node) List ADT

//linear, ����x -> ������ ��ġ�� ��� ����
//position�� ������ -> ���� ������ �ƴϿ��� ����

//Doubly Linked List�� ����
//-> ����� trailer & header 2���� dummy node

//Iterations: position�� ��� ����

#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <vector>

//����ó��

//Array�� LinkedList ����

//����

typedef int Elem;
class NodeList
{
private: //Node ����

	struct Node //DLL���� Node ����
	{
		Elem elem; //������ ��
		Node* prev; //����Ʈ���� ��/�� node
		Node* next;
	};

public: //Iterator ����

	class Iterator //����Ʈ�� ���� �ݺ��� (position�� ��� ����)
	{
	private:
		Node* v; //node���� ������
		Iterator(Node* u); //node�κ��� ����

	public:
		Elem& operator*(); //���Ҹ� ref �Ѵ�

		bool operator==(const Iterator& p) const; //��ġ ��
		bool operator!=(const Iterator& p) const;
		Iterator& operator++(); //���� ��ġ�� �̵�
		Iterator& operator--(); //���� ��ġ�� �̵�

		friend class NodeList; //NodeList���� ���� ���
	};

private:
	int n; //������ ���
	Node* header; //����Ʈ �տ� �ִ� dummy node
	Node* trailer;

public:
	//������
	NodeList();
	//�Ҹ���
	~NodeList();

	int size() const;
	bool empty() const;

	//Iterator
	Iterator begin() const; //���� ��ġ
	Iterator end() const; //������ ��ġ�� �ٷ� ����

	//Update function
	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void eraseFront();
	void eraseBack();

	//Position-based update
	void insert(const Iterator& p, const Elem& e); //p �տ� e insert
	void erase(const Iterator& p);
};
;