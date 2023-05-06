import json
import requests

#codificacion = json.dumps([None, True, False, 'Hola, mundo!'])
#print(codificacion)
#decodificacion = json.loads(codificacion)
#print(decodificacion)

entrega = requests.get("https://api.covid19api.com/summary").text
info_global = json.loads(entrega)
dGlobal = info_global["Global"]
print(dGlobal)
   