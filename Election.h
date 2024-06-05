#include <iostream>
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
        Election();
        void setAmountOfCandidates(int _amountOfCandidates);
        void setSizeOfCandidates(int _sizeOfCandidates);
        void setVotesAmount(int _votesAmount);
        void setVotesSize(int votesSize);
        void setCandidates(string _candidates, int i);
        void setVotes(int _votes, int i);
        string getCandidates(int i);
        int getVotes(int i);
        int getCandidatesSize();
        int getCandidatesAmount();
        int getVotesSize();
        int getVotesAmount();
        ~Election();
        void getRandomNumber();
        void getCandidatesName();
        string toString();
        int getBiggerPosition();
        void showByVotesPercentage(float percentage);
        bool isWinnerDefined(float fortypercentage);
        int getAbstentionism();
        void showElectionResults();
        void getSecondRandomNumber();
        string secondToString();
        void showComparation(Election ELECCIONPROCESO22024);
    };
};

