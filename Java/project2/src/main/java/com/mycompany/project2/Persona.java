package com.mycompany.project2;
    
public class Persona {
    private String nombre;
    private int edad;
    private String fono;

    public Persona(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }
    
    public Persona(String nombre, int edad, String fono){
        this.edad=edad;
        this.nombre=nombre;
        this.fono=fono;
    }

    public Persona() {
    }
    
    public String getNombre() {
        return nombre;
    }

    public int getEdad() {
        return edad;
    }

    public String getFono() {
        return fono;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public void setFono(String fono) {
        this.fono = fono;
    }
    
    
}   
    
