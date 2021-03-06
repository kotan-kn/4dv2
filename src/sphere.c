//
//  poly.c
//  P4
//
//  Created by Kota Nakano on 17/11/13.
//  Copyright (c) 2013 Kota Nakano. All rights reserved.
//
#include<math.h>
#include<stdio.h>
#include"gl.h"
#include"vector.h"
#include"sphere.h"
#define r 1.0f
int sprite_sphere_init(sprite_t*self,int dump)
{
	const float g=2.0f/(1.0f+(sqrtf(5.0f)));
	vec4_t	vertices[]=
	{
		{ 0*r, 1*r,-g*r, 1},
		{ 0*r, 1*r, g*r, 1},
		{ 0*r,-1*r,-g*r, 1},
		{ 0*r,-1*r, g*r, 1},
		
		{-g*r, 0*r, 1*r, 1},
		{ g*r, 0*r, 1*r, 1},
		{-g*r, 0*r,-1*r, 1},
		{ g*r, 0*r,-1*r, 1},
		
		{ 1*r,-g*r, 0*r, 1},
		{ 1*r, g*r, 0*r, 1},
		{-1*r,-g*r, 0*r, 1},
		{-1*r, g*r, 0*r, 1},
	};
	vec4_t	diffuse[]=
	{
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
	};
	vec4_t	ambient[]=
	{
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
	};
	vertex_t v[]=
	{
		{vertices[0x1],{0},ambient[0x1],diffuse[0x1]},
		{vertices[0xb],{0},ambient[0xb],diffuse[0xb]},
		{vertices[0x0],{0},ambient[0x0],diffuse[0x0]},
		
		{vertices[0x2],{0},ambient[0x2],diffuse[0x2]},
		{vertices[0xa],{0},ambient[0xa],diffuse[0xa]},
		{vertices[0x3],{0},ambient[0x3],diffuse[0x3]},
		
		{vertices[0x0],{0},ambient[0x0],diffuse[0x0]},
		{vertices[0xb],{0},ambient[0x0],diffuse[0xb]},
		{vertices[0x6],{0},ambient[0x0],diffuse[0x6]},
		
		{vertices[0x2],{0},ambient[0x2],diffuse[0x2]},
		{vertices[0x6],{0},ambient[0x6],diffuse[0x6]},
		{vertices[0xa],{0},ambient[0xa],diffuse[0xa]},
		
		{vertices[0x7],{0},ambient[0x7],diffuse[0x7]},
		{vertices[0x0],{0},ambient[0x0],diffuse[0x0]},
		{vertices[0x6],{0},ambient[0x6],diffuse[0x6]},
		
		{vertices[0x6],{0},ambient[0x6],diffuse[0x6]},
		{vertices[0x2],{0},ambient[0x2],diffuse[0x2]},
		{vertices[0x7],{0},ambient[0x7],diffuse[0x7]},
		
		{vertices[0x0],{0},ambient[0x0],diffuse[0x0]},
		{vertices[0x7],{0},ambient[0x7],diffuse[0x7]},
		{vertices[0x9],{0},ambient[0x9],diffuse[0x9]},
		
		{vertices[0x2],{0},ambient[0x2],diffuse[0x2]},
		{vertices[0x8],{0},ambient[0x8],diffuse[0x8]},
		{vertices[0x7],{0},ambient[0x7],diffuse[0x7]},
		
		{vertices[0x0],{0},ambient[0x0],diffuse[0x0]},
		{vertices[0x9],{0},ambient[0x9],diffuse[0x9]},
		{vertices[0x1],{0},ambient[0x1],diffuse[0x1]},
		
		{vertices[0x3],{0},ambient[0x3],diffuse[0x3]},
		{vertices[0x8],{0},ambient[0x8],diffuse[0x8]},
		{vertices[0x2],{0},ambient[0x2],diffuse[0x2]},
		
		{vertices[0x1],{0},ambient[0x1],diffuse[0x1]},
		{vertices[0x4],{0},ambient[0x4],diffuse[0x4]},
		{vertices[0xb],{0},ambient[0xb],diffuse[0xb]},
		
		{vertices[0x1],{0},ambient[0x1],diffuse[0x1]},
		{vertices[0x9],{0},ambient[0x9],diffuse[0x9]},
		{vertices[0x5],{0},ambient[0x5],diffuse[0x5]},
	
		{vertices[0xb],{0},ambient[0xb],diffuse[0xb]},
		{vertices[0x4],{0},ambient[0x4],diffuse[0x4]},
		{vertices[0xa],{0},ambient[0xa],diffuse[0xa]},
		
		{vertices[0x8],{0},ambient[0x8],diffuse[0x8]},
		{vertices[0x5],{0},ambient[0x5],diffuse[0x5]},
		{vertices[0x9],{0},ambient[0x9],diffuse[0x9]},
		
		{vertices[0x4],{0},ambient[0x4],diffuse[0x4]},
		{vertices[0x3],{0},ambient[0x3],diffuse[0x3]},
		{vertices[0xa],{0},ambient[0xa],diffuse[0xa]},
		
		{vertices[0x5],{0},ambient[0x5],diffuse[0x5]},
		{vertices[0x8],{0},ambient[0x8],diffuse[0x8]},
		{vertices[0x3],{0},ambient[0x3],diffuse[0x3]},
		
		{vertices[0xa],{0},ambient[0xa],diffuse[0xa]},
		{vertices[0x6],{0},ambient[0x6],diffuse[0x6]},
		{vertices[0xb],{0},ambient[0xb],diffuse[0xb]},
		
		{vertices[0x9],{0},ambient[0x9],diffuse[0x9]},
		{vertices[0x7],{0},ambient[0x7],diffuse[0x7]},
		{vertices[0x8],{0},ambient[0x8],diffuse[0x8]},
		
		{vertices[0x4],{0},ambient[0x4],diffuse[0x4]},
		{vertices[0x1],{0},ambient[0x1],diffuse[0x1]},
		{vertices[0x5],{0},ambient[0x5],diffuse[0x5]},
		
		{vertices[0x5],{0},ambient[0x5],diffuse[0x5]},
		{vertices[0x3],{0},ambient[0x3],diffuse[0x3]},
		{vertices[0x4],{0},ambient[0x4],diffuse[0x4]},
		
	};
	
	unsigned char i[]=
	{
		0x00,0x01,0x02,	0x03,0x04,0x05,
		0x06,0x07,0x08,	0x09,0x0a,0x0b,
		0x0c,0x0d,0x0e,	0x0f,0x10,0x11,
		0x12,0x13,0x14,	0x15,0x16,0x17,
		0x18,0x19,0x1a,	0x1b,0x1c,0x1d,
		0x1e,0x1f,0x20,	0x21,0x22,0x23,
		0x24,0x25,0x26,	0x27,0x28,0x29,
		0x2a,0x2b,0x2c,	0x2d,0x2e,0x2f,
		0x30,0x31,0x32,	0x33,0x34,0x35,
		0x36,0x37,0x38,	0x39,0x3a,0x3b,
	};
	
	//vertex_auto_normal_triangle(v,sizeof(i)/sizeof(*i));
	vertex_auto_normal_sphere(v,sizeof(i)/sizeof(*i));
	
	sprite_init(self,0);
	
	glBindBuffer(GL_ARRAY_BUFFER,self->buffer[0]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v),v,GL_DYNAMIC_DRAW);
	
	self->vertex.stride=sizeof(vertex_t),self->vertex.offset=sizeof(vec4_t)*0x0;
	self->normal.stride=sizeof(vertex_t),self->normal.offset=sizeof(vec4_t)*0x1;
	self->ambient.stride=sizeof(vertex_t),self->ambient.offset=sizeof(vec4_t)*0x2;
	self->diffuse.stride=sizeof(vertex_t),self->diffuse.offset=sizeof(vec4_t)*0x3;
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,self->buffer[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(i),i,GL_STATIC_DRAW);
	
	self->length=sizeof(i)/sizeof(unsigned char);
	self->stride=GL_UNSIGNED_BYTE;

	return 0;
}
