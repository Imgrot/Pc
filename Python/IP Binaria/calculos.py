def calculo(valor):
    array = []
    #2^7
    if valor >= 128:
        array.append("1")
        valor = valor - 128
    else:
        array.append("0")

    #2^6
    if valor >= 64:
        array.append("1")
        valor = valor - 64
    else:
        array.append("0")

    #2^5
    if valor >= 32:
        array.append("1")
        valor = valor - 32
    else:
        array.append("0")

    #2^4
    if valor >= 16:
        array.append("1")
        valor = valor - 16
    else:
        array.append("0")

    #2^3
    if valor >= 8:
        array.append("1")
        valor = valor - 8
    else:
        array.append("0")

    #2^2
    if valor >= 4:
        array.append("1")
        valor = valor - 4
    else:
        array.append("0")

    #2^1
    if valor >= 2:
        array.append("1")
        valor = valor - 2
    else:
        array.append("0")

    #2^0
    if valor >= 1:
        array.append("1")
        valor = valor - 1
    else:
        array.append("0")
    return array


    # 192.168.7.10
    # 11000000.10101000.00000111.00001010
    #192 - 128 = 64
    # 1
    # 2
    # 4
    # 8
    # 16
    # 32
    # 64
    # 128