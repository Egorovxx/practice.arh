#include <iostream>
#include <fstream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;
 
int reading(string myfile, string imagename, double lat1, double lon1, double lat2, double lon2)
{
    const string File = myfile;
    int x,y,xm,ym;
    unsigned long t, tt;
    long double  converted_x, converted_y;
    long double calc_KW, calc_KH;
    /*lat1 = 55.859314;//левая верхняя
    lon1 = 37.619000;
    lat2 = 55.857498;//правая нижняя
    lon2 = 37.621515;*/
    
    
    ifstream f(File);
    if (!(f.is_open()))  // проверка наличия файла с текстом
        cout<<"ERROR: not file "<<File;
    else
    {
        Mat img = imread(imagename);
        f>>t>>x>>y;
        calc_KW = (lat1-lat2)/img.size().width;
        calc_KH = (lon1-lon2)/img.size().height;
        
        while(!f.eof()) // чтении из файла
        {
            circle(img, Point(x,y),5, Scalar(255,255,255),CV_FILLED, 8,0);
            f>>tt>>xm>>ym;
            converted_x = calc_KW*(img.size().width - x) + lat2;
            converted_y = calc_KH*(img.size().height - y) + lon1;
            cout<<"time: "<<t<<" x: "<<converted_x<<" y: "<<converted_y<<endl;
            imshow("window", img);
            waitKey(tt-t);
            line(img, Point(x,y), Point(xm, ym), Scalar(0,255,0), 2);
            x = xm;
            y = ym;
            t = tt;
                    }
    }
    
    f.close();
    cout << endl;
    return 0;
}

