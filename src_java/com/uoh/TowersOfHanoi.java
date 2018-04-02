package com.uoh;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Prasad Bhavana (17MCPC14) on 8/12/2017.
 *
 * For Algorithms assignment: demonstration of O( 2 pwr n) using recursive approach
 */
public class TowersOfHanoi {

    // array to represent towers of integers
    static ArrayList<Integer> tower1 = new ArrayList<Integer>();
    static ArrayList<Integer> tower2 = new ArrayList<Integer>();
    static ArrayList<Integer> tower3 = new ArrayList<Integer>();

    /*
        Method that recursively moves n elements from one tower to another using a spare tower
     */
    private static void move(ArrayList<Integer> from, int fromTower, ArrayList<Integer> to, int toTower, ArrayList<Integer> temp, int tempTower, int count)
    {
        if(count > 1) {
            move(from, fromTower, temp, tempTower, to, toTower,count - 1);
        }

        //System.out.println("Move item#"+from.get(from.size()-1)+" from tower#"+fromTower+" to tower#"+toTower);
        to.add(to.size(), from.get(from.size()-1));
        from.remove(from.size()-1);

        if(count > 1) {
            move(temp, tempTower, to, toTower, from, fromTower,count - 1);
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
        System.out.println("Enter the tower size : ");
        String towerSize = in.nextLine();
        int towerHeight = 0;
        try{
            towerHeight = Integer.parseInt(towerSize);
        }
        catch (Exception ex){
            System.err.println("Invalid tower height");
            System.exit(-1);
        }

        // initialize tower1 as per input height
        for(int i=towerHeight; i >0; i--) {
            tower1.add(i);
        }

        //System.out.println("Initial state:");
        //System.out.println("Tower #1: "+ tower1);
        //System.out.println("Tower #2: "+ tower2);
        //System.out.println("Tower #3: "+ tower3);

        long beforeTime = System.currentTimeMillis();
        move(tower1, 1, tower2, 2, tower3, 3, tower1.size());

       // System.out.println("Final state:");
        //System.out.println("Tower #1: "+ tower1);
        //System.out.println("Tower #2: "+ tower2);
        //System.out.println("Tower #3: "+ tower3);

        System.out.println("Total time taken :"+(System.currentTimeMillis() - beforeTime));
    }
}
