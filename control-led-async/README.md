# Project 01: Async LED Control with ESP32

Este proyecto crear un servidor web asíncrono utilizando un ESP32 y PlatformIO para controlar el LED en tiempo real sin bloquear el código.

## ⚠️ ¡IMPORTANTE! Cómo subir la interfaz web (Carpeta `data`)

Este proyecto utiliza el sistema de archivos del ESP32 para almacenar la página web de forma separada del código de Arduino. Si solo compilas y subes el código normal, la página no cargará.

Sigue estos pasos en **PlatformIO** para subir todo correctamente:

1. Abre el menú lateral de **PlatformIO** (el icono de la hormiga).
2. Despliega la opción de tu placa (ej. `Default` o `esp32dev` o nombre de placa seleccionada).
3. Busca la sección **Platform** o **Advanced**.
4. Haz clic primero en **Build Filesystem Image** (esto empaqueta tu carpeta `data`).
5. Finalmente, haz clic en **Upload Filesystem Image** (esto sube la interfaz web al ESP32).
6. Una vez hecho eso, ya puedes presionar el botón de **Upload** normal en la barra inferior para subir el código (`main.cpp`).

## Tecnologías utilizadas

- **Framework:** Arduino
- **Gestor:** PlatformIO (VS Code)
- **Librerías:** ESPAsyncWebServer, AsyncTCP
- **Frontend:** HTML5, CSS3, JavaScript Vanilla
