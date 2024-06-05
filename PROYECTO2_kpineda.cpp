#include <iostream>
#include <ctime>
#include <sstream>  
#include "Election.cpp"   
using namespace std;
int main()
{
    srand(time(NULL));
    float percentage = 30.0;
    float fortyPercentage = 40.0;
    cout << "Bienvenido al sistema de elecciones de Costa Linda" << endl;
    cout << "\nDichas elecciones cuentan con 8 candidatos" << endl;
    cout << "\nEste pais cuenta con un millon de habitantes" << endl;
    cout << "\nIngrese 1 para ver los resultados de la primera eleccion: ";
    int optionElection;
    cin >> optionElection;
    switch (optionElection)
    {
    case 1:
    {
        cout << "\nA continuacion, los resultados de la primera ronda de votaciones del pais Costa Linda." << endl;
        Election ELECCIONPROCESO12024;
        ELECCIONPROCESO12024.getCandidatesName();
        ELECCIONPROCESO12024.getRandomNumber();
        cout << "\n" << ELECCIONPROCESO12024.toString();
        cout << "\nEl abstencionismo de la primera eleccion fue de: "
            << ELECCIONPROCESO12024.getAbstentionism() << endl;
        cout << "\nLa posicion con mayor numero de votos es: "
            << ELECCIONPROCESO12024.getBiggerPosition() << endl;
        ELECCIONPROCESO12024.showByVotesPercentage(percentage);
        if (ELECCIONPROCESO12024.isWinnerDefined(fortyPercentage))
        {
            cout << "\nLa eleccion termino porque un candidato obtuvo mas del 40% de los votos." << endl;
            ELECCIONPROCESO12024.showElectionResults();
        }
        else
        {
            cout << "\nNo hay candidato con mas del 40% de los votos, se necesita una segunda eleccion." << endl;
            int secondOptionElection;
            cout << "\nDigite 1 para ver los resultados de la segunda ronda: ";
            cin >> secondOptionElection;

            switch (secondOptionElection)
            {
            case 1:
            {
                Election ELECCIONPROCESO22024; 
                ELECCIONPROCESO22024.getCandidatesName();
                ELECCIONPROCESO22024.getSecondRandomNumber();
                cout << "\nLos resultados de la segunda ronda de elecciones en Costa Linda: " << endl;
                cout << ELECCIONPROCESO22024.secondToString();
                cout << "\nEl abstencionismo en la segunda eleccion fue de: "
                    << ELECCIONPROCESO22024.getAbstentionism() << endl;
                ELECCIONPROCESO22024.showByVotesPercentage(percentage);
                cout << "\nEl candidato ganador de la segunda ronda es el numero: "
                    << ELECCIONPROCESO22024.getBiggerPosition() << endl;
                int opcion;
                cout << "\nIngrese 1 para ver la comparacion de las elecciones: ";
                cout << "\nIngrese 2 para salir del sistema de votaciones: " << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    ELECCIONPROCESO12024.showComparation(ELECCIONPROCESO22024);
                    break;
                case 2:
                    break;
                default:
                    break;
                }
                break;
            }
            default:
                break;
            }
        }
        return 0;
    }
    }
}