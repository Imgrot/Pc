// const person = {
//     firstName: "Nick",
//     lastName: "Anderson",
//     age: 35,
//     sex: "M"
//   }

// const { firstName:first, age} = person; // That's it !

// console.log(age) // 35 -- A new variable age is created and is equal to person.age
// console.log(first) // "Nick" -- A new variable first is created and is equal to person.firstName
// console.log(first)
// console.log(person.firstName) // ReferenceError -- person.firstName exists BUT the new variable created is named first
// console.log(city) // "Paris" -- A new variable city is created and since person.city is undefined, city is equal to the default value provided "Paris".

// let array=["a", "b", "me eche el ramo", "d", "cinco:2"]
// const [primero, segundo, estado_mental]= array
// console.log(segundo, primero, estado_mental)
let array = [33, 30, 1, 5]
let a = 0
array.forEach(elemento => {
  a += elemento
})
console.log(a)