package com.mycompany.project2;

public class Project2 {  
 
    public static void main(String[] args) {
        System.out.println("aaaaaa");
        
        Persona p;
        p=new Persona();
        p.setNombre("Juan");
        //p.nombre="Juan";
        p.setEdad(42);
        //p.edad=42;
        p.setFono("45");
        //p.fono="45";
        
        System.out.println("El nombre es: "+p.getNombre());
    }
}