// finding the ceiling element.
// ceiling --> smallest element >= target 
// floor --> greatest element <= target

package searching.binarySearch;

import java.util.Scanner;

public class ceiling {
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
        System.out.println("Ceiling element is present at index: "+calcCeil(arr, target));
    }
    static int calcCeil(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target<arr[mid]){
                end = mid-1;
            }else if(target>arr[mid]){
                start = mid+1;
            }else{
                return mid;
            }
        }
        return start;   // for floor --> return end here.  and in the beginning, check if the target is greater than the greatest element in the array. if yes, return -1
    }
}

