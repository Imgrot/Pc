import requests 
import json  
def menu():     

    id = input("Que numero de pokedex desea ver?: ")     

    idPokemon=requests.get("https://pokeapi.co/api/v2/pokemon/{}".format(id)).text      
    lista_pokemon = []     
    API = json.loads(idPokemon)     

    HabilidadPokemon=API["abilities"]     
    print("Name: " + API["name"])     
    print("Abilities: ")
    numAbil=1
    for abilities in  HabilidadPokemon:  
        print(numAbil,end="- ")            
        print(abilities['ability']['name']) 
        numAbil+=numAbil   

    print("Types: ") 
    TipoPokemon=API["types"]     
    numTyp =1 
    for types in TipoPokemon:         
        print(numTyp,end="- ")         
        print(types["type"]['name']) 
        numTyp+=numTyp
menu()