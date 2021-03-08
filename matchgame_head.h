#ifndef MATCHGAME_HEAD_H_
#define MATCHGAME_HEAD_H_
#include<cstdlib>
#include<iostream>
using namespace std;

//结点信息
struct Node
{
	int number;                                    //结点值 
	int flag;                                      //1则表示结点值小于0 
	Node* lchild, * mchild, * rchild;              //三个结点指针 
	Node(int n, int f, Node* l, Node* m, Node* r) :number(n), flag(f), lchild(l), mchild(m), rchild(r) {}
};                                                 //构造函数：初始化 

//树类
class Tree
{
public:
	void Create_tree(int n) {Create_tree(root, n);}//创建树
	float Odds(Node* ptr) {return Odds(ptr, 1);}   //计算获胜概率
	void Run(Tree tree1);                          //运行函数
private: 
	Node* root;                                    //根结点
	float Odds(Node* ptr, int i);                  //计算获胜概率
	void Create_tree(Node*& ptr, int n);           //构建三叉树
};

#endif
