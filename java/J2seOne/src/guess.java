
import java.util.Scanner;

/**
 * С��Ϸ�ۺ���ϰ���µ���
 * @author Administrator
 *
 */
public class guess {
	//����
	private int len;
	private char[] letter = new char[26];
	private char[] word;
	private int[] position = new int[26];
	private boolean flag = false;
	private int count = 0;
	char[] input;
	int score;
	public guess(int len) {  //����26����ĸ
		this.len = len;
		word = new char[len];
		input = new char[len];
		score = len*100;
		for(int i=0 ; i<letter.length ; i++){
			letter[i] =(char)('a'+i);
		}
		// TODO Auto-generated constructor stub
	}
	public void setWord(){ //�����������
		int index = 0;
		for(int i=0 ; i<len ; i++){
			do{
				index = (int) (Math.random()*26);
				if(position[index] == 1 ){
					//System.out.println(position[index]+"--"+index);
					flag = true;
				}
				else{
					flag = false;
				}
				word[i] = letter[index];
				position[index] = 1;
			}while(flag);
		}
		System.out.println(word);
	}
	public int check(char[] input){
		count = 0;
		for (int i = 0; i < len; i++) {
			if(word[i] == input[i]){
				count++;
			}
			else{
				score-=10;
			}
		}
		return count;
	}
	public void game(){
		int sum = 0;
		System.out.println("��ʼ");
		Scanner s = new Scanner(System.in);
		while(true){
			sum++;
			setWord();
			do{		
				System.out.println("������"+len+"���ַ���");
				input = s.next().toLowerCase().toCharArray();
			}while(input.length < len || input.length >5);
			check(input);
			System.out.println("�¶�"+count+"��"+",�´�"+(len-count)+"����");
			System.out.println("�÷֣�"+score+",һ������"+sum+"�Ρ�");
			System.out.println("�Ƿ������y/n����");
			if(s.next().equals("n")){
				break;
			}
		}
	}
	
	public static void main(String[] args){
		guess g = new guess(5);
		g.game();
		
	}
}
