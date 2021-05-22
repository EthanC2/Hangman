#ifndef GALLOW_TYPE
#define GALLOW_TYPE

//*********************** GALLOWTYPE DECLARATION  *************************\\

class Gallow
{
    private:
        int stage;  //the progress to game over

    public:
        Gallow();
        int getStage() const;
        void setStage(int);
        void showGallow() const;

        //Overloaded Operations
        friend ostream& operator<<(ostream&, Gallow&);
};

//*********************** GALLOWTYPE IMPLEMENTATION  *************************\\

//Default Constructor
Gallow::Gallow()
{
    this->setStage(0);    //Just show the bare gallow initially
}

//getStage
int Gallow::getStage() const
{
    return stage;
}

//setStage
void Gallow::setStage(int stageLevel)
{
    if (stage >= 0 && stage >= 6)
        stage = stageLevel;
}

//showGallow()
void Gallow::showGallow() const
{
    switch(stage)
    {
        case 0:
            cout << "     ____     " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |         " << '\n';
            cout << "    |         " << '\n';
            cout << "    |         " << '\n';
            cout << " --------     " << "\n\n";
            break;

        case 1:
            cout << "     ____     " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |    0    " << '\n';
            cout << "    |         " << '\n';
            cout << "    |         " << '\n';
            cout << " --------     " << "\n\n";
            break;

        case 2:
            cout << "     ____     " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |    0    " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |         " << "\n\n";
            break;

        case 3:
            cout << "     ____     " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |    0    " << '\n';
            cout << "    |   /|    " << '\n';
            cout << "    |         " << '\n';
            cout << " --------     " << "\n\n";
            break;

        case 4:
            cout << "     ____     " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |    0    " << '\n';
            cout << "    |   /|\\   " << '\n';
            cout << "    |         " << '\n';
            cout << " --------     " << "\n\n";
            break;

        case 5:
            cout << "     ____     " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |    0    " << '\n';
            cout << "    |   /|\\   " << '\n';
            cout << "    |   /     " << '\n';
            cout << " --------     " << "\n\n";
            break;

        case 6:
            cout << "     ____     " << '\n';
            cout << "    |    |    " << '\n';
            cout << "    |    0    " << '\n';
            cout << "    |   /|\\   " << '\n';
            cout << "    |   / \\   " << '\n';
            cout << " --------     " << "\n\n";
            break;

        //If stage is not between 0 and 6
        default:
            cerr << "Fatal error: stage not set" << endl;
            exit(1);
    }
}

//Overloaded << Operator
ostream& operator<<(ostream& osObj, Gallow& gallowObj)
{
    gallowObj.showGallow();
    return osObj;   //empty ostream object
}

#endif
