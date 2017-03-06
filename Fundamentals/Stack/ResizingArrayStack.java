package com.algs.stackandqueue;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayStack<Item> implements Iterable<Item> {
	private Item[] a;
	private int n;
	
	/**
	 * Initialization an empty stack
	 */
	public ResizingArrayStack(){
		a = (Item[]) new Object[2];
		n = 0;
	}
	
	public boolean isEmpty(){
		return n==0;
	}
	
	public int size(){
		return n;
	}
	
	private void resize(int capacity){
		//assert capacity>0;
		//testbook implementation
		Item[] temp = (Item[]) new Object[capacity];
		for(int i=0;i<n;i++){
			temp[i] = a[i];
		}
		a= temp;
	}
	
	public void push(Item item){
		if(n == a.length) resize(2*a.length);
		a[n++] = item;
	}
	
	public Item pop(){
		if(isEmpty()) throw new NoSuchElementException("Stack underflow");
		Item item = a[n-1];
		a[n-1] = null;
		n--;
		//shrinksize of array if necessay and a.length/4 is important
		if(n>0 && n == a.length/4) resize(a.length/2);
		return item;
	}
	
	public Item peak(){
		if (isEmpty()) throw new NoSuchElementException("Stack underflow");
		return a[n-1];
	}
	
	@Override
	public Iterator<Item> iterator() {
		return new ReverseArrayIterator();
	}

	private class ReverseArrayIterator implements Iterator<Item>{
		private int i;
		public ReverseArrayIterator(){
			i = n-1;
		}
		
		public boolean hasNext(){
			return i>0;
		}
		
		public void remove(){
			throw new UnsupportedOperationException();
		}
		
		public Item next(){
			if(!hasNext()) throw new NoSuchElementException();
			return a[i--];
		}
	}
	public static void main(String[] args) {
		  ResizingArrayStack<String> stack = new ResizingArrayStack<String>();
		 //Test
	}

}
