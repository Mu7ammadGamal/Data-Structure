package linked.list;
public class linked_List {    
    private int size;
    private Node first;
    private Node end;    
    
    public boolean isEmpty(){        
        return first==null;
    }
    
    public void insertFirst(int val){        
        Node newNode = new Node(val);
        if(isEmpty()){
            first = newNode;
            end = newNode;
        }
        else{
            newNode.next = first;
            first = newNode;
        }
        
    }
    public void insertEnd(int val){        
        Node newNode = new Node(val);        
        if(isEmpty()){
            first = newNode;
            end = newNode;
        }        
        else{            
            end.next = newNode;            
            end = newNode;
        }
    }
    public void deleteFirst(){        
        if(isEmpty()){
            System.out.println("List is EMPTY to DELETE at FIRST");
        }
        else{        
        Node temp = first; 
        first = temp.next;
        temp.next = null;
        }        
    }
    
    private Node getPrev(){        
        Node prev = first;
        while(prev.next!=end){
            prev=prev.next;
        }        
        return prev;
    }
    public void deleteEnd(){        
        if(isEmpty()){
            System.out.println("List is EMPTY to DELETE at END");
        }
        
        else if(first.next == null){ //size ==1
            first = null;
            end = null;
        }
        
        else
        {
            Node prev = getPrev();
            end = prev;
            prev.next = null;
            
        }
    }
    public void insertSorted(int val){
        if(isEmpty())
            insertFirst(val);           
        else if(val<first.val)
            insertFirst(val);
        else if(val>end.val)
            insertEnd(val);
        else{
            Node newNode = new Node(val);
            Node temp = first;
            while(temp.next!=null && !(temp.val<= val && temp.next.val>=val)){
                temp = temp.next;
            }
            newNode.next = temp.next;
            temp.next = newNode;
            
            
        }
    }
    public void display(){        
        if(isEmpty())
        {
            System.out.println("List is EMPTY to Display");
            return;
        }        
        for(Node temp = first;temp!=null;temp=temp.next){
            temp.disp();
        }
        System.out.println("");
    }
    
    public int getSize(){ 
        return size;
    }   
    
    public Node find(int key){              
        for(Node temp = first;temp!=null;temp=temp.next){
            if(temp.val == key){
                System.out.println(key +" is FOUND!");
                return temp;
            }        
        }
        System.out.println(key +" is NOT FOUND!");
        return null;        
    }
    
    public void delete(int key){              
        Node endTemp = end;
        end = find(key);
        if(end!=null){
            Node prev = getPrev();
            prev.next = end.next;
            end.next = null;
        }                
        end = endTemp;
    }
    
    
    
    
        
        
            
}
    
    

