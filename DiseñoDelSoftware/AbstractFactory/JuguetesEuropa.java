public class JuguetesEuropa implements JugueteFactory{

    public Monopoli creaMonopoli(){
        Monopoli juguete = new MonopoliEuropa("2cm","A");
        return juguete;
    }

    public Playmobil creaPlaymobil() {
        Playmobil juguete = new PlaymobilEuropa("2cm","A", "Espada");
        return juguete;
    }

    public Lego creaLego() {
        Lego juguete = new LegoEuropa("2cm","A","Espada", "Termico");
        return juguete;
    }

}