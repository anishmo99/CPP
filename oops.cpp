#include <iostream>
#include <vector>
using namespace std;

class Channel{
    public:
    string channel;
    int price;

    Channel(){
        channel = "";
        price = 0;
    }

    Channel(string c, int p){
        channel = c;
        price = p;
    }
};

class Package : public Channel{
    public:
    vector<Channel> channels; 
    int price;
    int sum = 0;

    Package(){ 
        price = 0;
        sum = 0;
    }

    Package(vector<Channel> chan, int p){
        channels = chan;
        price = p;
        sum = 0;
    }

    bool check(){

        for(int i = 0; i < channels.size(); i++){
            sum += channels[i].price;
        }

        return price > sum ? false : true;
    }
};

int main(){
    Channel hbo("HBO Movies", 10);
    Channel ktv("KTV", 12);
    Channel zee("Zee News", 2);
    Channel ndtv("NDTV News", 5);
    Channel fox("Fox", 10);

    vector<Channel> english;
    english.emplace_back(hbo, ndtv);
    Package EngPack(english, 12);
    bool engIsPossible = EngPack.check();

    vector<Channel> news;
    news.emplace_back(ndtv, zee);
    Package News(news, 5);
    bool newsIsPossible = news.check();

    cout << "enter how many packages you want : " << endl;
    int packno;
    cin >> pack;

    cout << "enter how many channels you want : " << endl;
    int channo;
    cin >> channo;


    vector<Packages> packages;
    for(int i = 0; i < packno; i++){
        cout << "enter package : " << endl;
        string pack;
        if(pack == "English"){
            packages.emplace_back(EngPack);
        }
        else{
            packages.emplace_back(News);
        }
    }

}