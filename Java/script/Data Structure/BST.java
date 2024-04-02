

public class BST<Key> {

	private Key key;

	private BST left;

	private BST right;

	public BST(Key k, BST l, BST r) {
		key = k;
		left = l;
		right = r;
	}

	public BST(Key k) {
		key = k;
	}

	public BST find(BST T, Key sk) {
		if (T == null) {
			return null;
		} else if (T.key == sk) {
			return T;
		} else if (T.key < sk) {
			find(T.right, sk);
		} else {
			find(T.left, sk);
		}
	}

	private Pair findPair(BST T, Key sk) {
		return findPairHelper(new Pair(T, T), sk);
	}

	private Pair findPairHelper(Pair pair, Key sk) {
		BST T = pair.getSelf();
		if (T == null) {
			pair.next(null);
		} else if (T.key == sk) {
			return pair;
		} else if (sk < T.key) {
			pair.next(T.left, true);
		} else {
			pair.next(T.right, false);
		}
		return findPairHelper(pair, sk);
	}

	public BST insert(BST T, Key ik) {
		if (T == null) {
			return new BST(ik);
		} else if (ik < T.key) {
			T.left = insert(T.left, ik);
		} else if (ik > T.key) {
			T.right = insert(T.right, ik);
		}
		return T;
	}

	public BST delete(BST T, Key dk) {
		// 1. get the point to delete						==> search 		log(N)
		// 2. delete if the point don't have two child		==> comparison	(1)
		// 3. else, find the successor's					==> search		log(N)
		// 4. remove successor from its original position	==> delete		log(N)
		// 5. switch the point's value to it's successor's	==> write		(1)
		Pair pair = findPair(T);
		BST parent = pair.getParent();
		BST self = pair.getSelf();
		if (isLeft(self)) {
			if (parent == self) {
				return null;
			}
			if (pair.isLeft) {
				parent.left = null;
			}
		} else if (self.left != null && self.right == null) {

			self.key = 
		}
	}

	private BST getSuccessor(BST T) {
		T = T.right
	}

	public boolean isLeft(BST T) {
		return (T.left == null && T.right == null);
	}

	private class Pair {
		private BST parent;
		private BST self;
		private boolean left;
		public Pair(BST p, BST s) {
			parent = p;
			left = false;
			self = s;
		}

		public void next(BST n, boolean l) {
			parent = self;
			left = l;
			self = n;
		}

		public BST getParent() {
			return parent;
		}

		public BST getSelf() {
			return self;
		}

		public boolean isLeft() {
			return left;
		}

	}

}
