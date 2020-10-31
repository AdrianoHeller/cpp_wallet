#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <cstdlib>
#define NORMAL_OUT 0
#define EXCEPT_OUT 1

using namespace std;

class Usuario {
//Encapsuling data
private:
    std::string userName;
    std::string address;
    double wallet;
    time_t currentTime;
    tm *tmLocal;
    char dateStr[100];
    char timeStr[100];
//Methods to init and set properly the class data
public:
    double getWallet() const{
        return wallet;
    };

    void insertMoney(double amount){
        this->wallet = amount;
    };

    void retrieveMoney(double amount){
        this->wallet -= this->wallet > amount ? amount : 0 ;
    };
    //Standard Constructor
    Usuario():Usuario("","",0.00){
        std::cout << "new User" << " ";
    };
    //Composed Constructor
    Usuario(std::string _username, std::string _userAddress, double _amount ){
        this->userName = _username;
        this->address = _userAddress;
        this->wallet = _amount;
    };
    //Copy Constructor
    Usuario(Usuario& u){};
    //Class Destructor
    ~Usuario(){ std::cout << "destructor" << "\n"; };

    void setUsername(std::string userData){
        this->userName = userData;
    };

    void setUserAddress(std::string userAddress){
        this->address = userAddress;
    };
    //Referencing variables to pointers
    void setCurrentTime(){
      time(&currentTime);
      tmLocal = localtime(&currentTime);
    };
    //Timestamp through pointer's props call
    std::string getTimestamp(){
        stringstream timeStamp;
        timeStamp << tmLocal->tm_hour << ":"
                  << tmLocal->tm_min << ":"
                  << tmLocal->tm_sec;
        return timeStamp.str();
    };
    //
    void setFormatDatetime(){
      strftime(dateStr,50,"Today is %B %d %Y", tmLocal);
      strftime(timeStr,50,"Current time: %T",tmLocal);
    };

    std::string getDatetime(){
      stringstream datetime;
      datetime << dateStr << "\n"
               << timeStr;
      return datetime.str();
    };

    std::string getUserData() const{
        return this->userName + " " + this->address + " ";
    };

    time_t getCurrentTime(){
      return currentTime;
    };
};

//this method creates a copy of the instance to the stack
void printUser(Usuario u){
    u.setUsername("Chuck de Bruce");
    std::cout << u.getUserData() << std::endl;
};

int main(int argc, char* argv[]){
    //Init new user with constructor one
    Usuario novo;
    //Init new userRef
    Usuario& novoRef = novo;
    //Init new user with other constructor
    Usuario dois {"Charles Bronson", "Blvd West 53rd", 150000};
    novo.setUsername("Adriano Heller");
    novo.setUserAddress("Rua Padre Anchieta 1968 ap.405");
    //Checking memory addresses
    std::cout << &novo << " " << &novoRef << " " << std::endl;
    std::cout << novoRef.getUserData() << "\n";
    //Checking new instance output
    std::cout << dois.getUserData() << "\n";
    //Starting time pointers
    dois.setCurrentTime();
    std::cout << dois.getCurrentTime() << "\n";
    std::cout << dois.getTimestamp() << "\n";
    dois.setFormatDatetime();
    std::cout << dois.getDatetime() << "\n";
    printUser(dois);

#ifdef NORMAL_OUT
    return NORMAL_OUT;
#else
    return EXCEPT_OUT;
#endif

};