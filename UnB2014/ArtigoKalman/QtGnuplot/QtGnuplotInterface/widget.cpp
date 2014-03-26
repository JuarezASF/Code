#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/* //A FUNÇAO A SEGUIR PLOTA O RESULTADO EM PNG
    //ELA E FACILMENTE ADAPTADA PARA IMPRIMIR EM LATEX

#include <fstream>
#include <vector>
#include <map>
#include <limits>
#include <cmath>
#include <cstdio>
#include <boost/tuple/tuple.hpp>
#include <boost/foreach.hpp>

#ifndef M_PI
#	define M_PI 3.14159265358979323846
#endif


void demo_png() {
    Gnuplot gp;

    gp << "set terminal png\n";

    std::vector<double> y_pts;
    for(int i=0; i<1000; i++) {
        double y = (i/500.0-1) * (i/500.0-1);
        y_pts.push_back(y);
    }

    std::cout << "Creating my_graph_1.png" << std::endl;
    gp << "set output 'my_graph_1.png'\n";
    gp << "plot '-' with lines, sin(x/200) with lines\n";
    gp.send1d(y_pts);

    std::vector<std::pair<double, double> > xy_pts_A;
    for(double x=-2; x<2; x+=0.01) {
        double y = x*x*x;
        xy_pts_A.push_back(std::make_pair(x, y));
    }

    std::vector<std::pair<double, double> > xy_pts_B;
    for(double alpha=0; alpha<1; alpha+=1.0/24.0) {
        double theta = alpha*2.0*3.14159;
        xy_pts_B.push_back(std::make_pair(cos(theta), sin(theta)));
    }

    std::cout << "Creating my_graph_2.png" << std::endl;
    gp << "set output 'my_graph_2.png'\n";
    gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
    gp << "plot '-' with lines title 'cubic', '-' with points title 'circle'\n";
    gp.send1d(xy_pts_A);
    gp.send1d(xy_pts_B);
}*/

/*//O DEMO A SEGUIR GERA UM VIDEO EM TEMPO DE EXECUÇAO
void demo_animation() {

    Gnuplot gp;

    std::cout << "Press Ctrl-C to quit (closing gnuplot window doesn't quit)." << std::endl;

    gp << "set yrange [-1:1]\n";

    const int N = 1000;
    std::vector<double> pts(N);

    double theta = 0;
    while(1) {
        for(int i=0; i<N; i++) {
            double alpha = (double(i)/N-0.5) * 10;
            pts[i] = sin(alpha*8.0 + theta) * exp(-alpha*alpha/2.0);
        }

        gp << "plot '-' binary" << gp.binFmt1d(pts, "array") << "with lines notitle\n";
        gp.sendBinary1d(pts);
        gp.flush();

        theta += 0.2;
        mysleep(100);
    }
}*/

/*
    //O EXEMPLO A SEGUIR MOSTRA UM PROGRAMA INTERATIVO

#include <vector>
#include <cmath>
#include <cstdlib>

#include <boost/tuple/tuple.hpp>

// This must be defined before the first time that "gnuplot-iostream.h" is included.
#define GNUPLOT_ENABLE_PTY
#include "gnuplot-iostream.h"

int main() {
    Gnuplot gp;

    // Create field of arrows at random locations.
    std::vector<boost::tuple<double,double,double,double> > arrows;
    for(size_t i=0; i<100; i++) {
        double x = rand() / double(RAND_MAX);
        double y = rand() / double(RAND_MAX);
        arrows.push_back(boost::make_tuple(x, y, 0, 0));
    }

    double mx=0.5, my=0.5;
    int mb=1;
    while(mb != 3 && mb >= 0) {
        // Make the arrows point towards the mouse click.
        for(size_t i=0; i<arrows.size(); i++) {
            double x = arrows[i].get<0>();
            double y = arrows[i].get<1>();
            double dx = (mx-x) * 0.1;
            double dy = (my-y) * 0.1;
            arrows[i] = boost::make_tuple(x, y, dx, dy);
        }

        gp << "plot '-' with vectors notitle\n";
        gp.send1d(arrows);

        gp.getMouse(mx, my, mb, "Left click to aim arrows, right click to exit.");
        printf("You pressed mouse button %d at x=%f y=%f\n", mb, mx, my);
        if(mb < 0) printf("The gnuplot window was closed.\n");
    }
}
*/
