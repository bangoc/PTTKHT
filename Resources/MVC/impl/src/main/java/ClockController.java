import java.awt.* ;
import java.awt.event.* ;
import javax.swing.* ;

public class ClockController extends JFrame {
	private JLabel timeLabel;
	private JButton tickButton, resetButton;
	private JPanel buttonHolder;
	private Container contentPane;
	private ClockView view;
	private ClockModel model;
  private final int kStart = 723;

  public ClockController() {
    contentPane = getContentPane();
    setSize(300, 200 );
    setTitle("MVC Clock");
    buttonHolder = new JPanel();
    contentPane.add(buttonHolder, BorderLayout.SOUTH);

		tickButton = new JButton("Tick");
		resetButton = new JButton("Reset");
		timeLabel = new JLabel("12:00:00");

		buttonHolder.add(tickButton);
		buttonHolder.add(resetButton);
		buttonHolder.add(timeLabel);

		model= new ClockModel(kStart);
		view= new ClockView(model);
		contentPane.add(view, BorderLayout.CENTER);

		tickButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				advance(ae);
			}
		});

		resetButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				reset(ae);
			}
		});
  }

  public void advance(ActionEvent ae) {
    model.advance();
    view.repaint();
    setLabels();
  }

  public void reset(ActionEvent ae) {
    model.setTimeInSeconds(kStart);
    view.repaint();
    setLabels();
  }

	public void setLabels() {
    String s = "";
    if (model.getHours() >= 10) {
      s = s + model.getHours();
    } else {
      s = s + "0" + model.getHours();
    }
    s = s + ":";
    if (model.getMinutes() >= 10) {
      s = s + model.getMinutes();
    } else {
      s = s + "0" + model.getMinutes();
    }
    s = s + ":";
    if (model.getSeconds() >= 10) {
      s = s + model.getSeconds();
    } else {
      s = s + "0" + model.getSeconds();
    }

		timeLabel.setText(s);
	}

  public static void main(String[] args) {
    ClockController application = new ClockController() ;
    application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;
    application.setVisible(true) ;
  }
}