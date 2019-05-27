package com.test.annotation;

import java.lang.annotation.Annotation;
import java.lang.reflect.Field;

public class Demo {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		try {
			Class c = Class.forName("com.test.annotation.Student");
			//��ȡ���ע��
			Annotation[] annotation = c.getAnnotations();
			for (Annotation a : annotation) {
				System.out.println(a);
			}
			
			//��ȡ���ָ��ע��
			myannotation01   aa= (myannotation01) c.getAnnotation(myannotation01.class);
			SuppressWarnings s = (SuppressWarnings) c.getAnnotation(SuppressWarnings.class);
			System.out.println(aa.value());
			
			//��ȡ�������ע��
			Field[]  f = c.getDeclaredFields();
			for (Field field : f) {
				myField myField =  (com.test.annotation.myField) field.getAnnotation(myField.class);
				System.out.println(myField);
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
