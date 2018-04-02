package com.uoh;

import java.util.*;

/**
 * Created by Prasad Bhavana (17MCPC14) on 8/12/2017.
 *
 * For Algorithms assignment: demonstration of O( 2 pwr n) using recursive approach
 */
public class ChainedMatrixMultiplication {

    // list of matrices to multiply
    static List<Matrix> matrixArray = new ArrayList<Matrix>();

    /*
        Method that recursively finds optimal solution for multiplication of matrices
              - Finds optimal # of multiplication computations
              - Finds partitioning for a given set of matrices
     */
    private static KeyVal findOptimal(int position)
    {
        if(position >= matrixArray.size()) {
            return new KeyVal("", 1);
        }else if(position == matrixArray.size()-1) {
            return new KeyVal(genKey( new Matrix[]{matrixArray.get(position)}, ""), matrixArray.get(position).x * matrixArray.get(position).y);
        }

        KeyVal solution = findOptimal(position+1);
        long cost = matrixArray.get(position).x * solution.value;

        KeyVal solution2 = findOptimal(position+2);
        long cost2 = matrixArray.get(position).x * matrixArray.get(position).y* matrixArray.get(position+1).y*solution2.value;

        if(cost < cost2) {
           return new KeyVal(genKey( new Matrix[]{matrixArray.get(position)},solution.key), cost);
        }else {
           return new KeyVal(genKey(new Matrix[]{matrixArray.get(position) , matrixArray.get(position+1)}, solution2.key), cost2);
        }
    }

    /*
        Helper method to generate the matrix multiplication expression
     */
    private static String genKey(Matrix[] list, String str)
    {
        String key = "";

        if(list.length > 0){
            key = ""+list[0].name;
        }
        if(list.length == 2){
            key = "("+ key + "*"+ list[1].name+")";
        }

        if(!str.equals("")) {
            key = "(" + key + "*" + str + ")";
        }

        return key;
    }

    /*
        Helper method to initialize the matrices with given size of random numbers
     */
    public static void init(int count)
    {
        // place holder to store previous matrix X value
        int x = (int) (Math.random()*1000);
        for(int i=0; i<count; i++)
        {
            int y = (int) (Math.random()*1000);
            Matrix m = new Matrix("Auto"+i,x, y );
            matrixArray.add(m);
            x = y;
        }
    }

    /*
        Helper method to take user input and initiliaze the run
     */
    private static void handleUserInput()
    {
        Scanner in = new Scanner (System.in);

        System.out.println("Auto initilize the matrices for a specified count ? (y/n) : ");
        String debugStr = in.nextLine();

        if(debugStr.equalsIgnoreCase("y")) {
            System.out.println("Please enter the number of random elements needed : ");
            String countStr = in.nextLine();
            int count = 0;
            try {
                count = Integer.parseInt(countStr);
            } catch (Exception ex) {
                System.err.println("Invalid count");
                System.exit(-1);
            }

            // initialize the array with random elements
            init(count);
        }
        else {

            System.out.println("Enter each matix name, length, width (one matrix per line). Hit enter once done!");

            while (true) {

                String matrix = in.nextLine();
                if (matrix.trim().equals("")) {
                    break;
                }

                StringTokenizer tokens = new StringTokenizer(matrix, " ");
                try {
                    Matrix m = new Matrix(tokens.nextToken(), Integer.parseInt(tokens.nextToken()), Integer.parseInt(tokens.nextToken()));
                    if (tokens.hasMoreTokens()) {
                        System.out.println("Ignored additional token.");
                    }

                    if (matrixArray.size() > 0 && matrixArray.get(matrixArray.size() - 1).y != m.x) {
                        System.out.println("X value of current matix is not matching with Y value of previous matrix. Input ignored!");
                        continue;
                    }

                    matrixArray.add(m);

                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.err.println("Invalid matrix! Input ignored.");
                }
            }
        }
    }

    /*
        Program execution entry point method
           - does not take any command line arguments
           - prompts for user input
     */
    public static void main(String args[])
    {
        handleUserInput();

        long beforeTime = System.currentTimeMillis();
        KeyVal sol = findOptimal(0);

        System.out.println("Optimal expression:"+sol.key+" , cost:"+sol.value+" , time taken(milli seconds):"+(System.currentTimeMillis() - beforeTime));
    }
}

/*  Inner class: Matrix representation
 *               Contains length and width of matrix
 *               Also contains name of the matrix for the sake of re-call
 */
class Matrix{
    long x;
    long y;
    String name;
    List<List<Integer>> data;

    Matrix(String name, int x, int y)
    {
        this.name = name;
        this.x = x;
        this.y = y;
    }
}

/*  Inner class: Key, Value pair representation
 *               Contains string key
 *               and long value
 */
class KeyVal {

    String key;
    long value;

    KeyVal(String key, long value) {
        this.key = key;
        this.value = value;
    }
}
