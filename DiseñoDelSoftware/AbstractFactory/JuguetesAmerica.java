public class JuguetesAmerica implements JugueteFactory{

    public Monopoli creaMonopoli(){
        Monopoli juguete = new MonopoliAmerica("25cm","B");
        return juguete;
    }

    public Playmobil creaPlaymobil() {
        Playmobil juguete = new PlaymobilAmerica("5cm","C","Glock");
        return juguete;
    }

    public Lego creaLego() {
        Lego juguete = new LegoAmerica("5cm","D","M16", "Giroscopio");
        return juguete;
    }

}