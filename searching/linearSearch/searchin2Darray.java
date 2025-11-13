package searching.linearSearch;

import java.util.Scanner;

public class searchin2Darray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] arr = new int[3][];
        int f;
        int s;
        int t;
        System.out.println("Enter the no. of elements in the 1st row: ");
        f = sc.nextInt();
        System.out.println("Enter the no. of elements in the 2nd row: ");
        s = sc.nextInt();
        System.out.println("Enter the no. of elements in the 3rd row: ");
        t = sc.nextInt();
        arr[0] = new int[f];
        arr[1] = new int[s]; 
        arr[2] = new int[t];
        System.out.println("Enter the array: ");
        for(int row = 0; row<arr.length; row++){
            for(int col = 0; col<arr[row].length; col++){
                arr[row][col] = sc.nextInt();
            }
        }
        System.out.println("Enter the target element: ");
        int target = sc.nextInt();
        search(arr, target);
        sc.close();
    }

    static void search(int[][] arr, int target){
        int row, col;
        boolean found = false;
        for(row=0; row<arr.length; row++){
            for(col=0; col<arr[row].length; col++){
                if(arr[row][col] == target){
                    found = true;
                    System.out.printf("Element found at position: (%d, %d)", row, col);
                    System.out.println();
                }
            }
        }
        if(!found){
            System.out.println("Element not found!");
        }
    }
}
