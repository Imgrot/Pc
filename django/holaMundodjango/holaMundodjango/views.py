import datetime
from django.http import HttpResponse
from django.template import Template, Context

class Persona:
    def __init__(self, nombre, apellido):
        self.nombre=nombre
        self.apellido=apellido

def saludo(request):
    return HttpResponse("Hola a todos")

def plantilla(request):
    doc_externo=open("D:\Codigos\django\holaMundodjango\holaMundodjango\miplantilla.html")

    plt = Template(doc_externo.read())

    doc_externo.close()

    # nombre="Pedro"
    # apellido="Pascal"
    p1=Persona("Pedro","Pascal")

    fecha = datetime.datetime.now()
    temas = ["Modelaje", "Visitas", "Actuacion"]
    ctx=Context({
        "nombre_persona" : p1.nombre,
        "apellido_persona": p1.apellido,
        "fecha" : fecha,
        "temas": temas
        })

    pagina = plt.render(ctx)

    return HttpResponse(pagina)

def userinfo(request):
    pass