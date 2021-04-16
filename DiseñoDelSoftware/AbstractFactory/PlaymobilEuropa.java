public class PlaymobilEuropa implements Playmobil{
    private final String pieza, ficha, accesorio;

    PlaymobilEuropa(String pieza, String ficha, String accesorio){
        this.pieza = pieza;
        this.ficha = ficha;
        this.accesorio = accesorio;
    }

    public String descripcion() {
        return ("Playmobil europeo con pieza = " + pieza + ", ficha = " + ficha + " y accesorio = " + accesorio);
    }
}
