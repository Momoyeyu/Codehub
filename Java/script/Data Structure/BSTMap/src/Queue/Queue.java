package Queue;

import java.util.EmptyStackException;

public class Queue<T> {

    private Node head;

    private Node last;

    private int size;

    private class Node {
        private T data;
        private Node next;
        public Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    public Queue() {
        head = new Node(null);
        last = head;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void add(T data) {
        last.next = new Node(data);
        last = last.next;
        size += 1;
    }

    public T remove() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        Node n = head.next;
        head.next = n.next;
        size -= 1;
        return n.data;
    }

}
