import os
os.system("cls")
notas = {
  "matematicas": 7,
  "progra": 3,
  "introduccion": 6,
  "matrices": 5,
  "profesor": "el hidalgo ql"
}

x = notas.get("profesor")

print("Su profesor en progra es: {}".format(x))
input("pulse Enter para continuar.")
print("aweonao")