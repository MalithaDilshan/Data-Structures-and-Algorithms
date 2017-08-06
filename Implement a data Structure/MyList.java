//package com.company;

/**
 * Created by 14LAP on 4/3/2017.
 */
public class MyList<T> {

    private Node<T> head;          // pointing to the head
    private int count;     // count the number of Nodes

    public void add(T data){

        Node<T> node1= new Node<T>(data); // create a new node
        if(head==null)
            head=node1;

        else{
            node1.setNext(head);   // set the head as the next node
            head=node1;            // set the current head
        }
        count++;

    }

    public boolean isEmpty(){
        return head==null;      // check the head , if the head is null then the list is empty
    }

    public boolean hasElement(){  // this is the inverse of the isEmpty() method implementation
        if(isEmpty())
            return false;
        else
            return true;
    }

    public T remove(){         // remove the node from the list
        Node<T> temp;
        temp = head;

        if(!isEmpty()) {

            if (head.getNext() != null) {
                head = null;
                head = temp.getNext();    // get the next element in the list
            } else
                head = null;
            count--;             // decrement the count
            return temp.getData();      // return the removed element/data
        }
        else
            return null;

    }

    public void print_all_data() {     // print the data of each nodes in the linked list

        if (count == 0) System.out.println("There is no any data");
        else {
            Node<T> temp_node =head;
            int mycount=0;
            while (temp_node != null && mycount<=count) {
                System.out.println(temp_node.getData());
                temp_node=temp_node.getNext();
                mycount++;
            }
        }
    }

    public int getCount(){      // get the number of nodes in the list
        return count;
    }

}

// define the node class
class Node<T>{

    private T data;
    private  Node<T>  next;

    public Node( T data){
        this.data=data;
        next=null;
    }

    public T getData(){
        return data;
    }

    public void setNext(Node<T> node){
        this.next=node;
    }

    public Node<T> getNext(){
        return next;
    }

    
}
