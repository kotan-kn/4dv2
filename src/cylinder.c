//
//  cylinder.c
//  P4
//
//  Created by Kota Nakano on 17/11/13.
//  Copyright (c) 2013 Kota Nakano. All rights reserved.
//
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"gl.h"
#include"vector.h"
#include"cylinder.h"
int sprite_cylinder_init_x(sprite_t*self,float v,float d,float r,int division,int dump)
{

	sprite_init(self,0);
	
	glBindBuffer(GL_ARRAY_BUFFER,self->buffer[0]);
	self->vertex.stride=sizeof(vertex_t),self->vertex.offset=sizeof(vec4_t)*0x0;
	self->normal.stride=sizeof(vertex_t),self->normal.offset=sizeof(vec4_t)*0x1;
	self->ambient.stride=sizeof(vertex_t),self->ambient.offset=sizeof(vec4_t)*0x2;
	self->diffuse.stride=sizeof(vertex_t),self->diffuse.offset=sizeof(vec4_t)*0x3;
	{
		register vertex_t*V=(vertex_t*)malloc(sizeof(vertex_t)*(4*division+2));
		register unsigned int k,K;
		vec4_t	ambient=vec4_pack(0.5f,0.5f,0.5f,0.5f);
		vec4_t	diffuse=vec4_pack(0.5f,0.5f,0.5f,0.0f);	
		for(k=0,K=division;k<K;++k)
		{
			register const float t=M_PI*k/(0.5f*K);
			register const float c=r*cosf(t);
			register const float s=r*sinf(t);

			V[k+0*division].vertex=vec4_pack(d,c,s,1);
			V[k+0*division].normal=vec4_pack(v<d?1:-1,0,0,1);
			V[k+0*division].ambient=ambient;
			V[k+0*division].diffuse=diffuse;

			V[k+1*division].vertex=vec4_pack(d,c,s,1);
			V[k+1*division].normal=vec4_pack(0,c,s,1);
			V[k+1*division].ambient=ambient;
			V[k+1*division].diffuse=diffuse;

			V[k+2*division].vertex=vec4_pack(v,c,s,1);
			V[k+2*division].normal=vec4_pack(0,c,s,1);
			V[k+2*division].ambient=ambient;
			V[k+2*division].diffuse=diffuse;

			V[k+3*division].vertex=vec4_pack(v,c,s,1);
			V[k+3*division].normal=vec4_pack(v<d?-1:1,0,0,1);
			V[k+3*division].ambient=ambient;
			V[k+3*division].diffuse=diffuse;
		}
		{
			V[division*4+0].vertex=vec4_pack(d,0,0,1);
			V[division*4+0].normal=vec4_pack(v<d?1:-1,0,0,1);
			V[division*4+0].ambient=ambient;
			V[division*4+0].diffuse=diffuse;
		
			V[division*4+1].vertex=vec4_pack(v,0,0,1);
			V[division*4+1].normal=vec4_pack(v<d?-1:1,0,0,1);
			V[division*4+1].ambient=ambient;
			V[division*4+1].diffuse=diffuse;
		}
		glBufferData(GL_ARRAY_BUFFER,sizeof(vertex_t)*(4*division+2),V,GL_DYNAMIC_DRAW);
		free(V);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,self->buffer[1]);
	self->stride=GL_UNSIGNED_INT;
	{
		register unsigned int*i=(unsigned int*)malloc(sizeof(unsigned int)*(self->length=division*3*4));
		register unsigned int k,K;
		for(k=0,K=division;k<K;++k)
		{
			i[k*12+0x0]=4*division+0;
			i[k*12+0x1]=(k+0)%division+division*0;
			i[k*12+0x2]=(k+1)%division+division*0;

			i[k*12+0x3]=(k+0)%division+division*1;
			i[k*12+0x4]=(k+0)%division+division*2;
			i[k*12+0x5]=(k+1)%division+division*1;

			i[k*12+0x6]=(k+1)%division+division*2;
			i[k*12+0x7]=(k+1)%division+division*1;
			i[k*12+0x8]=(k+0)%division+division*2;

			i[k*12+0x9]=4*division+1;
			i[k*12+0xa]=(k+1)%division+division*3;
			i[k*12+0xb]=(k+0)%division+division*3;
		}
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*(self->length),i,GL_STATIC_DRAW);
		free(i);
	}
	return 0;
}
int sprite_cylinder_init_y(sprite_t*self,register float v,register float d,register float r,int division,int dump)
{

	sprite_init(self,0);
	
	glBindBuffer(GL_ARRAY_BUFFER,self->buffer[0]);
	self->vertex.stride=sizeof(vertex_t),self->vertex.offset=sizeof(vec4_t)*0x0;
	self->normal.stride=sizeof(vertex_t),self->normal.offset=sizeof(vec4_t)*0x1;
	self->ambient.stride=sizeof(vertex_t),self->ambient.offset=sizeof(vec4_t)*0x2;
	self->diffuse.stride=sizeof(vertex_t),self->diffuse.offset=sizeof(vec4_t)*0x3;
	{
		register vertex_t*V=(vertex_t*)malloc(sizeof(vertex_t)*(4*division+2));
		register unsigned int k,K;
		vec4_t	ambient=vec4_pack(0.5,0.5,0.5,0.5);
		vec4_t	diffuse=vec4_pack(0.5,0.5,0.5,0.0);
		for(k=0,K=division;k<K;++k)
		{
			register const float t=M_PI*k/(0.5f*K);
			register const float c=r*cosf(t);
			register const float s=r*sinf(t);

			V[k+0*division].vertex=vec4_pack(c,d,s,1);
			V[k+0*division].normal=vec4_pack(0,v<d?1:-1,0,1);
			V[k+0*division].ambient=ambient;
			V[k+0*division].diffuse=diffuse;

			V[k+1*division].vertex=vec4_pack(c,d,s,1);
			V[k+1*division].normal=vec4_pack(c,0,s,1);
			V[k+1*division].ambient=ambient;
			V[k+1*division].diffuse=diffuse;

			V[k+2*division].vertex=vec4_pack(c,v,s,1);
			V[k+2*division].normal=vec4_pack(c,0,s,1);
			V[k+2*division].ambient=ambient;
			V[k+2*division].diffuse=diffuse;

			V[k+3*division].vertex=vec4_pack(c,v,s,1);
			V[k+3*division].normal=vec4_pack(0,v<d?-1:1,0,1);
			V[k+3*division].ambient=ambient;
			V[k+3*division].diffuse=diffuse;
		}
		{
			V[division*4+0].vertex=vec4_pack(0,d,0,1);
			V[division*4+0].normal=vec4_pack(0,v<d?1:-1,0,1);
			V[division*4+0].ambient=ambient;
			V[division*4+0].diffuse=diffuse;
		
			V[division*4+1].vertex=vec4_pack(0,v,0,1);
			V[division*4+1].normal=vec4_pack(0,v<d?-1:1,0,1);
			V[division*4+1].ambient=ambient;
			V[division*4+1].diffuse=diffuse;
		}
		glBufferData(GL_ARRAY_BUFFER,sizeof(vertex_t)*(4*division+2),V,GL_DYNAMIC_DRAW);
		free(V);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,self->buffer[1]);
	self->stride=GL_UNSIGNED_INT;
	{
		register unsigned int*i=(unsigned int*)malloc(sizeof(unsigned int)*(self->length=division*3*4));
		register unsigned int k,K;
		for(k=0,K=division;k<K;++k)
		{
			i[k*12+0x0]=4*division+0;
			i[k*12+0x1]=(k+0)%division+division*0;
			i[k*12+0x2]=(k+1)%division+division*0;

			i[k*12+0x3]=(k+0)%division+division*1;
			i[k*12+0x4]=(k+0)%division+division*2;
			i[k*12+0x5]=(k+1)%division+division*1;

			i[k*12+0x6]=(k+1)%division+division*2;
			i[k*12+0x7]=(k+1)%division+division*1;
			i[k*12+0x8]=(k+0)%division+division*2;

			i[k*12+0x9]=4*division+1;
			i[k*12+0xa]=(k+1)%division+division*3;
			i[k*12+0xb]=(k+0)%division+division*3;
		}
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*(self->length),i,GL_STATIC_DRAW);
		free(i);
	}
	return 0;
}
int sprite_cylinder_init_z(sprite_t*self,register float v,register float d,register float r,int division,int dump)
{

	sprite_init(self,0);
	
	glBindBuffer(GL_ARRAY_BUFFER,self->buffer[0]);
	self->vertex.stride=sizeof(vertex_t),self->vertex.offset=sizeof(vec4_t)*0x0;
	self->normal.stride=sizeof(vertex_t),self->normal.offset=sizeof(vec4_t)*0x1;
	self->ambient.stride=sizeof(vertex_t),self->ambient.offset=sizeof(vec4_t)*0x2;
	self->diffuse.stride=sizeof(vertex_t),self->diffuse.offset=sizeof(vec4_t)*0x3;
	{
		register vertex_t*V=(vertex_t*)malloc(sizeof(vertex_t)*(4*division+2));
		register unsigned int k,K;
		vec4_t	ambient=vec4_pack(1.0,1.0,1.0,1.0);
		vec4_t	diffuse=vec4_pack(1.0,1.0,1.0,0.0);
		for(k=0,K=division;k<K;++k)
		{
			register const float t=M_PI*k/(0.5f*K);
			register const float c=r*cosf(t);
			register const float s=r*sinf(t);

			V[k+0*division].vertex=vec4_pack(c,s,d,1);
			V[k+0*division].normal=vec4_pack(0,0,v<d?1:-1,1);
			V[k+0*division].ambient=ambient;
			V[k+0*division].diffuse=diffuse;

			V[k+1*division].vertex=vec4_pack(c,s,d,1);
			V[k+1*division].normal=vec4_pack(c,s,0,1);
			V[k+1*division].ambient=ambient;
			V[k+1*division].diffuse=diffuse;

			V[k+2*division].vertex=vec4_pack(c,s,v,1);
			V[k+2*division].normal=vec4_pack(c,s,0,1);
			V[k+2*division].ambient=ambient;
			V[k+2*division].diffuse=diffuse;

			V[k+3*division].vertex=vec4_pack(c,s,v,1);
			V[k+3*division].normal=vec4_pack(0,0,v<d?-1:1,1);
			V[k+3*division].ambient=ambient;
			V[k+3*division].diffuse=diffuse;
		}
		{
			V[division*4+0].vertex=vec4_pack(0,0,d,1);
			V[division*4+0].normal=vec4_pack(0,0,v<d?1:-1,1);
			V[division*4+0].ambient=ambient;
			V[division*4+0].diffuse=diffuse;
		
			V[division*4+1].vertex=vec4_pack(0,0,v,1);
			V[division*4+1].normal=vec4_pack(0,0,v<d?-1:1,1);
			V[division*4+1].ambient=ambient;
			V[division*4+1].diffuse=diffuse;
		}
		glBufferData(GL_ARRAY_BUFFER,sizeof(vertex_t)*(4*division+2),V,GL_DYNAMIC_DRAW);
		free(V);	
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,self->buffer[1]);
	self->stride=GL_UNSIGNED_INT;
	{
		register unsigned int*i=(unsigned int*)malloc(sizeof(unsigned int)*(self->length=division*3*4));
		register unsigned int k,K;
		for(k=0,K=division;k<K;++k)
		{
			i[k*12+0x0]=4*division+0;
			i[k*12+0x1]=(k+0)%division+division*0;
			i[k*12+0x2]=(k+1)%division+division*0;

			i[k*12+0x3]=(k+0)%division+division*1;
			i[k*12+0x4]=(k+0)%division+division*2;
			i[k*12+0x5]=(k+1)%division+division*1;

			i[k*12+0x6]=(k+1)%division+division*2;
			i[k*12+0x7]=(k+1)%division+division*1;
			i[k*12+0x8]=(k+0)%division+division*2;

			i[k*12+0x9]=4*division+1;
			i[k*12+0xa]=(k+1)%division+division*3;
			i[k*12+0xb]=(k+0)%division+division*3;
		}
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*(self->length),i,GL_STATIC_DRAW);
		free(i);
	}
	return 0;
}
