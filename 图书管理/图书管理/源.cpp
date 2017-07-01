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


void add(L * head)//����鼮
{
	L * p=new L;
	string i, bn, au;
	cout << "�����������鼮���,����,����" << endl;
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
	cout << "������鼮" << endl;
}


void print(L * head)//������Ŀ¼
{
	cout << "Ŀ¼��" << endl;
	L * p = head;
	if (head->next == NULL)
	{
		cout << "���鼮" << endl;
		return;
	}
	else
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			cout <<"�鼮��ţ�"<< p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
		}
	}
	cout << endl;
}

int find_b(L * head,string kinds,string k)//�����鼮
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
			cout << "�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
			}
		}
		
		if (k == "bn")
		{
			if (p->book_name == kinds)
			{
				flag = 1;
				cout << "�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
			}
		}
		if (k == "au")
		{
			if (p->author == kinds)
			{
				flag = 1;
				cout << "�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
			}
		}
	}
	return flag;
}


void find_menu(L * head,string fk)//���ҷ�ʽ�˵�
{
	
	//string fk;
	string kinds;
	int flag = 0;
	//cin >> fk;
	if (head->next == NULL)
	{
		cout << "���Ϊ��" << endl;
		return;
	}
	if (fk == "id")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "���޴˱��" << endl;
	}
	if (fk == "bn")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "���޴�����" << endl;
	}
	if (fk == "au")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "���޴�����" << endl;
	}
}

int main()
{
	L * head=new L;
	head->next = NULL;
	int type;
	cout << "1:����鼮, 2:�鿴Ŀ¼, ,3:�����鼮, 0:�˳�����" << endl;
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
			cout << "���ҷ�ʽ���£�" << endl;
			cout << "���룺id ��ʾ��id�����鼮" << endl;
			cout << "      bn ��ʾ�����������鼮" << endl;
			cout << "      au ��ʾ�ò�����������鼮" << endl;
			cout << "      quit ��ʾ�˳�����" << endl;
			while (1)
			{
				string fk;
				cin >> fk;
				if (fk == "quit")
				{
					cout << "�˳�����ģʽ" << endl;
					break;
				}
				find_menu(head, fk);
			}
		}
		else if (type == 0) break;
		/*else
		{
			cout << "�����ʽ���ԣ����������룺" << endl;
			cin >> type;
			continue;
		}*/
	}
	system("pause");
	return 0;
}