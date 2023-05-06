from django.shortcuts import render
from django.http import HttpResponse
from django.template import Template, Context

class User:
    def __init__(self, nombre, apellido, nota, promedio):
        self.nombre=nombre
        self.apellido=apellido
        self.nota=nota
        self.promedio=promedio

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
        "jug1" : "Auto RC Insector",
        "jug2" : "Balón de Fútbol",
        "jug3" : "Set Lego Star Wars: Mandalorian Starfighter"
    }
    return render(request, 'index.html', data)

def users(request):
    doc_externo=open("django\Django_Evaluacion_1\templates\user.html")

    plt = Template(doc_externo.read())

    doc_externo.close()

    p1=User("Pedro","Pascal", 7, 7)

    ctx=Context({
        "nombre_persona" : p1.nombre,
        "apellido_persona": p1.apellido,
        "nota" : p1.nota,
        "promedio" : p1.promedio,
        })

    pagina = plt.render(ctx)

    return HttpResponse(pagina)
