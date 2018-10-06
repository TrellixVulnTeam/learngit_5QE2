package tool;

import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
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
//	private Image offScreenImage = null;
//	public void update(Graphics g) {
//		if(offScreenImage == null)
//			offScreenImage = this.createImage(constant.Width,constant.Height);
//		
//		Graphics gOff = offScreenImage.getGraphics();
//
//		paint(gOff);
//		g.drawImage(offScreenImage, 0, 0, null);
//	}
	
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
	public void printInfo(String str,int x,int y,Graphics g,Color color,int size){
		Font font = new Font("����",Font.BOLD,size);
		Color c = g.getColor();
		g.setColor(color);
		g.setFont(font);
		g.drawString(str, x, y);
		g.setColor(c);
	}

}
