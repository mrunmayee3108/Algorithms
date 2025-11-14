package searching.binarySearch;

import java.util.Scanner;

public class binarySearch {
    public static void main(String[] args) {
        System.out.print("How many numbers do you want to enter? ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the array elements (in ascending order): ");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter the target element: ");
        int target = sc.nextInt();
        sc.close();
        System.out.println("Element found at index: "+binaryS(arr, target));
    }
    static int binaryS(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;
        while(start<=end){
            // int mid = (start+end)/2; but it may be possible that start+end exceeds the range of int in java
            int mid = start + (end-start)/2;
            if(target<arr[mid]){
                end = mid-1;
            }else if(target>arr[mid]){
                start = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
}

// Time complexity:
// Best case: O(1) --> the target element is the middle element.
// Worst/avg case:O(log n) --> recursion.

// space complexity: O(1) --> only uses few variables.
