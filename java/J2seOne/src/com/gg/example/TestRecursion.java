package com.gg.example;
/**
 * �ݹ�test
 * @author Administrator
 *
 */
import java.util.Scanner;;
public class TestRecursion {
	
	public static void main(String [] args){
		System.out.println("����һ��������");
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		System.out.println(a+"�Ľ׳�Ϊ��"+f(a));
		s.close();
	}
	
	static long f(int n){
		if(n == 1){
			return 1;
		}
		else{
			return n*f(n-1);
		}
	}
	
	
}
