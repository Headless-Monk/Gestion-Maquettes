#include "interface.h"


using std::cout;
using std::endl;
using std::cin;

interface::interface(): d_formation{}, d_maquette{}, d_UEchoix{}, d_UEseule{}, d_UEcomposee{}, d_ecue{}
{
    temporaire_ecrit_maquette();
}

interface::~interface()
{
    for(unsigned int i=0; i<d_ecue.size(); i++)
        delete d_ecue[i];

    for(unsigned int i=0; i<d_UEcomposee.size(); i++)
        delete d_UEcomposee[i];

    for(unsigned int i=0; i<d_UEseule.size(); i++)
        delete d_UEseule[i];

    for(unsigned int i=0; i<d_UEchoix.size(); i++)
        delete d_UEchoix[i];

    for(unsigned int i=0; i<d_maquette.size(); i++)
        delete d_maquette[i];

    for(unsigned int i=0; i<d_formation.size(); i++)
        delete d_formation[i];
}

void interface::temporaire_ecrit_maquette()
{
    d_maquette.push_back(new maquette{"Licence Informatique", "MIAGE", 3, 5});

    d_UEcomposee.push_back(new UEcomposee{"13GUPRG5", "UE DE L'ETUDE DE CAS A LA PROGRAMMATION", 3, 1});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEcomposee[d_UEcomposee.size()-1]);
    d_ecue.push_back(new ecue{3, "13GPQUA5", "ECUE qualite de programmation", 12, 6, 6});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);
    d_ecue.push_back(new ecue{1, "13GPETC5", "ECUE Etudes de cas", 0, 16, 0});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);


    d_UEseule.push_back(new UEseule{14, 20, 0, "13GUPOO5", "PROGRAMMATION ORIENTEE OBJET", 3, 1});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEseule[d_UEseule.size()-1]);

    d_UEseule.push_back(new UEseule{14, 22, 0, "13GUALGO", "ALGORITHMIQUE", 3, 1});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEseule[d_UEseule.size()-1]);

    d_UEseule.push_back(new UEseule{14, 26, 0, "13GUCSI5", "CONCEPTION DE SYTEMES D'INFORMATION", 3, 1});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEseule[d_UEseule.size()-1]);

    d_UEseule.push_back(new UEseule{18, 10, 0, "13GUINR5", "INTRODUCTION AUX RESEAUX", 3, 1});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEseule[d_UEseule.size()-1]);

     /* IA et RO ues à choix */
    d_UEchoix.push_back(new UEchoix{});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEchoix[d_UEchoix.size()-1]);
    d_UEseule.push_back(new UEseule{15, 15, 0, "13GUIAR5", "INTELLIGENCE ARTIFICIELLE", 3, 1});
    d_UEchoix[d_UEchoix.size()-1]->ajouter_ue(d_UEseule[d_UEseule.size()-1]);
    d_UEseule.push_back(new UEseule{15, 20, 0, "13GUREO5", "RECHERCHE OPERATIONNELLE", 3, 1});
    d_UEchoix[d_UEchoix.size()-1]->ajouter_ue(d_UEseule[d_UEseule.size()-1]);
    d_maquette[d_maquette.size()-1]->position_ue_choix_dans_ue(6);

    d_UEcomposee.push_back(new UEcomposee{"13GUECOG", "ECONOMIE ET GESTION 1", 6, 2});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEcomposee[d_UEcomposee.size()-1]);
    d_ecue.push_back(new ecue{2, "13GPECEN", "ECUE Economie d'entreprise", 20, 0, 0});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);
    d_ecue.push_back(new ecue{1, "13GPCOMP", "ECUE Modele comtpable d'entreprise", 10, 0, 0});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);
    d_ecue.push_back(new ecue{3, "13GPMICR", "ECUE Micro-Macroeconomie", 26, 10, 0});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);

    d_UEcomposee.push_back(new UEcomposee{"13GUTEXT", "TECHNIQUES D'EXPRESSION", 3, 1});
    d_maquette[d_maquette.size()-1]->ajouter_ue(d_UEcomposee[d_UEcomposee.size()-1]);
    d_ecue.push_back(new ecue{2, "13GPANCO", "ECUE Anglais computing 1", 0, 20, 0});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);
    d_ecue.push_back(new ecue{2, "13GPALL5", "ECUE Allemand", 0, 20, 0});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);
    d_ecue.push_back(new ecue{1, "13GPSTAG", "ECUE Techniques de recherche de stage", 0, 10, 0});
    d_UEcomposee[d_UEcomposee.size()-1]->ajouter_ecue(d_ecue[d_ecue.size()-1]);
}

/**
   Initialisation de l'interface
*/
void interface::initialiser()
{
    int choix = 0;
    while(choix != 7)
    {
        system("cls");

        afficher_menu_principal();

        cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_menu_maquettes();
                break;
            case 2:
                afficher_menu_formations();
                break;
            case 3:
                afficher_menu_UEseuls();
                break;
            case 4:
                afficher_menu_UEcomposees();
                break;
            case 5:
                afficher_menu_ECUEs();
                break;
            case 6:
                afficher_menu_UEchoix();
                break;
            case 7:
                break;
            default:
                break;
        }
    }
}

/**
   Affichage du menu principal
*/
void interface::afficher_menu_principal()
{
    cout << "1) Gerer les maquettes" << endl;
    cout << "2) Gerer les formations" << endl;
    cout << "3) Gerer les UEseuls" << endl;
    cout << "4) Gerer les UEcomposees" << endl;
    cout << "5) Gerer les ECUEs" << endl;
    cout << "6) Gerer les UEs a choix" << endl;
    cout << "7) Quitter" << endl;
}

/**
   Affichage du menu des maquettes sur l'interface
*/
void interface::afficher_menu_maquettes()
{
    int choix = 0;
    while(choix != 6)
    {
        system("cls");
        cout << "1) Creer maquette" << endl;
        cout << "2) Modifier maquette" << endl;
        cout << "3) Supprimer maquette" << endl;
        cout << "4) Afficher liste des maquettes" << endl;
        cout << "5) Exporter les maquettes" << endl;
        cout << "6) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_maquette();
                system("pause");
                break;
            case 2:
                afficher_modifier_maquette();
                break;
            case 3:
                afficher_supprimer_maquette();
                break;
            case 4:
                afficher_liste_maquette();
                system("pause");
                break;
            case 5:
                afficher_export_maquette();
                system("pause");
                break;
            case 6:
                break;
            default:
                break;
        }
    }
}

/**
   Affichage du menu des formations sur l'interface
*/
void interface::afficher_menu_formations()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        std::cout << "1) Creer formation" << std::endl;
        std::cout << "2) Modifier formation" << std::endl;
        std::cout << "3) Supprimer formation" << std::endl;
        std::cout << "4) Afficher toutes les formation" << std::endl;
        std::cout << "5) Retour" << std::endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_formation();
                break;
            case 2:
                afficher_modifier_formation();
                break;
            case 3:
                afficher_supprimer_formation();
                break;
            case 4:
                afficher_liste_formation();
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

/**
   Affichage du menu des unites d'enseignements seules
*/
void interface::afficher_menu_UEseuls()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        cout << "1) Creer UE seule" << endl;
        cout << "2) Modifier UE seule" << endl;
        cout << "3) Supprimer UE seule" << endl;
        cout << "4) Afficher la liste des UE seules" << endl;
        cout << "5) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_UEseule();
                break;
            case 2:
                afficher_modifier_UEseule();
                break;
            case 3:
                afficher_supprimer_UEseule();
                break;
            case 4:
                afficher_liste_UEseule();
                system("pause");
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

/**
   Affichage du menu des unites d'enseignements composees
*/
void interface::afficher_menu_UEcomposees()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        cout << "1) Creer UE composee" << endl;
        cout << "2) Modifier UE composee" << endl;
        cout << "3) Supprimer UE composee" << endl;
        cout << "4) Afficher la liste des UEs composees" << endl;
        cout << "5) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_UEcomposee();
                break;
            case 2:
                afficher_modifier_UEcomposee();
                break;
            case 3:
                afficher_supprimer_UEcomposee();
                break;
            case 4:
                afficher_liste_UEcomposee();
                system("pause");
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

/**
   Affichage du menu des elements constitutifs d'unite d'enseignement
*/
void interface::afficher_menu_ECUEs()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        cout << "1) Creer ECUE" << endl;
        cout << "2) Modifier ECUE" << endl;
        cout << "3) Supprimer ECUE" << endl;
        cout << "4) Afficher toutes les ECUEs" << endl;
        cout << "5) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_ECUE();
                break;
            case 2:
                afficher_modifier_ECUE();
                break;
            case 3:
                afficher_supprimer_ECUE();
                break;
            case 4:
                afficher_liste_ECUE();
                system("pause");
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

/**
   Affichage du menu d'unite d'enseignement choix
*/
void interface::afficher_menu_UEchoix()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        std::cout << "1) Creer UE a choix" << std::endl;
        std::cout << "2) Modifier UE a choix" << std::endl;
        std::cout << "3) Supprimer UE a choix" << std::endl;
        std::cout << "4) Afficher toutes les UEs a choix" << std::endl;
        std::cout << "5) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_UE_choix();
                break;
            case 2:
                afficher_modifier_UE_choix();
                break;
            case 3:
                afficher_supprimer_UE_choix();
                break;
            case 4:
                afficher_liste_UE_choix();
                system("pause");
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

/**
   Creation de maquette a partir de l'interface
*/
void interface::afficher_creer_maquette()
{
    system("cls");
    d_maquette.push_back(new maquette{});
    d_maquette[d_maquette.size()-1]->saisir_maquette(cout, cin);
    cout << endl << "Maquette creee :" << endl;
    d_maquette[d_maquette.size()-1]->afficher(cout);
    cout << endl;
}

/**
   Modification de maquette a partir de l'interface
*/
void interface::afficher_modifier_maquette()
{
    system("cls");
    unsigned int maquette_a_modifier = 0;
    afficher_liste_maquette_entete();
    cout << "Saisir le numero de la maquette a modifier (0 pour annuler) :" << endl;
    cin >> maquette_a_modifier;

    if(maquette_a_modifier != 0)
    {
        maquette_a_modifier--;
        afficher_menu_modification_maquette(d_maquette[maquette_a_modifier]);
    }
}

/**
   Modification d'une maquette à partir d'un menu present sur l'interface
   @param[in] maquette* - m
*/
void interface::afficher_menu_modification_maquette(maquette *m)
{
   int choix = 0;
    while(choix != 5)
    {
        system("cls");
        m->afficher(cout);
        cout << endl;
        cout << "1) Modifier l'entete" << endl;
        cout << "2) Ajouter une UE a choix" << endl;
        cout << "3) Ajouter une UE seule" << endl;
        cout << "4) Ajouter une UE composee" << endl;
        cout << "5) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                m->saisir_maquette(cout, cin);
                break;
            case 2:
                unsigned int ue_choix_ajouter;
                afficher_liste_UE_choix();
                cout << "Saisir le numero de l'UE a choix a ajouter :" << endl;
                cin >> ue_choix_ajouter;
                ue_choix_ajouter--;
                m->ajouter_ue(d_UEchoix[ue_choix_ajouter]);
                break;
            case 3:
                unsigned int ue_seule_ajouter;
                afficher_liste_UEseule();
                cout << "Saisir le numero de l'UE seule a ajouter :" << endl;
                cin >> ue_seule_ajouter;
                ue_seule_ajouter--;
                m->ajouter_ue(d_UEseule[ue_seule_ajouter]);
                break;
            case 4:
                unsigned int ue_composee_ajouter;
                afficher_liste_UEcomposee();
                cout << "Saisir le numero de l'UE composee a ajouter :" << endl;
                cin >> ue_composee_ajouter;
                ue_composee_ajouter--;
                m->ajouter_ue(d_UEcomposee[ue_composee_ajouter]);
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

/**
   Monter une unite d'enseignement sur la maquette, a partir de l'interface
   @param[in] maquette* - m
*/
void interface::afficher_monter_ue(maquette *m)
{
    unsigned int ue_a_monter;
    cout << "Saisir le numero de l'UE a monter :" << endl;
    cin >> ue_a_monter;
    m->monter_ue(ue_a_monter);
}

/**
   Descendre une unite d'enseignement sur la maquette, a partir de l'interface
   @param[in] maquette* - m
*/
void interface::afficher_descendre_ue(maquette *m)
{
    unsigned int ue_a_descendre;
    cout << "Saisir le numero de l'UE a descendre :" << endl;
    cin >> ue_a_descendre;
    m->descendre_ue(ue_a_descendre);
}

/**
   Supression d'une maquette a partir de l'interface
*/
void interface::afficher_supprimer_maquette()
{
    system("cls");
    unsigned int maquette_a_supprimer = 0;
    afficher_liste_maquette_entete();
    cout << "Saisir le numero de la maquette a supprimer (0 pour annuler) :" << endl;
    cin >> maquette_a_supprimer;

    if(maquette_a_supprimer != 0)
    {
        maquette_a_supprimer--;
        delete d_maquette[maquette_a_supprimer];

        for(; maquette_a_supprimer<d_maquette.size()-1; maquette_a_supprimer++)
            std::swap(d_maquette[maquette_a_supprimer],d_maquette[maquette_a_supprimer+1]);
        d_maquette.resize(d_maquette.size()-1);
    }
}

/**
   Affiche la liste des maquette
*/
void interface::afficher_liste_maquette()
{
    for(unsigned int i=0; i<d_maquette.size(); i++)
    {
        cout << " " << i+1 << "  |  " << endl;
        d_maquette[i]->afficher(cout);
        cout << endl;
    }
}

/**
   Affiche la liste des entetes de la maquette
*/
void interface::afficher_liste_maquette_entete()
{
    for(unsigned int i=0; i<d_maquette.size(); i++)
    {
        cout << " " << i+1 << "  |  " << endl;
        d_maquette[i]->afficher_entete(cout);
        cout << endl;
    }
}

/**
   Affiche la liste d'unite d'enseignement seule sur l'interface
*/
void interface::afficher_export_maquette()
{
    afficheur_txt aff{};
    for(unsigned int i=0; i<d_maquette.size(); i++)
    {
        aff.exporter_maquette(d_maquette[i]);
    }
    cout << endl << "Les maquettes ont ete exportees correctement" << endl << endl;
}

/**
   Affiche la liste d'unite d'enseignement seule sur l'interface
*/

void interface::afficher_creer_formation()
{
    std::vector<int> numero_maquette;
    std::vector<maquette*> maquette;
    int taille;
    std::string mention;
    std::cout << "Mention : ";
    std::cin >> mention;
    std::cout << "Combien de maquettes voulez-vous inserer dans la formation : ";
    std::cin >> taille;

    numero_maquette.resize(taille);

    std::cout << "Selectionnez les maquettes que vous voulez inclure dans la formation : " << std::endl;
    afficher_liste_maquette();
    for(unsigned int i = 0; i < numero_maquette.size(); i++)
    {
        std::cout << "maquette " << i << " : ";
        std::cin >> numero_maquette[i];
        std::cout << std::endl;
    }
    for(unsigned int i=0; i<numero_maquette.size(); i++)
        maquette.push_back(d_maquette[numero_maquette[i]]);

    d_formation.resize(d_formation.size()+1);
    d_formation.push_back(new formation(maquette ,mention));

    std::cout << "Formation correctement créée" << std::endl;
    system("pause");
}

/**
   Modification d'une formation a partir de l'interface
*/
void interface::afficher_modifier_formation()
{
    unsigned int i;
    std::vector<int> numero_maquette;
    std::vector<maquette*> maquette;
    int taille;
    std::string mention;
    afficher_liste_formation();
    std::cout << "Quelle formation voulez-vous modifier : ";
    std::cin >> i;
    std::cout << std::endl;

    std::cout << "Nouvelle mention : ";
    std::cin >> mention;

    std::cout << "Combien de maquettes voulez-vous inserer dans la formation : ";
    std::cin >> taille;

    numero_maquette.resize(taille);

    std::cout << "Selectionnez les maquettes que vous voulez inclure dans la formation : " << std::endl;
    afficher_liste_maquette();
    for(unsigned int i = 0; i < numero_maquette.size(); i++)
    {
        std::cout << "maquette " << i << " : ";
        std::cin >> numero_maquette[i];
        std::cout << std::endl;
    }

    for(unsigned int i=0; i<numero_maquette.size(); i++)
        maquette.push_back(d_maquette[numero_maquette[i]]);

    d_formation[i]->modifier_maquette(maquette);

    std::cout << "Formation correctement créée" << std::endl;
    system("pause");
}

/**
   Supression d'une formation a partir de l'interface
*/
void interface::afficher_supprimer_formation()
{
    unsigned int i;
    afficher_liste_formation();

    std::cout << "Quelle formation voulez vous supprimer : " << std::endl;
    std::cin >> i;

    delete d_formation[i];

    for(; i<d_formation.size()-1; i++)
        std::swap(d_formation[i],d_formation[i+1]);
    d_formation.resize(d_formation.size()-1);

    std::cout << "Formation correctement supprimée" << std::endl;
    system("pause");
}

/**
   Affiche la liste des formations sur l'interface
*/
void interface::afficher_liste_formation()
{
    for(unsigned int i=0; i<d_formation.size(); i++)
    {
        std::cout << " " << i << "  |  ";
        d_formation[i]->afficher(std::cout);
        std::cout << std::endl;
    }
    system("pause");
}

/**
   Creation d'une unite d'enseignement composee a partir de l'interface
*/
void interface::afficher_creer_UEcomposee()
{
    std::string code, intitule;
    unsigned int credits, coefficient;

    cout << "Code UEcompose : ";
    cin >> code;

    cout<<"Intitule UEcompose : ";
    cin>>intitule;

    cout << "Nombre de credits UEcompose : ";
    cin >> credits;

    cout << "Coefficient UEcompose : ";
    cin >> coefficient;

    d_UEcomposee.push_back(new UEcomposee(code, intitule, credits, coefficient));

    cout << endl << "UE composee creee :" << endl;
    d_UEcomposee[d_UEcomposee.size()-1]->afficher(cout);
    cout << endl;
}

/**
   Affiche la liste d'unite d'enseignement seule sur l'interface
*/
void interface::afficher_modifier_UEcomposee()
{
    unsigned int entier_recherche;

    afficher_liste_UEcomposee();
    cout << "Saisir le numero de l'UE a modifier (0 pour annuler) :" << endl;
    cin >> entier_recherche;

    if(entier_recherche > 0)
    {
        entier_recherche--;
        afficher_menu_modification_UEcomposee(d_UEcomposee[entier_recherche]);
    }
}

/**
   Modification d'unite d'enseignement composee a partir de l'interface
   @param[in] UEcompose* - UEc
*/
void interface::afficher_menu_modification_UEcomposee(UEcomposee *UEc)
{
    int choix = 0;
    while(choix != 6)
    {
        system("cls");
        UEc->afficher(cout);
        cout << endl;
        cout << "1) Modifier l'entete" << endl;
        cout << "2) Ajouter une ECUE" << endl;
        cout << "3) Supprimer une ECUE" << endl;
        cout << "4) Deplacer une ECUE de 1 vers le haut" << endl;
        cout << "5) Deplacer une ECUE de 1 vers le bas" << endl;
        cout << "6) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                UEc->modifier_entete(cout, cin);
                break;
            case 2:
                unsigned int ecue_a_ajouter;
                afficher_liste_ECUE();
                cout << "saisir le numéro de l'ECUE a ajouter :" << endl;
                cin >> ecue_a_ajouter;
                UEc->ajouter_ecue(d_ecue[ecue_a_ajouter-1]);
                break;
            case 3:
                unsigned int ecue_a_supprimer;
                cout << "saisir le numéro de l'ECUE a supprimer :" << endl;
                cin >> ecue_a_supprimer;
                UEc->supprimer_ecue(ecue_a_supprimer-1);
                break;
            case 4:
                unsigned int ecue_a_monter;
                cout << "saisir le numéro de l'ECUE a monter :" << endl;
                cin >> ecue_a_monter;
                UEc->monter_ecue(ecue_a_monter-1);
                break;
            case 5:
                unsigned int ecue_a_descendre;
                cout << "saisir le numéro de l'ECUE a descendre :" << endl;
                cin >> ecue_a_descendre;
                UEc->descendre_ecue(ecue_a_descendre-1);
                break;
            case 6:
                break;
            default:
                break;
        }
    }
}

/**
   Supression d'une unite d'enseignement composee a partir de l'interface
*/
void interface::afficher_supprimer_UEcomposee()
{
    system("cls");
    unsigned int ue_a_supprimer = 0;
    afficher_liste_UEcomposee();

    cout << "Saisir le numero de l'ue a supprimer (0 pour annuler) :" << endl;
    cin >> ue_a_supprimer;

    if(ue_a_supprimer != 0)
    {
        ue_a_supprimer--;
        //delete d_UEcomposee[ue_a_supprimer];

        for(; ue_a_supprimer<d_UEcomposee.size()-1; ue_a_supprimer++)
            std::swap(d_UEcomposee[ue_a_supprimer],d_UEcomposee[ue_a_supprimer+1]);
        d_UEcomposee.resize(d_UEcomposee.size()-1);
    }
}

/**
   Affiche la liste d'unites d'enseignements composees
*/
void interface::afficher_liste_UEcomposee()
{
    for(unsigned int i=0; i<d_UEcomposee.size(); i++)
    {
        cout << " " << i+1 << "  |  " << endl;
        d_UEcomposee[i]->afficher(cout);
        cout << endl;
    }
}

/**
   Creation d'une unite d'enseignement seule a partir de l'interface
*/
void interface::afficher_creer_UEseule()
{
    std::string codeUE, intituleUE;
    unsigned int creditsUE, coefficientUE, td, tp, cm;
    cout << endl << "Code UE : ";
    cin >> codeUE;

    cout << "Intitule UE : ";
    cin >> intituleUE;

    cout << "Nombre de credits UE : ";
    cin >> creditsUE;

    cout << "Coefficient UE : ";
    cin >> coefficientUE;

    cout << "Heures td : ";
    cin >> td;

    cout << "Heures tp : ";
    cin >> tp;

    cout << "Heures cm : ";
    cin >> cm;
    d_UEseule.push_back(new UEseule(cm, td, tp, codeUE, intituleUE, creditsUE, coefficientUE));

    cout << endl;
    d_UEseule[d_UEseule.size()-1]->afficher(cout);
    cout << endl;

    cout << "UE correctement cree";
    cout << endl << endl;
    system("pause");

}

/**
   Modifie une unite d'enseignement seule a partir de l'interface
*/
void interface::afficher_modifier_UEseule()//il y a du copy pasta : peut etre "afficher_modifier_matiere(vectUE/ECUE)" ?
{
    unsigned int coeff, td, tp, cm, credits, entier_recherche;
    std::string code, intitule;
    afficher_liste_UEseule();
    cout << "Saisir le numero de l'UE a modifier :" << endl;
    cin >> entier_recherche;

    cout << "Code : ";
    cin >> code;

    cout << "Intitule : ";
    cin >> intitule;

    cout<<"Nombre de credits UE : ";
    cin>>credits;

    cout << "Coefficient : ";
    cin >> coeff;

    cout << "Heures td : ";
    cin >> td;

    cout << "Heures tp : ";
    cin >> tp;

    cout << "Heures cm : ";
    cin >> cm;

    d_UEseule[entier_recherche-1]->modifier_completement_ue(cm, td, tp, code, intitule, credits, coeff);

    cout << endl;
    d_UEseule[entier_recherche-1]->afficher(cout);
    cout << endl;
    cout << "UE correctement cree";
    cout << endl;
    system("pause");
}

/**
   Supprime une unite d'enseignement a partir de l'interface
*/
void interface::afficher_supprimer_UEseule()
{
    std::string intitule_recherche;
    afficher_liste_UEseule();
    cout << "Saisir le libelle de l'UE a supprimer :" << endl;
    cin >> intitule_recherche;

    unsigned int i = 0;
    while(d_UEseule[i]->intitule() != intitule_recherche)
        i++;

    delete d_UEseule[i];

    for(; i<d_ecue.size()-1; i++)
        std::swap(d_UEseule[i],d_UEseule[i+1]);
    d_UEseule.resize(d_UEseule.size()-1);
}

/**
   Affiche la liste d'unite d'enseignement seule sur l'interface
*/
void interface::afficher_liste_UEseule()
{
    for(unsigned int i=0; i<d_UEseule.size(); i++)
    {
        cout << " " << i+1 << "  |  " << endl;
        d_UEseule[i]->afficher(cout);
        cout << endl;
    }
}

/**
   Creation d'un element constitutif d'unite d'enseignement a partir de l'interface
*/

void interface::afficher_creer_ECUE()
{
    unsigned int coeff, td, tp, cm;
    std::string code, intitule;

    cout << "intitule : ";
    cin >> intitule;

    cout << "code : ";
    cin >> code;

    cout << "coefficient : ";
    cin >> coeff;

    cout << "heures td : ";
    cin >> td;

    cout << "heures tp : ";
    cin >> tp;

    cout << "heures cm : ";
    cin >> cm;
    cout << endl;

    d_ecue.push_back(new ecue{coeff,code,intitule,cm,td,tp});

    cout << endl;
    d_ecue[d_ecue.size()-1]->afficher(cout);
    cout << endl;

    cout << "ECUE correctement creee";
    cout << endl << endl;
    system("pause");
}

/**
   Modifie l'element constitutif  de l'unite d'enseignement a partir de l'interface
*/
void interface::afficher_modifier_ECUE()
{
    unsigned int coeff, td, tp, cm, entier_recherche;
    std::string code, intitule;
    afficher_liste_ECUE();
    cout << "Saisir le numero de l'ECUE a modifier" << endl;
    cin >> entier_recherche;
    entier_recherche--;

    cout << "intitule : ";
    cin >> intitule;
    d_ecue[entier_recherche]->intitule(intitule);

    cout << "code : ";
    cin >> code;
    d_ecue[entier_recherche]->code(code);

    cout << "coefficient : ";
    cin >> coeff;
    d_ecue[entier_recherche]->coefficent(coeff);

    cout << "heures td : ";
    cin >> td;
    d_ecue[entier_recherche]->heures_td(td);

    cout << "heures tp : ";
    cin >> tp;
    d_ecue[entier_recherche]->heures_tp(tp);

    cout << "heures cm : ";
    cin >> cm;
    d_ecue[entier_recherche]->heures_cm(cm);

    cout << endl;
    cout << "ECUE modifiee :";
    cout << endl;
    d_ecue[entier_recherche]->afficher(cout);
    cout << endl << endl;
    system("pause");
}

/**
   Supprime un element constitutif d'unite d'enseignement a partir de l'interface
*/
void interface::afficher_supprimer_ECUE()
{
    unsigned int entier_recherche;
    afficher_liste_ECUE();
    cout << "saisir le numéro de l'ECUE a supprimer ?" << endl;
    cin >> entier_recherche;
    entier_recherche--;

    //delete d_ecue[entier_recherche];

    for(; entier_recherche<d_ecue.size()-1; entier_recherche++)
        std::swap(d_ecue[entier_recherche],d_ecue[entier_recherche+1]);
    d_ecue.resize(d_ecue.size()-1);
}

/**
 Affiche la liste des elements constitutif d'unite d'enseignement sur l'interface
*/
void interface::afficher_liste_ECUE()
{
    cout << endl;
    for(unsigned int i=0; i<d_ecue.size(); i++)
    {
        cout << " " << i+1 << "  |  ";
        d_ecue[i]->afficher(cout);
        cout << endl;
    }
}

/**
   Cree une unite d'enseignement choix a partir de l'interface
*/
void interface::afficher_creer_UE_choix()
{
    unsigned int nbr_UE_composee, nbr_UE_seul;
    std::vector<int> selection_UE_composee;
    std::vector<int> selection_UE_seul;
    std::vector<UEcomposee*> UEcomposee;
    std::vector<UEseule*> UEseule;

    for(unsigned int i = 0; i < d_UEcomposee.size(); i++)
        d_UEcomposee[i]->afficher(std::cout);

    std::cout << "Combien d'UEs composées voulez vous ajouter : ";
    std::cin >> nbr_UE_composee;
    std::cout << "Quelle UEs composées voulez vous ajouter : ";
    for(unsigned int i = 0; i < nbr_UE_composee; i++)
    {
        std::cout << "UE composée " << i << " : ";
        std::cin >> selection_UE_composee[i];
        UEcomposee.resize(selection_UE_composee.size()+1);
        UEcomposee.push_back(d_UEcomposee[selection_UE_composee[i]]);
    }

    for(unsigned int i = 0; i < d_UEseule.size(); i++)
        d_UEseule[i]->afficher(std::cout);

    std::cout << "Combien d'UEs seules voulez vous ajouter : ";
    std::cin >> nbr_UE_seul;
    std::cout << "Quelle UEs seules voulez vous ajouter : ";
    for(unsigned int i = 0; i < nbr_UE_seul; i++)
    {
        std::cout << "UE seule " << i << " : ";
        std::cin >> selection_UE_seul[i];
        UEseule.resize(selection_UE_seul.size()+1);
        UEseule.push_back(d_UEseule[selection_UE_seul[i]]);
    }
}

/**
   Modifie une unite d'enseignement choix a partir de l'interface
*/
void interface::afficher_modifier_UE_choix()
{
    unsigned int numero_UE_choix_a_modifier;
    afficher_liste_UE_choix();
    std::cout << "Quelle UE à choix voulez vous modifier : ";
    std::cin >> numero_UE_choix_a_modifier;

    unsigned int nbr_UE_composee, nbr_UE_seul;
    std::vector<int> selection_UE_composee;
    std::vector<int> selection_UE_seul;
    std::vector<ue*> ue;

    for(unsigned int i = 0; i < d_UEcomposee.size(); i++)
        d_UEcomposee[i]->afficher(std::cout);

    std::cout << "Combien d'UEs composées voulez vous ajouter : ";
    std::cin >> nbr_UE_composee;
    std::cout << "Quelle UEs composées voulez vous ajouter : ";
    for(unsigned int i = 0; i < nbr_UE_composee; i++)
    {
        std::cout << "UE composée " << i << " : ";
        std::cin >> selection_UE_composee[i];
        ue.resize(selection_UE_composee.size()+1);
        ue.push_back(d_UEcomposee[selection_UE_composee[i]]);
    }

    for(unsigned int i = 0; i < d_UEseule.size(); i++)
        d_UEseule[i]->afficher(std::cout);

    std::cout << "Combien d'UEs seules voulez vous ajouter : ";
    std::cin >> nbr_UE_seul;
    std::cout << "Quelle UEs seules voulez vous ajouter : ";

    for(unsigned int i = 0; i < nbr_UE_seul; i++)
    {
        std::cout << "UE seule " << i << " : ";
        std::cin >> selection_UE_seul[i];
        ue.resize(selection_UE_seul.size()+1);
        ue.push_back(d_UEseule[selection_UE_seul[i]]);
    }

    d_UEchoix[numero_UE_choix_a_modifier]->modifier_ue(ue);

}

/**
   Supprime une unite s'enseignement a partir de l'interface
*/
void interface::afficher_supprimer_UE_choix()
{
    unsigned int numero_UE_choix_a_supprimer;
    afficher_liste_UE_choix();
    std::cout << "Quelle UE à choix voulez vous supprimer : ";
    std::cin >> numero_UE_choix_a_supprimer;

    delete d_UEchoix[numero_UE_choix_a_supprimer];

    for(; numero_UE_choix_a_supprimer<d_UEchoix.size(); numero_UE_choix_a_supprimer++)
        std::swap(d_UEchoix[numero_UE_choix_a_supprimer],d_UEchoix[numero_UE_choix_a_supprimer]);

    d_UEchoix.resize(d_UEchoix.size()-1);
}

/**
   Affiche sur l'interface la liste des unites d'enseignements choix
*/
void interface::afficher_liste_UE_choix()
{
    for(unsigned int i=0; i<d_UEchoix.size(); i++)
    {
        cout << " " << i+1 << "  |  " << endl;
        d_UEchoix[i]->afficher(cout);
        cout << endl;
    }
}
