class FibonacciSequence:
    def __init__(self, n):
        self.n = n
    
    def generate_sequence(self):
        sequence = []
        a, b = 0, 1
        for i in range(self.n):
            sequence.append(a)
            a, b = b, a + b
        return sequence

if __name__ == '__main__':
    n = int(input("Ingresa el número de términos de la secuencia de Fibonacci a generar: "))
    fib = FibonacciSequence(n)
    sequence = fib.generate_sequence()
    print(f"La secuencia de Fibonacci con {n} términos es: {sequence}")
