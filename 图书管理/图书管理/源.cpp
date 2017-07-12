#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Library {		//书籍链表
	string id;			//书籍编号
	string book_name;	//书名
	string author;		//作者
	int count;			//数量
	struct Library * next;
};
typedef struct Library L;


void init(L * head)  // 初始化链表
{
	L * p,* pre;
	pre = head;
	string s;
	char num;
	ifstream infile("e://Library//ALLBOOK.txt", ios::in);//以读取的方式打开本地文件
	while (!infile.eof())//本地数据存入链表
	{

		p = new L;
		getline(infile, s, '\n');
		p->id = s;
		infile>>p->count ;
		getline(infile, s, '\n');
		getline(infile, s, '\n');
		p->book_name = s;
		getline(infile, s, '\n');
		p->author = s;
		p->next = NULL;
		pre->next = p;
		pre = pre->next;
	}
}
void save(L *head)  //数据存入本地文件
{
	L * p = head;
	ofstream outfile("e://Library//ALLBOOK.txt", ios::out);//以写入的方式打开本地文件
	p = head->next;
	while (p != NULL)
	{
		if (p->id != "")
		{
		outfile << p->id << endl;
		outfile << p->count << endl;
		outfile << p->book_name << endl;
		outfile << p->author;

		if (p->next != NULL) outfile << endl;
		}
		p = p->next;
	}
}

bool find(L * head, string i, string bn, string au)//判断是否存在
{
	L * p = head;
	if (head->next == NULL)
	{
		return false;
	}
	for (p = head->next; p != NULL; p = p->next)
	{
		if (p->id == i&&p->book_name == bn&&p->author == au)
		{
			p->count++;                  //若是已经存在则添加其数量
			cout << "已添加书籍" << endl;
			return true;
		}
	}
	return false;
}
void add(L * head,string i,string bn,string au)//添加书籍
{
	if(!find(head,i,bn,au))//本地书库不存在 则添加新书籍
	{
	L * p=new L;
	p->author = au;
	p->book_name = bn;
	p->id = i;
	p->count = 1;
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

}


void print(L * head)//输出书库目录
{
	cout << "目录：" << endl;
	L * p = head;
	if (head->next == NULL||head->next->id=="")
	{
		cout << "	无书籍" <<endl<< endl;
		return;
	}
	else
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			cout <<"	书籍编号："<< p->id << " 书名：《" << p->book_name << "》 作者：" << p->author<<" 可借数："<<p->count<< endl;
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
			cout << "	书籍编号：" << p->id << " 书名：《" << p->book_name << "》 作者：" << p->author << " 可借数：" << p->count << endl;
			}
		}
		
		if (k == "bn")
		{
			if (p->book_name == kinds)
			{
				flag = 1;
				cout << "	书籍编号：" << p->id << " 书名：《" << p->book_name << "》 作者：" << p->author << " 可借数：" << p->count << endl;
			}
		}
		if (k == "au")
		{
			if (p->author == kinds)
			{
				flag = 1;
				cout << "	书籍编号：" << p->id << " 书名：《" << p->book_name << "》 作者：" << p->author <<" 可借数："<<p->count<< endl;
			}
		}
	}
	return flag;
}


void find_menu(L * head,string fk)//查找方式菜单
{
	
	string kinds;
	int flag = 0;
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
		if (flag == 0) cout << "查无此书" << endl;
	}
	if (fk == "au")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "查无此作者" << endl;
	}
}
void menu()
{
	cout << "=======================================" << endl;
	cout << "||                                   ||" << endl;
	cout << "||      欢迎使用图书管理系统         ||" << endl;
	cout << "||      本系统含有以下几种功能：     ||" << endl;
	cout << "||      1.输入1 进入添加书籍功能     ||" << endl;
	cout << "||      2.输入2 进入查看书库模式     ||" << endl;
	cout << "||      3.输入3 进入查找书籍模式     ||" << endl;
	cout << "||      4.输入0 退出该系统           ||" << endl;
	cout << "||      其他功能，敬请期待0.0        ||" << endl;
	cout << "||                                   ||" << endl;
	cout << "=======================================" << endl;
}
void end()
{
	cout << "=======================================" << endl;
	cout << "||                                   ||" << endl;
	cout << "||       感谢您对该系统的使用        ||" << endl;
	cout << "||       欢迎下次再来                ||" << endl;
	cout << "||                                   ||" << endl;
	cout << "=======================================" << endl;
}
int main()
{
	L * head=new L;
	head->next = NULL;
	int type;
	init(head);
	menu();
	while (1)
	{
		cout << "输入    1:添加书籍, 2:查看目录, ,3:查找书籍, 0:退出程序" << endl;
		cin >> type;
		if (type == 1)
		{
			string idd, bn, au;
			cout << "进入添加书籍模式，请依次输入书籍编号,书名,作者，输入quit返回菜单" << endl;
			while (1)
			{
				cin >> idd;
				if (idd == "quit")
				{
					cout << "退出添加书籍模式" << endl;
					break;
				}
				cin >> bn >> au;
				add(head,idd,bn,au);
			}
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
			cout << "输入时先表明是以何种方式 例如 输入 id 123  或者 bn HaliPoter" << endl;
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
	}
	end();
	save(head);
	system("pause");
	return 0;
}