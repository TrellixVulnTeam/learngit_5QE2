package com.testClassLoader;

public class testDemo4 {
	public static void main(String[] args) throws ClassNotFoundException {
		FilesystemClassLoader loader = new FilesystemClassLoader("D:\\es");
		Class<?> c = loader.loadClass("com.testClassLoader.A");
		Class<?> c2 = loader.loadClass("com.testClassLoader.A");
		System.out.println(c);
		System.out.println(c.hashCode());
		System.out.println(c2.getClassLoader());
		System.out.println(c2.hashCode());
		//ͬһ���������ͬһ���������ص��࣬��JVM��Ϊ��ͬһ����
		FilesystemClassLoader loader2 = new FilesystemClassLoader("D:\\es\\�½��ļ���\\partice\\bin\\com\\testClassLoader");
		Class<?> c4 = loader2.loadClass("com.testClassLoader.A");
		System.out.println(c4.getClassLoader());
		System.out.println(c4.hashCode());
		//��ͬ������������ص�ͬһ��������JVM��Ϊ�ǲ�ͬ����
		Class<?>  s = loader2.loadClass("java.lang.String");
		System.out.println(s);
		System.out.println(s.hashCode());
	}
	/*
	public static void main(String[] args) {
		System.out.println("classloader");
	}*/
}
