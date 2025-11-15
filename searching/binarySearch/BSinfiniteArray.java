// searching an element in a sorted array of infinite length

package searching.binarySearch;

import java.util.ArrayList;
import java.util.Scanner;

public class BSinfiniteArray {
    public static void main(String[] args) {
        System.out.println("Enter the infinite array(Enter -1 to stop): ");
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();
        while(true){
            int x = sc.nextInt();
            if(x == -1) break;
            list.add(x);
        }
        System.out.println("Enter the target element: ");
        int target = sc.nextInt();
        System.out.print("Your array: "+list);
        int[] arr = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i);
        }
        int ans = findinterval(arr, target);
        System.out.println("The target element is found at index: "+ans);
        sc.close();
    }

    static int findinterval(int arr[], int target){
        int start = 0;
        int end = 1;
        if(arr.length == 0) return -1;
        if(arr.length == 1) return arr[0] == target ? 0:-1;
        while(target>arr[end]){
            int newStart = end+1;
            end = end + (end-start+1)*2;
            start = newStart;
        }
        return binaryS(arr, target, start, end);
    }
    static int binaryS(int[] arr, int target, int start, int end){
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
        return -1;
    }
}

