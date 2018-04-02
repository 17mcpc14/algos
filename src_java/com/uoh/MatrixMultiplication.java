package com.uoh;

import java.util.Scanner;

/**
 * Created by Prasad Bhavana (17MCPC14) on 8/9/2017.
 *
 * For algorithms assignment: demonstration of O(n * n * n)
 */
public class MatrixMultiplication {

    // pre-initialized matrix-1
    static int[][] m1 = { {0,0,0,0,0},
                          {1,1,1,1,1},
                          {0,0,0,0,0}};

    // pre-initialized matrix-2
    static int[][] m2 = { {1,1,1},
            {2,2,2},
            {3,3,3},
            {4,4,4},
            {5,5,5}};

    // array to store matrix multiplication result
    static int[][] result;

    // flag to display tables as they get multiplied
    static String debugStr;

    /*
       Method to multiply two matrices using brute force approach
            - Order of the algorithm: O(n*n*n)
     */
    public static void multiply()
    {
        int x = m1.length;
        int y = m1[0].length;
        int z = m2[0].length;

        if(debugStr.equalsIgnoreCase("y")) {
            System.out.println("\nx:" + x + ",y:" + y + ",z:" + z);
        }

        result = new int[x][z];

        if(debugStr.equalsIgnoreCase("y")) {
            System.out.println("Result Matrix:\n");
        }

        for(int i=0; i<x; i++)
        {
            System.out.println();

            for(int j=0; j<z; j++)
            {
                int sum = 0;
                for(int k=0; k<y; k++)
                {
                    sum += m1[i][k] * m2[k][j];
                }
                result[i][j] = sum;

                if(debugStr.equalsIgnoreCase("y")) {
                    System.out.print(result[i][j] + " ");
                }
            }
        }
    }

    /*
        Helper method to initialize the matrices with given size of random numbers
     */
    public static void init(int count)
    {
        m1 = new int[count][count];
        m2 = new int[count][count];

        for(int i=0; i<count; i++)
        {
            for(int j=0; j<count; j++)
            {
                m1[i][j] = (int) (Math.random()*1000);
                m2[i][j] = (int) (Math.random()*1000);
            }
        }

    }

    /*
        Program execution entry point method
           - does not take any command line arguments
           - multiplies pre-defined matrices and displays the result
     */
    public static void main(String args[])
    {
        Scanner in = new Scanner (System.in);
        System.out.println("Please enter the number of random elements needed : ");
        String countStr = in.nextLine();
        int count = 0;
        try{
            count = Integer.parseInt(countStr);
        }catch (Exception ex){
            System.err.println("Invalid count");
            System.exit(-1);
        }

        // initialize the array with random elements
        init(count);

        System.out.println("Print the items as they are multiplied (y/n) : ");
        debugStr = in.nextLine();

        long beforeSort = System.currentTimeMillis();
        multiply();
        System.out.println("\nTime taken (milli seconds) for multiplication:"+ (System.currentTimeMillis() - beforeSort));
    }
}
