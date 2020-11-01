#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <cstdlib>
#define NORMAL_OUT 0
#define EXCEPT_OUT 1

using namespace std;

struct Message{
    std::string content;
    std::string sender;
    std::string destination;
    std::string getMessageContent(){
      return "From: " + sender + ", To: " + destination + " -> " + content;
    };
    Message(std::string c,std::string s,std::string d):
    content(c),sender(s),destination(d){
        std::cout << " struct created" << std::endl;
    };
    ~Message(){
        std::cout << "struct destructed" << std::endl;
    };
};

Message* createNewMessageInHeap(std::string c,std::string s, std::string d){
    return new Message(c,s,d);
};

void destructMessageInHeap(Message* m){
  if(sizeof m > 0 && m != nullptr){
    delete m;
  };
};

class User{
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
    User():User("","",0.00){
        std::cout << "new User" << " ";
    };
    //Composed Constructor
    User(std::string _username, std::string _userAddress, double _amount ){
        this->userName = _username;
        this->address = _userAddress;
        this->wallet = _amount;
    };
    //Copy Constructor
    User(User& u){};
    //Class Destructor
    ~User(){ std::cout << "destructor" << "\n"; };

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

class Company{
private:
    std::string name;
    std::string mktField;
    double socialCapital;
    bool receivedMoneyFee;
    bool isStartup;
public:
    Company():name(""),mktField(""),socialCapital(0),receivedMoneyFee(0),isStartup(0){
        cout << "new Company created" << endl;
    };
//    Company(std::string n,std::string mF,double sC, bool rMF, bool isS){};
    ~Company(){ cout << "destructor" << endl;};
};

//this method creates a copy of the instance to the stack
void printUser(User u){
    u.setUsername("Chuck de Bruce");
    std::cout << u.getUserData() << std::endl;
};

int main(int argc, char* argv[]){

    Message* nova = createNewMessageInHeap("Warning Message.", "John", "Paul");
    std::cout << nova->getMessageContent() << std::endl;
    destructMessageInHeap(nova);

    Company emp;
    //Init new user with constructor one
    User novo;
    //Init new userRef
    User& novoRef = novo;
    //Init new user with other constructor
    User dois {"Charles Bronson", "Blvd West 53rd", 150000};
    novo.setUsername("Adriano Heller");
    novo.setUserAddress("Strawberry Fields rd 1805");
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