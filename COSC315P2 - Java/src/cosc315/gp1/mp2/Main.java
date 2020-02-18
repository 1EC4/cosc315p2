// COSC 315 Group 1 - Mini Project 2
// #47462361 Anthony Boyko
// #29164977 Jonathan Gresl
// #22092845 Nick Rieske

package cosc315.gp1.mp2;

public class Main {

	// Specifies number of slaves (must be > 0)
	private static final int NUM_SLAVES = 5;
	// Specifies maximum task length (in seconds)
	private static final int MAX_TASK_LEN = 10;
	// Specifies maximum idle time between generating tasks of master thread (in seconds)
	private static final int MAX_MASTER_IDLE = 5;
	// Specifies maximum running time of program (0 = no maximum) in milliseconds
	private static final int TIMEOUT = 1800000; // 1800000 milliseconds = 30 minutes
	
	public static void main(String[] args) throws Exception {
		SafeQueue<Task> taskQ = new SafeQueue<Task>(NUM_SLAVES);
		
		Thread master = new Thread(new Master(MAX_TASK_LEN, MAX_MASTER_IDLE, NUM_SLAVES, taskQ));
		Thread[] slaves = new Thread[NUM_SLAVES];
		for(int i = 0; i < NUM_SLAVES; i++) {
			slaves[i] = new Thread(new Slave(i + 1, taskQ));
			slaves[i].start();
		}
		
		master.start();
		master.join(TIMEOUT);
	}
	
}
