package test;

public class testWrapper {
	public static void main(String[] args) {
		Integer intege9r  = new Integer(100);
		Integer.parseInt("300");
		int i = 1;
	//  ����ʱװ��	int i = new Integer(1)  �����Ͷ�����int��
	    Integer a = new Integer(128);
	    Integer b = new Integer(128);
	// ����ʱ�Զ�����  int a = new Integer(2).inValue()
	    int j = 1;
	    System.out.println(i == j);
	    System.out.println(a == b); //ע����byte���ͷ�Χʱ�Ե��������ʹ���
	}
}
