package com.algs.stackandqueue;

import java.util.Iterator;
import java.util.NoSuchElementException;
/**
 * 
 * @author Rather
 *
 * @param <Item>
 */
public class LinkedStack<Item> implements Iterable<Item> {
	private Node first;
	private int n;
	private class Node{
		Item item;
		Node next;
	}
	
	public LinkedStack(){
		first = null;
		n = 0;
		assert check();
	}
	
	public boolean isEmpty(){
		return first == null;
	}
	
	public int getsize(){
		return n;
	}
	
	public void push(Item item){
		Node oldfirst = first;
		Node first = new Node();
		first.item = item;
		first.next = oldfirst;
		n++;
		assert check();
	}
	
	public Item pop(){
		if(isEmpty()) throw new NoSuchElementException(); 
		Item item = first.item;
		first = first.next;
		n--;
		assert check();
		return item;
	}
	
	public Item peak(){
		if(isEmpty()) throw new NoSuchElementException(); 
		return first.item;
	}


	@Override
	public Iterator<Item> iterator() {
		return new ListIterator();
	}
	
	private class ListIterator implements Iterator<Item>{
		private Node current=first;
		@Override
		public boolean hasNext() {
			return current.next!=null;
		}

		public void remove()      { throw new UnsupportedOperationException();  }
		
		@Override
		public Item next() {
			if(!hasNext())  throw new NoSuchElementException();
			Item item = current.item;
			current = current.next;
			return item;
		}
	}
	
	 // check internal invariants
    private boolean check() {

        // check a few properties of instance variable 'first'
        if (n < 0) {
            return false;
        }
        if (n == 0) {
            if (first != null) return false;
        }
        else if (n == 1) {
            if (first == null)      return false;
            if (first.next != null) return false;
        }
        else {
            if (first == null)      return false;
            if (first.next == null) return false;
        }

        // check internal consistency of instance variable n
        int numberOfNodes = 0;
        for (Node x = first; x != null && numberOfNodes <= n; x = x.next) {
            numberOfNodes++;
        }
        if (numberOfNodes != n) return false;

        return true;
    }
	
    /**
     * Unit tests the {@code LinkedStack} data type.
     *
     * @param args the command-line arguments
     */
    public static void main(String[] args) {
        LinkedStack<String> stack = new LinkedStack<String>();
        //test
    }
}
	
