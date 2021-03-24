package linked.list;
public class Node {
    int val;
    Node next; //refrence var == pointer to Node  

    public Node(int val) {
        this.val = val;
        //next automatically is set to null
    }
    
    public void disp(){
        System.out.print(val+" ");        
    }      
    
}
