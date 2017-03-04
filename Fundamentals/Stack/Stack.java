package com.algs.stackandqueue;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;
/**
 * represents a last-in-first-out(LIFO) stack of generic items
 * @author Rather
 *
 * @param <Item>
 */
public class Stack<Item> implements Iterable<Item> {
    private Node<Item> first;
    private int n;
    
    private static class Node<Item>{
    	private Item item;
    	private Node<Item> next ;
    }
    
    public Stack(){
    	first = null;
    	n = 0;
    }
    
    public boolean isEmpty(){
    	return first == null;
    }
    
    public int size(){
    	return n;
    }
    
    /**
     * Removes and returns the item most recently added to this stack.
     *
     * @return the item most recently added
     * @throws NoSuchElementException if this stack is empty
     */
	public Item pop(){
		if(isEmpty())  throw new NoSuchElementException("stack underflow");
		Item item = first.item;
		first = first.next;
		n--;
		return item;
	}
	
	/**
     * Adds the item to this stack.
     *
     * @param  item the item to add
     */
	public void push(Item item){
		Node<Item> oldfirst = first;
	    first = new Node<Item>();
		first.item = item;
		first.next = oldfirst;
		n++;
	}
	
	/**
     * Returns (but does not remove) the item most recently added to this stack.
     *
     * @return the item most recently added to this stack
     * @throws NoSuchElementException if this stack is empty
     */
    public Item peek() {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        return first.item;
    }
    
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Item item : this) {
            s.append(item);
            s.append(' ');
        }
        return s.toString();
    }
    
	public Iterator<Item> iterator() {
		return new ListIterator<Item>(first);
	}
	
	@SuppressWarnings("hiding")
	private class ListIterator<Item> implements Iterator<Item>{
		private Node<Item> current;
		
		public ListIterator(Node<Item> first){
			current = first;
		}
		@Override
		public boolean hasNext() {
			return current.next != null;
		}
		@Override
		public Item next() {
			if(!hasNext()) throw new NoSuchElementException();
			Item item = current.item;
			current = current.next;
			return item;
		}
	}
    
	public static void main(String[] args){
		Stack<String> stack = new Stack<String>();
		Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String item = scanner.nextLine();
            if (!item.equals("-"))
                stack.push(item);
            else if (!stack.isEmpty())
                System.out.println(stack.pop() + " ");
        }
    }
	
}
