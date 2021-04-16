public class LegoAmerica implements Lego{

    private final String pieza, ficha, accesorio, sensor;

    LegoAmerica(String pieza, String ficha, String accesorio, String sensor){
        this.pieza = pieza;
        this.ficha = ficha;
        this.accesorio = accesorio;
        this.sensor = sensor;
    }

    public String descripcion() {
        return ("Lego americano con pieza = " + pieza + ", ficha = " + ficha + ",  accesorio = " + accesorio + " y sensor = " + sensor);
    }
    
}
