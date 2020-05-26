import java.awt.* ;
import java.awt.event.* ;
import javax.swing.* ;

public class ClockController extends JFrame {
	private ClockView view;
	private ClockModel model;
  private final int kStart = 723;

  public ClockController(ClockModel m, ClockView v) {
		model = m;
		view = v;
  }

  public void advance(ActionEvent ae) {
    model.advance();
    view.repaint();
  }

  public void reset(ActionEvent ae) {
    model.setTimeInSeconds(kStart);
    view.repaint();
  }
}