package circular_queue;
public class CircularQueue {
    private int size;
    private int n=0; //length / no of elements  
    private int head,tail;
    private Object[] arr;
    public CircularQueue(int size) {
        this.size = size;
        this.head = size-1;
        this.tail = size-1;
        arr = new Object[size];
    }   
    
    public boolean isFull(){
        if(n==size)
            return true;
        else
            return false;
    }
    
    public void enQueue(Object val){        
        //System.out.println("n: "+n);
        if(n==0)
        {
            head = (head+1)%size;            
            tail = (tail+1)%size;            
            arr[tail] = val;
            n++;
        }
        
        else if(n>0 && !isFull()){
            tail = (tail+1)%size;
            arr[tail] = val;
            n++;
        }
        else if(isFull()){
            System.out.println("FULL");
        } 
        //System.out.println("head: "+head);
        //System.out.println("tail: "+tail);
        
        
    }
    public Object deQueue(){
        Object temp = null;
        if(n==0)
        {
            System.out.println("EMPTY");
        }        
        else if(n>0){
            temp = arr[head];
            head = (head+1)%size;             
            n--;            
        }        
        
        return temp;
        
    }
    public void disp(){
        if(n==0){
            System.out.println("EMPTY");
            return;
        }        
        int i;
        for(i = head;i!=tail;i=(i+1)%size){
            System.out.print(arr[i]+" ");           
        }        
        System.out.println(arr[tail]);
    }
    
    
}
