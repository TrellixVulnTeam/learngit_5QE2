class Anmial{
	int foot;
	public void sleep(){
		System.out.println("˯��");
	}
	public void eat(){
		System.out.println("�Է�");
	}
}
class Dog extends Anmial{  //�̳�
	public void brak(){
		System.out.println("����....");
	}
}
class Cat extends Anmial{
	public void eat(){ 
		super.eat();  //���ø��౻���ǵķ���
		System.out.println("sisissi..."); //��д
	}
	public void say(){
		System.out.println("������...");
	}
}
public class TestExtend {
	public static void main(String [] args){
		Cat c = new Cat();
		c.eat();  //�����Լ��ķ���
		c.say(); //������д�ķ���
	}

}
