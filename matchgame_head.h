#ifndef MATCHGAME_HEAD_H_
#define MATCHGAME_HEAD_H_
#include<cstdlib>
#include<iostream>
using namespace std;

//�����Ϣ
struct Node
{
	int number;                                    //���ֵ 
	int flag;                                      //1���ʾ���ֵС��0 
	Node* lchild, * mchild, * rchild;              //�������ָ�� 
	Node(int n, int f, Node* l, Node* m, Node* r) :number(n), flag(f), lchild(l), mchild(m), rchild(r) {}
};                                                 //���캯������ʼ�� 

//����
class Tree
{
public:
	void Create_tree(int n) {Create_tree(root, n);}//������
	float Odds(Node* ptr) {return Odds(ptr, 1);}   //�����ʤ����
	void Run(Tree tree1);                          //���к���
private: 
	Node* root;                                    //�����
	float Odds(Node* ptr, int i);                  //�����ʤ����
	void Create_tree(Node*& ptr, int n);           //����������
};

#endif
