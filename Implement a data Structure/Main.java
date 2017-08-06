//package com.company;
import java.lang.*;

/*  Date  : 2017.03.04
    Title : Data Structures and Algorithms-Lab 04

    This is the implementation for the Linked List using java and it is a type-safe implementation using java generics
    Here are test cases for the String and Integers
    It can be extended to test other types also.
 */

public class Main {

    public static void main(String[] args) {

        // test the linked list implementation

        // 1. check the list for Strings
        System.out.println();
        System.out.println("*******  CHECK FOR STRINGS  ********");
        System.out.println();
        MyList<String> list1=new MyList<String>();    // define a list

        // check the empty list
        System.out.println("Check for empty linked list:");
        list1.print_all_data();
        System.out.println("Check the list is empty:");
        System.out.println(list1.isEmpty());

        System.out.println(".........................................");
        System.out.println();

        System.out.println("Add the String data to list:");
        list1.add("malitha");
        list1.add("dilshan");
        list1.add("kumarasiri");
        list1.add("ishara");
        System.out.println("list has following data");
        list1.print_all_data();
        System.out.println("number of nodes in the list: " + list1.getCount());

        System.out.println(".........................................");
        System.out.println();

        System.out.println("Check the list is empty:");
        System.out.println(list1.isEmpty());

        System.out.println(".........................................");
        System.out.println();

        System.out.println("Remove the top element from the list:");
        String name=list1.remove();
        System.out.println("The removed data is a:  " + name);
        System.out.println("Rest of the elements in the list: ");
        list1.print_all_data();

        System.out.println();

        // 1. check the list for Integers
        System.out.println("*******  CHECK FOR INTEGERS  ********");
        System.out.println();
        MyList<Integer> list2=new MyList<Integer>();    // define a list

        // check the empty list
        System.out.println("Check for empty linked list:");
        list2.print_all_data();
        System.out.println("Check the list is empty:");
        System.out.println(list2.isEmpty());

        System.out.println(".........................................");
        System.out.println();

        System.out.println("Add the Integer data to list:");
        list2.add(10);
        list2.add(20);
        list2.add(30);
        list2.add(40);
        list2.add(50);
        System.out.println("list has following data");
        list2.print_all_data();
        System.out.println("number of nodes in the list: " + list2.getCount());

        System.out.println(".........................................");
        System.out.println();

        System.out.println("Check the list is empty:");
        System.out.println(list2.isEmpty());

        System.out.println(".........................................");
        System.out.println();

        System.out.println("Remove the top element from the list:");
        int name1=list2.remove();
        System.out.println("The removed data is a:  " + name1);
        System.out.println("Rest of the elements in the list: ");
        list2.print_all_data();

        // you can test the code other test cases also....
    }
}
