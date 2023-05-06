const frankenSplice = (arr1, arr2, n) => {
    let a = arr2.slice()

    arr1.forEach(elemento => {
        a.splice(n, 0, elemento)
        n++
    })
    return a
}

console.log(frankenSplice([1, 2, 3], [4, 5, 6], 1))