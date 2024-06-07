#ifndef TAN_H
#define TAN_H
#include <wx/gdicmn.h>
#include <wx/dc.h>
#include <wx/region.h>

class Tan {
public:
	static int workspaceWidth, workspaceHeight;
	double angle = 0;
	wxPoint* vertices = nullptr; //alokowana dynamicznie tablica - przechowuje wierzcho�ki
	wxPoint tileOffset = wxPoint(0, 0);
	wxPoint centerOfMass = wxPoint(0,0);
	int nOfVertices; //liczba wierzcho�k�w
	bool visibleInTray = true; //Czy tan jest widoczny w zasobniku? Je�eli nie, to jest widoczny w obszarze roboczym
	bool isHeld = false;
	wxRegion region; //Pokrywa si� z p�ytk� - u�ywany do sprawdzania czy p�ytka zosta�a klikni�ta

	/**@brief Domy�lny konstruktor - ustawia widoczno�� w zasobniku na true*/
	Tan();
	/**@brief Przypisuje podaje punkty do vertices - wersja dla tr�jk�t�w*/
	void addPoints(wxPoint p1, wxPoint p2, wxPoint p3);
	/**@brief Przypisuje podaje punkty do vertices - wersja dla czworok�t�w*/
	void addPoints(wxPoint p1, wxPoint p2, wxPoint p3, wxPoint p4);
	/**@brief Rysuje p�ytk� w zadanym DC
	* @param[in] dc - Tray lub Workspace
	* @param[in] origin - offset
	* @param[in] scale - skala*/
	void drawInTray(wxDC* dc, wxPoint origin, int scale);
	void drawInWorkspace(wxDC* dc, wxPoint origin, int scale, bool QPressed, bool EPressed);
	/**@brief Sprawdza czy mysz znajduje sie nad plytka
	* @param[in] mousePosition - pozycja myszy w danym kontek�cie rysunkowym*/
	bool checkMousePosition(wxPoint mousePosition);
	void rotate(double angle);
	/**@brief Destruktor - usuwa dynamicznie zaalokowane vertices*/
	~Tan();

};

#endif // !TAN_H