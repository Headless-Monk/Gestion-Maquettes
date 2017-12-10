#ifndef ECUE_H
#define ECUE_H

#include <string>

class ecue
{
public:
  ecue();
  ecue(string d_code, string d_intitule, unsigned int cm, unsigned int td, unsigned int tp)
  ecue(ecue &e);
  ~ecue();

  void afficher(ostream &os) const; //par exemple : affichage en ligne, infos séparée par ; pour ensuite pouvoir copier coller dans excel
  //menu de modification géré par l'interface

  /* set */
  void set_code(std::string code);
  void set_intitule(std::string intitule);
  void set_nb_cm(unsigned int cm);
  void set_nb_td(unsigned int td);
  void set_nb_tp(unsigned int tp);

  /* get */
  std::string get_code() const;
  std::string get_intitule() const;
  std::string get_nb_cm() const;
  std::string get_nb_td() const;
  std::string get_nb_tp() const;

private:
  std::string d_code;
  std::string d_intitule;
  unsigned int d_cm, d_td, d_tp;
};

ecue& operator<<(ostream &os, ecue &e) const;

#endif
