from django.shortcuts import render
from django.http import HttpResponse
from django.template import Template, Context

def index(request):
    data = {
        "title" : "DJANGO SHOP",
        "pholder1" : "Info. de Usuario",
        "pholder2" : "Juguetes",
        "pholder3" : "Ropa",
    }
    return render(request, 'index.html', data)

def juguetes(request):
    data = {
        "title" : "DJANGO SHOP",
        "pholder2" : "Juguetes",
        "return" : "Volver",
        "jug1" : "Auto RC Insector",
        "jug2" : "Balón de Fútbol",
        "jug3" : "Set Lego Star Wars: Mandalorian Starfighter"
        }

    return render(request, 'juguetes.html', data)

def ropa(request):
    data = {
        "title" : "DJANGO SHOP",
        "pholder3" : "Ropa",
        "return" : "Volver",
        "ropa1" : "Máscara Médico de la peste",
        "ropa2" : "Terno Hombre, color negro",
        "ropa3" : "Polerón diseño osos",
        }

    return render(request, 'ropa.html', data)

def user(request):

    doc_externo=open('templates/user.html')

    plt = Template(doc_externo.read())

    doc_externo.close()

    ctx=Context({
        "title" : "DJANGO SHOP",
        "user" : "Datos de Usuario",
        "nombre" : "Xavier",
        "apellido": "Papito",
        "nacionalidad" : "Hindi",
        "return" : "Volver",
        })

    pagina = plt.render(ctx)

    return HttpResponse(pagina)