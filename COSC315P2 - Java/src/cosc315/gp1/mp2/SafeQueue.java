package cosc315.gp1.mp2;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class SafeQueue<T> extends ArrayBlockingQueue<T> {
	
	private final Lock lock;
	
	/**
	 * Creates a new SafeQueue object
	 * @param capacity Specifies maximum number of elements in the queue
	 */
	public SafeQueue(int capacity) {
		super(capacity);
		lock = new ReentrantLock();
	}

	/**
	 * Adds an element to the queue
	 */
	public boolean add(T e) {
		// Thread waits to acquire lock
		lock.lock();
		// Adds the element to the end of the queue
		boolean success = super.add(e);
		// Thread releases the lock
		lock.unlock();
		// Returns true on success; false otherwise
		return success;
	}
	
	/**
	 * Gets and removes the first element in the queue
	 */
	public T poll() {
		// Thread waits to acquire lock
		lock.lock();
		// retrieves element
		T e = super.poll();
		// Thread releases the lock
		lock.unlock();
		// Returns the element retrieved from queue
		return e;
	}
	
	/**
	 * Gets the number of elements in the queue
	 */
	public int size() {
		// Thread waits to acquire lock
		lock.lock();
		// retrieves size of queue
		int size = super.size();
		// Thread releases the lock
		lock.unlock();
		// Returns the size of queue
		return size;
	}
}
