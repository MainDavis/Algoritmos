public class PlaymobilAmerica implements Playmobil{
    private final String pieza, ficha, accesorio;

    PlaymobilAmerica(String pieza, String ficha, String accesorio){
        this.pieza = pieza;
        this.ficha = ficha;
        this.accesorio = accesorio;
    }

    public String descripcion() {
        return ("Playmobil americano con pieza = " + pieza + ", ficha = " + ficha + " y accesorio = " + accesorio);
    }
}
