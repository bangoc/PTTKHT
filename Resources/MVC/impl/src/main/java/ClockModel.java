public class ClockModel {
	private int minutes;

	public ClockModel(int m) {
		minutes = m;
	}
	public int getMinutes() {
		return minutes;
	}
	public void setMinutes(int m) {
		minutes = m;
	}
	public void advance() {
		minutes++;
		return;
	}
}