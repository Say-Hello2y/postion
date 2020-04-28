#include <math.h>
#include <stdio.h>
#define pi 3.1415926
#define e  2.7182818
#define e1 0.0819918
//����
struct lng{
double lng_d;
double lng_m;
double lng_s;}lng;
//ά��
struct lat{
double lat_d;
double lat_m;
double lat_s;}lat;
//��ʼ��
void lng_init(){
double lng_d=36;
double lng_m=9;
double lng_s=0;}
//��ʼ��
void lat_init(){
double lat_d=38;
double lat_m=54;
double lat_s=45;}
//��ά��ת��Ϊ����
double rad(struct lat l1)
{return l1.lat_d*pi/180+l1.lat_m*pi/180/60+l1.lat_s*pi/180/3600;}
//������װ��Ϊά��
double dms2m(struct lng ln)
{return ln.lng_d*60+ln.lng_m+ln.lng_s/60;}
//��ά��װ��Ϊ����
double dms2m2(struct lat ll)
{return ll.lat_d*60+ll.lat_m+ll.lat_s/60;}
//λ�ú��������λ��rad�����ȣ��;���
double getpostion(struct lat lat1,struct lng lng1,struct lat lat2,struct lng lng2)
{ double radlat1=rad(lat1);
 //printf("lat1:%f\n",radlat1);
 double radlat2=rad(lat2);
//printf("lat2:%f\n",radlat2);
 double mlng1=dms2m(lng1);
 double mlng2=dms2m(lng2);
 double MP1;
 double MP2;
 double C;
 double S;
 MP1=7915.70447*log10(tan(pi/4+radlat1/2))*pow((1-e1*sin(radlat1))/(1+e1*sin(radlat1)),e/2);
 //printf("MP1:%f\n",MP1);
MP2=7915.70447*log10(tan(pi/4+radlat2/2))*pow((1-e1*sin(radlat2))/(1+e1*sin(radlat2)),e/2);
//printf("MP2:%f\n",MP2);
C=atan((mlng2-mlng1)/(MP2-MP1));
printf("rad:%f\n",C);
S=abs((dms2m2(lat2)-dms2m2(lat1))/cos(C));
printf("distance:%f����\n",S);
return 0;
}
/*************��ȡ����ƫ��*************************///////////////////////////////
double geterror(struct lat lat1,struct lng lng1,struct lat lat2,struct lng lng2,struct lat lat3,struct lng lng3)
{
double radlat1=rad(lat1);
 //printf("lat1:%f\n",radlat1);
 double radlat2=rad(lat2);
//printf("lat2:%f\n",radlat2);
 double radlat3=rad(lat3);
 double mlng1=dms2m(lng1);
// printf("%f\n",mlng1);
 double mlng2=dms2m(lng2);
double mlng3=dms2m(lng3);
 double MP1;
 double MP2;
 double MP3;
 double C;
 double Sap;
 double P;
 double D;
 MP1=7915.70447*log10(tan(pi/4+radlat1/2))*pow((1-e1*sin(radlat1))/(1+e1*sin(radlat1)),e/2);
 //printf("MP1:%f\n",MP1);
MP2=7915.70447*log10(tan(pi/4+radlat2/2))*pow((1-e1*sin(radlat2))/(1+e1*sin(radlat2)),e/2);
//printf("MP2:%f\n",MP2);
MP3=7915.70447*log10(tan(pi/4+radlat3/2))*pow((1-e1*sin(radlat3))/(1+e1*sin(radlat3)),e/2);
//printf("MP3:%f\n",MP3);
C=atan((mlng2-mlng1)/(MP2-MP1));
//printf("rad:%f\n",C);
 //printf("MP1:%f\n",MP1);
P=atan((mlng3-mlng1)/(MP3-MP1));
//printf("rad:%f\n",P);
Sap=abs((dms2m2(lat3)-dms2m2(lat1))/cos(P));
//printf("distance ap:%f\n",Sap);
D=Sap*sin(C-P);
printf("error is :%f����\n",D);
return 0;
}
//������
void main()
{struct lat lat_dalian={38,54,45};//����ά��
struct lat lat_shanghai={31,11,0};//�Ϻ�
struct lng lng_dalian={121,36,9};//����
struct lng lng_shanghai={121,29,0};//�Ϻ�
struct lat lat_yantai={37,52,0};//��̨
struct lng lng_yantai={121,39,0};//��̨
printf("dalian to shanghai:\n");
getpostion(lat_dalian,lng_dalian,lat_shanghai,lng_shanghai);
printf("dalian to yantai:\n");
getpostion(lat_dalian,lng_dalian,lat_yantai,lng_yantai);
printf("����ƫ��:\n");
geterror(lat_dalian,lng_dalian,lat_shanghai,lng_shanghai,lat_yantai,lng_yantai);
}