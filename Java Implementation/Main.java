// COSC 315 Group 1 - Mini Project 2
// #47462361 Anthony Boyko
// #29164977 Jonathan Gresl
// #22092845 Nick Rieske

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Main {

	// Specifies number of slaves (must be > 0)
	private static int NUM_SLAVES = 5;
	// Specifies maximum task length (in seconds)
	private static int MAX_TASK_LEN = 20;
	// Specifies maximum idle time between generating tasks of master thread (in seconds)
	private static int MAX_MASTER_IDLE = 3;
	// Specifies maximum running time of program (0 = no maximum) in milliseconds
	private static final int TIMEOUT = 1800000; // 1800000 milliseconds = 30 minutes
	// Format for time debug output
	private static final DateTimeFormatter TIME_FORMAT = DateTimeFormatter.ofPattern("HH:mm:ss");
	
	public static void main(String[] args) throws Exception {

		if (args.length > 0){
			try {
				NUM_SLAVES = Integer.parseInt(args[0]);
			} catch (Exception e){
				System.out.printf("Bad Syntax. Expected: java Main [num_slaves] [max_task_len] [max_master_idle]%n");
				return;
			}
		}
		
		if (args.length > 1){
			try {
				MAX_TASK_LEN = Integer.parseInt(args[1]);
			} catch (Exception e){
				System.out.printf("Bad Syntax. Expected: java Main [num_slaves] [max_task_len] [max_master_idle]%n");
				return;
			}
		}

		if (args.length == 3){
			try {
				MAX_MASTER_IDLE = Integer.parseInt(args[2]);
			} catch (Exception e){
				System.out.printf("Bad Syntax. Expected: java Main [num_slaves] [max_task_len] [max_master_idle]%n");
				return;
			}
		}

		if (args.length > 3){
			System.out.printf("Bad Syntax. Expected: java Main [num_slaves] [max_task_len] [max_master_idle]%n");
			return;
		}

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
	
	public static void log(String thread, String message) {
		String time = LocalDateTime.now().format(TIME_FORMAT);
		System.out.printf("[%s] %s > %s%n", time, thread, message);
	}
	
}
