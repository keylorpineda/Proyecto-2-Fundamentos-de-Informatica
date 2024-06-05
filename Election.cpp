#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;
class Election
{
private:
    string candidates[8];
    int sizeOfCandidates;
    int amountOfCandidates;
    int votes[8];
    int votesSize;
    int votesAmount;
public:
    Election()
    {
        votesSize = 8;
        votesAmount = 0;
        for (int i = 0; i < votesSize; i++)
        {
            votes[i] = 0;
        }
        sizeOfCandidates = 8;
        amountOfCandidates = 0;
        for (int i = 0; i < sizeOfCandidates; i++)
        {
            candidates[i] = "";
        }
    }
    void setAmountOfCandidates(int _amountOfCandidates)
    {
        if ((_amountOfCandidates < sizeOfCandidates) && (_amountOfCandidates > 0))
        {
            amountOfCandidates = _amountOfCandidates;
        }
    }
    void setSizeOfCandidates(int _sizeOfCandidates)
    {
        sizeOfCandidates = _sizeOfCandidates;
    }
    void setVotesAmount(int _votesAmount)
    {
        if ((_votesAmount < votesSize) && (_votesAmount > 0))
        {
            votesAmount = _votesAmount;
        }
    }
    void setVotesSize(int votsSize)
    {
        votesSize = votsSize;
    }
    void setCandidates(string _candidates, int i)
    {
        candidates[i] = _candidates;
    }
    void setVotes(int _votes, int i)
    {
        votes[i] = _votes;
    }
    string getCandidates(int i)
    {
        return candidates[i];
    }
    int getVotes(int i)
    {
        return votes[i];
    }
    int getCandidatesSize()
    {
        return sizeOfCandidates;
    }
    int getCandidatesAmount()
    {
        return amountOfCandidates;
    }
    int getVotesSize()
    {
        return votesSize;
    }
    int getVotesAmount()
    {
        return votesAmount;
    }
    ~Election()
    {
    }
    void getRandomNumber() // metodo 1
    {
        int TotalVotes = 1000000;
        if (votesAmount < votesSize)
        {
            for (int i = 0; i < votesSize; i++)
            {
                votes[i] = (rand() * 10) % TotalVotes;
                TotalVotes -= votes[i];
                votesAmount++;
            }
        }
    }
    void getCandidatesName() // metodo para asignar un nombre a cada candidato
    {
        string names[] = { "1-Keylor Pineda", "2-Adrian Granados", "3-Moises Calderon", "4-Raul Mena",
                          "5-Tirso Maldonado", "6-Fabian Vargas", "7-Cristiano Ronaldo", "8-Diego Garro" };
        for (int i = 0; i < sizeOfCandidates; i++)
        {
            candidates[i] = names[i];
        }
    }
    string toString() // metodo 2 para mandar a pantalla todos los datos
    {
        stringstream print; // mediante la libreria sstream se hace el metodo 2 para imprimir los resultados
        for (int i = 0; i < votesAmount; i++)
        {
            print << "El Candidato " << candidates[i] << " tuvo: "
                << votes[i] << " votos" << endl;
        }
        return print.str();
    }
    int getBiggerPosition() // metodo 3 para obtener la posicion con mas datos
    {
        int position = 0;
        int max = votes[0];
        for (int i = 1; i < votesSize; i++)
        {
            if (votes[i] > max)
            {
                position = i;
                max = votes[i];
            }
        }
        return position + 1;
    }
    void showByVotesPercentage(float percentage) // metodo 4
    {
        cout << "\nCandidatos con mas del 30% de los votos totales: " << endl;
        int additionOfVotes = 0;
        for (int i = 0; i < votesSize; i++)
        {
            additionOfVotes += votes[i];
        }
        for (int i = 0; i < votesSize; i++)
        {
            float votesPercentage = (votes[i] * 100) / additionOfVotes;
            if (votesPercentage >= percentage)
            {
                cout << "\nEl candidato " << candidates[i] << " tuvo: "
                    << votesPercentage << "% de los votos totales" << endl;
            }
        }
    }
    bool isWinnerDefined(float fortypercentage) // metodo 5
    {
        int additionOfVotes = 0;
        for (int i = 0; i < votesSize; i++)
        {
            additionOfVotes += votes[i];
        }
        for (int i = 0; i < votesSize; i++)
        {
            float votesPercentage = (votes[i] * 100.0) / additionOfVotes;
            if (votesPercentage >= fortypercentage)
            {
                return true;
            }
        }
        return false;
    }
    int getAbstentionism() // metodo 6
    {
        int additionOfVotes = 0;
        for (int i = 0; i < votesSize; i++)
        {
            additionOfVotes += votes[i];
        }
        return 1000000 - additionOfVotes; // la suma de los votos correspondientes de cada candidato se le resta al millon de votos totales
    }
    void showElectionResults() // metodo 7
    {
        int fortypercentage = 40;
        if (!isWinnerDefined(fortypercentage))
        {
            cout << "Se necesita segunda ronda para las elecciones debido a que ningun candidato obtuvo mas del 40% de los votos totales." << endl;
        }
        else
        {
            int candidateWinner = getBiggerPosition();
            cout << "\nEl candidato ganador es " << candidates[candidateWinner - 1]
                << " con mas del 40% de los votos." << endl;
        }
    }
    void getSecondRandomNumber() // metodo segunda eleccion
    {
        int TotalVotes = 1000000;
        if (votesAmount < votesSize)
        {
            for (int i = 0; i < votesSize; i++)
            {
                votes[i] = (rand() * 10) % TotalVotes;
                TotalVotes -= votes[i];
                votesAmount++;
            }
        }
    }
    string secondToString() // metodo para la segunda eleccion
    {
        stringstream secondElection; // mediante la libreria sstream se hace el metodo 2 para imprimir los resultados
        for (int i = 0; i < votesAmount; i++)
        {
            secondElection << "El Candidato " << candidates[i] << " tuvo: "
                << votes[i] << " votos" << endl;
        }
        return secondElection.str();
    }
    void showComparation(Election ELECCIONPROCESO22024) // metodo 8
    {
        int secondVotes[8];
        for (int i = 0; i < votesSize; i++)
        {
            secondVotes[i] = ELECCIONPROCESO22024.getVotes(i); // se crea un for para la segunda eleccion
        }
        cout << "\nBienvenido al sistema de comparacion de las elecciones: " << endl;
        cout << "\nEstos fueron los candidatos que participaron en las 2 elecciones: " << endl;
        stringstream printCandidates;
        for (int i = 0; i < votesAmount; i++)
        {
            printCandidates << "El Candidato: " << candidates[i] << endl;
        }
        cout << printCandidates.str();
        int additionOfVotes = 0;
        for (int i = 0; i < votesSize; i++)
        {
            additionOfVotes += votes[i];
        }
        cout << "\nLos votos totales de la primera eleccion fueron: "
            << additionOfVotes << endl;
        int secondAdditionOfVotes = 0;
        for (int i = 0; i < votesSize; i++)
        {
            secondAdditionOfVotes += secondVotes[i];
        }
        cout << "\nLos votos totales de la segunda eleccion fueron: " << secondAdditionOfVotes << endl;
        int firstCandidate = getBiggerPosition() - 1;
        int secondCandidate = ELECCIONPROCESO22024.getBiggerPosition() - 1;
        int abstencionism = 1000000 - additionOfVotes;
        int secondAbstencionism = 1000000 - secondAdditionOfVotes;
        float votesPercentage = (abstencionism * 100.0) / 1000000;
        float secondVotesPercentage = (secondAbstencionism * 100.0) / 1000000;
        cout << "\nCandidatos Ganadores en las 2 rondas: " << endl;
        cout << "\nEl candidato ganador de la primera ronda fue: " << candidates[firstCandidate] << endl;
        cout << "\nEl candidato ganador de la segunda ronda fue: " << ELECCIONPROCESO22024.getCandidates(secondCandidate) << endl;
        cout << "\nEl porcentaje de abstencionismo de la primer eleccion fue: " << votesPercentage << "%" << endl;
        cout << "\nEl porcentaje de abstencionismo de la segunda eleccion fue: " << secondVotesPercentage << "%" << endl;
    }
};