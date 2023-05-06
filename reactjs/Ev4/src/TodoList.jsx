import React, { Fragment, useState, useRef } from "react";
import { TodoItem } from "./TodoItem";
import { v4 as uuid } from "uuid";
import { Card } from "react-bootstrap/Card"

export function TodoList() {
  const [todos, setTodos] = useState([]);
  const taskRef = useRef();

  const carta=() => {
    return <div className="App">
      <Card style={{ width: '18rem' }}>
      <Card.Body>
        <Card.Title>Card Title</Card.Title>
        <Card.Text>
          Some quick example text to build on the card title and make up the
          bulk of the card's content.
        </Card.Text>
      </Card.Body>
    </Card>
    </div>
  }



  const agregarTarea = () => {
    console.log("Agregando Tarea");
    const task = taskRef.current.value;
    console.log(task);
    if (task === "") return
    setTodos((prevTodos) => {
      const newTask = {
        id: uuid(),
        task: task,
        completed: false,
      }
      return [...prevTodos, newTask]
    })
    taskRef.current.value = null;
  }

  const eliminarTareasCompletadas = () => {
    const newTodos = todos.filter((todo) => !todo.completed);
    setTodos(newTodos)
  }

  const ResumenTareas = () => {
    const cant = cantidadTareas()
    if (cant == 0) {
      return <div className="alert alert-success mt-4"> Felicitaciones! no te quedan tareas pendientes</div>
    }
    if (cant == 1) {
      return <div className="alert alert-warning mt-4"> Te queda solamente {cant} tarea pendiente</div>
    }
    return <div className="alert alert-info mt-4"> Te quedan {cant} tareas pendientes </div>
  }

  const cantidadTareas = () => {
    return todos.filter((todo) => !todo.completed).length
  }

  const cambiarEstadoTarea = (id) => {
    const newTodos = [...todos];
    const todo = newTodos.find((todo) => todo.id === id)
    todo.completed = !todo.completed;
    setTodos(newTodos)
  }

  return (<Fragment>
    <h1>Listado de tareas</h1>
    <div className="input-group mt-4 mb-4">
      <input ref={taskRef} className="form-control" placeholder="Ingrese una Tarea" type="text"></input>
      <button onClick={agregarTarea} className="btn btn-sucess ms-2">+</button>
      <button onClick={eliminarTareasCompletadas} className="btn btn-danger ms-2">-</button>
    </div>
    <ul className="list-group">
      {todos.map((todo) => (
        <TodoItem todo={todo} key={todo.id} cambiarEstado={cambiarEstadoTarea} />
      )
      )}

    </ul>
    <ResumenTareas></ResumenTareas>
  </Fragment>
  );

}