public class ClockModel {
	private int time;

	public ClockModel(int m) {
		time = m;
	}
	public int getHours() {
		return time / 3600;
	}
	public int getMinutes() {
		return (time % 3600) / 60;
	}
	public int getSeconds() {
		return time % 60;
	}
	public void setTimeInSeconds(int t) {
		time = t;
	}
	public void advance() {
		++time;
	}
}