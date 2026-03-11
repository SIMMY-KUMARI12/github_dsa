import java.util.*;
public class Main{
    public class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
        }
    }
    public class LinkedList{
        Node head=null;
        Node tail= null;
        // different methiods of linked list
        void insertAtBegininig(int value){
            Node n= new Node(value);
            if(head==null){
                // that means the linkedlist is empty
                head=n;
            }
            else{
                n.next=head;
                head=n;
            }
        }
        void insertEnd(int value){
            Node n= new Node(value);
            if(head==null){
                // that means the linkedlist is empty
                head=n;
            }
            else{
                Node temp=head;
                while(temp.next!=null){
                    temp=temp.next;
                }
                
            } 
        }
        
    }
public static void main(String[] args){

}
}