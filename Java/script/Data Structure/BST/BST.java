

public class BST<Key> {

	private Key key;
	
	private BST lchild;
	
	private BST rchild;

	public BST(Key key, BST left, BST right) {
		this.key = key;
		this.lchild = left;
		this.rchild = right;
	}

	public BST(Key key) {
		this.key = key;
		this.lchild = null;
		this.rchild = null;
	}

	public BST find(BST T, Key sk) {
		if (T == null) {
			return null;
		} else if (T.key == sk) {
			return T;
		} else if (T.key < sk) {
			find(T.rchild, sk);
		} else {
			find(T.lchild, sk);
		}
	}

}
