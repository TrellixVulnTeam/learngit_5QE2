/*����һ������
��player�����뿪��Ϸʱ
     �ڲ˵���ѡ���淨 
        if the palyer wants to listen to the critter
	       Make the critter talk
		if the player wants to feed the critter
		   Make the critter eat
		if the player wants to play with the critter
		   Make the critter play 
*/
# include<iostream>
using namespace std;
class Critter
{
	private:
		int m_Hunger; //����ֵ 
		int m_Boredom; //���ʶ� 
		int GetMood()const   //������ ��ȡ���� 
		{
			return(m_Hunger+m_Boredom);
		}
		int PassTime(int time = 1) //ʱ������ 
		{
			m_Hunger+=time;
			m_Boredom+=time;
		}
	public:
		Critter(int hunger = 0,int boredom = 0):
		m_Hunger (hunger),m_Boredom(boredom)
        { }
		void Talk()
		{
		int mood = GetMood();
		 if	(mood>15)
		  {
			cout<<"I feel mad\n";
		  }
		 else if (mood>10)
		  {
		  	cout<<"I feel frustrated\n";
		  }
		 else if (mood>5)
		  {
		  	cout<<"I feel okay\n";
		  }
		  else
		  {
		  	cout<<"I feel happy\n";
		  }
		  PassTime();     //��ʱ�����Ƽ��������ʶ����� 
		}
		void Eat(int food = 4)
		{
		  cout<<"eat\n";   
		  m_Hunger -= food;  //�ı伢���� 
		  if(m_Hunger < 0)
		  {
		  	m_Hunger = 0;
		  }	
		  PassTime();
		}
		void Play(int fun = 4)
		{
		  cout<<"play\n";
		  m_Boredom -= fun;     
		  if(m_Boredom < 0)   //�����ݲ�Ϊ���� 
		  {
		  	m_Boredom = 0;
		  }
		  PassTime();
		}
};
int main()
{   
    Critter c;
    c.Talk();
    cout<<"0 - Quit\n";
    cout<<"1 - Listen to your critter\n";
    cout<<"2 - Feed your c\n";
    cout<<"3 - Play with your c\n";
    int choice;
    do{
     cin>>choice;
	 switch(choice)                    //switchǶ��while�� 
	   {
		case 0:                          //ѡ��һ���淨���˳�ѡ�� 
		    cout<<"Goodbye\n";
			break;
		case 1:c.Talk();
			break;
		case 2:c.Eat();
			break;
		case 3:c.Play();
			break;
		default: cout<<"illegal input\n";
      } 
    }while(choice != 0);        //��ѡ���ǣ�0���˳�ʱ ѭ�� 
	return 0;
}
 
