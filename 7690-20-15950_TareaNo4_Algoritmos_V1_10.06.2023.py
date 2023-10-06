'''Este programa contiene un menu con 4 opciones:
1- Calculo de Subsidio
2- Coparacion de vectores
3- Estadistica descriptiva
4- Generacion de cuadrado
Se utilizan estructuras de control anidadas y funciones.
Este programa es propiedad de Nelson Santos'''
menu = int(input("ingrese el numero del ejercicio que desa visualizar (del 1 al 4) "))
if menu == 1:
    print("Ingresando calculo de subsidio... ")
    def calcularSubsidio(n_hijos,h_Escolar,m_viuda):
        base = 0
        if n_hijos > 0 and n_hijos < 3:
            base = 70
        elif n_hijos > 2 and n_hijos < 6:
            base = 90
        elif n_hijos > 5:
            base = 120
        H_adicional = h_Escolar *10
        V_adicional = 20 if m_viuda else 0
        total = base + H_adicional + V_adicional
        return total
    
    n_hijos = int(input("Ingrese el numero de hijos "))
    h_Escolar = 0
    for i in range (n_hijos):
        edad = int(input("Ingrese edad del hijo No. {} ".format(i+1)))
        if edad > 5 and edad < 19:
            h_Escolar += 1
    viuda = int(input("La madre es viuda? (Ingrese 1 para decir que si y 0 para decir que no)"))
    if viuda == 1:
        m_viuda = True
    else:
        m_viuda = False
    subsidio = calcularSubsidio(n_hijos,h_Escolar,m_viuda)
    print("El monto mensual que debe de recibir la familia es de: ", subsidio)
elif menu == 2:
    print("Ingresando comparacion de dos vectores... ")
    ListaA = []
    ListaB = []
    sumaA = 0
    sumaB = 0
    import random 
    Vector1 = int(input("Ingrese la longitud del vector 1 "))
    Vector2 = int(input("Ingrese la longitud del vector 2 "))
    for i in range (Vector1):
        VectorA = random.randint(0, 100)
        ListaA.append(VectorA)
        sumaA += VectorA
    for j in range(Vector2):
        VectorB = random.randint(0, 100)
        ListaB.append(VectorB)
        sumaB += VectorB
    if sumaA == sumaB:
        print("Los vectores A y B son iguales ya que el Vector A tiene los elementos: ", ListaA, " y el Vector B tiene los elementos: ", ListaB)
    elif sumaA < sumaB:
        print("El Vector B es mayor que el Vector A")
        print("Vector A: ", ListaA, "=",sumaA)
        print("Vector B: ", ListaB, "=", sumaB)
    elif sumaA > sumaB:
        print("El Vector A es mayor que el Vector B")
        print("Vector A: ", ListaA, "=",sumaA)
        print("Vector B: ", ListaB, "=", sumaB)
elif menu == 3:
    print("Ingresando a la estadistica descriptiva... ")
    n_Datos = int(input("Cuantos datos desea ingresar? "))
    Lista = []
    mayor = 0
    menor = 0
    for i in range (n_Datos):
        d_real = float(input("Ingrese numero real "))
        Lista.append(d_real)
        if i == 0:
            mayor = d_real
            menor = d_real
        else:
            if d_real > mayor:
                mayor = d_real
            else:
                if d_real < menor:
                    menor = d_real
    print("Los numeros ingresados son: ", Lista)
    print("El rango de la lista anterior es de: ",mayor, " - ", menor," = ",round(mayor - menor,2))
elif menu == 4:
    print ("Ingresando a generacion de cuadrado... ")
    numero = int(input("Ingrese numero "))
    caracter = input("Ingrese el caracter")
    for i in range (numero):
        for j in range(numero):
            if i == 0 or i == (numero-1) or j == 0 or j == (numero-1):
                print (caracter," ",end="")
            else:
                print ("   ",end="")
        print()
else:
    print("Opcion no valida")