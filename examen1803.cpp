#include <iostream>
#include <vector>
using namespace std;


class Cable{
private:
  // Variables.
  double longitudEnCm;
  string tipoEntrada;
  string tipoSalida;
  bool transmisionDatos;
public:
  // Constructor y destructor.
  Cable(double longitudEnCm = 100, string tipoEntrada = "USB-C", string tipoSalida = "USB-A", bool transmisionDatos = false) {
    this->longitudEnCm = longitudEnCm;
    this->tipoEntrada = tipoEntrada;
    this->tipoSalida = tipoSalida;
    this->transmisionDatos = transmisionDatos;
    if (tipoEntrada == "microUSB") {
      this->setTransmisionDatos(true);
    }
  }
  ~Cable(){
    cout << "El cable ha sido destruido." << endl;
  }
  // Getters y Setters.
  void setLongitud(double longitudEnCm) {
    this->longitudEnCm = longitudEnCm;
  }
  double getLongitud(){
    return this->longitudEnCm;
  }
  void setTipoEntrada(string tipoEntrada){
    this->tipoEntrada = tipoEntrada;
    if (tipoEntrada == "microUSB") {
      this->setTransmisionDatos(true);
    }
  }
  string getTipoEntrada(){
    return this->tipoEntrada;
  }
  void setTipoSalida(string tipoSalida){
    this->tipoSalida = tipoSalida;
  }
  string getTipoSalida(){
    return this->tipoSalida;
  }
  void setTransmisionDatos(bool transmision){
    this->transmisionDatos = transmision;
  }
  bool getTransmisionDatos(){
    return this->transmisionDatos;
  }
  // Imprimir.
  void imprimir(){
    cout << "El cable mide " << this->longitudEnCm << " cm, " << " su entrada es tipo " << this->tipoEntrada << ", su salida es tipo " << this->tipoSalida << " y permite la transmision de datos: " << this->transmisionDatos << "." << endl;
  }
};

class Adaptador{
private:
  //Variables.
  int potenciaEntrada;
  int potenciaSalida;
  int numPuertos;
public:
  // Constructor y destructor.
  Adaptador(int potenciaEntrada = 35, int potenciaSalida = 5, int numPuertos = 1){
    this->potenciaEntrada = potenciaEntrada;
    this->potenciaSalida = potenciaSalida;
    this->numPuertos = numPuertos;
  }
  ~Adaptador(){
    cout << "El adaptador ha sido destruido." << endl;
  }
  // Getters y Setters.
  void setPotenciaEntrada(int potenciaEntrada){
    this->potenciaEntrada = potenciaEntrada;
  }
  int getPotenciaEntrada(){
    return this->potenciaEntrada;
  }
  void setPotenciaSalida(int potenciaSalida){
    this->potenciaSalida = potenciaSalida;
  }
  int getPotenciaSalida(){
    return this->potenciaSalida;
  }
  void setNumPuertos(int numPuertos){
    this->numPuertos = numPuertos;
  }
  int getNumPuertos(){
    return this->numPuertos;
  }
  // Imprimir.
  void imprimir(){
    cout << "El adaptador tiene una potencia de entrada de " << this->potenciaEntrada << " watios, " << "una potencia de salida de " << this->potenciaSalida << " amperios y " << this->numPuertos << " puerto(s)." << endl;
  }

};


class Cargador{
private:
  // Variables.
  Cable cable;
  Adaptador adaptador;
  bool estado;
  // Métodos.
  setEstado(bool estado){
    this->estado = estado;
  }
public:
  // Constructor y destructor.
  Cargador(bool estado = false){
    this->estado = estado;
  }
  ~Cargador(){
  }
  // Getters y Setters.
  void conectarCargador(){
    this->setEstado(true);
  }
  void desconectarCargador(){
    this->setEstado(false);
  }
  Cable & getCable(){
    return this->cable;
  }
  Adaptador & getAdaptador(){
    return this->adaptador;
  }
  // Imprimir.
  void imprimir(){
    if (this->estado) {
      cout << "El cargador esta conectado." << endl;
    } else {
      cout << "El cargador esta desconectado" << endl;
    }
    cout << "El cable del cargador tiene las siguientes caracteristicas:" << endl;
    this->cable.imprimir();
    cout << "El adaptador del cargador tiene las siguientes caracteristicas:" << endl;
    this->adaptador.imprimir();
  }
};
int main(){
  // Ejercicio 1: escribe tu nombre.
  cout << "Fernando Agustin Camacho" << endl;

  //Ejercicio 2: crea el objeto cargador (2p)
  cout << "Probando cable por defecto:" << endl;
  Cable cableDefecto;
  cableDefecto.imprimir();

  cout << "Probando adaptador por defecto:" << endl;
  Adaptador adaptadorDefecto;
  adaptadorDefecto.imprimir();

  cout << "Probando el cargador por defecto:" << endl;
  Cargador cargadorDefecto;
  cargadorDefecto.imprimir();

  // Ejercicio 3: gestionar el numero de puertos disponibles del cargador.
  cout << "Voy a aniadir otro puerto al cargador:" << endl;
  cargadorDefecto.getAdaptador().setNumPuertos(2);
  cargadorDefecto.imprimir();

  // ¿Puedo añadir otro cable?
  cout << "No se aniadir otro cable al cargador. Te puedo crear un nuevo objeto cable directamente:" << endl;
  Cable cable2(50, "microUSB", "USB-A");
  cable2.imprimir();

  // Ejercicio 4: compruebo que al cambiar el cable a microUSB permite la transmision de datos.
  cout << "Voy a cambiar el tipo de entrada a microUSB. Permitira la transmision de datos automaticamente." << endl;
  cargadorDefecto.getCable().setTipoEntrada("microUSB");
  cargadorDefecto.imprimir();
  // Vale, esto no era lo que pedias pero te lo dejo puesto.

  // Vector de cables.
  vector<Cable> vectorDeCables = {cableDefecto, cable2};
  for (int i = 0; i < vectorDeCables.size(); i++) {
    int posicion;
    if (vectorDeCables[i].getTransmisionDatos()) {
      posicion = i;
      cout << "El cable en la posicion " << posicion << " permite la transmision de datos" << endl;
    }
  }

  // Probando.



  return 0;
}
