//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include <iostream>
#include "Trip.h"
using namespace std;

void loadTrips(Trip *trip[]);
void printTrips(Trip *trip[]);
int getTrip(void);
float getSpeed(void);
void displayTime(Trip *trip, float speed);

void loadTrips(Trip *trip[])
{
	trip[0] = new Trip(89, "Milwaukee");
	trip[1] = new Trip(283, "Detroit");
	trip[2] = new Trip(345, "Cleveland");
	trip[3] = new Trip(1012, "Boston");
	trip[4] = new Trip(332, "Des Moines");
	trip[5] = new Trip(300, "St. Louis");
	trip[6] = new Trip(717, "Atlanta");
	trip[7] = new Trip(967, "Dallas");
	trip[8] = new Trip(408, "Minneapolis");
	trip[9] = new Trip(3571, "Anchorage");
	return;
}

void printTrips(Trip *trip[])
{
	cout << "Trip begins in Chicago" << endl;
	cout << "Trip #\tDistance\tDestination" << endl;
	cout << "-----------------------------------" << endl;
	for(int a = 0; a < 10; a++)
	{
		cout << a << ")\t" << trip[a]->getDistance() << "\t\t" <<
				trip[a]->getName() << endl;
	}
	cout << "10) Exit" << endl;
	return;
}

int getTrip(void)
{
	int c = -1;

	do
	{
		cout << "Enter trip number: ";
		cin >> c;
	} while((c > 10) || (c < 0));
	return c;
}

float getSpeed(void)
{
	float speed = -1.0;

	do
	{
		cout << "Enter speed (MPH): ";
		cin >> speed;
	} while(speed <= 0);
	return speed;
}

void displayTime(Trip *trip, float speed)
{
	float time = trip->calcETA(speed);
	cout << endl << "---------------------------------------------------" << endl;
	cout << "ETA at " << trip->getName() << " is " << time << " hour";
	if(time > 1.0) cout << "s";
	cout << "." << endl;
	cout << "---------------------------------------------------" << endl << endl;
	return;
}

int main(void)
{
	Trip *trip[10];
	int c = 0;
	float speed;
	loadTrips(trip);
	while(c != 10)
	{
		printTrips(trip);
		c = getTrip();
		if(c != 10)
		{
			speed = getSpeed();
			displayTime(trip[c], speed);
		}
	}

	return 0;
}
