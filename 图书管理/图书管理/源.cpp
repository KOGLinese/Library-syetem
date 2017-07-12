#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Library {		//�鼮����
	string id;			//�鼮���
	string book_name;	//����
	string author;		//����
	int count;			//����
	struct Library * next;
};
typedef struct Library L;


void init(L * head)  // ��ʼ������
{
	L * p,* pre;
	pre = head;
	string s;
	char num;
	ifstream infile("e://Library//ALLBOOK.txt", ios::in);//�Զ�ȡ�ķ�ʽ�򿪱����ļ�
	while (!infile.eof())//�������ݴ�������
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
void save(L *head)  //���ݴ��뱾���ļ�
{
	L * p = head;
	ofstream outfile("e://Library//ALLBOOK.txt", ios::out);//��д��ķ�ʽ�򿪱����ļ�
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

bool find(L * head, string i, string bn, string au)//�ж��Ƿ����
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
			p->count++;                  //�����Ѿ����������������
			cout << "������鼮" << endl;
			return true;
		}
	}
	return false;
}
void add(L * head,string i,string bn,string au)//����鼮
{
	if(!find(head,i,bn,au))//������ⲻ���� ��������鼮
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
	cout << "������鼮" << endl;
	}

}


void print(L * head)//������Ŀ¼
{
	cout << "Ŀ¼��" << endl;
	L * p = head;
	if (head->next == NULL||head->next->id=="")
	{
		cout << "	���鼮" <<endl<< endl;
		return;
	}
	else
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			cout <<"	�鼮��ţ�"<< p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author<<" �ɽ�����"<<p->count<< endl;
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
			cout << "	�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << " �ɽ�����" << p->count << endl;
			}
		}
		
		if (k == "bn")
		{
			if (p->book_name == kinds)
			{
				flag = 1;
				cout << "	�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author << " �ɽ�����" << p->count << endl;
			}
		}
		if (k == "au")
		{
			if (p->author == kinds)
			{
				flag = 1;
				cout << "	�鼮��ţ�" << p->id << " ��������" << p->book_name << "�� ���ߣ�" << p->author <<" �ɽ�����"<<p->count<< endl;
			}
		}
	}
	return flag;
}


void find_menu(L * head,string fk)//���ҷ�ʽ�˵�
{
	
	string kinds;
	int flag = 0;
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
	init(head);
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
	}
	end();
	save(head);
	system("pause");
	return 0;
}