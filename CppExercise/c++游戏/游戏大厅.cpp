# include <iostream>
# include <string>
using namespace std;
class Player
{ 
  private:
  	string m_Name;
  	Player *m_pNext;
  public:	  
    Player(const string & name =" "):m_Name(name),m_pNext(0)
    {}
    Player* GetNext() const  //����һ��ָ�����͵ĳ����� 
    {
    	return m_pNext;
    }
    string GetName() const
    {
    	return m_Name;
    }
    void SetNext(Player *next)//����ָ����󣬸���nextָ���Ա 
    {
    	m_pNext = next ; 
    }
};
class Lobby
{ 
  private:
  	Player *pHead;
  public:
  	Lobby():pHead(0)
  	{}
  	~Lobby()
  	{
  		clear();
  	}
  	void addPlayer()
  	{
  		string name;
  		cout<<"Enter the name:\n";
  		cin>> name;
  		Player *newplayer = new Player(name);
  		if(pHead == 0) //����ͷ��Ϊ�գ�ֱ�Ӳ��� 
  		{
  			pHead = newplayer;
  		}
  		else
  		{
  			Player * pIter = pHead;
  			while(pIter->GetNext() != 0){ //��β�ڵ�ʱpIter->Getnext()ָ��Ϊ0
		//�ҵ�һ�������nextָ��Ϊ�� ����ô���������β�ڵ� 
		//��ָ��pIterָ��Ķ���ķ������ص�ָ�����жϣ������ö������ж� 
  				pIter = pIter->GetNext();
	   //��pIter ָ��ָ��ָ��ָ��Ķ��󷵻ص�ָ������¸�����ĵ�ַ����һ������ 
  			}
  			pIter->SetNext(newplayer);
  			//���¶���ĵ�ַ������pIterָ��Ķ���ķ������أ�ĩβ�����nextָ�� 
  		}
  		cout<<"add successful\n";
  	}
  	void removePlayer()
  	{
  		if(pHead == 0)  //ͷ��Ϊ�գ� 
  		{
  			cout<<"The list is Empty\n";
  		}
  		else        
  		{
  			Player * pTemp = pHead;  
  			pHead = pHead->GetNext(); 	  //ͷ��ָ��ָ����һ������		 
  			delete pTemp;  //ɾ��ָ�� 
  		}
  		cout<<"delete successful\n";
  	}
  	void clear()
  	{
  		while(pHead != 0){ //һֱ�Ƴ���ֱ��ͷ��Ϊ�� 
  			removePlayer();
  		}
  		cout<<"clear successful\n";
  	}
  	friend ostream& operator << (ostream &os,const Lobby &lobby);
};
//����<<�������������Ԫ����  
ostream& operator << (ostream &os,const Lobby &lobby)
{
	Player *pIter = lobby.pHead ;  // 
	cout<<"\nWho is in the Lobby game:\n";
	if(pIter == 0){
		os<<"empty!\n";
	} 
	else{                //�������нڵ㣬���ÿ���ڵ������ 
	  while(pIter != 0){ //��β�ڵ�ʱpIterָ�벻Ϊ0
		os<<pIter->GetName()<<endl;
		pIter = pIter->GetNext(); 
	   }
	}
	return os; 
}
int main()
{
	Lobby lobby;
	cout<<"Lobby game\n";
	cout<<"0-Quit\n";
	cout<<"1-Add player game\n";
	cout<<"2-Remove player\n";
	cout<<"3-Clear player\n";
	int choice ;
	do
	{
	cout<<lobby;
	cout<<"\nplease choice:\n";
	cin>>choice ;
	switch (choice)
	 {
		case 0:cout<<"Goodbye!\n";
			break;
		case 1: lobby.addPlayer();
			break;
		case 2: lobby.removePlayer();
			break;
		case 3: lobby.clear();
			break;
		default: cout<<"you enter invavid input\n";
	 }
	}while (choice != 0);
	return 0;
} 
