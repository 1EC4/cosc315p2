package cosc315.gp1.mp2;

public class Slave implements Runnable {
	
	// Specifies the wait time for slave threads
	// if the queue is empty before checking again
	// (in milliseconds)
	private final int WAIT_TIME = 500;
	
	// Task Queue with locks
	private SafeQueue<Task> _taskQ;
	// Slave ID (only used for debugging output)
	private int _slaveID;
	
	/**
	 * Initializes all variables used in Slave Thread
	 * @param id Specifies the slave Thread ID
	 * @param queue Reference to the Task Queue
	 */
	public Slave(int id, SafeQueue<Task> queue) {
		_slaveID = id;
		_taskQ = queue;
	}

	@Override
	public void run() {
		while(true) {
			System.out.println("Slave Thread " + _slaveID + " is waiting for task...");
			Task t = null;
			while((t = _taskQ.poll()) == null) {
				try {
					Thread.sleep(WAIT_TIME);
				} catch(Exception e) {
					e.printStackTrace();
				}
			}
			System.out.println("Slave Thread " + _slaveID + " retrievied task with ID = " + t.getID() + " and length = " + t.getLength());
			try {
				System.out.println("Slave Thread " + _slaveID + " is executing task " + t.getID());
				Thread.sleep(t.getLength() * 1000);
				System.out.println("Slave Thread " + _slaveID + " finished executing task " + t.getID());
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	
	
}
