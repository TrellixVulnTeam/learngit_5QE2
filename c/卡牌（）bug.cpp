/*
deal player and the house two initial cards
Hide the house's card 
display player's card and house's card
deal addtional cards to players
Reveal house's first card
if house is busted 
    everyone who is not busted wins 
otherwise
    for each player
     if player isn't busted
       if players total is greater than the house's total
          player wins
       otherwise if player's total is less than house's total
          player less
       otherwise
          player pushes
Remove eneryone's cards
*/ 
# include<iostream>
# include<vector>
# include<string>
# include<algorithm>
# include<ctime>
using namespace std;
class Card{
  public:
  	//����ö������ ����ʾ�ƵĻ�ɫ����С 
   enum rank {ACE = 1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
   JACK,QUEEN,KING};
   enum suit {CLUBS,DIAMONDS,HEARTS,SPADES};
   Card(rank r = ACE,suit s = SPADES,bool b = true):m_Rank(r),m_Suit(s),m_IsFaceUp(b){}
   int GetValue() const  //�����Ƶ�ֵ ��1-11 
  	{   int value;
  		if(m_IsFaceUp)
  		{
  			value = m_Rank;
  			if(value >10)
  			{
  				value = 10;
  			}
  		}
  		return value;
  	}
   void Flip()  //���ƣ������泯�ϣ����ɷ��泯�� 
   {
  	m_IsFaceUp = !m_IsFaceUp;
   }
   private:
   	bool m_IsFaceUp ;
    rank m_Rank;  
	suit m_Suit; 
   friend ostream &operator <<(ostream & os,const Card &aCard);
};
class Hand{  //��ҵ����ƣ�Card�ļ��� 
public:
	Hand()
	{  
		m_Cards.reserve(7);  //�������������� 
	}
	virtual ~Hand()
	{
		Clear();
	}
	void Add(Card * pCard)   //���������� 
	{
		m_Cards.push_back(pCard);
	}
	void Clear() //������� 
	{
		//�����������ͷ��ڶ��е����пռ� ��Card��������ݣ� 
		vector<Card *>::iterator iter = m_Cards.begin() ;
		for(iter;m_Cards.end() != m_Cards.end(); ++iter)
		{
			delete *iter;  
			*iter = 0;
		}
		m_Cards.clear(); //��������е�ָ��
	}
	int GetTotal() const //��������ֵ�ĺ� 
	{
	 if(m_Cards.empty())  //���ж�Cards���������ǲ��ǿ� 
	 {
       return 0;
	 }
     if(m_Cards[0]->GetValue() == 0)
	 {  //����һ���Ƶ�ֵΪ0������������泯�µģ�ׯ�ҵ����ƣ�������0 
      return 0;
	 }
	 int total =0 ; 
	 vector<Card *>::const_iterator iter = m_Cards.begin() ;
	   for(iter;iter != m_Cards.end();++iter)
		{
			total += (*iter)->GetValue() ;  //�����������ֵ�ĺͣ���A��ֵĬ��1 
		}
       bool containsAce = false;  // ������A �� 
	 for(iter;iter != m_Cards.end();++iter)
		{
		 if((*iter)->GetValue() == Card::ACE) containsAce = true ;
		}
       if(containsAce && total<= 11)
	   {//�����ư���A������ֵ��С����A��ֵΪ11 
		   total += 10;
	   }
      return total ;
	}
protected:
	vector<Card *> m_Cards ;  //Cardָ�����͵�����  ��Card����ĵ�ַ 

};
class GenericPlayer: public Hand{//��� 
   public:
   	 GenericPlayer(const string & name ="  "):m_name(name){
   	 }
   	 virtual ~GenericPlayer(){//���������� 
   	 }
   	 virtual bool IsHitting() const = 0;  //ָʾ����Ƿ���Ҫ���� 
   	 bool IsBusted()const{   //������ң����Ƿ����21������ 
   	 	return (GetTotal() > 21);
   	 }
   	 void Bust(){
   	 	cout<<m_name<<"bust!\n";
   	 }
   friend ostream & operator <<(ostream & os,const GenericPlayer & play);
   protected:
   	 string m_name;
}; 
class Deck: public Hand{   //�ƶ� 
   public:
    Deck(){
    	m_Cards.reserve(52);   //һ����52�� 
    	Populate();    
    	} 
	virtual ~Deck(){}
	void Populate(){  //����һ����׼��52���� 
		Clear();  //������� 
		for(int s = Card::CLUBS; s <=Card::SPADES ;s++){
			for(int r = Card::ACE; r <= Card::KING;r++){
				Add(new Card(static_cast<Card::rank>(r),static_cast<Card::suit>(s))) ;
			}//�г����п��ܵ��ƣ�static_cars��int�ͱ�ΪCard�����ö���� 
		}
	}
	void Shuffle(){//�㷨shuffle��ϴ�� 
		random_shuffle(m_Cards.begin(),m_Cards.end());
	}
	void Deal(Hand & aHand){//���� 
		if(!m_Cards.empty()){    
			aHand.Add(m_Cards.back()); //�����ƶ�����m_Cards�����飩ĩβ��ָ��ĸ��� 
			m_Cards.pop_back();//�Ƴ������ĩβ��ָ�� 
		}
		else{
			cout<<"Out of Cards,Unable to Deal\n";
		}
	}
	void AdditionalCards(GenericPlayer & aGenericPlayer){//���� 
		while(!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()){
			Deal(aGenericPlayer);//�����û�г�������Ҫ���ƣ����� 
			cout<<aGenericPlayer<<endl;
			if(aGenericPlayer.IsBusted()){
				aGenericPlayer.Bust();//��ҳ��֣����������� 
			} 
		}
	} 
};

class Player: public GenericPlayer{ //������� 
   public:
   	Player(const string & name ):GenericPlayer(name){
   	}
   	virtual ~Player(){  
   	}
   	bool IsHitting() const{   //�����ѯ���Ƿ���� 
   		char response;
   		cout<<"do you want hit?(y/n):";
   		cin>>response ;
   		return (response == 'y' || response == 'Y');
   	}
   	void Win()const{  //������� 
   		cout<<m_name<<" win!\n"; 
   	}
   	void Lose()const{
   		cout<<m_name<<" loses!\n"; 
   	}
   	void Push()const{
   		cout<<m_name<<" pushes!\n"; 
   	}
};
class House: public GenericPlayer{  //ׯ�� 
    public:
    	House(const string & name = "House"){
    	}
    	~House(){
    	}
    	bool IsHitting()const{
    		return (GetTotal() <= 16);  //�жϷ��ص����Ƿ�С�ڵ���16����ʾׯ�Ҹ��� 
    	}
    	void FlipFirstCard(){   
    		if(!(m_Cards.empty())){
    			m_Cards[0]->Flip();  //��תׯ�ҵĵ�һ���� 
    		}
    		else{
    			cout<<"the cards is empty!\n";
    		}
    	}
};
class Game {
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;  //����һ��������͵����� 
    public: 
    Game(const vector<string> names){
    	vector<string>::const_iterator pName; // ����һ������������ʵ����Player���� 
    	for(pName = names.begin(); pName < names.end(); ++pName){
    	m_Players.push_back(Player(*pName));
		}
		srand(static_cast<unsigned int>(time(0)));
		m_Deck.Populate(); //�����ƶ� 
		m_Deck.Shuffle();  //ϴ�� 
    }
    ~Game(){}
    void Play(){  //����ҷ������� 
    	vector<Player>::iterator pPlayer ;
    	for(int i = 0; i < 2 ; ++i){
    		for(pPlayer = m_Players.begin(); pPlayer < m_Players.end(); ++pPlayer){
    			m_Deck.Deal(*pPlayer);
    		}
    		m_Deck.Deal(m_House);
    	}
    	m_House.FlipFirstCard();  //����ׯ�ҵĵ�һ���� 
    	for(pPlayer = m_Players.begin(); pPlayer < m_Players.end(); ++pPlayer){
    			cout<<*pPlayer<<endl;
    		}
    	cout<<m_House<<endl;     //��ʾÿ��������� 
    	for(pPlayer = m_Players.begin(); pPlayer < m_Players.end(); ++pPlayer){
    			m_Deck.AdditionalCards(*pPlayer);
    		}//�Ը��Ƶ���Ҽ�һ���� 
    	m_House.FlipFirstCard(); //����ׯ�ҵĵ�һ���� 
    	m_Deck.AdditionalCards(m_House);//ׯ�Ҹ��� 
    	
    	if(m_House.IsBusted()){ //ׯ�ҳ��� 
    		for(pPlayer =m_Players.begin(); pPlayer <m_Players.end(); ++pPlayer){
    			if(!pPlayer->IsBusted()){ //ÿ��û���ֵ���һ�ʤ 
    				pPlayer->Win();
    			}
    		}
    	}
    	else{ //�Ƚ�û���ֵ������ׯ�ҵ����ƣ����ֽ�� 
    		for(pPlayer =m_Players.begin(); pPlayer <m_Players.end(); ++pPlayer){
    			if(!pPlayer->IsBusted()){
    			   if(pPlayer->GetTotal() > m_House.GetTotal()){
    			   	pPlayer->Win();
    			   }
    			   else if(pPlayer->GetTotal() < m_House.GetTotal()){
    			   	pPlayer->Lose();
    			   }
    			   else{
    			   	pPlayer->Push(); 
    			   }
    			}
		    }
    	}
    	for(pPlayer =m_Players.begin(); pPlayer <m_Players.end(); ++pPlayer){
              pPlayer->Clear();
    	}
		m_House.Clear();    	
    } 
};
//����<<���ñ�׼��������Card��GenericPlayer���� 
ostream &operator <<(ostream & os,const Card &aCard)
{
   const string Rank[] = {"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
   const string Suit[] = {"÷��","����","����","����"};
   if(aCard.m_IsFaceUp){ //����������ƣ��������xx 
   	os<<Rank[aCard.m_Suit]<<Suit[aCard.m_Rank]<<endl;
   }
   else{
   	os<<"xx\n";
   }
   return os; 	
}
ostream &operator <<(ostream & os,const GenericPlayer & p)
{
	os<<p.m_name<<":\t"; //���� 
	vector<Card *>::const_iterator pCard;
	if(!p.m_Cards.empty()){   //��ҵ��� 
		for(pCard = p.m_Cards.begin(); pCard <p.m_Cards.end();++pCard){
			os<<*(*pCard)<<"\t";
		}
	}
	if(p.GetTotal() != 0){  //���� 
		os<<p.GetTotal()<<endl;
	}
	else{
		os<<"empty\n";
	}
	return os;
}
int  main()
{   
    cout<<"weclome blackjack\n";
    int playernum ;
    while(playernum > 7 || playernum < 1) //��������� 
    {
    	cout<<"�����������1-7����";
		cin>>playernum;
    }
    vector<string> names ;
    string name;
    for(int i = 1 ; i < playernum ; i++)  //�����װ������ 
    {
    	cout<<"�������"<<i<<"�����������:";
    	cin>>name;
		names.push_back(name); 
    }
    Game game(names);
    char again = 'y';   //��Ϸ��ѭ�� 
    while(again != 'n')
    {
    	game.Play();
    	cout<<"��ѡ���Ƿ������Ϸ��y/n����";
    	cin>>again;
    }
	return 0;
}
