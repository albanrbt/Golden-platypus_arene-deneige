#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <windows.h>

#define TOURS 50
#define MALADIE 66
#define TAILLE 10
#define CHANCE 2
#define SOL 0
#define KIT 44
#define PIEGE 33
#define RADAR 3
#define TAILLE_IMAGES 60
#define NB_JOUEURS 5

/// LES PROTOTYPES

void pause();

int Degats(int Nb_Vies[30],int joueur); // initialise les degats

int main();

void ClearTerms(); // clear la console

void Wait(); // fait une pause

int coord_JoueursX(int tab[TAILLE][TAILLE],int joueurs); // dopnne le X de chaque joueur

int coord_JoueursY(int tab[TAILLE][TAILLE],int joueurs); // donne le Y de chaque joueur

int fin_jeu(int tab[TAILLE][TAILLE], int joueur, SDL_Surface *ecran); // declare la fin du jeu

int Nombre_Joueurs(); // donne le nombre de joueurs dans la partie

int Numero_Joueur(int tab[TAILLE][TAILLE],int test); // recupere le numero du joueur suivant ses coordonnees

void Propagation_Maladie(int tab[TAILLE][TAILLE],int joueur,int Nb_Vies[30], SDL_Surface *ecran); // propage la maladie

int IA (int joueur, SDL_Surface *ecran, int tab[TAILLE][TAILLE]);

int Shifumi (int J1, int J2, int joueur, int tab[TAILLE][TAILLE], SDL_Surface *ecran); // lance le shifumi si egalite entre 2 joueurs

void Spawn_Bonus(int tab[TAILLE][TAILLE], SDL_Surface *ecran); // fait spawn les bonus

void Spawn_Joueurs(int tab[TAILLE][TAILLE],int nb_joueurs, SDL_Surface *ecran); // fait spawn les joueurs avec 2 cases d'ecart avec la maladie

void Spawn_Maladie (int tab[TAILLE][TAILLE], SDL_Surface *ecran); // fait spawn la maladie

void Spawn_Piege(int tab[TAILLE][TAILLE], SDL_Surface *ecran); // fait spawn les pieges

void Tour_par_Tour(int tab[TAILLE][TAILLE],int nb_joueurs,int Nb_Vies[30], SDL_Surface *ecran); // execute les actions des joueurs

void Afficher_carte(int tab[TAILLE][TAILLE], SDL_Surface *ecran);

int jeu(SDL_Surface *ecran);

void pause();

void SetColor(int ForgC);

void Menu(SDL_Surface *ecran);

void ClearTerms(){

    system("cls");

}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}


void Wait(){

    system("pause");

}

void SetColor(int ForgC)
{
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

  CONSOLE_SCREEN_BUFFER_INFO csbi;



  if(GetConsoleScreenBufferInfo(hStdOut, &csbi))

  {

    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);

    SetConsoleTextAttribute(hStdOut, wColor);

  }



}

int IA(int joueur,SDL_Surface *ecran,int tab[TAILLE][TAILLE])
{


    int action;

    switch(joueur)

    {

    case 1:

        action = 0;
        break;

    case 2:

        action = 1;
        break;

    case 3:

        action = 2;
        break;

    case 4:

        action = 3;
        break;

    case 5:

        action = 4;
        break;

     case 6:

        ///code IA
        break;

     case 7:

        ///code IA
        break;

     case 8:

        ///code IA
        break;

     case 9:

        ///code IA
        break;

     case 10:

        ///code IA
        break;

     case 11:

        ///code IA
        break;

     case 12:

        ///code IA
        break;

     case 13:

        ///code IA
        break;

     case 14:

        ///code IA
        break;

     case 15:

        ///code IA
        break;

     case 16:

        ///code IA
        break;

     case 17:

        ///code IA
        break;

     case 18:

        ///code IA
        break;

     case 19:

        ///code IA
        break;

     case 20:

        ///code IA
        break;

     case 21:

        ///code IA
        break;

     case 22:

        ///code IA
        break;

     case 23:

        ///code IA
        break;

     case 24:

        ///code IA
        break;

     case 25:

        ///code IA
        break;

     case 26:

        ///code IA
        break;

     case 27:

        ///code IA
        break;

     case 28:

        ///code IA
        break;

     case 29:

        ///code IA
        break;

     case 30:

        ///code IA
        break;

    }

    return action;
}


int coord_JoueursX(int tab[TAILLE][TAILLE],int joueurs){

    int i,j,x;

    for (i=0;i<TAILLE;i++){

        for(j=0;j<TAILLE;j++){

            if (tab[i][j] == joueurs){

                x = i;

                return x;

            }
        }
}
    return 0;
}

int coord_JoueursY(int tab[TAILLE][TAILLE],int joueurs){

    int i,j,y;

    for (i=0;i<TAILLE;i++){

        for(j=0;j<TAILLE;j++){

            if (tab[i][j] == joueurs){

                y = j;

                return y;

}
}
}
    return 0;
}

void Propagation_Maladie(int tab[TAILLE][TAILLE],int joueur,int Nb_Vies[30], SDL_Surface *ecran){

    int i,j;
    int test;
    int degats;
    int tab1[TAILLE][TAILLE];


    srand(time(NULL));

    for(i=0;i<TAILLE;i++){

        for(j=0;j<TAILLE;j++){

            tab1[i][j] = tab[i][j];

}
}

    for (i=0;i<TAILLE-1;i++){

        for(j=0;j<TAILLE-1;j++){

            if (tab[i][j] == MALADIE){


                test = rand()%CHANCE;   // 1 CHANCE sur 5 que la MALADIE se propage



                if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){ // Propagation de la MALADIE

                    if (tab[i-1][j] >= 1 && tab[i-1][j]<=30){

                        degats = Degats(Nb_Vies,joueur);

                }

                if (degats == 0){
                    tab1[i-1][j] = MALADIE;

            }

                else
                    {

                    tab1[i-1][j] = MALADIE;
                }
                }



                test = rand()%CHANCE;

                    if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){

                        if (tab[i+1][j] >= 1 && tab[i+1][j] <= 30){


                            degats = Degats(Nb_Vies,joueur);

}

                if (degats == 0){

                    tab1[i+1][j] = MALADIE;

}

                else{

                   tab1[i+1][j] = MALADIE;

                }
                }


                test = rand()%CHANCE;

                if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){


                    if (tab[i][j-1] >= 1 && tab[i][j-1] <= 30){

                        degats = Degats(Nb_Vies,joueur);

}

                if (degats == 0){

                    tab1[i][j-1] = MALADIE;

}
                else

                    {

                    tab1[i][j-1] = MALADIE;

                    }
                }

                test = rand()%CHANCE;

                if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){


                    if (tab[i][j+1] >= 1 && tab[i][j+1] <= 30){


                        degats = Degats(Nb_Vies,joueur);

                    }


                 if (degats == 0){

                    tab1[i][j+1] = MALADIE;

}

                    else

                        {

                        tab1[i][j+1] = MALADIE;

                    }

                }

}

}
}
    Afficher_carte(tab,ecran);
    SDL_Flip(ecran);
    SDL_Delay(100);

    for(i=0;i<TAILLE;i++){


        for(j=0;j<TAILLE;j++){


            tab[i][j] = tab1[i][j];

        }
    }

    }


void Bonus(int Nb_Vies[30],int joueur){

    Nb_Vies[joueur-1] = Nb_Vies[joueur-1] + 1;

}

int Degats(int Nb_Vies[30],int joueur){

    Nb_Vies[joueur-1] = Nb_Vies[joueur-1] - 1;

    if (Nb_Vies[joueur-1] <= 0){

        return 0;

    }
    else
    {
        return 1;

    }
}

void Tour_par_Tour(int tab[TAILLE][TAILLE],int nb_joueurs,int Nb_Vies[30], SDL_Surface *ecran){ /// La fonction qui lance les différentes actions a faire (ou les execute)

    int i, x, y;
    int action;
    int degats;

        for (i=1;i<= nb_joueurs+1;i++)

        {
            x = coord_JoueursX(tab,i);

            y = coord_JoueursY(tab,i);

            action = IA(i,ecran, tab);



       if (action == 1){ ///en bas


            if ((tab[x+1][y] == PIEGE) || (tab[x+1][y] == MALADIE))

                {

                degats = Degats(Nb_Vies,i);


            if (degats == 1)
            {
                tab[x][y] = 0;

                tab[x+1][y] = i;



            if (tab[x+1][y]== KIT)
                {

                Bonus(Nb_Vies,i);
                }
            }
       }
       }

       else if (action == 2){///en haut

            tab[x][y] = 0;

            tab[x-1][y] = i;



            if (tab[x-1][y] == KIT)
                {

                Bonus(Nb_Vies,i);

            }

            else if ((tab[x-1][y] == PIEGE) || (tab[x-1][y] == MALADIE))
                {

                Degats(Nb_Vies,i);

            }

       }


       else if (action == 3){/// a droite

          tab[x][y] = 0;

          tab[x][y+1] = i;



            if (tab[x][y+1] == KIT)
                {

                Bonus(Nb_Vies,i);

            }

            else if ((tab[x][y+1] == PIEGE) || (tab[x][y+1] == MALADIE)){

                Degats(Nb_Vies,i);

            }

       }



       else if (action == 4){ /// a gauche

        tab[x][y] = 0;

        tab[x][y-1] = i;



            if (tab[x][y-1] == KIT)
            {

                Bonus(Nb_Vies,i);

            }

            else if ((tab[x][y-1] == PIEGE) || (tab[x][y-1] == MALADIE))
                {

                Degats(Nb_Vies,i);

            }

       }



       else if (action == 0){ /// pas bouger

        tab[x][y] = i;

       }

        }

            Afficher_carte(tab,ecran);
            SDL_Flip(ecran);
            SDL_Delay(100);
}

void Spawn_Joueurs(int tab[TAILLE][TAILLE],int nb_joueurs, SDL_Surface *ecran){

    int x,y,i;

    int X_maladie,Y_maladie;

    SDL_Surface *perso = NULL;
    SDL_Rect position_Perso;

    perso = IMG_Load("perso.png");

    X_maladie = coord_JoueursX(tab,MALADIE);

    Y_maladie = coord_JoueursY(tab,MALADIE);

    srand(time(NULL));

    for (i=1;i<=nb_joueurs;i++){

        do {

            x = rand()%TAILLE;

            y = rand()%TAILLE;


        }

        while (tab[x][y] != SOL || (x > (X_maladie-RADAR) && x < (X_maladie+RADAR)) || (y > (Y_maladie-RADAR) && y < (Y_maladie+RADAR)));

        tab[x][y] = i;

        position_Perso.x = x * TAILLE_IMAGES;
        position_Perso.y = y * TAILLE_IMAGES;

        SDL_BlitSurface(perso, NULL, ecran, &position_Perso);

        SDL_Flip(ecran);
        SDL_Delay(200);
    }

}

void Spawn_Maladie (int tab[TAILLE][TAILLE], SDL_Surface *ecran){

    int x,y;

    SDL_Surface *maladie = NULL;
    SDL_Rect position_Maladie;

    maladie = IMG_Load("maladie.png");

    srand(time(NULL));

    do

    {

    x = rand()%TAILLE-1; //spawn de la MALADIE aléatoire

    y = rand()%TAILLE-1;

    }

    while (x<1 || x>TAILLE-1 || y<1 || y>TAILLE-1);

    tab[x][y] = MALADIE;

    position_Maladie.x = x * TAILLE_IMAGES;
    position_Maladie.y = y * TAILLE_IMAGES;

    SDL_BlitSurface(maladie, NULL, ecran, &position_Maladie);

    SDL_Flip(ecran);
    SDL_Delay(200);
}

void Spawn_Piege(int tab[TAILLE][TAILLE], SDL_Surface *ecran){

    int x,y;

    SDL_Surface *piege = NULL;
    SDL_Rect position_Piege;

    piege = IMG_Load("potion.png");

    srand(time(NULL));

    do

    {

        x = rand()%TAILLE;

        y = rand()%TAILLE;

    }
    while (tab[x][y] != SOL);

    tab[x][y] = PIEGE;

    position_Piege.x = x * TAILLE_IMAGES;
    position_Piege.y = y * TAILLE_IMAGES;

    SDL_BlitSurface(piege, NULL, ecran, &position_Piege);

    SDL_Flip(ecran);
    SDL_Delay(200);
}

void Spawn_Bonus(int tab[TAILLE][TAILLE], SDL_Surface *ecran){

    int x,y;

    SDL_Surface *kit = NULL;
    SDL_Rect position_Kit;

    kit = IMG_Load("medic_kit.png");

    srand(time(NULL));

    do

    {

        x = rand()%TAILLE;

        y = rand()%TAILLE;

    }

    while (tab[x][y] != SOL);

    tab[x][y] = KIT;

    position_Kit.x = x * TAILLE_IMAGES;
    position_Kit.y = y * TAILLE_IMAGES;

    SDL_BlitSurface(kit, NULL, ecran, &position_Kit);

    SDL_Flip(ecran);
    SDL_Delay(200);
}

void Afficher_carte(int tab[TAILLE][TAILLE], SDL_Surface *ecran){

    int i,j;


    SDL_Surface *terre_normale = NULL;
    SDL_Surface *maladie = NULL;
    SDL_Surface *kit = NULL;
    SDL_Surface *piege = NULL;
    SDL_Surface *perso = NULL;

    piege = IMG_Load("potion.png");
    maladie = IMG_Load("maladie.png");
    terre_normale = IMG_Load("Terre_normale_V1.png");
    kit = IMG_Load("medic_kit.png");
    perso = IMG_Load("perso.png");





    for (i=0;i<TAILLE;i++)

    {

        for(j=0;j<TAILLE;j++){

            if (tab[i][j] == SOL)
                {

                SDL_Rect position_Terre;

                position_Terre.x = i * TAILLE_IMAGES;
                position_Terre.y = j * TAILLE_IMAGES;
                SDL_BlitSurface(terre_normale, NULL, ecran, &position_Terre);

            }

           else if (tab[i][j] == MALADIE)
            {

                SDL_Rect position_Maladie;

                position_Maladie.x = i * TAILLE_IMAGES;
                position_Maladie.y = j * TAILLE_IMAGES;
                SDL_BlitSurface(maladie, NULL, ecran, &position_Maladie);
            }

           else if (tab[i][j] == KIT)
            {
                SDL_Rect position_Kit;

                position_Kit.x = i * TAILLE_IMAGES;
                position_Kit.y = j * TAILLE_IMAGES;
                SDL_BlitSurface(kit, NULL, ecran, &position_Kit);


            }

           else if (tab[i][j] == PIEGE)
            {
                SDL_Rect position_Piege;

                position_Piege.x = i * TAILLE_IMAGES;
                position_Piege.y = j * TAILLE_IMAGES;
                SDL_BlitSurface(piege, NULL, ecran, &position_Piege);


            }
            else if ((tab[i][j] >= 1) && (tab[i][j] <= 30))
            {
                SDL_Rect position_Perso;

                position_Perso.x = i * TAILLE_IMAGES;
                position_Perso.y = j * TAILLE_IMAGES;
                SDL_BlitSurface(perso, NULL, ecran, &position_Perso);


            }
        }

    }
    SDL_Flip(ecran);
    SDL_Delay(50);
}

int Nombre_Joueurs(){

int nb_joueurs;

    printf("Combien de joueurs: ");

    scanf("%d", &nb_joueurs);

    printf("\n");


    return nb_joueurs;

}

int Numero_Joueur(int tab[TAILLE][TAILLE],int test)

{

    int i,j,x;

    for (i=0;i<TAILLE;i++)

        {

        for(j=0;j<TAILLE;j++)

        {

            if ((tab[i][j]>= 1) && (tab[i][j]<= 30) && (tab[i][j]!= test))

            {

                x = tab[i][j];

            }

        }

        }

        return x;

}

int Shifumi (int J1, int J2,int joueur,int tab[TAILLE][TAILLE], SDL_Surface *ecran)
{

    int i,jeu_1,jeu_2;

    int pierre = 1;
    int ciseaux = 2 ;
    int feuille = 3;
    int gagnant = 0;


    printf("bataille entre  joueur %d et joueur %d :", J1,J2);

    do

    {

        for (i=0; i<3; i++)

        {

            jeu_1 = IA(joueur,ecran,tab);

            jeu_2 = IA(joueur,ecran,tab);

        }

        if ((jeu_1 == pierre) && (jeu_2 == pierre))

        {

            printf("LES DEUX JOUEURS ONT FAIT PIERRE \n");

        }

        else if ((jeu_1 == ciseaux) && (jeu_2 == ciseaux))

        {

            printf("LES DEUX JOUEURS ONT FAIT CISEAUX\n");

        }

        else if ((jeu_1 == feuille) && (jeu_2 == feuille))

        {

            printf("LES DEUX JOUEURS ONT FAIT FEUILLE");

        }

        else if ((jeu_1 == pierre) && (jeu_2 == ciseaux))

        {

            printf(" Aie aie joueur %d a casse ses ciseaux contre la pierre de joueur %d\n",J2,J1);

            gagnant = J1;

        }

        else if ((jeu_1 == ciseaux) && (jeu_2 == pierre))

        {

             printf(" Aie aie joueur %d a casse ses ciseaux contre la pierre de joueur %d \n",J1,J2);

            gagnant = J2;

        }

        else if ((jeu_1 == ciseaux) && (jeu_2 == feuille))

        {

            printf(" Joueur %d a appris a Joueur %d comment reduire en confettis un mauvais bulletin \n",J1,J2);

            gagnant = J1;

        }

        else if ((jeu_1 == feuille) && (jeu_2 == ciseaux))

        {

            printf(" Joueur %d a appris a Joueur %d comment reduire en confettis un mauvais bulletin\n ",J2,J1);

            gagnant = J2;

        }

        else if ((jeu_1 == pierre) && (jeu_2 == feuille))

        {

            printf("joueur %d viens d'emballer a la perfection la pierre de Joueur %d dans sa feuille\n", J2,J1);

            gagnant = J2;

        }

        else if ((jeu_1 == feuille) && (jeu_2 == pierre))

        {

             printf("joueur %d viens d'emballer a la perfection la pierre de Joueur %d dans sa feuille \n", J1,J2);

             gagnant = J1;

        }

    } while (gagnant == 0);

    return gagnant;

}

int Afficher_Gagnant(int gagnant)
{

    ClearTerms();

    printf("\n");

    printf("===========================================\n \n \n \n");

    printf("      LE GAGNANT EST LE JOUEUR %d !!! \n \n \n \n", gagnant);

    printf("=========================================== \n \n");

    Wait();

    return 1;

}

int fin_jeu (int tab[TAILLE][TAILLE],int joueur, SDL_Surface *ecran)
{

    int i,j,y;
    int joueur_Restant, test, Joueur1, Joueur2, cas, gagnant;


    test=0;

    y=0;

    joueur_Restant = 0;

    for (i=0;i<TAILLE;i++){


        for(j=0;j<TAILLE;j++){

            if ((tab[i][j]>= 1) && (tab[i][j]<= 30)){

                joueur_Restant = joueur_Restant+1;

            }

        }

    }


     if (joueur_Restant == 2)

     {

         cas = 2;

         Joueur1 = Numero_Joueur(tab,test);

         test = Joueur1;

         Joueur2 = Numero_Joueur(tab,test);

     }

    if (joueur_Restant > 2)

    {

        cas = 3;

    }

     if (joueur_Restant == 0)

    {

        if (cas == 2)

        {

            gagnant = Shifumi(Joueur1, Joueur2, joueur, tab, ecran);

            y = Afficher_Gagnant(gagnant);

        }

        else if (cas == 3)

        {

            printf("pas de gagnant, on relance la partie");

            Wait();

            ClearTerms();

            Menu(ecran);

        }

    }

    if (joueur_Restant == 1)

    {

        gagnant = Numero_Joueur(tab,test);

        y = Afficher_Gagnant(gagnant);

    }

 return y;

}

int jeu (SDL_Surface *ecran)
{
    int i,j;
    int tab[TAILLE][TAILLE];
    int nb_joueurs;
    int Nb_Vies[30];
    int joueur = 1;  /// Le joueur qui joue actuellement
    int gagnant;



    for (i=0;i<TAILLE;i++){

        for(j=0;j<TAILLE;j++){

            SetColor(0);

            tab[i][j] = 0;

        }

    }

    SetColor(255);

    /*do

    {

       nb_joueurs = Nombre_Joueurs();

    }

    while (nb_joueurs <= 0);*/

    nb_joueurs = NB_JOUEURS;

    for(i=0;i<30;i++){

        Nb_Vies[i] = 1;

    }

    Spawn_Maladie(tab,ecran);

    Spawn_Joueurs(tab,nb_joueurs,ecran);

    Spawn_Bonus(tab,ecran);

    Spawn_Piege(tab,ecran);


    for (i=0;i<TOURS;i++){


            Afficher_carte(tab, ecran);

            Tour_par_Tour(tab,nb_joueurs,Nb_Vies,ecran);

            Propagation_Maladie(tab,joueur,Nb_Vies,ecran);

            /*gagnant = fin_jeu(tab,joueur, ecran);

            if (gagnant == 1)

            {

                return 0;

            }

            else {

            Wait();

            ClearTerms();

            }*/

    }

    return 0;
}

void Menu(SDL_Surface* ecran)
{
    int choix = 1;

    do
    {

    ClearTerms();
    SetColor(255);

    /*printf("====== Menu ======\n\n");
    printf("Choisir une action\n");
    printf("1. Jouer\n");
    printf("2. Quitter\n\n");
    printf("==================\n");
    scanf("%d", &choix);*/

    if(choix == 1)
    {
        jeu(ecran);
    }

    }
    while (choix!=2);

}


int main (int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *terre_normale = NULL;
    SDL_Surface *maladie = NULL;
    SDL_Surface *kit = NULL;
    SDL_Surface *piege = NULL;

    piege = IMG_Load("potion.png");
    maladie = IMG_Load("maladie.png");
    terre_normale = IMG_Load("Terre_normale_V1.png");
    kit = IMG_Load("medic_kit.png");


    SDL_Init(SDL_INIT_VIDEO); /// initialiser la fenetre

    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL); /// mettre une icone sur la barre

    ecran = SDL_SetVideoMode(620, 620, 32, SDL_HWSURFACE); /// initialiser la taille de la fenetre
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL); /// titre de la barre

    Menu(ecran);

    pause();



    SDL_FreeSurface(kit);
    SDL_FreeSurface(piege);
    SDL_FreeSurface(terre_normale); ///liberer
    SDL_FreeSurface(maladie);
    SDL_Quit();

    return EXIT_SUCCESS;
}

