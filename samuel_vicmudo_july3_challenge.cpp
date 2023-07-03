#include <iostream>
#include <vector>
#include <limits>

using namespace std;
//Rice Terraces Trekking Challenge
int numOfTerrace; //# of terraces
int timeToTravel; //hours you have to travel
vector<int> hrsPerTerrace; //storage, hours per terrace
int sumOfHrs = 0;//storage total hours travelled
int visitedTerrace = 0;//storage total of terraces travelled

int getInput(int* input){
    while(!(cin >> *input)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong Input Please re-enter ";
    }
    return *input;
}
void travelTerraces(){
    cout << "# of Terraces: ";
    getInput(&numOfTerrace);//user input number of terraces
    cout << "Hours you can travel: ";
    getInput(&timeToTravel);//user input time limit to travel
    hrsPerTerrace.resize(numOfTerrace);//resize vector on how many terraces the user input
    for(int i = 0; i < numOfTerrace; i++){
        cout << "Terrace " << i+1 << " ";
        getInput(&hrsPerTerrace[i]);//user input how many hours per terraces
    }
    for(int i = 0; i < numOfTerrace; i++){
        if(sumOfHrs <= timeToTravel){//if hours travelled is less than time to travel
            sumOfHrs += hrsPerTerrace[i] += hrsPerTerrace[i+1];//add index i and i+1 to calculate total hours travelled
            visitedTerrace++;//add +1 every time you travel
        }
    }
    cout << "Terraces Travelled " << visitedTerrace << endl;//output number of times you travelled
}
//Typhoon Evacuation Plan
void getEvacuationPlan(){
    int numOfBarangay;//storage # of barangay
    vector<int> populationPerBarangay;//vector # of population per barangay
    vector<int> capacityPerEvac;//vector # of evacuation center capacity per barangay
    cout << "# of Brngy: ";
    getInput(&numOfBarangay);//input # of barangay
    populationPerBarangay.resize(numOfBarangay);//resize vector to # of barangay to save space
    capacityPerEvac.resize(numOfBarangay);//resize vector to # of barangay to save space
    for(int i = 0; i < numOfBarangay; i++){
        cout << "Barangay " << i << endl;
        cout << "Population count: ";
        getInput(&populationPerBarangay[i]);//input population
        cout << "Evacuation capacity: ";
        getInput(&capacityPerEvac[i]);//input evacuation center capacity
        cout << "Will they fit? " << (populationPerBarangay[i] <= capacityPerEvac[i] ? "Yes" : "No") << endl;//check if they will fit or not
    }
}
//Lazada Flash Sale Event
void getUnits(){
    int numOfItems;
    cout << "# of items ";
    getInput(&numOfItems);//Input # of items
    vector<int> quantityOfItems;//storage of quantity of items
    vector<int> attemptedPurchase;//attempted purchase of user
    quantityOfItems.resize(numOfItems);
    attemptedPurchase.resize(numOfItems);
    for(int i = 0; i < numOfItems; i++){
        cout << "Item " << i+1 << " ";
        getInput(&quantityOfItems[i]);//input quantity of items
    }
    for(int i = 0; i < numOfItems; i++){
        cout << "Purchase " << i+1 << " ";
        getInput(&attemptedPurchase[i]);//input attempted purchase
        quantityOfItems[i] -= attemptedPurchase[i];//subtract quantity to attempted purchase
        if(quantityOfItems[i] < 0){
            quantityOfItems[i] = 0;//if over purchased convert to 0 quantity
        }
        cout << "Units Left " << quantityOfItems[i] << endl;//output units left
    }

}
int main() {
    int user;
    while(true){
        cout << "1. Travel Terraces\n2. Get Evacuation Plan\n3. Get Units (lazada flash sale)\n4. Exit Program\n->";
        getInput(&user);//input menu choices
        if(user == 1){//1. terraces challenge
            travelTerraces();
        } else if(user == 2){//2. evacuation plan challenge
            getEvacuationPlan();
        } else if(user == 3){//3. lazada flash sale challenge
            getUnits();
        } else if(user == 4){//4. exit program
            return 0;
        }
    }
}
