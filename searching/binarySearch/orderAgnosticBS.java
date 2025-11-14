// Order Agnostic binary search is used when we dont know if the array is sorted in ascending or descending order.

package searching.binarySearch;

import java.util.Scanner;

public class orderAgnosticBS {
    public static void main(String[] args) {
        System.out.print("How many numbers do you want to enter? ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the array elements: ");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter the target element: ");
        int target = sc.nextInt();
        sc.close();
        System.out.println("Element found at index: "+orderAgnostic(arr, target));
    }
    static int orderAgnostic(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;
        boolean isAsc = arr[start]<arr[end];
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target){
                return mid;
            }
            if(isAsc){
                if(target<arr[mid]){
                   end = mid-1;
                }else if(target>arr[mid]){
                   start = mid+1;
                }
            }else{
                if(target>arr[mid]){
                   end = mid-1;
                }else if(target<arr[mid]){
                   start = mid+1;
                }
            }
        }
        return -1;
    }
}
