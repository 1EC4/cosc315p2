package cosc315.gp1.mp2;

public class Task {

	// Variable to keep track of the ID that
	// will be assigned to the next generated
	// task.
	private static int _nextid = 0;
	
	// ID and Length of each task
	private int _id;
	private int _len;
	
	/**
	 * Creates a new Task
	 * @param ID Specifies Task ID
	 * @param Length Specifies Task Length
	 */
	private Task(int ID, int Length) {
		_id = ID;
		_len = Length;
	}
	
	/**
	 * Generates a new task
	 * @param maxLength Specifies the maximum length of the task
	 * @return The generated Task
	 */
	public static Task GenerateTask(int maxLength) {
		int length = (int)(Math.random() * (maxLength - 1)) + 1;
		Task t = new Task(_nextid, length);
		_nextid++;
		return t;
	}

	/**
	 * Getter for the Length of the Task
	 * @return The Task Length
	 */
	public int getLength() {
		return _len;
	}

	/**
	 * Getter for the ID of the Task
	 * @return The Task ID
	 */
	public int getID() {
		return _id;
	}
	
}
