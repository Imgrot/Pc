from django.shortcuts import render

# Create your views here.

def index(request):
    data = {
        "title" : "DJANGO SHOP",
        "pholder1" : "Electrodomésticos",
        "pholder2" : "Juguetes",
        "pholder3" : "Ropa",
        "return" : "Volver",
        "ropa1" : "Máscara Médico de la peste",
        "ropa2" : "Terno Hombre, color negro",
        "ropa3" : "Polerón diseño osos",
        "electro1" : "Sandwichera 3 en 1",
        "electro2" : "Hervidor Oister 1.7L",
        "electro3" : "Consola Nintendo Switch",
        "jug1" : "Auto RC Insector",
        "jug2" : "Balón de Fútbol",
        "jug3" : "Set Lego Star Wars: Mandalorian Starfighter"
    }
    return render(request, 'index.html', data)
