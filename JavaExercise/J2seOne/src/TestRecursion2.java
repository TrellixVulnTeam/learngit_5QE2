/**
 * ���Եݹ�Ļ������̣��׳˵�����
 * @author Administrator
 *
 */
public class TestRecursion2 {
	static int a = 0;
	/**
	 * ���Եݹ��壬�ݹ�ͷ
	 */
	public static void test01(){
		a++;
		System.out.println("test01:"+a);
		if(a<=10){  //�ݹ�ͷ
			test01();
		}else{      //�ݹ���
			System.out.println("over");
		}
	}
	/**
	 * ���������һ�仰test02
	 */
	public static void test02(){
		System.out.println("TestRecursion.test02()");
	}
	
	/**
	 * һ������������ĳ�����Ľ׳�
	 * @param n  n�Ľ׳�
	 * @return   �׳˽��
	 */
	public static long factorial(int n){
		if(n==1){
			return 1;
		}else{
			return n*factorial(n-1);
		}
	}
	
	public static void main(String[] args) {
		test01();
		System.out.println(factorial(10));  
	}
}
