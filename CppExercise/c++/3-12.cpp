# include <iostream>
// # include <cstring>
using namespace std;
class Student
{
	private:
	string name;
	string department;
    int  sno;
	string tel;
	public:
		Student(string a="null",string b="null",int c=0,string d="null")
		{
		name=a;
	 	department=b;
	 	sno=c;
	 	tel=d;
		}
      void setinfo(string a,string b,int c,string d)
	 {
	 	name=a;
	 	department=b;
	 	sno=c;
	 	tel=d;
	 }		
	 void print()
	 {
	 	cout<<"ѧ�ţ�"<<sno<<endl;
	 	cout<<"������"<<name<<endl;
	 	cout<<"�绰���룺"<<tel<<endl;
	 	cout<<"����Ժϵ��"<<department<<endl;
	 }
};
int main()
{
	Student s;
	s.setinfo("��","Ӣ��\0",2305,"15147483647"); 
	s.print();
	return 0;
} 
