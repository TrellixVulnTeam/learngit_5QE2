# include <iostream>
// # include <cstring>
using namespace std;
class Car
{
	private:
	string brand;
	string type;
	int price;
	int time;
	public:
      void setinfo(string b,string m,int p,int t)
	 {
	 	price=t;
	 	time=p;
	 	brand=b;
	 	type=m;
	 }		
	 void print()
	 {
	 	cout<<"�̱꣺"<<brand<<endl;
	 	cout<<"���ͣ�"<<type<<endl;
	 	cout<<"������ݣ�"<<time<<endl;
	 	cout<<"�۸�"<<price<<endl;
	 }
};
int main()
{
	Car c;
	c.setinfo("Ford\0","usv\0",2007,1000000); 
	c.print();
	return 0;
} 
