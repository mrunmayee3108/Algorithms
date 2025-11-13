package searching.linearSearch;
import java.util.Scanner;

public class linearSearch {
    public static void main(String[] args) {
        System.out.println("How many elements do u want for linear search? ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Enter the elements in the array: ");
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        int target;
        System.out.print("Enter the target element: ");
        target = sc.nextInt();
        sc.close();
        System.out.println("Target element found at index: "+linearS(a, n, target));

    }
    static int linearS(int[] a, int n, int target){
        if(a.length == 0){
                return -1;
        }
        for(int i=0; i<n; i++){
            if(a[i] == target){
                return i;
            }
        }
        return -1;
    }
}

// Time complexity:
// Best case: O(1) --> when target element is the 1st element or if the array is empty.
// Average and worst case: O(n).

// Space complexity: O(1).
