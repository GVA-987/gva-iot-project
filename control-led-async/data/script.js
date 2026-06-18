// Seleccionamos el botón del HTML por su ID
const botonLed = document.getElementById("toggleButton");

// Escuchamos el clic del usuario
botonLed.addEventListener("click", () => {
  // Hacemos la petición asíncrona al ESP32 sin recargar la página
  fetch("/toggle-led")
    .then((response) => response.text()) // Leemos la respuesta ("Encendido" o "Apagado")
    .then((estado) => {
      console.log("El ESP32 menciona su estado:", estado);

      // Cambiamos el texto del botón según lo que respondió el ESP32
      if (estado === "Encendido") {
        botonLed.innerText = "Apagar LED"; // Cambiamos el texto del botón
        botonLed.classList.add("on"); // Agregamos una clase para cambiar el estilo
      } else {
        botonLed.innerText = "Encender LED";
        botonLed.classList.remove("on");
      }
    })
    .catch((error) => console.error("Error en la petición:", error));
});
