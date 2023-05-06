import hashlib

def cifrado(dato):
    cifrar = hashlib.sha512(dato.encode("utf-8"))
    return cifrar.hexdigest()