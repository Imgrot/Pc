export function TodoItem({ todo , cambiarEstado }) {
  const { id, task, completed } = todo;
  const fnCambiarEstado = () => {
    cambiarEstado(id);
  }
  return (
    <li className="list-group-item">
      <input type="checkbox" checked={completed} onChange={fnCambiarEstado} className="form-check-input me-2"></input>
      {task}</li>
  );
}