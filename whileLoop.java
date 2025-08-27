import java.util.*;

public class Main {
    public static void main(String args[]) {
        int n;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        int no = n*10;
        while ( no > 0){
            System.out.print(no + " ");
            no = no-n;
        }
 
    }
}
