
package circular_queue;

public class Circular_Queue {
    
    public static void main(String[] args) {

    CircularQueue q = new CircularQueue(6);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);    
    q.disp();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.disp();
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);    
    q.disp();
    
    
    
    }
    
}
