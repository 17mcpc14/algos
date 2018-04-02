package com.uoh;

import java.util.Scanner;
import java.util.Stack;

/**
 * Created by Prasad Bhavana (17MCPC14) on 8/10/2017.
 *
 * During Data-structures lab: brute force Prefix to Postfix conversion
 */
public class Prefix2Postfix {

    // prefix expression
    static String expression;

    // stacks to store operations and operands
    static Stack operatorStack = new Stack();
    static Stack operandStack = new Stack();

    /*
        Method to read user-input expression and generate operand, operations stacks
     */
    private static void readExpression(String str)
    {
        for(int i=0; i<str.length(); i++)
        {
            char c = str.charAt(i);
            if(c == ' ' )
            {
            }
            else if ( c == '(')
            {

                String enclosedExpression = str.substring(i+1, str.indexOf(')', i));

                operatorStack.push("(");

                readExpression(enclosedExpression);

                operatorStack.push(")");

                i = str.indexOf(")", i);
            }
            else if(c == '+' || c == '-' || c == '*' || c == '/' )
            {
                operatorStack.push(""+c);
            }
            else{
                operandStack.push(""+c);
            }
        }

    }

    /*
        Method to generate post-fix expression using data from operands, operations stacks
     */
    private static void popExpression()
    {
        String operation = (String) operatorStack.pop();
        if(operation.equals(")"))
        {
            System.out.print("(");
            popExpression();

            if(operatorStack.empty())
            {
                System.err.println("Invalid Expression!");
            }

            String operation2 = (String) operatorStack.pop();
            if(!operation2.equals("("))
            {
                System.out.println();
                System.err.println("Invalid expression!");
                return;
            }
            System.out.print(")");
        }
        else{
            if(operandStack.empty())
            {
                System.out.print(""+ operation);
            }
            else{
                String o1 = (String) operandStack.pop();

                if(!operandStack.empty())
                {
                    String o2 = (String) operandStack.pop();
                    System.out.print(""+ o2 );
                }

                System.out.print(" "+ o1+ " "+operation);
            }
        }

    }

    /*
        Helper method to print post-fix expression
     */
    private static void writeExpression()
    {
        while(!operatorStack.empty())
        {
            popExpression();
        }

    }

    /*
        Program execution entry point method
           - does not take any command line arguments
           - prompts for user input
     */
    public static void main(String[] args) {

        Scanner in = new Scanner (System.in);

        System.out.println("Enter the prefix expression : ");
        expression = in.nextLine();

        System.out.println("Prefix Expression:"+expression);

        readExpression(expression);

        System.out.println("Operator Stack:"+operatorStack);

        System.out.println("Operand Stack:"+operandStack);

        System.out.println();
        System.out.print("Postfix Expression:");

        writeExpression();

        System.out.println();

        if(!operatorStack.empty() || !operandStack.empty())
        {
            System.err.println("Invalid input expression!!");
        }
    }

}
