/**
 * ��ӡ����
 */
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

import javax.security.auth.kerberos.KerberosKey;

public class diamond {
	public static void game(int len){				
		int up = len / 2 ;
		for(int i=1; i<=len ; i++){
			for(int k=len-i; k >= 1 ; k--){
				System.out.print(' ');
			}
			for(int j=len + 1 ; j<=len + i ; j++){				
				System.out.print('*');
				System.out.print(' ');
			}
			System.out.println();
		}
		for(int i=1 ; i<len ; i++ ){
			for(int k=1 ; k<=i ; k++){
				System.out.print(' ');
			}
			for(int j=i+1 ; j<=len; j++){
				System.out.print('*');
				System.out.print(' ');
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws IOException{
		Scanner s = new Scanner(System.in);
		System.out.println("��ʼ");
		boolean flag;
		String str = "";
		while(true){
			System.out.print("���γ���:");
			int len ;
			while((len = s.nextInt()) % 2 == 0){
				System.out.println("����������:");
			}
			game(len);		
			System.out.println("������(quit):");
			str = s.next();
			flag = str.toString().equals("quit");
			if(flag){
				break;
			}
		}
	}
	

}
