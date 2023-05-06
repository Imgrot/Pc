
horas_trabajadas = int(input("Ingrese las horas que trabajó esta semana:"))
tarifa_por_hora = int(input("¿Cual es la tarifa por hora?:"))
descuentos_semanales = int(input("¿Cuanto se le descuenta esta semana?:"))

if horas_trabajadas > 40:
    horas_extra = horas_trabajadas - 40  
    tarifa_overtime = tarifa_por_hora + (tarifa_por_hora/2) 
    pago_total = ((40 * tarifa_por_hora) + (horas_extra * tarifa_overtime)) - descuentos_semanales

elif horas_trabajadas <= 40:
    pago_total = (horas_trabajadas * tarifa_por_hora) - descuentos_semanales

print("Usted trabajó {} horas".format(pago_total))