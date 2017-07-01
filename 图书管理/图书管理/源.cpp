#include<iostream>
#include<string>
using namespace std;
struct Libary {
	string id;
	string book_name;
	string author;
	//int count;
	struct Libary * next;
};
typedef struct Libary L;


void add(L * head)//添加书籍
{
	L * p=new L;
	string i, bn, au;
	cout << "请依次输入书籍编号,书名,作者" << endl;
	cin >> i >> bn >> au;
	p->author = au;
	p->book_name = bn;
	p->id = i;
	p->next = NULL;
	if (head->next == NULL)
	{
		head->next = p;
	}
	else
	{
		L * pre = head;
		while (pre->next!=NULL)
		{
			pre = pre->next;
		}
		pre->next = p;
	}
	cout << "已添加书籍" << endl;
}


void print(L * head)//输出书库目录
{
	cout << "目录：" << endl;
	L * p = head;
	if (head->next == NULL)
	{
		cout << "无书籍" << endl;
		return;
	}
	else
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			cout <<"书籍编号："<< p->id << " 书名：《" << p->book_name << "》 作者：" << p->author << endl;
		}
	}
	cout << endl;
}

int find_b(L * head,string kinds,string k)//查找书籍
{
	L * p = head;
	int flag = 0;
	for (p = head->next; p != NULL; p = p->next)
	{
		if (k == "id")
		{
			if (p->id == kinds)
			{
			flag = 1;
			cout << "书籍编号：" << p->id << " 书名：《" << p->book_name << "》 作者：" << p->author << endl;
			}
		}
		
		if (k == "bn")
		{
			if (p->book_name == kinds)
			{
				flag = 1;
				cout << "书籍编号：" << p->id << " 书名：《" << p->book_name << "》 作者：" << p->author << endl;
			}
		}
		if (k == "au")
		{
			if (p->author == kinds)
			{
				flag = 1;
				cout << "书籍编号：" << p->id << " 书名：《" << p->book_name << "》 作者：" << p->author << endl;
			}
		}
	}
	return flag;
}


void find_menu(L * head,string fk)//查找方式菜单
{
	
	//string fk;
	string kinds;
	int flag = 0;
	//cin >> fk;
	if (head->next == NULL)
	{
		cout << "书库为空" << endl;
		return;
	}
	if (fk == "id")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "查无此编号" << endl;
	}
	if (fk == "bn")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "查无此书名" << endl;
	}
	if (fk == "au")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "查无此作者" << endl;
	}
}

int main()
{
	L * head=new L;
	head->next = NULL;
	int type;
	cout << "1:添加书籍, 2:查看目录, ,3:查找书籍, 0:退出程序" << endl;
	while (1)
	{
		cin >> type;
		if (type == 1)
		{
			add(head);
		}
		else if (type == 2)
		{
			print(head);
		}
		else  if (type == 3)
		{
			cout << "查找方式如下：" << endl;
			cout << "输入：id 表示用id查找书籍" << endl;
			cout << "      bn 表示用书名查找书籍" << endl;
			cout << "      au 表示用查找作者相关书籍" << endl;
			cout << "      quit 表示退出查找" << endl;
			while (1)
			{
				string fk;
				cin >> fk;
				if (fk == "quit")
				{
					cout << "退出查找模式" << endl;
					break;
				}
				find_menu(head, fk);
			}
		}
		else if (type == 0) break;
		/*else
		{
			cout << "输入格式不对，请重新输入：" << endl;
			cin >> type;
			continue;
		}*/
	}
	system("pause");
	return 0;
}