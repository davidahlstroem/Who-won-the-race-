#include <iostream>
#include <iomanip>
using namespace std;

int convertIntoSeconds(int tim, int min, int sek) {
	int total;
    total = tim * 3600 + min * 60 + sek;
	return total;
}

int main() {

	int startnummer = 1, antal = 0, vinnare = 0, vinnarTim = 0, vinnarMin = 0, vinnarSek = 0;
	int startSek = 0, startMin = 0, startTim = 0, slutSek = 0, slutMin = 0, slutTim = 0,  totalTim = 0, totalMin = 0, totalSek = 0, snabbastTid = 99999999; 

	while (startnummer > 0)
	{
		cout << "Startnummer? ";
		cin >> startnummer;
		if (startnummer <= 0){break;}
		cout << "Starttid? ";
		cin >> startTim >> startMin >> startSek;
		cout << "Sluttid? ";
		cin >> slutTim >> slutMin >> slutSek;

		// calculate time
		totalTim = (slutTim - startTim + 24) % 24;
		totalMin = (slutMin - startMin + 60) % 60;
		totalSek = (slutSek - startSek + 60) % 60;
		if (slutMin < startMin) {
			totalTim = (--totalTim + 24) % 24;
		}
		if (slutSek < startSek) {
			if (totalMin == 0) {
				totalTim = (--totalTim + 24) % 24;
			}
			totalMin = (--totalMin + 60) % 60;
		} // calculate time END

		// calculate fastest time
		int tidTotal = convertIntoSeconds(totalTim, totalMin, totalSek);
		if (tidTotal < snabbastTid){
			snabbastTid = tidTotal;
			vinnare = startnummer;
			vinnarTim = totalTim;
			vinnarMin = totalMin;
			vinnarSek = totalSek;
		} // calculate fastest time END

		antal++;
	}

	if (antal > 0){
		cout << "Vinnare ar startnr: " << vinnare << endl;
		cout << "Tim: " << vinnarTim << " Min: " << vinnarMin << " Sek: " << vinnarSek << endl;
		cout << "Antal tavlande: " << antal << endl;
	} else cout << "Inga tavlande " << endl;
	cout << "Programmet avslutas" << endl;
	return 0;
}