let array = []
        let negativos = 0
        let positivos = 0
        let mult15 = 0
        let sumaPares = 0

        array.push(prompt("Ingrese su número"))

        for (let i = 2; i < 11; i++) {
            array.push(prompt("Ingrese su siguiente número"))
        }
        
        function Comprobar(valor) {
            if (Number(valor) >= 0) { positivos++ }
            if (Number(valor) < 0) { negativos++ }
            if (Number(valor) % 15 == 0) { mult15++ }
            if (Number(valor) % 2 == 0) { sumaPares += valor + sumaPares }
        }
        for (let a = 0; a < 10; a++) {
            Comprobar(array[a])
        }


        document.write("Sus números ingresados fueron:<br>" + array 
        + "<br> Entre los números ingresados:<br>")

        document.write(positivos + " son positivos<br>")
        document.write(negativos + " son negativos<br>")
        document.write(mult15 + " son múltiplos de 15<br>")
        document.write(sumaPares + " es la suma de todos los valores pares.")