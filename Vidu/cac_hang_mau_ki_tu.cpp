#include <conio.h>
#include <stdio.h>
main()
{
	int X,Y;
	fflush(stdin);
	X=10; Y=2;
	printf("NGONNGU");
	 // thiet lap tieu de cho windows
  
    setbkcolor(3) ;  // man nen trang
    cleardevice() ;  // xoa man hinh , cap nhat mau nen moi
  
    setcolor(RED) ;  // mau chu va duong ke mau do
  
    circle(200,250,50) ;  //ve duong trong tam co toa do (200,250) va ban kinh 50px
  
    cout<<"ma mau nen :"<<getbkcolor()<<endl ;  // in ma mau nen ra man hinh
    cout<<"ma mau chu " <<getcolor()<<endl ; // in ma mau chu ra man hinh
  
    delay(50000) ;  // cho chuong trinh ngu trong 50 giay
    return 0 ;
	getch();
}
