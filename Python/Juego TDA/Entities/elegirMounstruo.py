def monsterSelect(valor):
    Goblin={
            "Nombre":"Goblin",
            "Vida Máxima": 35,
            "Vida":35,
            "Ataque":5, 
            "Defensa":3, 
            "Critico": 5, 
            "Evasión": 15
            }
    SlimeDeHielo={
            "Nombre":"Slime de Hielo",
            "Vida Máxima": 50,
            "Vida":50,
            "Ataque":3, 
            "Defensa":4, 
            "Critico": 10, 
            "Evasión": 10
            }
    Kobold={
            "Nombre":"Kobold",
            "Vida Máxima": 40,
            "Vida":40,
            "Ataque":9, 
            "Defensa":0, 
            "Critico": 35, 
            "Evasión": 20
            }
    LoboCongelante={
            "Nombre":"Lobo Congelante",
            "Vida Máxima": 40,
            "Vida":40,
            "Ataque":3, 
            "Defensa":2, 
            "Critico": 30, 
            "Evasión": 30
            }
    if valor == 0:
        return Goblin
    if valor == 1:
        return SlimeDeHielo
    if valor == 2:
        return Kobold
    if valor == 3:
        return LoboCongelante