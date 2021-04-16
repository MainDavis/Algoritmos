public class MonopoliEuropa implements Monopoli{
    final String pieza, ficha;

    MonopoliEuropa(String pieza, String ficha){
        this.pieza = pieza;
        this.ficha = ficha;
    }

    public String descripcion(){
        return ("Monopoli Europeo con pieza: " + pieza + " y ficha: " + ficha);
    }
}
