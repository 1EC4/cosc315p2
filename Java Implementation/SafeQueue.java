
import java.util.concurrent.ArrayBlockingQueue;

public class SafeQueue<T> extends ArrayBlockingQueue<T> {
	
	/**
	 * Creates a new SafeQueue object
	 * @param capacity Specifies maximum number of elements in the queue
	 */
	public SafeQueue(int capacity) {
		super(capacity);
	}

	/**
	 * Adds an element to the queue
	 */
	public synchronized boolean add(T e) {
		// Adds the element to the end of the queue
		// and returns the result
		return super.add(e);
	}
	
	/**
	 * Gets and removes the first element in the queue
	 */
	public synchronized T poll() {
		// retrieves element and returns it
		return super.poll();
	}
	
	/**
	 * Gets the number of elements in the queue
	 */
	public synchronized int size() {
		// retrieves size of queue
		return super.size();
	}
}
