package searching.linearSearch;

import java.util.Scanner;

public class searchinStr {
    public static void main(String[] args) {
        System.out.println("Enter the string: ");
        Scanner sc = new Scanner(System.in);
        String string = sc.next();
        System.out.println("Enter the character to find in the string: ");
        char c = sc.next().charAt(0);
        sc.close();
        searchStr(string, c);
        }
    static void searchStr(String string, char c){
        boolean found = false;
        if(string.length() == 0){
            System.out.println("String is empty.");
        }
        System.out.print("Character "+c+" found at position(s): ");
        for(int i=0; i<string.length(); i++){
            if(string.charAt(i) == c){
                System.out.print(i+" ");
                found = true;
            }
        }
        if(!found){
            System.out.println("Character not found in the string.");
        }else{
            System.out.println();
        }
    }
}
