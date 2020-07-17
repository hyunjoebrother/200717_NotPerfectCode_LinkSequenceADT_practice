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
	bubbleSort2(ns); // bubbleSort1(ns); ��� ���

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
void bubbleSort1(NodeSequence& ns) //index�� ���� bubble-sort
{
	int n = ns.size();
	for (int i = 0; i < n; i++) //i��° �н�
	{
		for (int j = 1; j < n - i; j++)
		{
			NodeSequence::Iterator prec = ns.atIndex(j - 1); //��
			NodeSequence::Iterator succ = ns.atIndex(j); //����
			if (*prec > *succ) //������ Ʋ���� change
			{
				int tmp = *prec;
				*prec = *succ;
				*succ = tmp;
			}
		}
	}
}

void bubbleSort2(NodeSequence& ns) //position�� ���� bubble-sort
{
	int n = ns.size();
	for (int i = 0; i < n; i++) //i��° �н�
	{
		for (int j = 1; j < n - i; j++)
		{
			NodeSequence::Iterator prec = ns.begin(); //��
			for (int j = 1; j < n - i; j++) {
				NodeSequence::Iterator succ = prec;
				++succ; //����
				if (*prec > *succ) //������ Ʋ���� change
				{
					int tmp = *prec;
					*prec = *succ;
					*succ = tmp;
				}
				++prec; //���� next
			}
		}
	}
}


//Linear Searching �Լ��� �����غ���
NodeSequence::Iterator linearSearch(NodeSequence& ns, int k) // ���������� Ư�� Ű �� k�� ã�� �װ��� �������� ��ȯ
{
	int a = 0;							  // at������ ���� index
	bool b = true;						  // if�� �Ǵ������� ��ǥ
	if (ns.empty())
	{
		return NULL; //�������� ������� NULL��ȯ
	}

	else {
		// �������� �Ⱥ���ٸ�
		for (a = 0; a < ns.size(); a++) { // a = rank��
			if (ns.at(a) == k) {
				break;					  // elem�� k�� ���ٸ� b= true��ä�� for��Ż���� �ٷ� if����
			}
			else if (a == ns.size() - 1) {     // a�� ������ ����Ž���ߴµ��� ��ġ�ϴ� k���� ���°�� 
				b = false;				       // else���ϸ� ������ ������ �����ʰ� else���ɸ��Ƿ� �̷���.
			}
		}
		if (b == true)						   // b�� true��� k�� �������� ����
			return ns.atIndex(a);
		else                                   // b�� false��� NULL return
			return NULL;
	}
}
