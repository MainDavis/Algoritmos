public class LegoEuropa implements Lego{

    private final String pieza, ficha, accesorio, sensor;

    LegoEuropa(String pieza, String ficha, String accesorio, String sensor){
        this.pieza = pieza;
        this.ficha = ficha;
        this.accesorio = accesorio;
        this.sensor = sensor;
    }

    public String descripcion() {
        return ("Lego europeo con pieza = " + pieza + ", ficha = " + ficha + ",  accesorio = " + accesorio + " y sensor = " + sensor);
    }
    
}