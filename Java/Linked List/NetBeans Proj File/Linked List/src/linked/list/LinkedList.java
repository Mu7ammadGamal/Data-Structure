package linked.list;
import java.util.*;
public class LinkedList {    
    public static void main(String[] args) {
        linked_List l = new linked_List();
//        l.insertFirst(5);
//        l.insertFirst(4);
//        l.insertFirst(3);
//        l.insertEnd(6);
//        l.insertEnd(7);
//        l.display();
//        //l.find(3);
//        l.delete(11);
//        l.deleteEnd();
//        l.deleteEnd();
//        l.deleteEnd();
//        l.deleteEnd();
//        l.deleteEnd();        
//        l.insertEnd(0);
        l.insertSorted(9);
        l.insertSorted(4);
        l.insertSorted(3);
        l.insertSorted(8);
        l.insertSorted(0);
        l.insertSorted(5);
        l.insertSorted(5);
        l.insertSorted(8);
        l.insertSorted(8);
        l.insertSorted(1);
        l.display();
        
        
    }
    
}
