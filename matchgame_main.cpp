#include "matchgame_head.h"

//主函数
int main()
{
	Tree a;
	char choice;
	while(1)
	{
	    a.Run(a);
	    cout << "您还要继续玩吗？(Y/N) ";
	    cin >> choice;
	    if (choice == 'N')
	       break;
	} 
	return 0;
}
