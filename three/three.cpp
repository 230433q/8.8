#include <iostream>
#include<string.h>
int main() {
	char buf[8];
	float f1 = 3.16f, f2 = 2.34f;
	memcpy(buf, &f1, sizeof f1);
	memcpy(buf, &f2, sizeof f2);
	//通过memcpy将f1，f2的值存入buf数组中//
	float g1, g2;
	memcpy(&g1, buf, sizeof g1);
	memcpy(&g2, buf+4, sizeof g2);
	//通过memcpy将buf数组中的值读取到g1，g2中//
	printf("%f%f", g1, g2);
	typedef union {
		char baf[8];
		float f[2];
	} acg ; 
	//通过联合体共享内存//
	 acg pack;
	pack.f[0] = 3.16f;
	pack.f[1] = 2.34f;
	//此时acg.c中及为所要求的float读入char数组的值//
	float a1 = pack.f[0];
	float a2 = pack.f[1];
	//将联合体中的值读取到a1和a2中//
	printf("%f%f", a1, a2);
	char bcf[8];
	float b1 = 3.14f, b2 = 2.56f;
	unsigned char * p = (unsigned char *)&b1;
	for (int i = 0; i < 4; ++i) bcf[i] = p[i];
	p = (unsigned char*)&b2;
	for (int i = 0; i < 4; ++i) bcf[i + 4] = p[i];
	//将float手动接入char数组中//
	unsigned char tmp[4];
	for (int i = 0; i < 4; ++i) tmp[i] = bcf[i];
	float c1 = *(float*)tmp;
	for (int i = 0; i < 4; ++i) tmp[i] = bcf[i+4];
	float c2 = *(float*)tmp;
	printf("%f%f", c1, c2);
	return 0;
}