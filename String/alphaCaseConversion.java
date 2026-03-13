package String;

import java.util.Scanner;

public class alphaCaseConversion {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s=sc.next();
    String str="";
    int n=s.length();
    for(int i=0;i<n;i++){
        str=str+(char)(s.charAt(i)^32);   // ^ converts the uppercase to the lowercase and the lowercase to the uppercase throughout the string
    }
    System.out.println(str);
    }
}
