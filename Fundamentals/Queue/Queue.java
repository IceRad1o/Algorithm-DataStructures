package com.algs.stackandqueue;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Queue<Item> implements Iterable<Item> {
	private Node<Item> first;
	private Node<Item> last;
	private int n;
	
	private static class Node<Item>{
		private Item item;
		private Node<Item> next;
	}
	
	public Queue(){
		first = null;
		last = null;
		n = 0;
	}
	
	public boolean isEmpty(){
		return first == null;
	}
	
	 public int size() {
	        return n;
	    }
	
	public Item peak(){
		if (isEmpty()) throw new NoSuchElementException("Queue underflow");
		return first.item;
	}
	
	public void enqueue(Item item){
		Node<Item> oldlast = last;
		last = new Node<Item>();
		last.item = item;
		last.next = null;
		if (isEmpty()) first = last;
        else           oldlast.next = last;
		n++;
		System.out.println(this.toString());
	}
	
	public Item dequeue(){
		if (isEmpty()) throw new NoSuchElementException("Queue underflow");
		Item item = first.item;
		first = first.next;
		n--;
		if (isEmpty()) last = null;   // to avoid loitering
		return item;
	}
	
	 /**
     * Returns a string representation of this queue.
     *
     * @return the sequence of items in FIFO order, separated by spaces
     */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		for(Item item:this){
			sb.append(item);
			sb.append(" ");
		}
		return sb.toString();
	}
	
	public Iterator<Item> iterator() {
		return new ListIterator<Item>(first);
	}
	
	private class ListIterator<Item> implements Iterator<Item>{
		private Node<Item> current ;
		
		public ListIterator(Node<Item> first){
			current = first;
		}
		@Override
		public boolean hasNext() {
			return current!=null;
		}
		public void remove()      { throw new UnsupportedOperationException();  }

	    public Item next() {
	            if (!hasNext()) throw new NoSuchElementException();
	            Item item = current.item;
	            current = current.next; 
	            return item;
	        }
		
	}
	
	public static void main(String[] args){
		Queue<String> queue = new Queue<String>();
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			String item = scanner.next();
			if(!item.equals("-")) queue.enqueue(item); 
			else if(!queue.isEmpty())
				System.out.println(queue.dequeue()+" dequeue()");
		}
	}
	
}
