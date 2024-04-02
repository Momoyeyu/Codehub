package Map61B;

import java.util.Collection;
import java.util.Iterator;
import Queue.Queue;
import java.util.Set;

public class BSTMap<K extends Comparable<K>, V> implements Map61B<K, V> {

	private Node root;

	@Override
	public Iterator<K> iterator() {
		return new BSF();
	}

	private class BSF implements Iterator<K> {

		private Queue<Node> queue;

		public BSF() {
			queue = new Queue<Node>();
			enqueue(root);
		}

		private void enqueue(Node node) {
			while (node != null) {
				queue.add(node);
				node = node.left;
			}
		}

		public boolean hasNext() {
			return !queue.isEmpty();
		}

		public K next() {
			Node cur = queue.remove();
			enqueue(cur.right);
			return cur.key;
		}

	}

	private class Node {
		private K key;
		private V value;
		private Node left, right;
		private int size;

		public Node(K key, V value, int size) {
			this.key = key;
			this.value = value;
			this.size = size;
		}

		public void copy(Node node) {
			key = node.key;
			value = node.value;
		}
	}

	public BSTMap() {
		root = new Node(null, null, 0);
	}

	public void clear() {
		root = new Node(null, null, 0);
	}

	public V get(K key) {
		Node target = find(root, key);
		if (target == null)
			return null;
		return target.value;
	}

	/**
	 *
	 * @param node The base of the Tree
	 * @param key The key to find the target node
	 * @return the node whose key equal to the given one
	 */
	private Node find(Node node, K key) {
		if (node == null || isEmpty())
			return null;
		else if (key.compareTo(node.key) < 0)
			return find(node.left, key);
		else if (key.compareTo(node.key) > 0)
			return find(node.right, key);
		return node;
	}

	private void insert(Node base, Node node) {
		if (isEmpty()) {
			root = node;
			return;
		}
		if (node.key.equals(base.key)) {
			base.value = node.value;
			return;
		}
		while(true) {
			base.size += 1;
			if (node.key.compareTo(base.key) < 0) {
				if (base.left == null) {
					base.left = node;
					break;
				} else {
					base = base.left;
				}
			} else {
				if (base.right == null) {
					base.right = node;
					return;
				} else {
					base = base.left;
				}
			}
		}

	}

	public void put(K key, V value) {
		insert(root, new Node(key, value, 1));
	}

	public int size() {
		return root.size;
	}

	public int size(Node node) {
		return node.size;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public Set<K> keySet() {
		throw new UnsupportedOperationException();
	}

	public V remove(K key) {
		if (key == null) {
			throw new IllegalArgumentException("calls delete() with a null key");
		}
		V v = find(root, key).value;
		root = remove(root, key);
		return v;
	}

	public V remove(K key, V value) {
		if (key == null) {
			throw new IllegalArgumentException("calls delete() with a null key");
		}
		V v = find(root, key).value;
		if (v != value) {
			return null;
		}
		root = remove(root, key);
		return v;
	}

	private Node remove(Node node, K key) {
		if (node == null) {
			return null;
		}
		int cmp = key.compareTo(node.key);
		if (cmp < 0) {
			node.left = remove(node.left, key);
		} else if (cmp > 0) {
			node.right = remove(node.right, key);
		} else {
			if (node.right == null)
				return node.left;
			if (node.left == null)
				return node.right;
			Node successor = getSuccessor(node);
			root = remove(root, successor.key);
			node.copy(successor);
		}
		node.size = size(node.left) + size(node.right) + 1;
		return node;
	}

	private Node getSuccessor(Node target) {
		target = target.right;
		while (target.left != null) {
			target = target.left;
		}
		return target;
	}

}
