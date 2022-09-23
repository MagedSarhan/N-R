#include<iostream>
#include<cmath>
using namespace std;
double m, a, g, e, d, s, u, r, h, n;
// Derivative Methode (f) w.r.t x 
double dfx(double xn) {
	double fx = (m*a)* pow(xn , (a-1));
	return fx;
}
// Derivative Methode (f) w.r.t y 
double dfy(double yn) {
	double fy = (g * e) * pow(yn, (e - 1));
	return fy;
}
// Derivative Methode (f) w.r.t x 
double dgx(double xn) {
	double gx = (s * u) * pow(xn, (u - 1));
	return gx;
}
// Derivative Methode (f) w.r.t y 
double dgy(double yn) {
	double gy = (r * h) * pow(yn, (h - 1));
	return gy;
}
// Find F_node = f (xn , yn )
double f_node(double xn, double yn) {
	double fn = m*pow(xn,a) + g*pow(yn , e) + d;
	return fn;
}
// Find g_node = g (xn , yn )
double g_node(double xn, double yn) {
	double gn = s * pow(xn, u) + r * pow(yn, h) + n;
	return gn;
}
int main() {
	double xn, yn, stages;
	cout << "Consider the equations: " << endl;
	cout << " f(x, y) = mX^a + gY^e - d" << endl;
	cout << " g(x, y) = sX^u + rY^h - n" << endl;
	cout << "Enter the values of ( m, a, g, e, d, s, u, r, h, n ) respectively: ";
	cin >> m >> a >> g >> e >> d >> s >> u >> r >> h >> n;
	cout << "Entr an intial approximation: => ( x , y ) ";
	cin >> xn >> yn;
	cout << "enter Number Of Stages: ";
    cin >> stages;
	for (int i = 1;i <= stages;i++)
	{
		dfx(xn);
		dfy(yn);
		dgx(xn);
		dgy(yn);
		f_node(xn, yn);
		g_node(xn, yn);
		// Get h & k values
		double a = dfx(xn), b = dfy(yn), c = f_node(xn, yn),
			d = dgx(xn), e = dgy(yn), f = g_node(xn, yn);
		double Dx, Dy, D;
		Dx = (-c * e) +( b * f);
		Dy = (-a * f) + (c * d);
		D = (a * e) - (d * b);
		double h =( Dx / D), k = (Dy / D), x , y;
		x = h + xn;
		y = k + yn;
		cout << "x" << i << " = " << x << endl;
		cout << "y" << i << " = " << y << endl;
		xn = x;
		yn = y;
	}
	return 0;

}