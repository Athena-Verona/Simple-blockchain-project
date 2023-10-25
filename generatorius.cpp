#include "main.h"

string generateRandomHashKey(int keyLength) {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string hashKey;
    for (int i = 0; i < keyLength; ++i) {
        hashKey.push_back(charset[rand() % charset.length()]);
    }
    return hashKey;
}

void gen_map(){
   int size = 1200;
  FILE *F;
  string pav = "users" + std::to_string(size) + ".txt";
  F=fopen(pav.c_str(),"w");

  mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
  int_distribution dist(100, 121);
  std::uniform_int_distribution<int> balanceDist(100, 1000000); // Range for user balance
  map<int, string> vardai;
  
  vardai[100]="Gabrisele";
  vardai[101]="Agatsa";
  vardai[102]="Laurisa";
  vardai[103]="Vistorija";
  vardai[104]="Sinsija";
  vardai[105]="Mastas";
  vardai[106]="Dovysdas";
  vardai[107]="Luskas";
  vardai[108]="Aslanas";
  vardai[109]="Ritsa";
  vardai[110]="Pitsa";
  vardai[111]="Roksas";
  vardai[112]="Kroksas";
  vardai[113]="Antanas";
  vardai[114]="Slimonas";
  vardai[115]="Bensas";
  vardai[116]="Sjustas";
  vardai[117]="Kristuspas";
  vardai[118]="Justinsas";
  vardai[119]="Minija";
  vardai[120]="Raspolas";
  vardai[121]="Misgle";

  cout<<"> Vardų ir pavardžių generavimas vyksta..."<<endl;
  string vardas;
  for (int i=0;i<size;i++) {
    vardas=vardai[dist(mt)];
    std::string hashKey = generateRandomHashKey(64);
    int balance = balanceDist(mt);
    fprintf(F, "%-15s%15s%10d\n", vardas.c_str(), hashKey.c_str(), balance);
  }
  fclose(F);
}
std::ostream& operator<<(std::ostream& out, const transaction& v){
    out << "Transaction ID: "<< v.ID <<endl<<
    "Sender public key: " << v.sender_key <<endl<<
    "Getter public key: " << v.getter_key <<endl<<
    "Amount spent:" << v.amount << endl;
    return out;
}
