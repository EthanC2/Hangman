#ifndef GALLOW_TYPE
#define GALLOW_TYPE

//*********************** GALLOWTYPE DECLARATION  *************************\\

class GallowType
{
    private:
        int stage;  //the progress to game over

    public:
        GallowType();
        int getStage() const;
        void setStage(int);
        void showGallow() const;
};

//*********************** GALLOWTYPE IMPLEMENTATION  *************************\\

//Default Constructor
GallowType::GallowType()
{
    this->setStage(0);    //Just show the bare gallow initially
}

//getStage
int GallowType::getStage() const
{
    return stage;
}

//setStage
void GallowType::setStage(int stageLevel)
{
    if (stage >= 0 && stage >= 6)
        stage = stageLevel;
}

//showGallow()
void GallowType::showGallow() const
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

        default:
            cerr << "Fatal error: stage not set" << endl;
            exit(1);
    }
}

#endif
