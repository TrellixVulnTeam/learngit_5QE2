# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;
const char X = 'X';  //ȫ�ֳ��� 
const char O = 'O';
const char EMPTY = ' '; 
const char TIE = 'T';
const char NO_ONE = 'N';
void instructions(); //��ʾ��Ϸ����ָ�� 
char askYesNo(string question);  
int askNumber(string question, int high, int low = 0);
char humanpiece();
char opponent(char piece);
void displayBoard(const vector<char> & board);
char winner(const vector<char> & board);
bool isLegal(const vector<char> &board, int move);
int humanMove(const vector<char> & board,char human);
int computerMove(vector<char> board , char computer);
void announceWinner(char winner , char computer, char human);
int main()
{
	int move;
	const int NUM_SQUARES = 9; 
    vector<char> board(NUM_SQUARES,EMPTY); //��ʼ������Ϊ�� 
    instructions(); 
    char human = humanpiece();  //ȷ��������� 
    char computer = opponent(human);  
    displayBoard(board);
    char turn = X; 
    while(winner(board) == NO_ONE)  //winner����ȷ��ʤ��  ѭ������������ȡʤ 
    {
    //	if (human == turn)
    	if (turn == human) //������������X������ 
    	{
    		move = humanMove(board,human); //move��������λ�� 
    		board[move] = human; //�������� 
    	}
    	else
    	{
    		move = computerMove(board,computer);
    		board[move] = computer;
    	}
    	displayBoard(board);
    	turn = opponent(turn); //���� ���ö������� 
    }
    announceWinner(winner(board),computer,human);
	return 0;
}
void instructions()
{
	cout<<"Welcome to the game!\n"; 
} 
char askYesNo(string question) //������������ 
{
	char answer;
	do{
	cout<<question<<"(y/n):";
	cin>>answer;                           
    }while(answer != 'y' && answer != 'n');  // ��ѭ�����ƻش�Ϊy��n 
	return answer ;	
} 
int askNumber(string question, int high, int low )
{
	int number; //�����ִ�������λ�� 
	do{
	cout<<question<<"("<<high<<"-"<<low<<"):";
	cin>>number;
    }while(number < low || number >high);	//number���ܳ�������λ�� ||�� 
	return number;	
} 
char humanpiece()
{
  char go_first = askYesNo("Do you require the first move");
  if (go_first == 'y')  //ѯ������Ƿ����� 
  {
  	return X;  
  }
  else 
  {
  return O;
  }
}
char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else 
	{
		return X;
	}
}
void displayBoard(const vector<char> & board) //��ʾ���� 
{
	cout<<"\n\t"<<board[0]<<"|"<<board[1]<<"|"<<board[2];
	cout<<"\n\t"<<"------";
	cout<<"\n\t"<<board[3]<<"|"<<board[4]<<"|"<<board[5];
	cout<<"\n\t"<<"------";
	cout<<"\n\t"<<board[6]<<"|"<<board[7]<<"|"<<board[8];
	cout<<"\n\n"; 
}
char winner(const vector<char> & board)
{  //������װ���ʤ����������λ�� 
   const int winner_row[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},
                                {1,4,7},{2,5,8},{0,4,8},{2,4,6}};
   const int TOTAL_ROWS = 8 ; 
   for(int i =0; i < TOTAL_ROWS; ++i) //�Ƚ�ÿ����������λ�õ������Ƿ�һ���Ҳ�Ϊ�� 
   {
   	if(board[winner_row[i][0]] != EMPTY && board[winner_row[i][0]]
   	== board[winner_row[i][1]] && board[winner_row[i][0]]
   	== board[winner_row[i][2]] )
   	{ return board[winner_row[i][0]]; };//�������������ص�һ������ 
   }
   	if(count(board.begin(),board.end(),EMPTY) == 0)
   	{
   		return TIE ;//count()�����������λ���Ƿ��п�λ 
   	}
  return NO_ONE ;	
}
inline bool isLegal( int move,const vector<char>& board)//���ز���ֵ 
{  
   return (board[move] == EMPTY);  //�����ѡλ���Ƿ�Ϊ�� ����true 
}
int humanMove(const vector<char> & board,char human)
{   // ��������λ�� 
	int move = askNumber("\nwhere you move��",(board.size()-1));
	while(!isLegal(move, board)){ //��Ϊ�� false ʱѭ�� 
	move = askNumber("\nwhere you move��",(board.size()-1));
	}
	return move;
}
int computerMove(vector<char> board , char computer)
{  //1.���������һ��ȡʤ��ѡ�������� 
   unsigned	int move;  //�޷������� 
   bool found =false;  //�߼��ж� ��ʼ��Ϊfalse 
   while(!found && move < board.size()){ //��������Ϊfound��Ϊfalse  
   	 if(isLegal(move,board)){   //�����������У����Ϸ��� 
   		board[move] = computer; //�ٶ����� 
   		found = winner(board) == computer;//�ж������Ƿ�ȡʤ ʤ����true 
   		//���򷵻�false  
   		board[move] = EMPTY ; //������� 
   	   }
   	 if(!found){ // 
   		++move ;
   	   } 	
   }
   //2 ����������������һ��ȡʤ������ֹ 
   if(!found){ //if(true) Ϊ���ִ��if 
   	move =0;
   	char human = opponent(computer);
   	while(!found  && move < board.size()){//����������foundΪ true 
   	    if(isLegal(move,board)){
   	    	board[move] = human;  //�ҵ�������һ����ʤλ�� 
   	    	found = winner(board) == human;
   		    board[move] = EMPTY ;
   	      }
   	    if(!found){
   		    ++move ;
   	      }
      }
   } 
   //3.������ʣ�¿ո�ѡ���ŵķ��� 
   if(!found){ 
   	 move = 0;
   	 unsigned int i = 0;
     const int BEST_MOVES[] ={4,0,2,6,8,1,3,5,7};//�ո����ȶȣ��м����ţ�������� 
   	 while(!found  && i < board.size()){
           move =BEST_MOVES[i];
   	       if(isLegal(move,board))
			 {
        	   found = true ;
             } 
             ++i; 
   	   }
    }
    cout<<"computer choice move:"<<move<<endl;
	return move;
}
void announceWinner(char winner , char computer, char human)
{

	if(winner == computer)
	{
		cout<<"computer winner!\n";
	}
	else if(winner == human)
	{
		cout<<"human winner!\n";
	}
	else
	{
		cout<<"Not winner!\n";
	}
}
