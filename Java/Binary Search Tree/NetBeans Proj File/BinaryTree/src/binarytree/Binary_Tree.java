package binarytree;
public class Binary_Tree{
    public Node root;
    public Node find(int val){        
        Node i = root;
        while(i!=null && i.val!=val){
            if(val>i.val)
                i=i.right;
            else
                i=i.left;
        }
        return i;

//        if(root == null){            
//            return null;
//        }
//        else{ 
//            Node temp = root;
//            while(temp!=null && temp.val!=val){
//                if(val>temp.val)
//                    temp = temp.right;
//                else if(val<temp.val)
//                    temp = temp.left;                
//            } 
//            return temp;
//        }        
    }
    public boolean searchKey(Node root,int val){        
        if(root == null)            
            return false;
        if(val>root.val)
            return searchKey(root.right,val);
        else if(val<root.val)
            return searchKey(root.left,val);
        else
            return true;       
                
    }
    
    public boolean searchAllhKey(Node root,int val){        
        if(root == null)            
            return false;
        if(root.val==val)
            return true;        
        boolean r = searchKey(root.right,val);        
        boolean l = searchKey(root.left,val);  
        return l|r;             
                
    }
    
    public Node insert(int val){
        Node newNode = new Node(val);
        if(root == null){            
            root = newNode;
        }
        else{
            Node temp = root;
            while(true){
                if(val>=temp.val && temp.right!=null)
                    temp = temp.right;
                else if(val<temp.val && temp.left!=null)
                    temp = temp.left;
                else
                    break;
            }
            if(val>=temp.val)
               temp.right = newNode;            
            else
               temp.left = newNode;            
            
        }
        return newNode;
    } 
    public Object getMax(){
        Node temp = root;
        while(temp.right!=null)
            temp = temp.right;
        return temp.val;        
    }
    public Object getMin(){
        Node temp = root;
        while(temp.left!=null)
            temp = temp.left;
        return temp.val;        
    }
    public int maxDepth(Node currRoot){
        if(currRoot == null)
            return -1;
        int rD = maxDepth(currRoot.right);
        int lD = maxDepth(currRoot.left);
        return Math.max(rD, lD)+1;
    }
    public int balance_factor(){
        int rD = maxDepth(root.right);
        int lD = maxDepth(root.left);
        return Math.abs(lD-rD);
    }
    public boolean isBalnced(){
        int bf = balance_factor(); 
        if(bf>1)
            return false;
        else 
            return true;
        
    }
    
    
    public Object successor(){
        if(root==null || root.right== null )
            return null;
        Node temp = root.right;
        //if(root.right!=null){
            //minRight            
            while(temp.left!=null)
                temp = temp.left;                       
       // }
        return temp.val;        
    }
    public Object predecessor(){
        if(root==null || root.left== null )
            return null;
        Node temp = root.left;
        if(root.right!=null){
            //maxLeft            
            while(temp.right!=null)
                temp = temp.right;
        }
        return temp.val;
    }
    public void reverse(Node currRoot){
        if(currRoot==null)
            return;        
        reverse(currRoot.left);
        reverse(currRoot.right);
        //swap pointers
        Node temp = currRoot.left;
        currRoot.left = currRoot.right;
        currRoot.right = temp;
        
    }
    public void traverse_preOrder_VLR(Node currRoot){
        if(currRoot==null)
            return;
        currRoot.dispNode();
        traverse_preOrder_VLR(currRoot.left);
        traverse_preOrder_VLR(currRoot.right);
        
    }
    public void traverse_inOrder_LVR(Node currRoot){
        if(currRoot==null)
            return;        
        traverse_inOrder_LVR(currRoot.left);
        currRoot.dispNode();
        traverse_inOrder_LVR(currRoot.right);
        
    }
    public void traverse_postOrder_LRV(Node currRoot){
        if(currRoot==null)
            return;        
        traverse_postOrder_LRV(currRoot.left);
        traverse_postOrder_LRV(currRoot.right);
        currRoot.dispNode();
        
    }
       
    public Node removeLeaves(Node currRoot){        
        if(currRoot==null)
            return null;
        if(currRoot.left==null && currRoot.right==null)
            return null;
        currRoot.left = removeLeaves(currRoot.left);        
        currRoot.right = removeLeaves(currRoot.right);        
        return currRoot;        
    }  
  
    
}
