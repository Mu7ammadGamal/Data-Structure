package binarytree;
public class BinaryTree {    
    public static void main(String[] args) {
        Binary_Tree b = new Binary_Tree();
        b.insert(4);
        b.insert(2);
        b.insert(8);
        b.insert(6);
        b.insert(3);
        b.insert(1);
        b.insert(9);
        b.insert(10);
        b.insert(11);       
        
        //b.traverse_inOrder_LVR(b.root);
        //System.out.println();
        //System.out.println(b.successor());
        //System.out.println(b.balance_factor());
        //b.traverse_inOrder_LVR(b.root);
        //b.reverse(b.root);
        //System.out.println();
        //b.traverse_inOrder_LVR(b.root);
        //System.out.println();
        //b.removeLeaves(b.root);
        //b.traverse_inOrder_LVR(b.root);
        System.out.println(b.searchAllhKey(b.root,4));
        
        //b.traverse_preOrder_VLR(b.root);
        //System.out.println();
        //b.traverse_postOrder_LRV(b.root);
        //System.out.println();
//        System.out.println(b.find(10));
//        System.out.println(b.getMax());
//        System.out.println(b.getMin());
//        System.out.println(b.maxDepth(b.root));
//        System.out.println("Succ = "+b.successor());
//        System.out.println("Pred = "+b.predecessor());
    }
    
}
