package stack;

public class arrayStack {        
    private Object[] s;
    private int size;
    private int top=-1;  

    public arrayStack(int size) {
        this.size = size;
        s = new Object[size];
    } 
    public boolean isFull(){
        return (top == size-1); 
    }
    public boolean isEmpty(){
        return (top == -1); 
    }
    public void push(Object val){       
        if(!isFull()){
            s[++top]=val;
        }
        else{
            System.out.println("Stack overflow");
        }        
    }
    public Object pop(){
        if(!isEmpty()){
            Object temp = s[top--];
            return temp;
        }
        else{
            System.out.println("Stack is empty");
            return -1;
        }       
    }
    
    public arrayStack reverse(){
        arrayStack temp = new arrayStack(this.size);
        for(int i=top;i>=0;i--){
            temp.push(s[i]);
        }              
        return temp;
    }    
    public void copy(arrayStack s1){        
        for(int i=0;i<=s1.top;i++){
            this.push(s1.s[i]);           
        }
        
        
    } 
    
    public void disp(){
        if(!isEmpty()){
          for(int i=top;i>=0;i--){
            System.out.print(s[i]+" ");
          }
          System.out.println();
        }
        else{
            System.out.println("Stack is empty");           
        }       
        
    }
}
