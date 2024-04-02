public class BinaryTree<Key> {

    private Key key;
    private BinaryTree<Key> lchild;
    private BinaryTree<Key> rchild;

    public BinaryTree(Key k, BinaryTree<Key> l, BinaryTree<Key> r) {
        key = k;
        lchild = l;
        rchild = r;
    }

    public BinaryTree(Key k) {
        key = k;
    }

    private BinaryTree<Key> rotateLL() {
        BinaryTree<Key> root = this.lchild;
        this.lchild = root.rchild;
        root.rchild = this;
        return root;
    }

    private BinaryTree<Key> rotateRR() {
        BinaryTree<Key> root = this.rchild;
        this.rchild = root.lchild;
        root.lchild = this;
        return root;
    }

    private BinaryTree<Key> rotateLR() {
        this.lchild = this.lchild.rotateRR();
        return this.rotateLL();
    }

    private BinaryTree<Key> rotateRL() {
        this.rchild = this.rchild.rotateLL();
        return this.rotateRR();
    }
}
