//Prueba Tercer Progreso Sebastian Cadena

#include <stdio.h>
#include <ctype.h> // Aqui se inicializan las 2 librerias principiales , la original de stdio.h y ctype, libreria que ayuda a transformar caracteres, en este caso para modifical la palabra ecuador a mayuscula


void reemplazarPalabra(FILE *archivo1, FILE *archivo2, const char *palabramin, const char *palabramay) { // creamos una funcion llamada " reemplazarPalabra", la cuañ ejecutara el primer punto a resolver del problema el cual es el reemplazo de las palabras
    char palabra[100];
    
    while (fscanf(archivo1, "%s", palabra) != EOF) {// A continuaciòn , se verifica si la palabra es exactamente igual a "ecuador",Use EOF para evitar el error generado al intentar obtener entrada más allá del final de un archivo.
        
        if (strcasecmp(palabra, palabramin) == 0) { //Hacemos uso de la libreria ctype , donde La funcion strcasecmp compara dos diferentes valores o textos , en este caso palabra es la palabra que se desea obtener y palabra min es en minuscula
           
            fprintf(archivo2, "%s ", palabramay);// Reemplazar la palabra minuscula por "ECUADOR" en mayuscula
        } else { 
            
            
            fprintf(archivo2, "%s ", palabra); 
        }
    }
}

// En la funcion main , lo que se hace es la construccion del nuevo archivo de texto , llamado textonuevo a traves de el uso de diferentes conceptos de archivos.
int main() { // llamamos a la funcion main
    FILE *archivo1, *archivo2; // aqui ponemos los dos archivos que tenemos
    const char *palabramin = "ecuador"; 
    const char *palabramay = "ECUADOR"; // mediante el puntero const char comparamos los valores de la cadena , aqui comparamos las palabras ecuador en palabmin y la palabre ECUADOR en palabmay
    
     // comenzamos a leer los archivos

    archivo1 = fopen("tricolor.txt", "r"); // abrimos el texto otiginal proporcionado por el maestro en el aula virtual , este archivo es el original , dispueso a ser corregido.
    archivo2 = fopen("textonuevo.txt", "w"); // y abrimos el texto que tiene la solucion del codigo , llamado "textonuevo"
    
    if (archivo1 == NULL || archivo2 == NULL) {
        printf("No se pudo abrir los archivos.");
        return 1;// si por algun motivo la ejecuciòn de los archivos falla, el programa avisara del error mediante un mensaje
    }
    
    reemplazarPalabra(archivo1, archivo2, palabramin, palabramay);//ejecutamos los cambios hechos ya anteriormente , llamando nuevamente a la funcion reemplazarPalabra, como se puede ver , dicha funcion contiene los 2 archivos , el original y el modificado y las variables con las que guardaos a la palabra ecuador y ECUADOR.
    
    
    fclose(archivo1); // cerramos el archivo original
    fclose(archivo2); // cerramos el archivo modificado
    
    printf("Se ha creado el archivo 'textonuevo.txt' \n");// confirmamos con este mensaje al usuario , que se ha creado exitosamente el archivo
    
    return 0;
}