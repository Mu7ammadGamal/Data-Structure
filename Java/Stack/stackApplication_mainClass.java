package stack;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;

public class stack_mainClass {
    //https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/
    
    public static void evenSubArray(){
        listStack s = new listStack();
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        for(int i=str.length()-1;i>=0;i--){
            
            if(s.getTop()==null  || (char)s.getTop()!=str.charAt(i)){
                s.push(str.charAt(i));
            }
            else{
                s.pop();
            }
        }
        if(s.isEmpty())
            System.out.println("KHALI");
        else
            System.out.println(s.StacktoString());        
    }
    
    public static void game_ofNumbers(){
        
    }
    public static boolean isPair(char l,char r){
        return(l=='['&&r==']' ||l=='('&&r==')'||l=='{'&&r=='}');       
    }
    public static boolean isLPair(char l){
        return(l=='['||l=='('||l=='{');      
       
    }
    public static void balanced_Brackets(){
        Stack s = new Stack();
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        for(int i=0;i<str.length();i++){
            if(isLPair(str.charAt(i))){
                s.push(str.charAt(i));                                
            }
            else{                    
                if(!s.isEmpty() && isPair((char)s.peek(),str.charAt(i)))
                    s.pop();                    
                else{
                    System.out.println("NO");
                    return;
                }
                
            }
        }
        if(s.isEmpty())
            System.out.println("Yes");
        else
            System.out.println("NO");
//        int i=0;
//        for(i=0;i<str.length();i++){
//            char c = str.charAt(i);
//            if(c=='[' || c=='{' ||c=='('){
//                s.push(c);
//            }
//            else
//            {
//                if(!s.isEmpty() && isPair((char)s.getTop(), c)){
//                    s.pop();
//                }
//                else{
//                    System.out.println("NO");
//                    return;
//                }
//            } 
//            }           
//        
//        if(s.isEmpty())
//            System.out.println("YES");
//        else
//            System.out.println("NO");       
    }
    public static void capillary_Game(int x){
        String res="";
        listStack A = new listStack();
        while(x>0){
            A.push(x);
            x--;
        }
        listStack B = A.reverse();        
        while(!A.isEmpty() && !B.isEmpty()){
            if((int)A.getTop()>(int)B.getTop()){
                res+='1';
                B.pop();
            }
            else if((int)A.getTop()<(int)B.getTop()){
                res+='2';
                A.pop();
            }
            else{
                res+='0';
                A.pop();
                B.pop();
            }
        }
        System.out.println(res);
     }
    
    public static void reverse_word(){
        Stack s = new Stack();
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        //str+=' ';        
        String res="";       
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)!=' ') 
               s.push(str.charAt(i));
            else{
                while(!s.empty()){
                    res += (char)s.pop();
                }
                res+=' ';
            }            
        }
        while(!s.empty()){
            res += (char)s.pop();
        }            
        System.out.println(res);
        

//        for(int i=0;i<=str.length();i++){
//            if(i==str.length() || str.charAt(i)==' '){
//                while(!s.empty()){
//                res += (char)s.pop();
//                }
//                res+=' ';
//            }
//            else{
//                s.push(str.charAt(i));
//            }           
//            
//        }
//        System.out.println(res);
        
        
        
        
        
    }
    public static void main(String[] args) {
        //p1
        //evenSubArray();
        //p2
        //game_ofNumbers();
        //p3
        balanced_Brackets();
        //p4
        //capillary_Game(3);
        //p5
        //reverse_word();
        
        
        
        





















//        listStack s = new listStack();        
//        arrayStack s = new arrayStack(6);
//        s.push(5);        
//        s.push(2);
//        s.push(8);
        
//        s.push(1);
//        s.push(9);
//        s.push(7);        
//        s.disp();
//        s = s.reverse();
//        arrayStack s2 = new arrayStack(6);
//        s2.copy(s);        
//        s2.disp();
//        listStack s2 = s.reverse();        
//        s = s2.copy();
//        s = s.reverse();
//        s2.disp();
        
    }
    
}
