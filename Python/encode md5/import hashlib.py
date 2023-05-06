import hashlib
from hashlib import md5

mensaje = input('mensaje a cifrar: ')
print(md5(mensaje.encode("utf-8")).hexdigest())