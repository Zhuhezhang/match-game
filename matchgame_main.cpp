#include "matchgame_head.h"

//������
int main()
{
	Tree a;
	char choice;
	while(1)
	{
	    a.Run(a);
	    cout << "����Ҫ��������(Y/N) ";
	    cin >> choice;
	    if (choice == 'N')
	       break;
	} 
	return 0;
}
