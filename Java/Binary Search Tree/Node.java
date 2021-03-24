package binarytree;
public class Node {
    int val;
    Node left;
    Node right;

    public Node(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
    public void dispNode(){
        System.out.print(val+" ");
    }
    
}
