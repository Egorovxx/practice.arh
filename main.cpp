#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <string>
#include <cstring>
#include <typeinfo>

#include <nlohmann/json.hpp>

//имя файла с картинкой (скрин карт),  имя файла с траекторией, метка времени, широта, долгота, нарисовать траекторию поверх изображения карты
// экранные координаты двух точек (5 точек)
//нарисовать траекторию точками
//вычислить масштаб
using namespace cv;
using namespace std;

int main() {
    Mat image = imread("/Users/anyawindsford/Desktop/opencv/road.jpg");
    cout << "Width : " << image.size().width << endl;
    cout << "Height: " << image.size().height << endl;
    Rect recte =Rect((image.size().width/2),(image.size().height/2),200,200);
    rectangle(image, recte, Scalar(255,205,0),20,8,0);
    imwrite("/Users/anyawindsford/Desktop/opencv/road2.jpg", image);
    imshow("my img", image);
    while (1){
        if (waitKey(30)==27)
            break;
    }
    
    return 0;
}

/*using namespace cv;
using namespace std;
using json = nlohmann::json;


void my_mouse_callback(int event, int x, int y, int flags, void* param);
int reading(string myfile, string imagename, double lat1, double lon1, double lat2, double lon2);

int main(int argc, char** argv ) {
    //чтение JSON файла
    std::ifstream i("/Users/anyawindsford/Desktop/opencv/config.json");
    json j;
    i >> j;

    string imagename = j.at("imageName").get<string>();
    //cout << "imageName = " << imagename << '\n';
    //char* image_name = new char[imagename.length() + 1];
    //strcpy(image_name, imagename.c_str());
    
    string myfile = j.at("fileName").get<string>();
    //cout << "fileName = " << myfile << '\n';
    
    double lat1 = j.at("lat1").get<double>();
    //cout << "lat1 = " << lat1 << '\n';
    
    double lon1 = j.at("lon1").get<double>();
    //cout << "lon1 = " << lon1 << '\n';
    
    double lat2 = j.at("lat2").get<double>();
    //cout << "lat2 = " << lat2 << '\n';
    
    double lon2 = j.at("lon2").get<double>();
    //cout << "lon2 = " << lon2 << '\n';*/
    
    
    /*cv::CommandLineParser parser(argc, argv, "{ @image |maps.png | }"
                                 "{@text|dfs.txt |}"
                                 "{lat1 | 55.859314|}"
                                 "{lon1 | 37.619000|}"
                                 "{lat2 | 55.857498|}"
                                 "{lon2 | 37.621515|}");
    
    std::string filename = parser.get<std::string>("@image");
    char* imagename = new char[filename.length() + 1];
    strcpy(imagename, filename.c_str());
   string textname = parser.get<string>("@text");
    char* myfile = new char[textname.length() + 1];
    strcpy(myfile, textname.c_str());
    
    double lat1 = parser.get<double>("lat1");
    double lon1 = parser.get<double>("lon1");
    double lat2 = parser.get<double>("lat2");
    double lon2 = parser.get<double>("lon2");*/
    
   //reading(myfile, imagename, lat1, lon1, lat2, lon2);
    
    /*Mat image = imread(filename);
    
    namedWindow("maps");
    setMouseCallback("maps", my_mouse_callback, &image );
    
    while(true){
        imshow("maps",image);
        waitKey(1);}*/
    
     //reading();
    
    // return(0);
//}


/*void my_mouse_callback( int event, int x, int y, int flags, void* param ) {
    if(event==CV_EVENT_LBUTTONDOWN){
        Mat* pImage = (Mat*)param;
        Mat image = *pImage;
        circle( image, Point(x,y), 20, Scalar(0xff,0xff,0xff) );
        ofstream file;
        file.open("/Users/anyawindsford/Desktop/opencv/maps.png", ios_base::app);
        unsigned long milliseconds_since_epoch =std::chrono::system_clock::now().time_since_epoch() /std::chrono::milliseconds(1);
        file<< milliseconds_since_epoch <<" "<< x <<" "<< y<<endl;
        file.close();

    }
    
}*/

//1) файл изображения должен указываться в качестве параметра командной строки - done
//2) координаты точек и географические и экранные указываются в качестве параметров командной строки
//3) имя файла маршрута - параметры командной строки

/* 3 задание
Добавить возможность чтения параметры которые нужны для запуска из конфигурационного файла(в формате json или ini) - посмотреть что из себя представляет json формат */

/* 4 задание
 Сделать поток в котором вычитываем текущие координаты и рисовать из файла траектории по времени. Во втором потоке эти координаты считываем и рисуем на экран. Это должно быть не всегда а при специфичном ключе thread который выдали на вход программы*/

/* 1 вар 4 задание
 Сделать один поток для чтения и отображения кадра. второй поток в котором будем осуществлять отрисовку прямоугольника который мы нашли */
