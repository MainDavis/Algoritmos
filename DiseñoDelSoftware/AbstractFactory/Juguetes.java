interface JugueteFactory{
    Monopoli creaMonopoli();
    Playmobil creaPlaymobil();
    Lego creaLego();
}

interface Monopoli{
    String descripcion();
}

interface Playmobil{
    String descripcion();
}

interface Lego{
    String descripcion();
}
