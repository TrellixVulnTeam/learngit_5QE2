package com.test.collection;

import java.lang.reflect.Field;
import java.util.*;

@SuppressWarnings({"rawtypes","unused","unchecked"})
public class collection {
	public static void main(String[] args) {
		run();
	}
	public static void run() {
		List list = new LinkedList<>();
		Collection c ;
		Map  map = new HashMap<>();
		map.put("1","a");
		
		
	}
	
	public static void testA_Field(){
		A a = new A();
		Field[] field = a.getClass().getDeclaredFields();
		for (Field f : field) {   //��aʵ�����õ�A��ķ�˽������ ����
			try {
				A aa = new A();
				System.out.println(f.getInt(aa));  //get INt�������Ե�ֵ��param������
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
}

class A{
	public int a = 9;
	public String b = "9";
	public int b5 = 8;
}