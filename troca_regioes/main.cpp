#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
void dofor(Mat* image,Mat* subimage,int i,int j){
    int i_aux=0;
    int j_aux=0;


}
int main()
{   Mat image;
    Mat image1;
    Mat sub_image1,sub_image2,sub_image3,sub_image4;
    image=imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);
    if(!image.data)
        cout<<"Nao abriu imagem"<<endl;
    sub_image1=image(Range(0,127),Range(0,127));        //IIQ
    sub_image2=image(Range(128,255),Range(0,127));      //IIIQ
    sub_image3=image(Range(0,127),Range(128,255));      //IQ
    sub_image4=image(Range(128,255),Range(128,255));    //IVQ
//    namedWindow("janela1",WINDOW_AUTOSIZE);
//    imshow("janela1", sub_image1);
//    waitKey();
//    namedWindow("janela2",WINDOW_AUTOSIZE);
//    imshow("janela2", sub_image2);
//    waitKey();
//    namedWindow("janela3",WINDOW_AUTOSIZE);
//    imshow("janela3", sub_image3);
//    waitKey();
//    namedWindow("janela4",WINDOW_AUTOSIZE);
//    imshow("janela4", sub_image4);
//    waitKey();
    int i_aux=0;
    int j_aux=0;
    for(int i=0; i<128;i++){
        j_aux=0;

        for(int j=0;j<128;j++){
            image.at<uchar>(i,j)=sub_image3.at<uchar>(i_aux,j_aux)+0;
            j_aux++;
        }
        i_aux++;
    }

        namedWindow("janela1",WINDOW_AUTOSIZE);
        imshow("janela1", image);
        waitKey();


    return 0;
}
