package com.uoh;

import java.util.Scanner;

/**
 * Created by user on 8/9/2017.
 */
public class QuickSort {

    // array containing the list of elements
    static int[] items;

    /*
         Sort method that returns void once the sorting is complete
     */
    public static void sort(int low, int high)
    {
        if(low >= high) return;

        int pivot = partition(low, high);

        sort(low, pivot-1);

        sort(pivot+1, high);

    }

    /*
        Partion the array with boundaries low, high
            - Partitioning based on pivot element located at position before the process
            - Once complete the pivot element is moved to its correct position;
                All elements <= pivot are moved to the left of pivot's position
                All elements > pivot are moved to the right of pivot's position
            - Returns the position of pivot element back to the calling program
     */
    public static int partition(int low, int high) {

        // tracking index of all items lower than pivot
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            // if an item is lower than pivot, move it to tracking index and adjust tracker
            if(items[j] <= items[high])
            {
                i++;
                swap(i, j);
            }
        }

        // move pivot element to the right position
        i++;
        swap(i, high);

        loopInvariant(low, high, i);

        // return position of the pivot element
        return i;
    }

    /*
        Loop invariant checker
            - takes boundaries, pivot position as input
            - checks if all items below pivot are smaller or equal
            - checks if all items above pivot are bigger than or equal
     */
    private static boolean loopInvariant(int low, int high, int pivot)
    {
        for(int i=low; i<pivot; i++)
        {
            if(items[i] > items[pivot])
            {
                System.err.println("Loop invariant failure!");
                return false;
            }
        }
        for(int i=pivot; i<high; i++)
        {
            if(items[i] < items[pivot])
            {
                System.err.println("Loop invariant failure!");
                return false;
            }
        }
        return true;
    }

    /*
        Helper method to elements with positions x,y in the array
     */
    private static void swap(int x, int y)
    {
        int temp = items[y];
        items[y] = items[x];
        items[x] = temp;
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

        sort(0, count-1);

        System.out.println();
        if(debugStr.toLowerCase().startsWith("b") || debugStr.toLowerCase().startsWith("y")) {
            System.out.print(" After sort : ");
            printItems();
        }

        System.out.println("Time taken (milli seconds) for search:"+ (System.currentTimeMillis() - beforeSort));
    }
}
