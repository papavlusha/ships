#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <fstream>

using namespace std;

int main()
{
	int N;
	bool empty;
	string ship;
	string info;
	vector <string> Ports;
	deque <string> Raid;
	ifstream FIN;
	ofstream FOUT;
	FIN.open("SHIPS.IN");
	FOUT.open("SHIPS.OUT");
	if (!FIN.is_open())
	{
		cout << "Imposible to find file!\n";
		return 0;
	}
	if (FIN.peek() == EOF)
	{
		cout << "file is empty!\n";
		return 0;
	}
	FIN >> N;
	for (int i = 0; i < N; i++) {
		Ports.push_back("");
	}
	FIN.ignore(1, '\n');
	while (getline(FIN, info))
	{
		char op = info[0];
		switch (op)
		{

		case '1':
			empty = false;
			info.erase(0, 2);
			for (int i = 0; i < N; i++) {
				if (Ports[i] == "") {
					Ports[i] = info;
					empty = true;
					FOUT << "Ship " + info + " now on " << i + 1 << " - pier\n";
					break;
				}
			}
			if (empty == false) {
				Raid.push_back(info);
				FOUT << "all piers are not empty !\n";
				FOUT << "ship " + info + " now on raid\n";
			}
			FOUT << "\n";
			break;

		case '2':
			info.erase(0, 2);
			FOUT << "pier number " << info << " now is empty\n";
			if (Raid.size() > 0) {
				Ports[stoi(info) - 1] = Raid[0];
				FOUT << "ship " << Raid[0] << " now on pier " << stoi(info) << endl;
				Raid.pop_front();
			}
			else
				Ports[stoi(info) - 1] = "";
			FOUT << "\n";
			break;

		case '3':
			if (Raid.size() > 0) {
				FOUT << "ships on raid \n";
				for (auto now : Raid) {
					FOUT << "<" << now << ">  ";
				}
				FOUT << endl;
			}
			else
			{
				FOUT << "No ships on raid\n";
			}
			FOUT << "\n";
			break;

		case '4':
			for (int i = 0; i < Ports.size(); i++) {
				if (Ports[i] == "")
					FOUT << i + 1 << " - pier is empty\n";
				else
					FOUT << i + 1 << " - pier holds " + Ports[i] + '\n';
			}
			FOUT << "\n";
			break;
		}
	}
	FIN.close();
	FOUT.close();
	system("SHIPS.OUT");
	return 0;
}