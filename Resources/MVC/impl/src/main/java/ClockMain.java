import java.awt.* ;
import java.awt.event.* ;
import javax.swing.* ;

public class ClockMain extends JFrame {
  private JLabel timeLabel;
  private JButton tickButton, resetButton;
  private JPanel buttonHolder;
  private Container contentPane;
  private ClockView view;
  private ClockModel model;
  private ClockController controller;

  public ClockMain() {
    contentPane = getContentPane();
    setSize(300, 200);
    setTitle("MVC Clock");
    buttonHolder = new JPanel();
    contentPane.add(buttonHolder, BorderLayout.SOUTH);

    tickButton = new JButton("Tick");
    resetButton = new JButton("Reset");
    timeLabel = new JLabel("12:00:00");

    buttonHolder.add(tickButton);
    buttonHolder.add(resetButton);
    buttonHolder.add(timeLabel);

    model= new ClockModel(723);
    view= new ClockView(model);
    controller = new ClockController(model, view);

    contentPane.add(view, BorderLayout.CENTER);
    tickButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent ae) {
        controller.advance(ae);
        setLabels();
      }
    });

    resetButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent ae) {
        controller.reset(ae);
        setLabels();
      }
    });
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
    ClockMain app = new ClockMain() ;
    app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;
    app.setVisible(true) ;
  }
}