import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.nio.charset.CharacterCodingException;

import javax.swing.*;
import javax.swing.Timer;

public class Cube extends JFrame {
	public Cube() {
		Tetrisblock bTetrisblock = new Tetrisblock();
		addKeyListener(bTetrisblock);
		add(bTetrisblock); 
	}

	public static void main(String[] args) {
		Cube game = new Cube();
//		JMenuBar menu = new JMenuBar();
//		frame.setJMenuBar(menu);
//		JMenu game = new JMenu("��Ϸ");
//		JMenuItem newgame = game.add("����Ϸ");
//		JMenuItem pause = game.add("��ͣ");
//		JMenuItem goon = game.add("����");
//		JMenuItem exit = game.add("�˳�");
//		JMenu help = new JMenu("����");
//		JMenuItem about = help.add("����");
//		menu.add(game);
//		menu.add(help);
		game.setLocationRelativeTo(null);
		game.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		game.setSize(190, 390);
		game.setTitle("��ª�Ķ���˹���飺");
		// frame.setUndecorated(true);
		game.setVisible(true);
		game.setResizable(false);

	}
}

// ����һ������˹������
class Tetrisblock extends JPanel implements KeyListener {

	// blockType ����������
	// turnState������״̬
	private int blockType;
	private int score = 0;
	private int h_score = 0;
	private int turnState;

	private int x;

	private int y;

	private int i = 0;

	int j = 0;
	int flag = 0;
	// �����Ѿ����µķ���x=0-11,y=0-21;
	int[][] map = new int[13][23];

	// �������״ ��һ�������������S��Z��L��J��I��O��T 7�� �ڶ��� ������ת���� ��������Ϊ �������
	private final int shapes[][][] = new int[][][] {
	// i
			{ { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
					{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 } },
			// s
			{ { 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } },
			// z
			{ { 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 } },
			// j
			{ { 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
					{ 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
			// o
			{ { 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
			// l
			{ { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
			// t
			{ { 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 } } };

	// �����·���ķ���
	public void newblock() {
		blockType = (int) (Math.random() * 1000) % 7;
		turnState = (int) (Math.random() * 1000) % 4;
		x = 0;
		y = 0;
		if (gameover(x, y) == 1) {

			newmap();
			drawwall();
			score = 0;
			JOptionPane.showMessageDialog(null, "GAME OVER");
		}
	}

	// ��Χǽ
	public void drawwall() {
		for (i = 0; i < 12; i++) {
			map[i][21] = 2;
			map[i][0] = 3;
		}
		for (j = 0; j < 22; j++) {
			map[11][j] = 2;
			map[0][j] = 2;
		}
	}

	// ��ʼ����ͼ
	public void newmap() {
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 22; j++) {
				map[i][j] = 0;
			}
		}
	}

	// ��ʼ�����췽��
	Tetrisblock() {
		newblock();
		newmap();
		drawwall();
		Timer timer = new Timer(1000, new TimerListener());
		timer.start();
	}

	// ��ת�ķ���
	public void turn() {
		int tempturnState = turnState;
		turnState = (turnState + 1) % 4;
		if (blow(x, y, blockType, turnState) == 1) {
		}
		if (blow(x, y, blockType, turnState) == 0) {
			turnState = tempturnState;
		}
		repaint();
	}

	// ���Ƶķ���
	public void left() {
		if (blow(x - 1, y, blockType, turnState) == 1) {
			x = x - 1;
		}
		;
		repaint();
	}

	// ���Ƶķ���
	public void right() {
		if (blow(x + 1, y, blockType, turnState) == 1) {
			x = x + 1;
		}
		;
		repaint();
	}

	// ����ķ���
	public void down() {
		if (blow(x, y + 1, blockType, turnState) == 1) {
			y = y + 1;
			delline();
		}
		;
		if (blow(x, y + 1, blockType, turnState) == 0) {//������Ϸ
			add(x, y, blockType, turnState);
			newblock();
			delline();
		}
		;
		repaint();
	}

	// �Ƿ�Ϸ��ķ���
	public int blow(int x, int y, int blockType, int turnState) {
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				if (((shapes[blockType][turnState][a * 4 + b] == 1) && (map[x
						+ b +1][y + a ] == 1))
						|| ((shapes[blockType][turnState][a * 4 + b] == 1) && (map[x
								+ b +1][y + a ] == 2))) {

					return 0;
				}
			}
		}
		return 1;
	}

	// ���еķ���
	public void delline() {
		int c = 0;
		for (int b = 0; b < 22; b++) {
			for (int a = 0; a < 12; a++) {
				if (map[a][b] == 1) {

					c = c + 1;
					if (c == 10) {
						score += 10;
						for (int d = b; d > 1; d--) {
							for (int e = 0; e < 11; e++) {
								map[e][d] = map[e][d - 1];

							}
						}
					}
				}
			}
			c = 0;
		}
	}

	// �ж���ҵķ���
	public int gameover(int x, int y) {
		if (blow(x, y, blockType, turnState) == 0) {
			return 1;
		}
		return 0;
	}

	// �ѵ�ǰ���map
	public void add(int x, int y, int blockType, int turnState) {
		int j = 0;
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				if (map[x + b + 1][y + a] == 0) {
					map[x + b + 1][y + a] = shapes[blockType][turnState][j];
				}
				;
				j++;
			}
		}
	}

	// ������ĵķ���
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		int R = (int) (Math.random() * 255);
		int G = (int) (Math.random() * 255);
		int B = (int) (Math.random() * 255);
		Color color = new Color(R,G,B);
		Color c = g.getColor();
		g.setColor(color);
		// ����ǰ����
		for (j = 0; j < 16; j++) {
			if (shapes[blockType][turnState][j] == 1) {
				g.fillRect((j % 4 + x + 1) * 15, (j / 4 + y) * 15+40, 15,15);
			}
		}
		// ���Ѿ��̶��ķ���
		g.setColor(c);
		for (j = 0; j < 22; j++) {
			for (i = 0; i < 12; i++) {
				if (map[i][j] == 1) {
					g.fillRect(i * 15, j * 15+30,15,15);

				}
				if (map[i][j] == 2 ) {
					//g.drawRect(i * 15, j * 15+30,15,15);
					g.fillOval(i * 15, j * 15+30,15,15);

				}
				if (map[i][j] == 3 ) {
					//g.drawRect(i * 15, j * 15+30,15,15);
					g.fillOval(i * 15, j * 15+30,15,15);

				}
			}
		}
		g.setColor(c);
		Font font = new Font("����", Font.BOLD, 15);
		g.setFont(font);
		g.drawString("�÷֣�" + score, 0, 20);
		g.drawString("��߷֣�" + h_score, 90, 20);
		if(score > h_score){
			h_score = score;
			g.drawString("��߷֣�" + score, 90, 20);
		}
		
	}

	// ���̼���
	public void keyPressed(KeyEvent e) {
		switch (e.getKeyCode()) {
		case KeyEvent.VK_DOWN:
			down();
			break;
		case KeyEvent.VK_UP:
			turn();
			break;
		case KeyEvent.VK_RIGHT:
			right();
			break;
		case KeyEvent.VK_LEFT:
			left();
			break;
		}

	}

	// ����
	public void keyReleased(KeyEvent e) {
	}

	// ����
	public void keyTyped(KeyEvent e) {
	}

	// ��ʱ������
	class TimerListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {

			repaint();
			if (blow(x, y + 1, blockType, turnState) == 1) {
				y = y + 1;
				delline();
			}
			;
			if (blow(x, y + 1, blockType, turnState) == 0) {

				if (flag == 1) {
					add(x, y, blockType, turnState);
					delline();
					newblock();
				//	flag = 0;
				}
				flag = 1;
			}
			;
		}
	}
}
