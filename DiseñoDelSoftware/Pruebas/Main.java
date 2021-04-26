import java.util.Scanner;


public class Main{
    public static void main(String srgv[]){
        Gui ventana = new Gui(700,300, "Prueba");       
        Scanner in = new Scanner(System.in);
        
        while(true){
            
            //ventana.cambiar( in.nextLine() );
            ventana.attack();
            in.nextLine();
        }

    }
}

