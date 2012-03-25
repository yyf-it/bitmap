#include <iostream>
#include <malloc.h>
#include <stdexcept>
#include <ctime>
#include <bitset>
#include <sys/timeb.h>
#include "bitmap.h"

long getSystemTime(){
	timeb t;
	ftime(&t);
	return 1000*t.time+t.millitm;
};


//#define TEST
int main(int argc, char **argv){
	#ifdef TEST	
	BitMap bi(11);
	std::cout<<"initailize the bitmap"<<std::endl;
	bi.printBitMap();

	std::cout<<"set the first bit to 1"<<std::endl;	
	bi.setBit(1,true);
	bi.printBitMap();

	std::cout<<"set the twenty bit to 1"<<std::endl;
	bi.setBit(2,true);
	bi.printBitMap();

	bool tp=bi.getBit(2);
	std::cout<<"is the twenty bit 1? "<< tp<<std::endl;
	#endif	

	const int init_length=10000000;
	const int am_factor=1;
	std::cout<<"bit_length:"<<init_length<<std::endl;
	std::cout<<"amplification factor:"<<am_factor<<std::endl;

	time_t t1;
	time(&t1);
	long tb1=getSystemTime();
	std::cout<<"time: "<<ctime(&t1)<<std::endl;
	
	std::cout<<"our BitMap to execut ... "<<std::endl;
	BitMap bit(init_length);
	for(int t=0;t<am_factor;t++){
		for(int i=0;i<init_length;i++)
			bit.setBit(i,true);
	}
	
	time_t t2;
	time(&t2);
	long tb2=getSystemTime();
	std::cout<<"time: "<<ctime(&t2)<<std::endl;
	
	std::cout<<"using c++ bitset to execut ... "<<std::endl;
	std::bitset<init_length> bvec;
	for(int t=0;t<am_factor;t++){
		for(int i=0;i<init_length;i++)
			bvec.set(i);
	}
	
	time_t t3;
	time(&t3);
	long tb3=getSystemTime();
	std::cout<<"time: "<<ctime(&t3)<<std::endl;
	std::cout<<"tb1="<<tb1<<"\ttb2="<<tb2<<"\ttb3="<<tb3<<std::endl;
	std::cout<<"BitMap elapsed: "<<tb2-tb1<<"ms"<<std::endl;
	std::cout<<"bitset elapsed: "<<tb3-tb2<<"ms"<<std::endl;

}
