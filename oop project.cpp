//petrol pump management system
#include <iostream>
#include<fstream>
using namespace std;

class price {
public:
    static int dprice;
    static int pprice;
    static int hprice;
    static int pstoke;
    static int hstoke;
    static int dstoke;
    void changep(int add){
	pstoke = add;
	 ofstream file2("details.txt",ios::app);
	 file2<<"stoke add new petrol inventry is "<<pstoke<<endl;
	 file2.close();
	}
	 void changed(int add){
	dstoke = add;
	 ofstream file2("details.txt",ios::app);
	 file2<<"stoke add new diesel inventry is "<<dstoke<<endl;
	 file2.close();
	}
	 void changeh(int add){
	hstoke = add;
    ofstream file2("details.txt",ios::app);
	 file2<<"stoke add new high octane inventry is "<<hstoke<<endl;
	 file2.close();
	}
	
	void minusp(int litter){
		pstoke-=litter;
	}
	void minusd(int litter){
		dstoke-=litter;
	}
	void updatep(int price){
		
		pprice = price;
		ofstream file2("details.txt",ios::app);
		file2<<"petrol price changed"<<endl;
		file2<<"new price : "<<pprice<<endl;
		file2.close();
	
	}
	void updated(){
		cout<<"plz enter the updated price of diesel : ";
		cin>>dprice;
		ofstream file2("details.txt",ios::app);
		file2<<"diesel  price changed"<<endl;
		file2<<"new price : "<<dprice<<endl;
		file2.close();
		
	}
		void updateh(){
		cout<<"plz enter the updated price of high ocatane  : ";
		cin>>hprice;
		ofstream file2("details.txt",ios::app);
		file2<<"high octane price changed"<<endl;
		file2<<"new price : "<<hprice<<endl;
		file2.close();
		
		
	}
};
 int price::dprice = 299;
 int price::pprice = 256;
 int price::hprice = 310;
 int price::pstoke = 200;
 int price::hstoke = 200;
 int price::dstoke = 200;

class receipt {
public:
    void rp(string type, int liter, double bill) {
        cout << "\t\t\t\t\t\t=================================" << endl;
        cout<<"\t\t\t\t\t\t||            PSO "<<"\t\t||"<<endl;
        cout << "\t\t\t\t\t\t||   Total Bill: " << bill << "\t\t||" << endl;
        cout << "\t\t\t\t\t\t||   Payment Method: " << type << "\t||" << endl;
        cout << "\t\t\t\t\t\t||   Total Liter: " << liter << "\t\t||" << endl;
        cout << "\t\t\t\t\t\t||        Thank You! \t\t||" << endl;
        cout << "\t\t\t\t\t\t||      For Trusting Us \t\t||" << endl;
        cout << "\t\t\t\t\t\t=================================" << endl;
        
    }
};
class salePerson {
    string name;
  static  int preading;  
   static int dreading;     
static	int hreading;      
	int initial_preading;  
    int initial_dreading;
    int initial_hreading;

public:
	salePerson(){
	  this->preading = 0;
        this->hreading =0;
        this->dreading = 0;

       
        initial_preading =0;
        initial_dreading = 0;
        initial_hreading = 0;	
	}
    salePerson(string name, int preading, int hreading, int dreading) {
        this->name = name;
        this->preading = preading;
        this->hreading = hreading;
        this->dreading = dreading;

       
        initial_preading = preading;
        initial_dreading = dreading;
        initial_hreading = hreading;
    }

    
    void displayname() {
        cout << "Current sale person: " << name << endl;
        cout << "Initial readings when duty started:" << endl;
        cout << "Petrol meter reading: " << initial_preading << " Liters" << endl;
        cout << "High Octane meter reading: " << initial_hreading << " Liters" << endl;
        cout << "Diesel meter reading: " << initial_dreading << " Liters" << endl;

    }
    void fdisplay(){
    	 ofstream file2("details.txt",ios::app);
    	 file2<<"in end  petrol meter is : "<<preading<<endl;
    	 file2<<"in end high octane meter is : "<<hreading<<endl;
    	 file2<<"in end diesel meter is "<<dreading<<endl;
    	 file2.close();
	}
    void addp(int litter)
	{
	preading+=litter;
	}
    void	addd(int litter){
		dreading+=litter;
	}
    void	addh(int litter){
		hreading+=litter;
	}
	void afterDisplay(){
		  cout << "\nCurrent readings after fuel is added:" << endl;
        cout << "Petrol meter reading: " << preading << " Liters" << endl;
        cout << "High Octane meter reading: " << hreading << " Liters" << endl;
        cout << "Diesel meter reading: " << dreading << " Liters" << endl;
	}
};
class paymentCapture: public receipt {
	int result;
	int cardNo;
	int year;
	int cvc;
	int money;
	int option;
	int install;
	string name;
	public:
	 void card(int total,int litter){
	 	cout<<"plz enter card holder name ";
	 	cin.ignore();
	 getline(cin, name);
	 	cout<<"plz enter card number ";
	 	cin>>cardNo;
	 	cout<<"plz enter exp year : ";
	 	cin>>year;
	 	cout<<"plz enter cvc : ";
	 	cin>>cvc;
	 	cout<<"\t\t\t\tpayment processing "<<endl;
	 	cout<<"\t\t\t\tpayment recived!!!!!!!!!!!"<<endl;
		 rp("card",litter,total);
	 }
	 void cash(int total, int litter)
    {
        int remaining = total;
        do
        {
            cout << "How much cash did the customer give you: ";
            cin >> money;

            if (money < remaining)
            {
                remaining -= money;
                cout << "Insufficient amount. Please provide the remaining: " << remaining << endl;
            }
            else
            {
                int change = money - remaining;
                if (change > 0)
                {
                    cout << "Please return this amount: " << change << endl;
                }
                remaining = 0;
            }
        } while (remaining > 0);

        rp("cash", litter, total);
    }
	  void card2(int total,int litter){
	 	cout<<"plz enter card holder name ";
	 	cin.ignore();
	 getline(cin, name);
	 	cout<<"plz enter card number ";
	 	cin>>cardNo;
	 	cout<<"plz enter exp year : ";
	 	cin>>year;
	 	cout<<"plz enter cvc : ";
	 	cin>>cvc;
	 	cout<<"\t\t\t\tpayment processing "<<endl;
	 	cout<<"\t\t\t\tpayment recived!!!!!!!!!!!"<<endl;
		 rp("installment ",litter,total);
		 ofstream file("installment_card_details.txt",ios::app);
		 file<<"card holder name : "<<name<<endl;
		 file<<"card  number : "<<cardNo<<endl;
		 file<<"exp year :"<<year<<endl;
		 file<<"cvc : "<<cvc<<endl;
		 file<<"total remaining : "<<total<<endl;
		 file<<"\t\t\t\t\t\t---------------------------------"<<endl;
		 file.close();
		 
	 }
	 void installment(int total,int litter){
	 	if(litter >100){
	 		cout<<"your total is "<<total<<endl;
	 		cout<<"how much installment we provide you(min 2 possible ):";
	 		cin>>install;
	 		if(install == 1){
	 			cout<<"same amount you have to pay "<<total<<endl;
	 		cout<<"do you want by cash(1) or card(2) : ";
	 		cin>>option;
	 		if(option == 2){
	 			card(total,litter);
			 }
			 else if (option == 1){
			 	cash(total,litter);
			 }
			 else {
			 	cout<<"invalid entry !!!!!"<<endl;
			 }
			 }
		
			 else if (install >=2){
			 		cout<<"you have selected "<<install<<" installment so you have to pay  : "<<total/install<<endl;
			 	cout<<"your next installment will cut on same date of next month thats why you have to add card for payment\nplz add card"<<endl;
			 	total = total/install;
			 	card2(total,litter);
			 }
		 }
		 else{
		 	cout<<"you are not  illegible for installment "<<endl;
		 	cout<<"do you want by cash(1) or card(2) : ";
	 		cin>>option;
	 		if(option == 2){
	 			card(total,litter);
			 }
			 else if (option == 1){
			 	cash(total,litter);
			 }
			 else {
			 	cout<<"invalid entry !!!!!"<<endl;
			 }
		 }
	 }
};
class payment : public paymentCapture{
	int paymentM;
	public:
		void pay(int total,int litter){
			cout<<"which payment do you perfer(card(1),cash(2),installment(3)) : ";
			cin>>paymentM;
			if(paymentM == 1){
				card(total,litter);
			}
			else if(paymentM == 2){
				cash(total,litter);
			}
			else if (paymentM == 3){
				installment(total,litter);
			}
			else{
				cout<<"invalid entry!!"<<endl;
			}
		}
};
class total  {
	static int totalSales;
public: 
  
    void totalB(int sales){
    	totalSales +=sales; 
    	 ofstream file2("details.txt",ios::app);
    	 file2<<"total sales till now  : "<<totalSales<<endl;
    	 file2.close();
	}
	void displaySales(){
		cout<<"total sales till now is : "<<totalSales<<endl;
	}
		
};

int total::totalSales = 0;

class calculate : public price,public total {
	double cal; 
public:
    int dbilling(int litter) {
    	 cal = litter * dprice;
    	   totalB(cal);
        minusd(litter);
        return litter * dprice;
     
    }
    int pbilling(int litter) {
    	 cal = litter * pprice;
    	   totalB(cal);
    	   minusp(litter);
        return litter * pprice;
        
      
    }
    int hbilling(int litter) {
    	 cal = litter * hprice;
    	         totalB(cal);
int minush(litter);
        return litter * hprice;
    }
};

class fuel : public calculate,public payment ,public salePerson{ 
    int litter;
  int select;
  
public:
		fuel(string name,int preading,int hreading,int dreading):salePerson(name,preading,hreading,dreading){
		
	}
    void diesel() {
        cout << "You selected diesel and the current price of diesel is " << dprice << endl;
        cout << "How much litter you require: ";
        cin >> litter;
        cout << "Your total bill is " << dbilling(litter) << endl;
      pay(dbilling(litter),litter);
      addd(litter);
        
    }

    void petrol() {
        cout << "You selected petrol and the current price of petrol is " << pprice << endl;
        cout << "How much litter you require: ";
        cin >> litter;
        int price=pbilling(litter);
        cout << "Your total bill is " << price << endl;
         pay(price,litter);
    addp(litter);
	}

    void highoctane() {
        cout << "You selected high-octane and the current price of high-octane is " << hprice << endl;
        cout << "How much litter you require :";
        cin >> litter;
        cout << "Your total bill is " << hbilling(litter) << endl;
         pay(hbilling(litter),litter);
   addh(litter);
    }
    
};

class customer : public fuel { 
    int fuelType;
int choice;
public:
		customer(string name,int preading,int hreading,int dreading):fuel(name,preading,hreading,dreading){
		
	}
    void filling() {
        cout << "Which type of fuel do you want:\nPetrol (1)\nHigh-octane (2)\nDiesel (3)\nPlease select: ";
        cin >> fuelType;
        if (fuelType == 1) {
            petrol();
        } else if (fuelType == 2) {
            highoctane();
        } else if (fuelType == 3) {
            diesel();
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
};


class admin : public price,public salePerson ,public total{
	int cheak;
	int uCheak;
	int mcheak;
	int choice;
	public: 
	admin(string name,int preading,int hreading,int dreading):salePerson(name,preading,hreading,dreading){
		
	}
		void inventry(){
		cout<<"you want to cheak(1) or update inventry(2) : ";
		cin>>cheak;
		if(cheak == 1){
			cout<<"petrol : "<<pstoke<<" avaiable ";
			cout<<"high ocatane  : "<<hstoke<<" avaiable ";
			cout<<" diesel : "<<dstoke<<" avaiable ";
		}
		else if(cheak ==2 ){
			cout<<"want to update petrol(1),high ocatane(2) or diesel(3) : ";
			cin>>uCheak;
			if(uCheak == 1){
				cout<<"plz enter the updated stoke of petrol : ";
				cin>>pstoke;
				changed(pstoke);
					
			}
			else if(uCheak == 2){
					cout<<"plz enter the updated stoke of high octane : ";
				cin>>hstoke;
			changeh(hstoke);
			}
			else if (uCheak ==3){
					cout<<"plz enter the updated stoke of diesel  : ";
				cin>>dstoke;
				changed(dstoke);
		
			}
			else{
				cout<<"invalid entry!!!!!!!"<<endl;
			}
		}
	}
	void saleperson(){
	  displayname();
	afterDisplay();
	}
	void sales(){
	displaySales();
	}
	void change(){
		int select;
		cout<<"you want to change the pprice of petrol(1),high octane(2),diesel(3) : ";
		cin>>select;
		if(select == 1){
			int price;
			cout<<"plz enter new price : ";
			cin>>price;
			updatep(price);
		}
		else if(select ==2){
			updateh();
		
		}
		else if(select ==3){
		updated();
		}
	}
	void manager(){
do{
		cout<<"what are you looking for saleperson details (1) , total sales(2),  looking for inventry(3) , change price(4) : ";
	cin >> mcheak;
	if(mcheak == 1){
		saleperson();
	}
	else if (mcheak == 2){
		sales();
		
	}
	else if(mcheak == 3){
		inventry();
	}
	else if (mcheak == 4){
		change();
	}
	else{
		cout<<"invalid entry !!!!"<<endl;
		
	}
	cout<<"do you want to get out from admin access yes(1)or no(2) : ";
		cin>>choice;
}while(choice == 2);
	}
		
};

int main() {

    int check;
    int choice;
    int preading;
    int dreading;
    int hreading;
    string name;

    cout << "\t\t\t\t\t\tWelcome to our petrol pump" << endl;
    cout << "Enter sale person's name: ";
        cin >> name;
        cout << "Enter reading of petrol meter: ";
        cin >> preading;
        cout << "Enter reading of diesel meter: ";
        cin >> dreading;
        cout << "Enter the reading of high-octane meter: ";
        cin >> hreading;
        ofstream file2("details.txt",ios::app);
        file2<<"name of saleperson "<<name<<endl;
        file2<<"reading on petrol meter "<<preading<<endl;
        file2<<"reading of diesel meter "<<dreading<<endl;
        file2<<"reading of high octane meter "<<hreading<<endl;
        file2.close();
    
do {

    cout << "Are you a customer (1) = ";
    cin >> check;

    if (check == 1) {
        customer obj(name,preading,hreading,dreading); 
        obj.filling();
    } else if (check == 1111) {
        cout << "\t\t\t\t\t\t\tAdmin" << endl;
        admin ob(name,preading,hreading,dreading);;
        ob.manager();
    }
	else{
		cout<<"invalid entry !!!!"<<endl;
		
	}
cout<<"do you want to close pump yes(1)or no(2) :";
cin>>choice;
	
	}while(choice == 2);
    cout<<"pump closed!!! all data are avilable in txt docoments " <<endl;
    salePerson obj9;
obj9.fdisplay();
    return 0;
}