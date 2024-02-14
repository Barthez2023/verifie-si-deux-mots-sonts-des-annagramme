import java.util.Scanner;

public class MainApp
{ 
    public static void main(String[] args)
    {
        int x,y;
        Scanner scanner = new Scanner(System.in);
        int ageUtilisateur=25;
        final int MUNBER=45;
        System.out.println("Mon premier programme ") ;
        System.out.println("Bonjour tout le monde!:)");
        System.out.println(ageUtilisateur);
        ageUtilisateur=24*2;
        System.out.println("l'age de l'utilisteur est de:"+ageUtilisateur);
        System.out.println("Mon premier programme "+(2+ageUtilisateur)) ;
        /*System.out.print("entrer un entier:");
        x=scanner.nextInt();
        System.out.println(MUNBER);
        scanner.close();*/
        boolean result=14<8;
        System.out.println(result) ;
        String choice = "n";
        switch (choice) {
            case "y":
                System.out.println("Nous allons tous bien");
                break;
            case "n":
                System.out.println("Nous n'allons pas tous bien ici");
                break;
            default:
                System.out.println("Nous ne pouvons rien dire");
                break;
        }

    }
    

}