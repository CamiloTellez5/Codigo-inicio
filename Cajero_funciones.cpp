#include <iostream>
#include <cstdlib> 
#include <stdio.h>
using namespace std;
// comentario

void limpiarPantalla();
void imprimir_menu();
void ejecutar_switch();
int contar_billetes(int r, int b);
void consultar_saldo();
long consignar(long valor);
void retirar(long valor);
bool validar_usuario(int usuario, int contrasena);
bool continuar();

long SALDO_ahorro;
long SALDO_credito = 1000000;
long SALDO_corriente = 500000;
int opcion;
long valor;
int usuario1 = 315000;
int password1 = 9876;
    
int main() {
	int user;
	int password;
	cout << "Ingrese su numero de usuario: " << endl;
	cin >> user;
	cout << "Ingrese su contrasena: " << endl;
	cin >> password;
	
	validar_usuario(user, password);
	return 0;
}


void imprimir_menu(){
  limpiarPantalla();
  cout << "\t\t Bienvenido al Cajero del estudiante Camilo Tellez.\n";
  cout << "Seleccione la operacion que desea realizar.\n";
  cout << "1. Consultar saldo.\n";
  cout << "2. Realizar una consignacion.\n";
  cout << "3. Retirar.\n";
  cout << "4. Salir.\n\n";
  cout << "Por favor, introduzca su seleccion (1, 2, 3 o 4): ";
  cin >> opcion;
  ejecutar_switch();
}

bool continuar(){
	int indicacion;
	bool seguir;
	cout << "Escriba '1' para realizar otra transaccion o '0' para salir" << endl;
	cin >> indicacion;
	if (indicacion == 1){
		seguir = true;
		imprimir_menu();
	} else {
		seguir = false;
	}
	return seguir;
}

void ejecutar_switch(){
	switch(opcion){
    case 1:
      limpiarPantalla();
      system("color B0");
      consultar_saldo();
      continuar();
      break;
    case 2:
      limpiarPantalla();
      system("color A0");
      cout << "Ingrese el valor que desea consignar: $";
      cin >> valor;
      SALDO_ahorro = consignar(valor);
      continuar();
      break;
    case 3:
      limpiarPantalla();
      system("color E0");
      retirar(valor);
      continuar();
      
      break;
    case 4:
      system("color 40");
      cout << "Saliendo del cajero, gracias por su consulta" << endl;
      break;
    default:
      cout << "No selecciono una opcion valida, intentelo de nuevo." << endl;
      continuar();
	}
}


int contar_billetes(int r, int b){
	int q = r/b;
	if (q>0){
		cout << q << " billetes de " << b << endl;
	}
	int n = r-(q*b);
	return n;
}

void consultar_saldo(){
	cout << "Su saldo es de: " << SALDO_ahorro << endl;
}

long consignar(long valor){
	SALDO_ahorro += valor;
	cout << "Su nuevo saldo es de: " << SALDO_ahorro << endl;
	return SALDO_ahorro;
}

void retirar(long valor){
	cout << "A continuacion encontrara el tipo de cuenta que tiene disponible: " << endl;
	cout << "1. Ahorros (saldo en cuenta: $" << SALDO_ahorro << ")" << endl;
	cout << "2. Credito(saldo en cuenta: $" << SALDO_credito << ")" << endl;
	cout << "3. Corriente(saldo en cuenta: $" << SALDO_corriente << ")" << endl;
	cout << "Marque el tipo de cuenta del cual desea realizar el retiro (1, 2 O 3): " << endl;
	int cuenta;
	cin >> cuenta;
	cout << "Ingrese la cantidad que desea retirar: $" << endl;
    cin >> valor;
	switch(cuenta){
		case 1:
			if (valor <= SALDO_ahorro){
		SALDO_ahorro -= valor;
		cout << "Retiro realizado satisfactoriamente" << endl;
		cout << "Su nuevo saldo es de " << SALDO_ahorro << " y su retiro sera dado en:" << endl;
		int a1 = contar_billetes(valor, 100000);
		int a2 = contar_billetes(a1, 50000);
        int a3 = contar_billetes(a2, 20000);
        int a4 = contar_billetes(a3, 10000);
        int a5 = contar_billetes(a4, 5000);
        contar_billetes(a5, 2000);
	} else {
		cout << "No hay suficiente dinero en el banco para realizar la operacion" << endl;
		SALDO_ahorro = SALDO_ahorro;
	} break;
		case 2:
			if (valor <= SALDO_credito){
		SALDO_credito -= valor;
		cout << "Retiro realizado satisfactoriamente" << endl;
		cout << "Su nuevo saldo es de " << SALDO_credito << " y su retiro sera dado en:" << endl;
		int a1 = contar_billetes(valor, 100000);
		int a2 = contar_billetes(a1, 50000);
        int a3 = contar_billetes(a2, 20000);
        int a4 = contar_billetes(a3, 10000);
        int a5 = contar_billetes(a4, 5000);
        contar_billetes(a5, 2000);
	} else {
		cout << "No hay suficiente dinero en el banco para realizar la operacion" << endl;
		SALDO_credito = SALDO_credito;
	} break;
		case 3:
		if (valor <= SALDO_corriente){
		SALDO_corriente -= valor;
		cout << "Retiro realizado satisfactoriamente" << endl;
		cout << "Su nuevo saldo es de " << SALDO_corriente << " y su retiro sera dado en:" << endl;
		int a1 = contar_billetes(valor, 100000);
		int a2 = contar_billetes(a1, 50000);
        int a3 = contar_billetes(a2, 20000);
        int a4 = contar_billetes(a3, 10000);
        int a5 = contar_billetes(a4, 5000);
        contar_billetes(a5, 2000);
	} else {
		cout << "No hay suficiente dinero en el banco para realizar la operacion";
		SALDO_corriente = SALDO_corriente;
	} break;
	default:
		cout << "No selecciono una opcion valida, intentelo de nuevo." << endl;	
	}
	
}

bool validar_usuario(int usuario, int contrasena){
	bool valido;
	if (usuario==usuario1 && contrasena==password1){
		valido = true;
		cout << "Ingrese el abono inicial para su cuenta de ahorros: " << endl;
		cin >> SALDO_ahorro;
		imprimir_menu();
	} else {
		valido = false;
		cout << "Credenciales incorrectas";
		cout << endl;
		main();
	}
	return valido;
}

void limpiarPantalla() {
    system("cls");
}





