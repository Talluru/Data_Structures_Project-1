#include <iostream>
using namespace std;

class Item
{
	// Item attributes
protected:
	int code, colorCode, brandCode, typeCode;

public:
	static int noOfItems;
	double height, length, width, weight, price;
	bool commonBool;

	// Default constructor
	Item()
	{
		
		code = 0;
		colorCode = 0;
		brandCode = 0;
		height = 0;
		length = 0;
		width = 0;
		weight = 0;
		price = 0;
		typeCode = 0;
		commonBool = false;
		//cout << "Default Item constructor called" << endl;

	}

	// Constructor with all attributes
	Item( int i2, int i3, int i4, double f5, double f6, double f7, double f8, double f9, int i10, bool b11)
	{
		
		code = i2;
		colorCode = i3;
		brandCode = i4;
		height = f5;
		length = f6;
		width = f7;
		weight = f8;
		price = f9;
		typeCode = i10;
		commonBool = b11;
		//cout << "Non default item constructor called" << endl;
		noOfItems++;

	}

	// Object destructor
	~Item() { cout << "Item destructed" << endl; }

	// Setters for a few protected attributes
	// Setter for Color code
	void setColorCode(int c) {
		if (((c == 1 || c == 2 || c == 3 || c == 4) && (code == 1)) ||  // Pen has 4 color codes
			((c == 1 || c == 2) && (code == 2 || code == 3))) {  // printer and safebox has only 2 color codes

			colorCode = c;
		}
		else
			cout << " Invalid color code" << endl;
	}

	// Setter for Brand code
	void setBrandCode(int b) {
		if (((b == 1 || b == 2 || b == 3 || b == 4) && (code == 1|| code==2)) ||  // Pen and Printer has 4 brand codes
			((b == 1 || b == 2|| b==3) && (code == 3))) {  //  Safebox has only 3 brand codes

			brandCode = b;
		}
		else
			cout << " Invalid brand code" << endl;
	}

	// Setter for Type code
	void setTypeCode(int t) {
		if (((t == 1 || t == 2 || t == 3 || t == 4) && (code == 1 )) ||  // Pen and Printer has 4 brand codes
			((t == 1 || t == 2 || t == 3) && (code==2||code == 3))) {  //  Safebox has only 3 brand codes

			typeCode = t;
		}
		else
			cout << " Invalid type code" << endl;
	}

	// Getter for code, color code, brand code, type code
	int getCode() { return code; }
	int getBrandCode() { return brandCode; }
	int getColorCode() { return colorCode; }
	int getTypeCode() { return typeCode; }

	// method to print boolian parameters as Yes or No
	void printBool(bool x) {
		if (x == 1)
			cout << "Yes"<<endl;
		else
			cout << "No"<<endl;
	}

};

//------------------------------------------------------------------------------------------------------------------------------------

class Pens : public Item
{

// Pen attributes

public:
	static int noOfPens;
	static double pensValue;
	int packetSize;
	
	// Default constructor
	Pens() :Item() { packetSize = 0; }

	// Constructor with given attributes
	Pens( int i2, int i3, int i4, double f5, double f6, double f7, double f8, double f9, int i10, bool b11, int i12):
	Item( i2,  i3,  i4,  f5,  f6,  f7,  f8,  f9,  i10, b11)
	{
		packetSize = i12;
		noOfPens++;
		pensValue += f9;
		//cout << " Object pens created with main constructor" << endl;
	}

	// Destructor
	~Pens() { cout << "Pens Distructed" << endl; }
	
	// Method to print color according to code
	void printColor()
	{
		switch (colorCode)
		{
		case 1:
			cout << "Red"; break;
		case 2:
			cout << "Blue"; break;
		case 3:
			cout<< "Green"; break;
		case 4:
			cout << "Black"; break;
		default:
			cout<< "Unknown Color"; break;
		}
	}

	// Method to print brand according to code
	void printBrand()
	{
		switch (brandCode)
		{
		case 1:
			cout<< "Pilot"; break;
		case 2:
			cout<< "Paper mate"; break;
		case 3:
			cout<< "Uni-ball"; break;
		case 4:
			cout<< "Sharpie"; break;
		default:
			cout<< "Unknown Brand";
		}
	}

	// Method to print Type according to code
	void printType()
	{
		switch (typeCode)
		{
		case 1:
			cout<< "Ball Point"; break;
		case 2:
			cout<< "Roller Ball"; break;
		case 3:
			cout<< "Fountain"; break;
		case 4:
			cout<< "Calligraphy"; break;
		default:
			cout<< "Unknown type";
		}
	}

	// Method to print all the attributes
	void display(int ii)
	{
		cout << "\n\n-----------------"<<"Item: "<< ii+1 <<" Pen  Details--------------------------" << endl;
		cout << "Color:         "; this->printColor(); cout << endl;
		cout << "Brand:         "; this->printBrand(); cout << endl;
		cout << "Height:        "<< height<< endl;
		cout << "Length:        "<<length<< endl;
		cout << "Width:         "<<width<< endl;
		cout << "Weight:        "<<weight << endl;
		cout << "Price:         "<<price << endl;
		cout << "Type:          "; this->printType(); cout << endl;
		cout << "Assorted Ink:  "; printBool(commonBool);
		cout << "Packek Size:   "<<packetSize << endl;
	}

};

//------------------------------------------------------------------------------------------------------------------------------------
class Printer: public Item
{

// Printer attributes
public:
	static int noOfPrinters;
	static double printersValue;
	int trayCapacity;

	// Default constructor
	Printer() :Item() { trayCapacity = 0; }

	// Constructor with all the attributes
	Printer( int i2, int i3, int i4, double f5, double f6, double f7, double f8, double f9, int i10, bool b11, int i12):
		Item( i2, i3, i4, f5, f6, f7, f8, f9, i10, b11){
		trayCapacity = i12;
		noOfPrinters++;
		printersValue += f9;
	}

	
	// Object destructor
	~Printer() { cout << "Printer Distructed" << endl; }

	// Method to print color
	void printColor()
	{
		switch (colorCode)
		{
		case 1:
			cout << "Black"; break;
		case 2:
			cout<< "White"; break;
		default:
			cout<< "Unknown Color"; break;
		}
	}

	// Method to print Brand
	void printBrand()
	{
		switch (brandCode)
		{
		case 1:
			cout<< "Dell"; break;
		case 2:
			cout<< "HP"; break;
		case 3:
			cout<<"Cannon"; break;
		case 4: 
			cout<< "Brother"; break;
		default:
			cout << "Unknown Brand";
		}
	}

	// Method to print type
	void printType()
	{
		switch (typeCode)
		{
		case 1:
			cout << "All-In-One"; break;
		case 2:
			cout << "Laser"; break;
		case 3:
			cout << "InkJet"; break;
		default:
			cout << "Unknown Type";
		}
	}

	// Method to print all the attributes
	void display(int ii)
	{
		cout << "\n\n-----------------" << "Item: " << ii+1 << " Printer  Details--------------------------" << endl;
		cout << "Color:         "; this->printColor(); cout << endl;
		cout << "Brand:         "; this->printBrand(); cout << endl;
		cout << "Height:        " << height << endl;
		cout << "Length:        " << length << endl;
		cout << "Width:         " << width << endl;
		cout << "Weight:        " << weight << endl;
		cout << "Price:         " << price << endl;
		cout << "Type:          "; this->printType(); cout << endl;
		cout << "Network:  "; printBool(commonBool);
		cout << "Tray Capacity:   " << trayCapacity << endl;
	}

};

//------------------------------------------------------------------------------------------------------------------------------------
class SafeBox: public Item
{

// Safe box attributes
	public:
	static int noOfSafeBoxs;
	static double safeBoxsValue;
	bool electronicLock;

	// Default constructor
	SafeBox():Item(){electronicLock = 0;}

	// Constructor with all the attributes
	SafeBox( int i2, int i3, int i4, double f5, double f6, double f7, double f8, double f9, int i10, bool b11, int i12):
		Item( i2, i3, i4, f5, f6, f7, f8, f9, i10, b11){
		noOfSafeBoxs++;
		safeBoxsValue += f9;
		electronicLock = i12;
		//cout << " Safebox created with main constructor" << endl;
	}
	
	// Object destructor
	~SafeBox() { cout << "SafeBox Distructed" << endl; }

	// Method to print color
	void printColor()
	{
		switch (colorCode)
		{
		case 1:
			cout << "Black"; break;
		case 2:
			cout << "Red"; break;
		default:
			cout<< "Unknown Color";
		}
	}

	// Method to print brand
	void printBrand()
	{
		switch (brandCode)
		{
		case 1:
			cout << "SentrySafe"; break;
		case 2:
			cout<< "First Alert"; break;
		case 3:
			cout<< "Honeywell"; break;
		default:
			cout<< "Unknown Brand";
		}
	}

	// Method to print type
	void printType()
	{
		switch (typeCode)
		{
		case 1:
			cout << "Water Proof"; break;
		case 2:
			cout << "Wall Mountable"; break;
		case 3:
			cout << "Desktop"; break;
		default:
			cout<< "Unknown Type"; 
		}
	}

	// Method to print all the attributes
	void display(int ii)
	{
		cout << "\n\n-----------------" << "Item: " << ii+1 << " Safe Box  Details--------------------------" << endl;
		cout << "Color:         "; this->printColor(); cout << endl;
		cout << "Brand:         "; this->printBrand(); cout << endl;
		cout << "Height:        " << height << endl;
		cout << "Length:        " << length << endl;
		cout << "Width:         " << width << endl;
		cout << "Weight:        " << weight << endl;
		cout << "Price:         " << price << endl;
		cout << "Type:          "; this->printType(); cout << endl;
		cout << "Fire Resistant:  "; printBool(commonBool);
		cout << "Electronic Lock:   "; printBool(electronicLock);
	}
};

//------------------------------------------------------------------------------------------------------------------------------------

// Setting the count of each item to 0 initially
int Pens::noOfPens = 0;
double Pens::pensValue = 0;

int Printer::noOfPrinters = 0;
double Printer::printersValue = 0;

int SafeBox::noOfSafeBoxs = 0;
double SafeBox::safeBoxsValue = 0;

int Item::noOfItems = 0;

//-----------------------------------------------------------------------------------------------------------------------------------
void main()
{
	//Bag containing pointers of all the items
	Item* bag[100];
	int bagPos = 0;
	int inputCount = 0;


	cout << "***************************************************************" << endl;
	cout << "Author: Gowtham Talluru" << endl;
	cout << "Computing Structures - Project-1" << endl;
	cout << "\n\n************************** INPUT ***************************\n\n"<<endl;

	// While loop runs for each line in the input 
	while (!cin.eof())
	{
		// Variables for each item in the line
		// alphabet represents data type and number represents position of the input in the line
		bool  b11;
		int i1, i2, i3, i4, i10, i12;
		double f9, f5, f6, f7, f8;

		// Incrementing Input count
		inputCount++;

		// For loop  identifies each element in a line (attributes)
		for (int i = 0; i < 13; i++)
		{
			char line[10];
			cin >> line;
			
			// Following switch statement sets each input parameter
			switch (i) 
			{
			case 1:
				i1 = atoi(line);
				break;
			case 2:
				i2 = atoi(line);
				break;
			case 3:
				i3 = atoi(line);
				break;
			case 4:
				i4 = atoi(line);
				break;
			case 5:
				f5 = atof(line);
				break;
			case 6:
				f6 = atof(line);
				break;
			case 7:
				f7 = atof(line);
				break;
			case 8:
				f8 = atof(line);
				break;
			case 9:
				f9 = atof(line);
				break;
			case 10:
				i10 = atoi(line);
				break;
			case 11:
				b11 = (atoi(line) == 1) ? true : false;
				break;
			case 12:
				i12 = atoi(line);
			}

		}

		// Printing each input line 
		cout << "Input:  " <<inputCount << "    "<< i1 << " " << i2 << " " << i3 << " " << i4 << " " << f5 << " " <<
			f6<<" " << f7<<" " << f8<<" " << f9<<" " << i10<<" " << b11<<" " << i12<< endl;

		// Creates required number of objects for each line based on quantity
		for (int i = 0; i < i1; i++)
		{
			// Switch statement creates objects based on code
			switch (i2)
			{
			case 1:
			{
				bag[bagPos] = new Pens(i2, i3, i4, f5, f6, f7, f8, f9, i10, b11, i12);
				bagPos++;
				break;
			}
			case 2:
			{
				bag[bagPos] = new Printer(i2, i3, i4, f5, f6, f7, f8, f9, i10, b11, i12);
				bagPos++;
				break;
			}
			case 3:
			{
				bag[bagPos] = new SafeBox(i2, i3, i4, f5, f6, f7, f8, f9, i10, b11, i12);
				bagPos++;
				break;
			}
			default:
				cout << " Un Identified object detected" << endl;

			}

		}

	}
	// Printing item wise count
	cout << "\n*************************************************************\n" << endl;
	cout << Pens::noOfPens << " Pens   " << Printer::noOfPrinters << " Printers     " << SafeBox::noOfSafeBoxs
		<< " Safe Boxes   Created" << endl;

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------

	//Printing Summary
	cout << "\n************************* Summary ***************************\n" << endl;

	cout << "No of Pens:       " << Pens::noOfPens << "        "<< "Value of Pens:        "<< Pens::pensValue<< endl;

	cout << "No of Printers:   " << Printer::noOfPrinters << "        " <<"Value of Printers:    " << Printer::printersValue << endl;

	cout << "No of Safe Boxes: " << SafeBox::noOfSafeBoxs << "        " <<"Value of Safe Boxes:  " << SafeBox::safeBoxsValue << endl;

	cout << "---------------------------------------------------------" << endl;

	cout << "Total Items:      " << Pens::noOfPens + Printer::noOfPrinters + SafeBox::noOfSafeBoxs <<"        "<< "Total Value of items: " <<
		Pens::pensValue + Printer::printersValue + SafeBox::safeBoxsValue << endl;
	cout << "---------------------------------------------------------\n" << endl;

	cout << " Average Pen value:	 " << Pens::pensValue / Pens::noOfPens << endl;
	cout << " Average Printer value:	 " << Printer::printersValue / Printer::noOfItems << endl;
	cout << " Average Safe Box value:  " << SafeBox::safeBoxsValue / SafeBox::noOfItems << endl;

	cout << "\n\n************************************************************************" << endl;
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	// Printing details of each items
	for (int i = 0; i < Item::noOfItems ; i++) {

		cout << "--------------------------------------------------------"<<endl;
		
		switch ((*bag[i]).getCode())
		{
		case 1: {//Pens
			(static_cast<Pens*>(bag[i]))->display(i);
			break;
		}
		case 2: {//Printers
			(static_cast<Printer*>(bag[i]))->display(i);
			break;
		}
		case 3: {//Safe Box
			(static_cast<SafeBox*>(bag[i]))->display(i);
			break;
		}
		default:
			cout << " Cannot find this item " << endl;
		}
	}
	
} 


//-------------------------------------------------------------------------- End of Code ----------------------------------------------------------------------------------