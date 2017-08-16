#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat image;
    int width,height;
    int nobj=0;
    int pilha[80][2]={0};
    int pilha_pos=0;
    int contPilhaPos=0;
    image = imread("bolhas.png",CV_LOAD_IMAGE_GRAYSCALE);
    if(!image.data)
        cout<<"Nao abriu imagem"<<endl;
    namedWindow("janela1",WINDOW_AUTOSIZE);
    imshow("janela1", image);
    //waitKey();

    width = image.size().width;
    height = image.size().height;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(image.at<uchar>(i,j)==255){
                contPilhaPos=0;
                pilha_pos=0;
                nobj++;
                pilha[pilha_pos][0]=i;
                pilha[pilha_pos][1]=j;
                image.at<uchar>(pilha[pilha_pos][0],(pilha[pilha_pos][1]))=60;
                while(pilha[0][0]!=-1){

                    if(image.at<uchar>(pilha[pilha_pos][0],pilha[pilha_pos][1]-1)==255){
                        image.at<uchar>(pilha[pilha_pos][0],(pilha[pilha_pos][1]-1))=15;
                        //pilha_pos++;
                        contPilhaPos++;
                        pilha[contPilhaPos][0]=pilha[pilha_pos][0];
                        pilha[contPilhaPos][1]=pilha[pilha_pos][1]-1;
                    }
                    if(image.at<uchar>(pilha[pilha_pos][0],(pilha[pilha_pos][1]+1))==255){
                        //mudar cor
                        image.at<uchar>(pilha[pilha_pos][0],(pilha[pilha_pos][1]+1))=15;
                        //pilha_pos++;
                        contPilhaPos++;
                        pilha[contPilhaPos][0]=pilha[pilha_pos][0];
                        pilha[contPilhaPos][1]=pilha[pilha_pos][1]+1;
                    }
                    if(image.at<uchar>(pilha[pilha_pos][0]+1,pilha[pilha_pos][1])==255){

                        //mudar cor
                        image.at<uchar>(pilha[pilha_pos][0]+1,pilha[pilha_pos][1])=15;
                        //pilha_pos++;
                        contPilhaPos++;
                        pilha[contPilhaPos][0]=pilha[pilha_pos][0]+1;
                        pilha[contPilhaPos][1]=pilha[pilha_pos][1];

                    }
                    if(image.at<uchar>(pilha[pilha_pos][0]-1,pilha[pilha_pos][1])==255){
                        //mudar cor
                        image.at<uchar>(pilha[pilha_pos][0]-1,pilha[pilha_pos][1])=15;
                        //pilha_pos++
                        contPilhaPos++;
                        pilha[contPilhaPos][0] = pilha[pilha_pos][0]-1;
                        pilha[contPilhaPos][1] = pilha[pilha_pos][1];
                    }
                    for(int aux=0;aux<contPilhaPos&&aux<79;aux++){
                        if(aux==70){
                            cout<<"Perigo"<<endl;
                        }
                        pilha[aux][0]=pilha[aux+1][0];
                        pilha[aux][1]=pilha[aux+1][1];

                    }
                    for(int aux1=contPilhaPos;aux1<80;aux1++){
                            pilha[aux1][0]=-1;
                            pilha[aux1][1]=-1;

                        }
                    }


                }

            }

        }
    namedWindow("janela",WINDOW_AUTOSIZE);
    imshow("janela", image);
    imwrite("fill.png", image);
    waitKey();
    cout<<"Numero de bolhas: "<<nobj<<endl;
        return 0;
    }
