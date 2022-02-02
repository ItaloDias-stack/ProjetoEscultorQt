#include "Sculptor.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

Sculptor::Sculptor(int x, int y, int z) {
    nx = x;
    ny=y;
    nz=z;
    v = new Voxel **[nx];

    // v[i] = new Voxel *[nx];
    for ( int j = 0 ; j <ny; j ++) {
        v[j] = new Voxel *[ny];
        for ( int k = 0 ; k <nz; k ++) {
            v[j][k] = new Voxel[nz];
        }
    }
    for(int i=0;i<nx;i++){
        for ( int j = 0 ; j <ny; j ++) {
            for ( int k = 0 ; k <nz; k ++) {
                v[i][j][k].r = 0.0 ;
                v[i][j][k].g = 0.0 ;
                v[i][j][k].b = 0.0 ;
                v[i][j][k].a = 0.0 ;
                v[i][j][k].isOn = false ;
            }

        }
    }
}

Sculptor::Sculptor(const Sculptor& orig) {
}

Sculptor::~Sculptor() {
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}
void Sculptor::setColor(float _r,float _g,float _b, float _op){
    if(_r<0 || _g<0 || _b<0 || _op<0){
        cout << "Os parâmetros informados são inválidos" << endl;
        exit(1);
    }
    r = _r;
    g = _g;
    b = _b;
    a = _op;

}
void Sculptor::cutVoxel(int x, int y, int z){
    if (x < nx && x >= 0 && y < ny && y>= 0 && z < nz && z >= 0 ) {
        v[x][y][z].isOn = false ;
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    if(x0<0){
        x0=0;
    }
    if(x1 >= nx){
        x1=nx-1;
    }
    if(y0<0){
        y0=0;
    }
    if(y1>=ny){
        y1=ny-1;
    }
    if(z0<0){
        z0=0;
    }
    if(z1>=nz){
        z1=nz-1;
    }
    for(int x=x0;x<=x1;x++){
        for (int y=y0;y<=y1;y++) {
            for ( int z=z0;z<=z1;z++) {
                v[x][y][z].isOn = false;
            }
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    if((xcenter<0)|| (ycenter<0)|| (zcenter<0)|| (xcenter>nx)|| (ycenter>ny)|| (zcenter>nz)|| radius <=0){
        return;
    }
    double raio = (double)radius * (double)radius;
    for ( int x = 0 ; x <nx; x++) {
        for ( int y = 0 ; y <ny; y++) {
            for ( int z = 0 ; z <nz; z++) {
                if( ( (double)(x-xcenter)*(double)(x-xcenter) +
                        (double)(y-ycenter)*(double)(y-ycenter) +
                        (double)(z-zcenter)*(double)(z-zcenter)) < raio){
                    v[x][y][z].r = r;
                    v[x][y][z].g = g;
                    v[x][y][z].b = b;
                    v[x][y][z].a = a;
                    v[x][y][z].isOn = true;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    if((xcenter<0)|| (ycenter<0)|| (zcenter<0)|| (xcenter>nx)|| (ycenter>ny)|| (zcenter>nz)|| radius <=0){
        return;
    }
    double r = (double)radius * (double)radius;
    for ( int x = 0 ; x <nx; x++) {
        for ( int y = 0 ; y <ny; y++) {
            for ( int z = 0 ; z <nz; z++) {
                if( ( (double)(x-xcenter)*(double)(x-xcenter) +
                        (double)(y-ycenter)*(double)(y-ycenter) +
                        (double)(z-zcenter)*(double)(z-zcenter)) < r){
                    v[x][y][z].isOn = false;
                }
            }
        }
    }
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if((xcenter<0)|| (ycenter<0)|| (zcenter<0)|| (xcenter>nx)|| (ycenter>ny)|| (zcenter>nz)|| rx <0 || ry <0 || rz <0){
        return;
    }

    for ( int x = 0 ; x <nx; x++) {
        for ( int y = 0 ; y <ny; y++) {
            for ( int z = 0 ; z <nz; z++) {
                double res = ( (double)(x-xcenter)*(double)(x-xcenter) )/( (double)rx*(double)rx)+
                ( (double)(y-ycenter)*(double)(y-ycenter) )/( (double)ry*(double)ry)+
                ( (double)(z-zcenter)*(double)(z-zcenter) )/( (double)rz*(double)rz);
                //Eu tirei as pontas pq achei que fica melhor, para colocar as pontas coloque "res<=1" no if
                if( res < 1 ){
                    v[x][y][z].r = r;
                    v[x][y][z].g = g;
                    v[x][y][z].b = b;
                    v[x][y][z].a = a;
                    v[x][y][z].isOn = true;
                }
            }
        }
    }
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if((xcenter<0)|| (ycenter<0)|| (zcenter<0)|| (xcenter>nx)|| (ycenter>ny)|| (zcenter>nz)|| rx <0 || ry <0 || rz <0){
        return;
    }

    for ( int x = 0 ; x <nx; x++) {
        for ( int y = 0 ; y <ny; y++) {
            for ( int z = 0 ; z <nz; z++) {
                double res = ( (double)(x-xcenter)*(double)(x-xcenter) )/( (double)rx*(double)rx)+
                ( (double)(y-ycenter)*(double)(y-ycenter) )/( (double)ry*(double)ry)+
                ( (double)(z-zcenter)*(double)(z-zcenter) )/( (double)rz*(double)rz);
                if( res < 1 ){
                    v[x][y][z].isOn = false;
                }
            }
        }
    }
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    if(x0<0){
        x0=0;
    }
    if(x1 >= nx){
        x1=nx-1;
    }
    if(y0<0){
        y0=0;
    }
    if(y1>=ny){
        y1=ny-1;
    }
    if(z0<0){
        z0=0;
    }
    if(z1>=nz){
        z1=nz-1;
    }

    for(int x=x0;x<=x1;x++){
        for (int y=y0;y<=y1;y++) {
            for ( int z=z0;z<=z1;z++) {
                v[x][y][z].isOn = true;
                v[x][y][z].r = r;
                v[x][y][z].g = g;
                v[x][y][z].b = b;
                v[x][y][z].a = a;
            }
        }
    }
}

void Sculptor::putVoxel(int x, int y, int z){
    if(x < nx && x >= 0 && y < ny && y >= 0 && z < nz && z >= 0){
        v[x][y][z].isOn = true ;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::writeOFF(const char* filename){
    int nf, nv, vox = 0 , nfc = 0 , face;
    ofstream arquivo;
    arquivo.open(filename);

    if (!arquivo.is_open()) {
        cout << "Não foi possível abrir o arquivo" << endl;
        exit(1);
    }

    for ( int i = 0 ; i <nx; i ++) {
        for ( int j = 0 ; j <ny; j ++) {
            for ( int k = 0 ; k <nz; k ++) {
                if (v[i][j][k].isOn ) {
                    vox ++;
                }
            }
        }
    }

    nf = 6 * vox;
    nv = 8 * vox;
    arquivo << "OFF \n" ;
    arquivo << nv << "  " << nf << " 0 \n " ;

    double bX, aX, bY, aY, bZ, aZ;

    for ( int k = 0 ; k <nz; k ++) {
        bZ = - 0.5 + k;
        aZ = 0.5 + k;
        for ( int j = 0 ; j <ny; j ++) {
            bY = - 0.5 + j;
            aY = 0.5 + j;
            for ( int i = 0 ; i <nx; i ++) {
                bX = - 0.5 + i;
                aX = 0.5 + i;
                if(i== nz-1 && j==ny-1 && i ==nx-1){
                    if (v[i][j][k].isOn ) {
                        arquivo << bX << "  " << aY << "  " << bZ << endl
                            << bX << "  " << bY << "  " << bZ << endl
                            << aX << "  " << bY << "  " << bZ << endl
                            << aX << "  " << aY << "  " << bZ << endl
                            << bX << "  " << aY << "  " << aZ << endl
                            << bX << "  " << bY << "  " << aZ << endl
                            << aX << "  " << bY << "  " << aZ << endl
                            << aX << "  " << aY << "  " << aZ;
                    }
                }else{
                    if (v[i][j][k].isOn ) {
                        arquivo << bX << "  " << aY << "  " << bZ << endl
                            << bX << "  " << bY << "  " << bZ << endl
                            << aX << "  " << bY << "  " << bZ << endl
                            << aX << "  " << aY << "  " << bZ << endl
                            << bX << "  " << aY << "  " << aZ << endl
                            << bX << "  " << bY << "  " << aZ << endl
                            << aX << "  " << bY << "  " << aZ << endl
                            << aX << "  " << aY << "  " << aZ << endl;
                    }
                }
            }
        }
    }

    for ( int k = 0 ; k <nz; k ++) {
        for ( int j = 0 ; j <ny; j ++) {
            for ( int i = 0 ; i <nx; i ++) {
                if (v[i][j][k].isOn ) {
                    face = nfc * 8 ;
                    arquivo << " 4 " << 0 + face << "  " << 3 + face << "  " << 2 + face << "  " << 1 + face << "  "<< std::fixed << std::setprecision(6) << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << endl
                        << " 4 " << 4 + face << "  " << 5 + face << "  " << 6 + face << "  " << 7 + face << "  "<< std::fixed << std::setprecision(6) << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << endl
                        << " 4 " << 0 + face << "  " << 1 + face << "  " << 5 + face << "  " << 4 + face << "  " << std::fixed << std::setprecision(6)<< v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << endl
                        << " 4 " << 0 + face << "  " << 4 + face << "  " << 7 + face << "  " << 3 + face << "  "<< std::fixed << std::setprecision(6) << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << endl
                        << " 4 " << 3 + face << "  " << 7 + face << "  " << 6 + face << "  " << 2 + face << "  "<< std::fixed << std::setprecision(6) << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << endl
                        << " 4 " << 1 + face << "  " << 2 + face << "  " << 6 + face << "  " << 5 + face << "  "<< std::fixed << std::setprecision(6) << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << endl;
                    nfc ++;
                }
            }
        }

    }
    arquivo.close();
}

