

/*
Author : E/13/200
Title  : Lab 05  - Create a sparse matrix implementation

    Here I use a HashMap to store the value that not equal to zero, by calculate the unique positions of that relevant values.
    Then HashMap have used to uniquely identify the positions of that vale and return it.
 */


import java.util.HashMap;


public class SparseMatrix {

    private static HashMap<Integer,Integer> structure ;
    private int size=0;

    // create an empty square matrix of given size
    public void createEmptyMatrix(int size1){
        this.size=size1;

        if(size<=0)
            System.out.println("the size in not valid ");
        else
            structure=new HashMap<>();  // initiallize the empty hash map

    }

    public void set(int i, int j,int value){
        int count;
        if(value != 0){

            count=size*i+j+1;     // map the matrix positions to relevalnt position number(for squre matrix)
            structure.put(count,value);   // only add value that not eqaul to zero
        }

    }

    public int get(int i, int j) {
        //System.out.println(structure);
        boolean has_value=false;
        int return_value=0;
        int return_count=size*i+j+1;

        if(structure.get(return_count) != null) // check whether hash map has the relevant value and update the has_value
            has_value=true;

        if(has_value)      // if there is a value corresponding to the value this will return the value to the Main class else return zero
            return_value=structure.get(return_count);


        return return_value;

    }



}