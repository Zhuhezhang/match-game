#include "matchgame_head.h"

float number1 = 0;                    //当前结点到0叶子结点的边数为基数的个数
float number2 = 0;                    //叶结点0的个数 

//递归创建树
void Tree::Create_tree(Node*& ptr, int n)
{
	ptr = new Node(n, 0, nullptr, nullptr, nullptr);
	if (n > 0)
	{
		Create_tree(ptr->lchild, n - 1);
		Create_tree(ptr->mchild, n - 2);
		Create_tree(ptr->rchild, n - 3);
	}
	else if (n < 0)
		ptr->flag = 1;                //当前结点值小于0，无效结点 
}

//计算获胜概率
float Tree::Odds(Node* ptr, int i)
{
	if (ptr != nullptr)               //一直递归到叶子结点 
	{
		Odds(ptr->lchild, ++i);
		--i;                          //i表示树的层数
		if (ptr->lchild == nullptr && ptr->flag == 0)
		{
			if ((i + 1) % 2 != 0)     //当前结点到0叶子结点的边数为奇数 
			{
				number1++;            //当前结点到0叶子结点的边数为基数的个数
				number2++;            //叶结点0的个数
			}
			else
				number2++;
		}
	     
		Odds(ptr->mchild, ++i);
		--i;
		if (ptr->mchild == nullptr && ptr->flag == 0)
		{
			if ((i + 1) % 2 != 0)
			{
				number1++;
				number2++;
			}
			else
				number2++;
		}

		Odds(ptr->rchild, ++i);
		--i;
		if (ptr->rchild == nullptr && ptr->flag == 0)
		{
			if ((i + 1) % 2 != 0)
			{
				number1++;
				number2++;
			}
			else
				number2++;
		}
	}
	return number1 / number2;
}

//执行函数
void Tree::Run(Tree tree)
{
	
	int total;
	cout << "请输入火柴总数：";
	cin >> total;
	tree.Create_tree(total);          //创建三叉树 
	Node* ptr = tree.root;
	first:
	cout << "请选择对战模式(1、人机对战  2、双人对战)：";
	int i, c, gamer1, gamer2, j; 
	float odds[3], max_odds;          //odds为概率 
	Node* temp = nullptr;
	cin >> i;
	switch (i)
	{
	    case 1:                       //人机对战
			while (1)
			{
		    	if (ptr->number < 1)
				{
			    	cout << "游戏结束！恭喜您获得胜利！" << endl;
				    break;
		    	}
		    	second:
				cout << "请输入您要取的火柴数(火柴剩余：" << ptr->number << ")：";
				cin >> gamer1;
				if (gamer1 == 1)      //取1根火柴 
				    ptr = ptr->lchild;
			    else if (gamer1 == 2) //取2根火柴
			  	    ptr = ptr->mchild;
				else if (gamer1 == 3) //取3根火柴
				    ptr = ptr->rchild;
				else
				{ 
				    cout << "您违规了！最多只能取3根火柴！" << endl;
				    goto second;       //火柴取多了返回取  
				} 

			    if (ptr->number < 1)
				{
					cout << "游戏结束！机器获得胜利！" << endl;
					break;            //游戏结束，则退出循环 
			    }

                /*for (c = 1;c <= 3;++c)//输出概率 
		    	{
			    	temp = ptr;
			    	if (c == 1)
			    		temp = ptr->lchild;
			    	else if (c == 2)
				    	temp = ptr->mchild;
			    	else
				    	temp = ptr->rchild;
			    	if (temp != nullptr && temp->flag == 0)
			    	{
			    		cout << "取" << c << "根火柴获胜概率：";
				    	number2 = number1 = 0;
				    	cout << tree.Odds(temp) << endl;
			    	}
		    	}*/

                for (c = 0;c < 3;c++) //依次计算概率
		    	{
			    	temp = ptr;
					if (c == 0)       //取1时 
				 	   temp = ptr->lchild;
				    else if (c == 1)  //取2时 
					    temp = ptr->mchild;
				   	else              //取3时
						temp = ptr->rchild;
				    if (temp != nullptr && temp->flag == 0)
				    {
				    	number2 = number1 = 0;
				    	odds[c] = tree.Odds(temp);
			    	}
			    	else
			    	    odds[c] = -1;
	    	    }
	    	    j = 0;
                max_odds = 0;         //找到获胜概率最大结点下标
                for (c = 0;c < 3;c++)
                {
                	if (max_odds <= odds[c])
                	{
                	    max_odds = odds[c];
                	    j++;
                	}
				}
				gamer2 = j;           //机器取赢的最大概率的火柴数 
			    if (gamer2 == 1)
					ptr = ptr->lchild;
			    else if (gamer2 == 2)
				    ptr = ptr->mchild;
				else if (gamer2 == 3)
					ptr = ptr->rchild;
			    cout << "机器取的火柴数量：" << gamer2 << endl;
		   }
		   break;                     //退出人机对战 
    	case 2:                       //双人对战模式 
	    	while (1)
		    {
		    	if (ptr->number < 1)
		    	{
			    	cout << "游戏结束！玩家1取得胜利！" << endl;
			    	break;            //游戏结束，则退出循环
			    }

			    third:
			    cout << "请玩家1输入要取的火柴数(火柴剩余：" << ptr->number << ")：";
		    	cin >> gamer1;
		    	if (gamer1 == 1)
			        ptr = ptr->lchild;
			    else if (gamer1 == 2)
			        ptr = ptr->mchild;
			    else if (gamer1 == 3)
				    ptr = ptr->rchild;
				else
				{
					cout << "玩家1违规了！最多只能取3根火柴！" << endl;
				    goto third;      //火柴取多了返回取
				}

		    	if (ptr->number < 1)
		    	{
			    	cout << "游戏结束！玩家2取得胜利！" << endl;
			    	break;            //游戏结束，则退出循环
			    }

			    fourth:
			    cout << "请玩家2输入要取的火柴数(火柴剩余：" << ptr->number << ")：";
			    cin >> gamer2;
		    	if (gamer2 == 1)
				    ptr = ptr->lchild;
		     	else if (gamer2 == 2)
			    	ptr = ptr->mchild;
			    else if (gamer2 == 3)
			        ptr = ptr->rchild;
			    else
			    {
			    	cout << "玩家2违规了！最多只能取3根火柴！" << endl;
				    goto fourth;      //火柴取多了返回取
				}
		    }
	    	break;
    	default:
	    	cout << "请输入正确指令！" << endl;
		    goto first;               //返回重新输入
	}
}
