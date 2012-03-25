
/*
 *This class implemented BitMap with the memory management using char* type
 *it provide three public functions:
 *
 *getBit(unsigned long index) get the bit value in position index
 *
 *setBit(unsigned long index, bool value) set the bit value in position index
 *
 *printBitMap() print the bits
 *
 */
#ifndef BIT_MAP_H
#define BIT_MAP_H
typedef unsigned char u_char;
class BitMap{
	public:
		bool getBit(unsigned long index);
		void setBit(unsigned long index,bool value);
		void printBitMap();

	/*
	 * the construction function
	 */
	public:
		BitMap(unsigned long length);
		~BitMap();
	
	private:
		unsigned long buf_size;
		unsigned long real_buf_size;
		u_char *buf;
		inline u_char _set1(u_char data,int number){
			return data|0x1<<number;
		}
		inline u_char _set0(u_char data,int number){
			return data&~(0x1<<number);
		}
		inline bool _getbit(u_char data,int number){
			return (data>>number)&0x1;
		}
		inline void _printChar(u_char data){
			char buf[9];
			int i=7;
			while(i>=0){
				buf[i--]=(data%2==0 ? '0' : '1');
				data/=2;
			}   
			buf[8]=0;
			printf("%s",buf);
		}
		inline void _printChar(u_char data,int len){
			//just print the first len bit	
			char buf[9];
			int i=len-1;
			while(i>=0){
				buf[i--]=(data%2==0 ? '0' : '1');
				data/=2;
			}   
			buf[len]=0;
			printf("%s",buf);
		}
};
#endif
