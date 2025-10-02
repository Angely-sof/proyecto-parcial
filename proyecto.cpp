#include <iostream>
using namespace std;

const int palabras = 10;
string listapalabras[palabras] = {
	"PEZ", "PERRO", "GATO",
	"ABEJA", "JIRAFA", "ELEFANTE",
	"HAMSTER", "MAPACHE", "CISNE", "TIGRE"
};
const int maxintentos = 6;
string palabrasecreta;
string estado;
string letrasusadas = "";
int errores = 0;
int indice;
char letra;
bool acierto = false;
void seleccionarpalabra() {
	cout << "Elige un numero entre 0 y 9: ";
	cin >> indice;
	if (indice < 0 || indice >= palabras) indice = 0;
	palabrasecreta = listapalabras[indice];
}
void inicializarEstado() {
	estado = string(palabrasecreta.size(), '_');
}
void mostrarEstado() {
	cout << "Palabra:" << endl;
	for (int i = 0; i < estado.size(); i++) {
		cout << estado[i] << " ";
	}
	cout << endl;
	cout << "Intentos restantes: " << (maxintentos - errores) << endl;
	cout << "Letras usadas: " << letrasusadas << endl;
}
char validarentrada() {
	cout << "Ingresa una letra: ";
	cin >> letra;
	if (letra >= 'a' && letra <= 'z') letra -= 32;
	if (letra < 'A' || letra > 'Z') {
		cout << "Entrada invalida. Intenta otra vez."<<endl;
		return validarentrada();
	}
	for (int i = 0; i < letrasusadas.size(); i++) {
		if (letrasusadas[i] == letra) {
			cout << "Ya intentaste esa letra."<<endl;
			return validarentrada();
		}
	}
	letrasusadas += letra;
	return letra;
}
bool verificarLetra(char letra) {
    acierto = false; 
    bool letraIncorrecta = true;
	for (int e = 0; e < palabrasecreta.size(); e++) {
		if (palabrasecreta[e] == letra) {
			estado[e] = letra;
			acierto = true;
		}
	}
	return acierto;
}
bool verificarVictoria() {
	for (int o = 0; o < estado.size(); o++) {
		if (estado[o] == '_') return false;
	}
	return true;
}
int main() {
	seleccionarpalabra();
	inicializarEstado();
	cout << "JUEGO DEL AHORCADO" << endl;
	while (errores < maxintentos) {
		mostrarEstado();
		char letra = validarentrada();
		if (!verificarLetra(letra)) {
			errores++;
			cout << "Letra incorrecta!"<<endl;
		}
		if (verificarVictoria()) {
			cout << "B!Ganaste! La palabra era: " << palabrasecreta << endl;
			return 0;
		}
	}
	cout << "Has perdido. La palabra era: " << palabrasecreta << endl;
	return 0;
}
