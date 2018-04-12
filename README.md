# Tarea 4 #
#### Copyright (C) 2018 - ITCR ####
###### Realizado por David Cordero ```(dcorderoch@ieee.org)``` e Isaac Núñez `(isaacnez@outlook.com)` ###### 

Filtrado de imágenes usando filtros gaussianos de tamaño NxN para tamaño de imágenes variables.
Además de generación de gráficas comparando la duración para el filtrado en frecuencia y espacio usando
kernel separable y no separable.

## Requerimientos del sistema

Verificar que Python3 esté instalado con todas sus dependencias necesarias para este trabajo, para esto instalar:

> $ apt install python3 python3-matplotlib python3-tk

Versión mínima de boost `libboost1.58` y versión mínima de cmake `3.5.1`.

* Si no tiene boost instalado, hay dos caminos:
    
    > $ apt install libboost1.58-all-dev
    
    Descargando el archivo `.tar.gz` (de aquí http://bit.ly/2ErTbV9) y extrayendo la información, luego proceder con: 
    
    > $ cd <directory\>/boost_1_65_1/
    
    > $ ./bootstrap.sh
    
    > $ sudo ./b2 install
    
* Debe tener instalado `Opencv 2.4.9`, sino instálelo usando:
    
    > $ apt install libopencv-dev
    
## Instrucciones de uso

> $ cmake .

> $ make

> $ ./image_viewer [-h | --help] [-i | --kernel-i [arg]] [-j | --kernel-j [arg]] [-p | --plot [arg]]

    -h/--help: despliega la ayuda
    -i/--kernel-i: cantidad de filas del kernel gaussiano a usar
                   (requiere usar -j/--kernel-j)
    -p/--plot: se realizan las pruebas, indicar la imagen a usar
                  (debe tener un tamaño mínimo de 1920x1080)

Si utiliza `-p/--plot`, esta generará 4 imágenes: 

    SFSK.svg: tiempo de ejecución del filtrado en espacio con kernel 
              separable para diferentes tamaños de kernel y de imágenes.
              
    SFNSK.svg: tiempo de ejecución del filtrado en espacio con kernel
               no separable para diferentes tamaños de kernel y de imágenes.
               
    FFNSK.svg: tiempo de ejecución del filtrado en frecuencia con kernel
               no separable para diferentes tamaños de kernel y de imágenes.
               
    F&SFNSK.svg: gráfica comparativa entre el tiempo de ejecución con filtrado
                 en frecuencia y espacio usando kernel no separables para diferentes 
                 tamaños de kernel e imágenes