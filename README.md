# Práctica 4 - Procesamiento e Interpolación de Imágenes Táctiles

## Objetivos

* Leer y procesar archivos JSON en C++.
* Validar matrices de tamaño 16x16.
* Implementar interpolación bilineal manual.
* Desarrollar comunicación cliente-servidor mediante HTTP.
* Generar imágenes científicas utilizando Python y Matplotlib.
* Almacenar automáticamente las imágenes generadas.


### Cliente C++

* C++
* nlohmann/json
* libcurl

### Servidor Python

* Flask
* NumPy
* Matplotlib

---

## Estructura del proyecto

practica_4_
├── cpp_client
│   ├── include
│   ├── src
│   └── client
│
├── python_server
│   ├── server.py
│   └── images
│
└── tactile_captures_50.json


## Funcionamiento del sistema

1. Lectura del archivo JSON.
2. Validación de las 50 matrices de entrada.
3. Interpolación bilineal de 16x16 a 128x128.
4. Envío de cada matriz mediante HTTP POST.
5. Recepción de datos en el servidor Flask.
6. Generación de imágenes táctiles.
7. Almacenamiento de las imágenes generadas.


## Guía de ejecución

### 1. Iniciar el servidor Python

Abrir una terminal y ejecutar:

```bash
cd python_server
python3 server.py
```

El servidor quedará escuchando en:

```text
http://127.0.0.1:5000
```

---

### 2. Compilar el cliente C++

Abrir una segunda terminal:

```bash
cd cpp_client

g++ src/*.cpp -lcurl -o client
```

---

### 3. Ejecutar el cliente

```bash
./client
```

Durante la ejecución el sistema:

* Leerá las 50 capturas.
* Validará las matrices.
* Aplicará interpolación bilineal.
* Enviará las matrices al servidor.

---

### 4. Verificar los resultados

Las imágenes generadas se almacenan automáticamente en:

```text
python_server/images
```

Para comprobar el número de imágenes:

```bash
ls images | wc -l
```

Resultado esperado:

```text
50
```

---

## Resultados obtenidos

El sistema procesa correctamente las 50 capturas táctiles proporcionadas.

Se verifica que todas las matrices originales poseen dimensiones 16x16 y posteriormente se generan matrices interpoladas de 128x128 mediante interpolación bilineal.

Las matrices procesadas son enviadas correctamente al servidor Flask y finalmente se generan 50 imágenes PNG que representan visualmente los mapas de presión táctil.

---

## Conclusiones

La práctica ha permitido integrar conceptos relacionados con:

* Procesamiento de matrices.
* Interpolación numérica.
* Programación modular en C++.
* Comunicación cliente-servidor.
* Visualización científica de datos.

El resultado final es un sistema funcional capaz de transformar datos táctiles de baja resolución en representaciones visuales de mayor calidad para aplicaciones robóticas.
