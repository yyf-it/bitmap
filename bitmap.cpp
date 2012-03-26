#include <iostream>
#include <malloc.h>
#include <stdexcept>
#include <cstdio>
#include <cstring>
#include "bitmap.h"

//just for test branch
/*
 * construction function
*/
BitMap::BitMap(unsigned long length){
	real_buf_size=length;
	int tmp=0;
	if((tmp=length%8)!=0)
		buf_size=length+8-tmp;
	else
		buf_size=length;
	int mem=buf_size/8;
	if((buf=(u_char*)malloc(sizeof(char)*(mem)))==NULL)
		throw std::runtime_error("malloc failed");
	memset(buf,0,mem);


};

BitMap::~BitMap(){
	//std::cout<<"buf:"<<static_cast<const void *>(buf)<<std::endl;
	free(buf);
	//std::cout<<"free the memory okay\n\n";
};


/*
 * private function
*/
/*
 * public function
*/
void BitMap::setBit(unsigned long index,bool isHit){
	if(index>real_buf_size){
		char tp[64];
		sprintf(tp,"%d",index);
		throw std::range_error(std::string("index out of range: ")+tp) ;
	}
	int sub_index=7-index%8;
	u_char *location=buf+index/8;
	if(isHit)
		*location=_set1(*location,sub_index);
	else
		*location=_set0(*location,sub_index);	
};

bool BitMap::getBit(unsigned long index){
	return _getbit(*(buf+index/8),7-index%8);
}

void BitMap::printBitMap(){
	u_char *start=buf;
	while(start<buf+real_buf_size/8){
		_printChar(*start);
		start++;
	}
	if(buf_size>real_buf_size)
		_printChar(*start,8-buf_size+real_buf_size);
	printf("\n");

}


