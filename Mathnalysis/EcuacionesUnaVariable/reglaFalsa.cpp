#include<iostream>
#include<cmath>
#include<iomanip>
#include "reglaFalsa.h"

using namespace std;


void reglaFalsa(double (*func)(double),double a, double b, double tol, int niter) {
	cout << fixed;
	cout.precision(7);
	double y0 = func(a);
	double y1 = func(b);
	if (tol < 0) {
		cout << "tolerancia no valida";
		cout << "tolerancia no valida";
	}
	else if (niter <= 0) {
		cout << "numero de iteraciones no validas";
	}
	else if (y0 == 0) {
		cout << "a es unan raiz";
	}
	else if (y1 == 0) {
		cout << "b es una raiz";
	}
	else if (y0 * y1 < 0) {

		double xm = a - ((y0 * (b - a)) / (y1 - y0));
		double ym = func(xm);
		cout << "  niter        a           b          xm         fxm         error  " << endl;
		int cont = 01;
		double error = tol + 1;
		cout << cont << "        " << a << "   " << b << "   " << xm << "   " << ym << "   " << "       " << "   " << endl;
		while (ym != 0 && error > tol && cont < niter) {
			if (ym * y1 < 0) {
				a = xm;
				y0 = ym;
			}
			else {
				b = xm;
				y1 = ym;
			}
			double aux = xm;
			xm =  a - ((y0 * (b - a)) / (y1 - y0));
			ym = func(xm);
			cont++;
			error = abs(xm - aux);
			cout << cont << "        " << a << "   " << b << "   " << xm << "   " << ym << "   " << error << "   " << endl;
		}
		if (ym == 0) {
			cout << xm << "es una raiz" << endl;
		}
		else if (error < tol) {
			cout << xm << "es una aproximacion a la raiz con una tolerancia de: " << tol << endl;
		}
		else {
			cout << " fracasa con " << niter << "iteraciones" << endl;
		}

	}
	else {
		cout << "fracasa" << endl;
	}

}
