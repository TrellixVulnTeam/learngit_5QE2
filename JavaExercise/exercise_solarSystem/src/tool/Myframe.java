package tool;

import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import tool.constant;
/**
 * ��ܽṹ��
 * @author Administrator
 *
 */
@SuppressWarnings("serial")
public class Myframe extends Frame {
	public void launchFrame(){  //���ش���
		setSize(constant.Width, constant.Height);
		setLocation(100,100);
		setVisible(true);
		new PaintThread().start();  //�����ػ��߳�
		addWindowListener(new WindowAdapter(){  //������
			@Override       
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
			
		});
	}
	
	class PaintThread extends Thread{ //�ڲ��࣬ˢ�´��ڵ��߳���
		public void run(){
			while(true){
				repaint();
				try {
					Thread.sleep(40);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
