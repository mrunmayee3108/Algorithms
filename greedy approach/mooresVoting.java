// Moore's algo is used to find the majority element from an array. 
// The majority element is the one which occurs more than int(n/2) times in an array of size n.

import java.util.Scanner;

public class mooresVoting {
    static int findME(int[] a, int n){
        int ME = 0; 
        int vote = 0;
        for(int i=0; i<n; i++){
            if(vote == 0){
                ME = a[i];
            }
            if(ME == a[i]){
                vote++;
            }else{
                vote--;
            }
        }

        // Verifying if the element obtained is actually the majority element.
        // eg. 1,2,3,4  here theres no majority element! (otherwise we'll get 4, but its wrong.)
        int count = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == ME){
                count++;
            }
        }

        if(count > n/2){
            return ME;   
        } else {
            return -1;   
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("How many elements do you want to enter in the array? ");
        int n = sc.nextInt();
        int[] a = new int[n];
        System.out.println("Enter the array elements: ");
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        sc.close();
        int ans = findME(a, n);
        if(ans == -1)
            System.out.println("No majority element exists.");
        else
            System.out.println("The majority element is: " + ans);
    }
}

// Time complexity: O(n)
// Space Complexity: O(1)
