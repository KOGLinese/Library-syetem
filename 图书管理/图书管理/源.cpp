#include<iostream>
#include<string>
using namespace std;
struct Library {
	string id;
	string book_name;
	string author;
	//int count;
	struct Library * next;
};
typedef struct Library L;


void add(L * head,string i,string bn,string au)//����鼮
{
	L * p=new L;
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
		cout << "	���鼮" <<endl<< endl;
		return;
	}
	else
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			cout <<"	�鼮��ţ�"<< p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
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
			cout << "	�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
			}
		}
		
		if (k == "bn")
		{
			if (p->book_name == kinds)
			{
				flag = 1;
				cout << "	�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
			}
		}
		if (k == "au")
		{
			if (p->author == kinds)
			{
				flag = 1;
				cout << "	�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << endl;
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
		if (flag == 0) cout << "���޴���" << endl;
	}
	if (fk == "au")
	{
		cin >> kinds;
		flag = find_b(head, kinds,fk);
		if (flag == 0) cout << "���޴�����" << endl;
	}
}

void menu()
{
	cout << "=======================================" << endl;
	cout << "||                                   ||" << endl;
	cout << "||      ��ӭʹ��ͼ�����ϵͳ         ||" << endl;
	cout << "||      ��ϵͳ�������¼��ֹ��ܣ�     ||" << endl;
	cout << "||      1.����1 ��������鼮����     ||" << endl;
	cout << "||      2.����2 ����鿴���ģʽ     ||" << endl;
	cout << "||      3.����3 ��������鼮ģʽ     ||" << endl;
	cout << "||      4.����0 �˳���ϵͳ           ||" << endl;
	cout << "||      �������ܣ������ڴ�0.0        ||" << endl;
	cout << "||                                   ||" << endl;
	cout << "=======================================" << endl;
}
void end()
{
	cout << "=======================================" << endl;
	cout << "||                                   ||" << endl;
	cout << "||       ��л���Ը�ϵͳ��ʹ��        ||" << endl;
	cout << "||       ��ӭ�´�����                ||" << endl;
	cout << "||                                   ||" << endl;
	cout << "=======================================" << endl;
}
int main()
{
	L * head=new L;
	head->next = NULL;
	int type;
	menu();
	while (1)
	{
		cout << "����    1:����鼮, 2:�鿴Ŀ¼, ,3:�����鼮, 0:�˳�����" << endl;
		cin >> type;
		if (type == 1)
		{
			string idd, bn, au;
			cout << "��������鼮ģʽ�������������鼮���,����,���ߣ�����quit���ز˵�" << endl;
			while (1)
			{
				cin >> idd;
				if (idd == "quit")
				{
					cout << "�˳�����鼮ģʽ" << endl;
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
			cout << "���ҷ�ʽ���£�" << endl;
			cout << "���룺id ��ʾ��id�����鼮" << endl;
			cout << "      bn ��ʾ�����������鼮" << endl;
			cout << "      au ��ʾ�ò�����������鼮" << endl;
			cout << "      quit ��ʾ�˳�����" << endl;
			cout << "����ʱ�ȱ������Ժ��ַ�ʽ ���� ���� id 123  ���� bn HaliPoter" << endl;
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
	end();
	system("pause");
	return 0;
}