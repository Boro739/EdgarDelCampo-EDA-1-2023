def MostrarBiblioteca (catalogo):
    if catalogo :
        print("Los libros que estan en la biblioteca son:")
        for libro in catalogo.keys():
            print(libro)
    else:
        print("La biblioteca esta vacia") 

def Alfabeticamente (catalogo):
    for libro in range(1,len(catalogo.keys())):
        actual = catalogo[libro]
        posicion = libro
        while posicion>0 and catalogo[posicion-1]>actual:
            catalogo[posicion]=catalogo[posicion-1]
            posicion = posicion-1           
        catalogo[posicion]=actual
    print("\n\tYa odernados alfabeticamente")
    MostrarBiblioteca(catalogo)

def ID (catalogo):
    for id in range(1,len(catalogo.values())):
        actual = catalogo.values[id]
        posicion = id
        while posicion>0 and catalogo.values[posicion-1]>actual:
            catalogo.values[posicion]=catalogo.values[posicion-1]
            posicion = posicion-1           
        catalogo.values[posicion]=actual
    print("\n\tYa odernados por ID")
    MostrarBiblioteca(catalogo)

def OrdenarBiblioteca(catalogo):
    if catalogo:
        MostrarBiblioteca(catalogo)
        ordenar = int(input("""
        \t\tSeleccione como desea ordenar la biblioteca
        1 Alfabeticamente
        2 Por ID
        Ingrese la opcion : """))

        if ordenar == 1:
            Alfabeticamente(catalogo)
        elif ordenar == 2:
            ID(catalogo)
        else:
            print("opcion invalida")

    else:
        print("La biblioteca esta vacia") 

def eliminar (catalogo):
    if catalogo :
        MostrarBiblioteca(catalogo)
        eliminacion = input("Ingrese el libro que desea eliminar: ")
        if eliminacion in catalogo:
            del catalogo [eliminacion]
            print(f"\n\tEl libro {eliminacion} ha sido eliminado con exito\n ")
            MostrarBiblioteca(catalogo)
        else:
            print(f"El libro {eliminacion} no se encuentra en la biblioteca")    
    else:
        print("La biblioteca esta vacia") 
        

#Pasa el titulo ingresado a ASCII para hacer su codigo de barras
def CodigoBarras (libro):
    codigo = []
    for letra in libro:
        codigo.append (ord(letra))
    print(codigo)
    return codigo

def AgregarLib (catalogo):
    libro = input("Ingrese el titulo del libro: ")
    ID = CodigoBarras(libro)
    catalogo[libro] = ID


#int main 
catalogo = {}

while True:
    opcion = int(input("""
    \t\tBienvenido a la biblioteca, puede realizar las siguientes operaciones:
    1 Agregar libro
    2 Eliminar libro
    3 Ordenar biblioteca
    4 Ver biblioteca
    5 Salir

    Ingresela opcion : """))

    if opcion==1:
        AgregarLib(catalogo)
    elif opcion==2:
        eliminar(catalogo)
    elif opcion==3:
        OrdenarBiblioteca(catalogo)
    elif opcion==4:
        MostrarBiblioteca(catalogo)
    elif opcion==5:
        break
    else:
        print("Opcion invalida")

