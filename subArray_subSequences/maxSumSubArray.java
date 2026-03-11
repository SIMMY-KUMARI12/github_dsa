import java.util.*;
public class maxSumSubArray{

    // method 2     --------  > tc: O(n^2)   & Sc: 1;
    public static int maxSum(int arr[], int n){
        int ans=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                
                    sum+=arr[j];
                
                ans=Math.max(ans, sum);
            }
        }
        return ans;
    }
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
     int n = sc.nextInt();
     int arr[]= new int[n];
     for(int i=0;i<n;i++){
        arr[i]=sc.nextInt();
     }
     int ans=maxSum(arr,n);
     System.out.println(ans);
     sc.close();
    }

    /* 

    //  method 1   brutforce       tc----> O(n^3)      sc-------> 1

    public static int maxSum(int arr[], int n){
        int ans=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=arr[k];
                }
                ans=Math.max(ans, sum);
            }
        }
        return ans;
    }
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
     int n = sc.nextInt();
     int arr[]= new int[n];
     for(int i=0;i<n;i++){
        arr[i]=sc.nextInt();
     }
     int ans=maxSum(arr,n);
     System.out.println(ans);
     sc.close();
    }
*/


}