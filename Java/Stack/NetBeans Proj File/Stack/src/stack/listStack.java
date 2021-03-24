package stack;
import java.util.LinkedList;
public class listStack {    
    private LinkedList<Object> s = new LinkedList<>();
    
    public void push(Object val){
        s.addFirst(val);
    }
    
    public Object pop(){
        return s.removeFirst();
    }
    public Object getTop(){
        return s.peek();
    }
    
    public listStack reverse(){
        listStack temp = new listStack();
        for(Object i :s ){
            temp.push(i);
        }        
        return temp;
    }
    public listStack copy(){
        listStack temp = this.reverse();
        return temp.reverse();     
        
    } 
    
    public String StacktoString(){
        String st="";
        for(Object i :s){            
            st+=i.toString();
        }
        return st; 
    }
    public void disp(){        
        for(Object i :s){
            System.out.print(i+" ");           
        }
        System.out.println();
        
    }
    public boolean isEmpty(){
        return (s.peekFirst() == null); 
    }
    
    
}
