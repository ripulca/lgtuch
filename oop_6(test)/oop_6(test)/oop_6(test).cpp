#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;
using namespace System;
using namespace System::Xml;
using namespace System::Xml::Serialization;
using namespace System::IO;
using namespace System::Collections::Generic;
ref class Cruise;
ref class Warship;
[Serializable]
public ref class Factory {
public:
	String^ country;
	String^ name;
};
[XmlInclude(Cruise::typeid)]
[XmlInclude(Warship::typeid)]
[Serializable]
public ref class Ship : public Factory {
public:
	float weight;
	float price;
};
[Serializable]
public ref class Cruise : public Ship {
public:
	int serial_number;
};
[Serializable]
public ref class Warship : public Ship {
public:
	bool weapon;
};
[Serializable]
public ref class Elementary {
public:
	List<Ship^>^ element=gcnew List<Ship^>();
};

int main(){
	int choice = 1, index;
	XmlSerializer^ serializer;
	Elementary^ part = gcnew Elementary(); TextReader^ in; TextWriter^ out; Cruise^ ship; Warship^ wrship;
	String ^ file;
	while (choice) {
		cout << "Press 1 use data from file" << endl;
		cout << "Press 2 to add some cruise stuff" << endl;
		cout << "Press 3 to add some brutal stuff" << endl;
		cout << "Press 4 to remove smth" << endl;
		cout << "Press 5 to save stuff in file" << endl;
		cout << "Press 6 to see wha u've done" << endl;
		cout << "Press 0 to leave the chat" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "filename" << endl;
			file = Console::ReadLine();
			serializer = gcnew XmlSerializer(part->GetType());
			in = gcnew StreamReader(file);
			part = (Elementary^)serializer->Deserialize(in);
			in->Close();
			break;
		case 2:
			ship = gcnew Cruise();
			cout << "serial number" << endl;
			ship->serial_number = Int32::Parse(Console::ReadLine());
			cout << "name" << endl;
			ship->name = Console::ReadLine();
			cout << "country" << endl;
			ship->country = Console::ReadLine();
			cout << "weight" << endl;
			ship->weight = Int32::Parse(Console::ReadLine());
			cout << "price" << endl;
			ship->price = Int32::Parse(Console::ReadLine());
			part->element->Add(ship);
			break;
		case 3:
			wrship = gcnew Warship();
			wrship->weapon = true;
			cout << "name" << endl;
			wrship->name = Console::ReadLine();
			cout << "country" << endl;
			wrship->country = Console::ReadLine();
			cout << "weight" << endl;
			wrship->weight = Int32::Parse(Console::ReadLine());
			cout << "price" << endl;
			wrship->price = Int32::Parse(Console::ReadLine());
			part->element->Add(wrship);
			break;
		case 4:
			cout << "enter index" << endl;
			cin >> index;
			index--;
			part->element->Remove(part->element[index]);
			break;
		case 5:
			cout << "filename" << endl;
			file = Console::ReadLine();
			serializer = gcnew XmlSerializer(part->GetType());
			out = gcnew StreamWriter(file);
			serializer->Serialize(out, part);
			out->Close();
			break;
		case 6:
			if (part->element->Count == 0) throw gcnew IndexOutOfRangeException();
				for (int i = 0; i < part->element->Count; i++) {
					if (part->element[i]->GetType()==(Cruise::typeid)) {
						cout << "serial number" << endl << ((Cruise^)part->element[i])->serial_number << endl;
						Console::WriteLine("name: " + part->element[i]->name);
						cout << "weight" << endl << part->element[i]->weight << endl;
						Console::WriteLine("made in: " + part->element[i]->country);
						cout << "weight" << endl << part->element[i]->price << endl;
					}
					else if(part->element[i]->GetType()==(Warship::typeid)) {
						cout << "weapon (has or not)" << endl << ((Warship^)part->element[i])->weapon << endl;
						Console::WriteLine("name: " + part->element[i]->name);
						cout << "weight" << endl << part->element[i]->weight << endl;
						Console::WriteLine("made in: " + part->element[i]->country);
						cout << "weight" << endl << part->element[i]->price << endl;
					}
				}
		}
	}
    return 0;
}
