
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
			Main.log("S" + _slaveID, "Idle");
			
			// Waiting for a task to be in the queue
			Task t = null;
			while((t = _taskQ.poll()) == null) {
				try {
					Thread.sleep(WAIT_TIME);
				} catch(Exception e) {
					e.printStackTrace();
				}
			}

			Main.log("S" + _slaveID, "Task "+t.getID()+" with length "+t.getLength()+" received");
			// Executing task by sleeping
			try {
				Main.log("S" + _slaveID, "Executing Task " + t.getID());
				Thread.sleep(t.getLength() * 1000);
				Main.log("S" + _slaveID, "Finished Task " + t.getID());
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	
	
}
