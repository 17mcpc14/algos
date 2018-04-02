package com.uoh;

import com.sun.xml.internal.ws.util.StringUtils;

import java.util.Scanner;

/**
 * Created by Prasad Bhavana (17MCPC14) on 8/10/2017.
 *
 * For Data-structures lab assignment: Tree based approach to Prefix to Postfix conversion
 */
public class Prefix2PostfixTree {

    /*
        Program execution entry point method
           - does not take any command line arguments
           - prompts for user input
           - validates the expression for matching number of left, right braces
     */
    public static void main(String[] args) {

        Scanner in = new Scanner (System.in);
        System.out.println("Enter the prefix expression : ");
        String expression = in.nextLine();

        if(countMatches(expression, '(') != countMatches(expression, ')') )
        {
            System.err.println("Invalid expression!");
            System.exit(-1);
        }

        BinaryTreeNode expressionTree = new BinaryTreeNode(expression);
        expressionTree.readPrefix();

        System.out.println("Postfix Expression:");
        expressionTree.printPostfix();
    }

    /*
        Method to count the number of occurrences of a char in a string
     */
    private static int countMatches(String expression, char ch)
    {
        int count = 0;
        for(int i=0; i < expression.length(); i++)
        {
            if(expression.charAt(i) == ch)
            {
                count++;
            }
        }
        return count;
    }
}

/*  Inner class: Binary tree implementation
 *               Each node contain an operation or single operand as its data elements
 *               If node represents a sub-expression, the data element is an operation
 *                  and the left, right nodes contain operands or sub-expressions
 */
class BinaryTreeNode {

    public BinaryTreeNode left;
    public BinaryTreeNode right;
    private String data;

    /*
        Constructor: takes the expression as input
                     and sanitizes the data
                     validates the expression for closing brace
     */
    public BinaryTreeNode(String data) {

        data = data.replaceAll("\\*", " * ");
        data = data.replaceAll("\\+", " + ");
        data = data.replaceAll("-", " - ");
        data = data.replaceAll("/", " / ");
        data = data.replaceAll("  ", " ");

        data = data.trim();
        if(data.charAt(0) == '(')
        {
            if(data.charAt(data.length()-1) != ')') {
                System.err.println("Invalid expression!");
                System.exit(-1);
            }
            data = data.substring(1, data.length()-1);
        }
        this.data = data.trim();
    }

    /*
        Method to extract the leading operation of an expression and set it to current node
     */
    private String setOp()
    {
        if (data.charAt(0) != '+' && data.charAt(0) != '-' && data.charAt(0) != '*' && data.charAt(0) != '/') {
            System.err.println("Unsupported operation!");
            System.exit(-1);
        }

        String remainigExpression = data.substring(1, data.length()).trim();
        data = ""+data.charAt(0);
        return remainigExpression;
    }

    /*
        Method to evaluate an input prefix expression and generate binary tree
     */
    public void readPrefix()
    {
       if(data.indexOf(' ') <= 0){
            return;
       }

        String remaingExpression = setOp();

        left = new BinaryTreeNode(remaingExpression.substring(0, remaingExpression.indexOf(' ')));
        left.readPrefix();

        right = new BinaryTreeNode(remaingExpression.substring(remaingExpression.indexOf(' '), remaingExpression.length()));
        right.readPrefix();
    }

    /*
        Method to evaluate an input infix expression and generate binary tree
     */
    public void readInfix()
    {
       if(data.indexOf(' ') <= 0){
            return;
       }

        left = new BinaryTreeNode(data.substring(0, data.indexOf(' ')));
        left.readInfix();

        data = data.substring(data.indexOf(' ')+1);

        String remaingExpression = setOp();

        right = new BinaryTreeNode(remaingExpression);
        right.readInfix();
    }

    /*
        Method to evaluate an input postfix expression and generate binary tree
     */
    public void readPostfix()
    {
        if(data.indexOf(' ') <= 0) {
           return;
        }

        left = new BinaryTreeNode(data.substring(0, data.indexOf(' ')));
        left.readPostfix();

        data = data.substring(data.indexOf(' '));

        String remaingExpression = setOp();

        right = new BinaryTreeNode(remaingExpression.substring(remaingExpression.indexOf(' '), remaingExpression.length()));
        right.readPostfix();
    }

    /*
        Displays an infix expression from binary tree
     */
    public void printInfix() {
        if(left!=null){
            System.out.print("( " );
            left.printInfix();
            System.out.print(" ");
        }

        System.out.print(data);

        if(left!=null) {
            System.out.print(" ");
            right.printInfix();
            System.out.print(" )");
        }
    }

    /*
        Displays an prefix expression from binary tree
     */
    public void printPrefix() {
        if(left!=null) {
            System.out.print("( ");
        }

        System.out.print(data);

        if(left!=null) {
            left.printPrefix();
            System.out.print(" ");
            right.printPrefix();
            System.out.print(" )");
        }
    }

    /*
        Displays an postfix expression from binary tree
     */
    public void printPostfix() {
        if(left!=null) {
            System.out.print("( ");
            left.printPostfix();
            System.out.print(" ");
            right.printPostfix();
            System.out.print(" ");
        }

        System.out.print(data);

        if(left!=null) {
            System.out.print(" )");
        }
    }
}