package com.uoh;

import java.util.Scanner;

/**
 * Created by Prasad Bhavana (17MCPC14) on 8/12/2017.
 *
 * For algorithms assignment: demonstration of O(n * n)
 */
public class BubbleSort {

    // array containing items to sort
    static int[] items;

    /*
         Sort method that returns void once sorting is complete
    */
    public static void sort()
    {

        for(int i=0; i<items.length; i++)
        {
            for(int j=0; j<(items.length - i - 1); j++)
            {
                if(items[j] > items[j+1])
                {
                    int temp = items[j+1];
                    items[j+1] = items[j];
                    items[j] = temp;
                }
            }

            // loop invariant check
            loopInvariant(i);
        }

    }

    /*
        Loop invariant checker
            - takes loop number as input
            - checks if all items below loop number are smaller or equal
            - checks if all items above loop number are bigger than or equal
     */
    private static boolean loopInvariant(int i)
    {
        for(int j=0; j<(items.length-i); j++)
        {
            if(items[j] > items[items.length-i-1])
            {
                System.err.println("\nLoop invariant failure! Loop #"+(i+1));
                printItems();
                return false;
            }
        }

        return true;
    }

    /*
        Helper method to display the items in the array
     */
    public static void printItems()
    {
        for(int i=0; i < items.length; i++)
        {
            System.out.print(" "+items[i]+" ");
        }

    }

    /*
        Initialize the array of given size with random numbers
     */
    public static void init(int count)
    {
        items = new int[count];
        for(int i=0; i <count; i++)
        {
            items[i] = (int) (Math.random()*1000);
        }
    }

    /*
        Program execution entry point method
           - does not take any command line arguments
           - prompts for user input
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

        System.out.println("Print the items before/after/both times (b/a/y) : ");
        String debugStr = in.nextLine();

        System.out.println("Sorting the array of random elements..");

        if(debugStr.toLowerCase().startsWith("b") || debugStr.toLowerCase().startsWith("y")) {
            printItems();
        }

        long beforeSort = System.currentTimeMillis();

        sort();

        System.out.println();
        if(debugStr.toLowerCase().startsWith("b") || debugStr.toLowerCase().startsWith("y")) {
            System.out.print(" After sort : ");
            printItems();
        }
        System.out.println();
        System.out.println("Time taken (milli seconds) for search:"+ (System.currentTimeMillis() - beforeSort));
    }
}
