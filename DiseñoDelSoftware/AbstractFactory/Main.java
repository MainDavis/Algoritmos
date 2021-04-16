public class Main{
    public static void main(String[] argv){

        System.out.println("Hey");
        
        JugueteFactory america = new JuguetesAmerica();
        JugueteFactory europa = new JuguetesEuropa();

        Monopoli product1 = america.creaMonopoli();
        Monopoli product2 = europa.creaMonopoli();

        Playmobil product3 = america.creaPlaymobil();
        Playmobil product4 = europa.creaPlaymobil();

        Lego product5 = america.creaLego();
        Lego product6 = europa.creaLego();

        System.out.println("Producto 1: " + product1.descripcion() + "\nProducto 2: " + product2.descripcion() + "\n");
        System.out.println("Producto 3: " + product3.descripcion() + "\nProducto 4: " + product4.descripcion() + "\n");
        System.out.println("Producto 5: " + product5.descripcion() + "\nProducto 6: " + product6.descripcion() + "\n");

    }
}