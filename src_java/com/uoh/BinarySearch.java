package com.uoh;

import java.util.Scanner;

/**
 * Created by Prasad Bhavana (17MCPC14) on 8/9/2017.
 *
 * For algorithms assignment: demonstration of O(n log n)
 */
public class BinarySearch {

    // array containing the list of elements
    static int[] items;

    /*
       Search method that returns 0 : if the value is not found in the array
                          returns n : position (index+1) of the value, if the value is found
     */
    public static int search(int val)
    {
        int left = 0;
        int right = items.length;

        do{
            int pivot = (left + right)/2;

            System.out.println("Left Index: "+left+", Pivot: "+pivot+", Right Index:"+right);

            if(items[pivot] == val)
            {
                return pivot+1;
            }
            else if(items[pivot] > val)
            {
                right = pivot-1;
            }
            else{
                left = pivot+1;
            }

        }
        while(left>=0 & right>=0 & left < items.length & right < items.length);

        return 0;
    }

    /*
        Initialize the array of given size with sequence numbers
     */
    public static void init(int count)
    {
        items = new int[count];
        for(int i=0; i <count; i++)
        {
            items[i] = i;
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

        System.out.println("Please enter the element to search : ");
        String searchStr = in.nextLine();
        int searchKey = 0;
        try{
            searchKey = Integer.parseInt(searchStr);
        }catch (Exception ex){
            System.err.println("Invalid search key.");
            System.exit(-1);
        }

        // initialize the array with random elements
        init(count);

        System.out.println("Searching "+searchStr+ " out of "+countStr+ " random elements..");

        long beforeSearch = System.currentTimeMillis();

        System.out.println("Search Result :"+search(searchKey));

        System.out.println("Time taken (milli seconds) for search:"+ (System.currentTimeMillis() - beforeSearch));
    }

}
