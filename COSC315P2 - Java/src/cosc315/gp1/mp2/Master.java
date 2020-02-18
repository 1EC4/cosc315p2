package cosc315.gp1.mp2;

public class Master implements Runnable {

	// Specifies the wait time for master thread
	// if the queue is full before checking the
	// queue size again (in milliseconds)
	private final int WAIT_TIME = 500;
	
	// Specifies the maximum length of all tasks
	private int _mLen;
	// Specifies the maximum timeout before generating
	// a new task (in seconds)
	private int _mIdle;
	// Specifies the number of slaves executing
	// tasks. This also specifies the maximum
	// size of the queue.
	private int _nSlaves;
	// Task Queue with locks
	private SafeQueue<Task> _taskQ;
	
	/**
	 * Initializes all variables used in the Master Thread
	 * @param maxLength Specifies maximum task length
	 * @param maxIdle Specifies maximum idle time for master thread
	 * @param numSlaves Specifies number of slaves
	 * @param queue Reference to the Task Queue
	 */
	public Master(int maxLength, int maxIdle, int numSlaves, SafeQueue<Task> queue) {
		_taskQ = queue;
		_mLen = maxLength;
		_mIdle = maxIdle;
		_nSlaves = numSlaves;
	}

	@Override
	public void run(){
		while(true) {
			// Randomly generates a number between 1 and _mIdle (inclusive)
			int sleep = (int)(Math.random() * (_mIdle - 1)) + 1;
			// Master Thread sleeps for a random amount of time
			try {
				System.out.println("Master Thread is idling...");
				Thread.sleep(sleep * 1000);
			} catch (Exception e) {
				e.printStackTrace();
			}
			
			// Master Thread generates a new task
			Task t = Task.GenerateTask(_mLen);
			System.out.println("Master Thread received new task " + t.getID() + " with length " + t.getLength());
			// Master Thread waits for queue to be non-full
			System.out.println("Master Thread is waiting for queue to be idle...");
			while(_taskQ.size() == _nSlaves) {
				try {
					Thread.sleep(WAIT_TIME);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
			
			// Master Thread adds new Task to the queue/
			_taskQ.add(t);
			System.out.println("Master Thread added task " + t.getID() + " to the task queue");
		}
	}
	
}
