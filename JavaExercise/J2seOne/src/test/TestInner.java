package test;



import org.omg.CORBA.PUBLIC_MEMBER;

import com.gg.example.TestThis;

import test.Computer.Boardkey;
import test.Computer.Cpu;

public class TestInner {
	public static void main(String[] args) {

		Computer c = new Computer();  //�Ǿ�̬�ڲ�������ȴ����ⲿ�࣬�����ⲿ�����������
		Computer.Cpu c1 = c.new Cpu ();
		Computer.Cpu c2 = new Computer().new Cpu();

		Boardkey  b = new Boardkey(); //��̬��ֱ�Ӵ���
		Computer.Boardkey bb= new Computer.Boardkey();
		b.f();
		bb.f();
		c2.f();
	}
//	public static void function(new WindowAdapter(){
//		void fun(){
//		System.out.println("���ܲ���");}
//	}){System.out.println("���ܲ���");}
  


}



class Computer{
	private int price =1000;
	static String brand = "dell";
	static void work(){
		System.out.println("����");
	}
	void close(){
		System.out.println("end");
	}
	class Cpu{  //�Ǿ�̬�಻���о�̬��Ա���ɵ��þ�̬���������ԣ��Ǿ�̬��������
		int price;
		void f(){
			work();
			close();
			System.out.println(Computer.brand);  //��̬����
			System.out.println(Computer.this.price);
			System.out.println("cpu");
		}
	}
	static class Boardkey{  //��̬��ֻ�ܵ��þ�̬����������
		static int price;
		void f(){
			price =120;
			System.out.println("��̬�ڲ��� "+brand);
		}
	}
}