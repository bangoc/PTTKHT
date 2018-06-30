import java.awt.* ;
import java.awt.geom.*;
import javax.swing.* ;

public class ClockView extends JPanel {
    private ClockModel model ;

    public ClockView( ClockModel cm ) {
        model = cm ;
    }

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2= (Graphics2D) g;
		double minutes= model.getMinutes();
		Shape e= new Ellipse2D.Double(100, 0, 100, 100);
		g2.draw(e);
		double hourAngle = 2 * Math.PI * (minutes - 3 * 60) / (12 * 60);
		double minuteAngle = 2 * Math.PI * (minutes - 15) / 60;
		Line2D.Double hour= new Line2D.Double(150, 50, 150 + (int) (30 * Math.cos(hourAngle)),
				50 + (int) (30 * Math.sin(hourAngle)));
		g2.draw(hour);
		Line2D.Double m= new Line2D.Double(150, 50, 150 + (int) (45 * Math.cos(minuteAngle)),
				50 + (int) (45 * Math.sin(minuteAngle)));
		g2.draw(m);
	}
}