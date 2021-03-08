#include "matchgame_head.h"

float number1 = 0;                    //��ǰ��㵽0Ҷ�ӽ��ı���Ϊ�����ĸ���
float number2 = 0;                    //Ҷ���0�ĸ��� 

//�ݹ鴴����
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
		ptr->flag = 1;                //��ǰ���ֵС��0����Ч��� 
}

//�����ʤ����
float Tree::Odds(Node* ptr, int i)
{
	if (ptr != nullptr)               //һֱ�ݹ鵽Ҷ�ӽ�� 
	{
		Odds(ptr->lchild, ++i);
		--i;                          //i��ʾ���Ĳ���
		if (ptr->lchild == nullptr && ptr->flag == 0)
		{
			if ((i + 1) % 2 != 0)     //��ǰ��㵽0Ҷ�ӽ��ı���Ϊ���� 
			{
				number1++;            //��ǰ��㵽0Ҷ�ӽ��ı���Ϊ�����ĸ���
				number2++;            //Ҷ���0�ĸ���
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

//ִ�к���
void Tree::Run(Tree tree)
{
	
	int total;
	cout << "��������������";
	cin >> total;
	tree.Create_tree(total);          //���������� 
	Node* ptr = tree.root;
	first:
	cout << "��ѡ���սģʽ(1���˻���ս  2��˫�˶�ս)��";
	int i, c, gamer1, gamer2, j; 
	float odds[3], max_odds;          //oddsΪ���� 
	Node* temp = nullptr;
	cin >> i;
	switch (i)
	{
	    case 1:                       //�˻���ս
			while (1)
			{
		    	if (ptr->number < 1)
				{
			    	cout << "��Ϸ��������ϲ�����ʤ����" << endl;
				    break;
		    	}
		    	second:
				cout << "��������Ҫȡ�Ļ����(���ʣ�ࣺ" << ptr->number << ")��";
				cin >> gamer1;
				if (gamer1 == 1)      //ȡ1����� 
				    ptr = ptr->lchild;
			    else if (gamer1 == 2) //ȡ2�����
			  	    ptr = ptr->mchild;
				else if (gamer1 == 3) //ȡ3�����
				    ptr = ptr->rchild;
				else
				{ 
				    cout << "��Υ���ˣ����ֻ��ȡ3�����" << endl;
				    goto second;       //���ȡ���˷���ȡ  
				} 

			    if (ptr->number < 1)
				{
					cout << "��Ϸ�������������ʤ����" << endl;
					break;            //��Ϸ���������˳�ѭ�� 
			    }

                /*for (c = 1;c <= 3;++c)//������� 
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
			    		cout << "ȡ" << c << "������ʤ���ʣ�";
				    	number2 = number1 = 0;
				    	cout << tree.Odds(temp) << endl;
			    	}
		    	}*/

                for (c = 0;c < 3;c++) //���μ������
		    	{
			    	temp = ptr;
					if (c == 0)       //ȡ1ʱ 
				 	   temp = ptr->lchild;
				    else if (c == 1)  //ȡ2ʱ 
					    temp = ptr->mchild;
				   	else              //ȡ3ʱ
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
                max_odds = 0;         //�ҵ���ʤ����������±�
                for (c = 0;c < 3;c++)
                {
                	if (max_odds <= odds[c])
                	{
                	    max_odds = odds[c];
                	    j++;
                	}
				}
				gamer2 = j;           //����ȡӮ�������ʵĻ���� 
			    if (gamer2 == 1)
					ptr = ptr->lchild;
			    else if (gamer2 == 2)
				    ptr = ptr->mchild;
				else if (gamer2 == 3)
					ptr = ptr->rchild;
			    cout << "����ȡ�Ļ��������" << gamer2 << endl;
		   }
		   break;                     //�˳��˻���ս 
    	case 2:                       //˫�˶�սģʽ 
	    	while (1)
		    {
		    	if (ptr->number < 1)
		    	{
			    	cout << "��Ϸ���������1ȡ��ʤ����" << endl;
			    	break;            //��Ϸ���������˳�ѭ��
			    }

			    third:
			    cout << "�����1����Ҫȡ�Ļ����(���ʣ�ࣺ" << ptr->number << ")��";
		    	cin >> gamer1;
		    	if (gamer1 == 1)
			        ptr = ptr->lchild;
			    else if (gamer1 == 2)
			        ptr = ptr->mchild;
			    else if (gamer1 == 3)
				    ptr = ptr->rchild;
				else
				{
					cout << "���1Υ���ˣ����ֻ��ȡ3�����" << endl;
				    goto third;      //���ȡ���˷���ȡ
				}

		    	if (ptr->number < 1)
		    	{
			    	cout << "��Ϸ���������2ȡ��ʤ����" << endl;
			    	break;            //��Ϸ���������˳�ѭ��
			    }

			    fourth:
			    cout << "�����2����Ҫȡ�Ļ����(���ʣ�ࣺ" << ptr->number << ")��";
			    cin >> gamer2;
		    	if (gamer2 == 1)
				    ptr = ptr->lchild;
		     	else if (gamer2 == 2)
			    	ptr = ptr->mchild;
			    else if (gamer2 == 3)
			        ptr = ptr->rchild;
			    else
			    {
			    	cout << "���2Υ���ˣ����ֻ��ȡ3�����" << endl;
				    goto fourth;      //���ȡ���˷���ȡ
				}
		    }
	    	break;
    	default:
	    	cout << "��������ȷָ�" << endl;
		    goto first;               //������������
	}
}
