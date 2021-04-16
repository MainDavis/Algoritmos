public class MonopoliAmerica implements Monopoli{
    final String pieza, ficha;

    MonopoliAmerica(String pieza, String ficha){
        this.pieza = pieza;
        this.ficha = ficha;
    }

    public String descripcion(){
        return ("Monopoli Americano con pieza: " + pieza + " y ficha: " + ficha);
    }
}