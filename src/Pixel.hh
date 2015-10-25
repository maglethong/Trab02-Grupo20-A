#ifndef __PIXEL_HH__
#define __PIXEL_HH__

#include <string>
#include <sstream>
#include <iostream>

//! Pixel channel type definition
typedef unsigned char p_type;

//! Channel color enumeration
enum Pixel_Color { RED, GREEN, BLUE };

//!
/*
 *
*/
class Pixel
{
public:
	//!
	p_type r, g, b;

private:

public:
	//! [Constructor]
	Pixel();

	//! [Constructor]
	/*
	*
	*/
	Pixel(const p_type r, const p_type g, const p_type b);

	//! [Constructor]
	~Pixel();

	//! Conversion to string
	std::string ToString();

private:
	//! 
	void Init(const p_type r, const p_type g, const p_type b);

public:
	//! [Operator Overload] Copy
	Pixel& operator = (const Pixel& other)
	{
		if (this != &other)
		{
			this->r = other.r;
			this->g = other.g;
			this->b = other.b;
		}
		return *this;
	}

	//! [Operator Overload] ADD Assign
	Pixel& operator += (const Pixel& other)
	{
		this->r = ( (int)this->r + (int)other.r < 255 ) ? this->r + other.r : 255;
		this->g = ( (int)this->g + (int)other.g < 255 ) ? this->g + other.g : 255;
		this->b = ( (int)this->b + (int)other.b < 255 ) ? this->b + other.b : 255;
		return *this;
	}

	//! [Operator Overload] ADD
	friend Pixel operator + (Pixel a, const Pixel& b)
	{
		a += b;
		return a;
	}

	//! [Operator Overload] SUB Assign
	Pixel& operator -= (const Pixel& other)
	{
		this->r = ( this->r >= other.r ) ? this->r - other.r : 0;
		this->g = ( this->g >= other.g ) ? this->g - other.g : 0;
		this->b = ( this->b >= other.b ) ? this->b - other.b : 0;
		return *this;
	}

	//! [Operator Overload] SUB
	friend Pixel operator - (Pixel a, const Pixel& b)
	{
		a -= b;
		return a;
	}

	//! [Operator Overload] MUL Assign
	Pixel& operator *= (const float b)
	{
		this->r = ( (int)this->r *b < 255 ) ? this->r *b : 255;
		this->g = ( (int)this->g *b < 255 ) ? this->g *b : 255;
		this->b = ( (int)this->b *b < 255 ) ? this->b *b : 255;

		return *this;
	}

	//! [Operator Overload] MUL 1
	friend Pixel operator * (Pixel a, const float b)
	{
		a *= b;
		return a;
	}

	//! [Operator Overload] MUL 2
	friend Pixel operator * (const float b, Pixel a)
	{
		a *= b;
		return a;
	}

	//! [Operator Overload] DIV Assign
	Pixel& operator /= (const float b)
	{
		this->r = ( (int)this->r /b < 255 ) ? this->r /b : 255;
		this->g = ( (int)this->g /b < 255 ) ? this->g /b : 255;
		this->b = ( (int)this->b /b < 255 ) ? this->b /b : 255;

		return *this;
	}

	//! [Operator Overload] DIV 1
	friend Pixel operator / (Pixel a, const float b)
	{
		a /= b;
		return a;
	}

	//! [Operator Overload] DIV 2
	friend Pixel operator / (const float b, Pixel a)
	{
		a /= b;
		return a;
	}

	//! [Operator Overload] Comparison
	inline bool operator == (const Pixel& other)
	{
		return this->r == other.r && this->g == other.g && this->b == other.b;
	}
	inline bool operator != (const Pixel& other)
	{
		return !(*this == other);
	}

	//! [Operator Overload] Access 1
	p_type& operator [] (int idx)
	{
		if(idx == 0)
			return this->r;
		if(idx == 1)
			return this->g;
		if(idx == 2)
			return this->b;
		// Not in list? Exception
		throw 1;
	}

	//! [Operator Overload] Access 2
	const
	p_type& operator[] (int idx)
	const
	{
		if(idx == 0)
			return this->r;
		if(idx == 1)
			return this->g;
		if(idx == 2)
			return this->b;
		// Not in list? Exception
		throw 1;
	}

	friend std::ostream &operator<<(std::ostream &out, Pixel obj)
	{
	//	out << obj.r;
	//	out << obj.g;
	//	out << obj.b;
		char c;
		c = (char)obj.r;
		out.write( &c, 1);
		c = (char)obj.g;
		out.write( &c, 1);
		c = (char)obj.b;
		out.write( &c, 1);
		return out;
	}

	friend std::istream &operator>>(std::istream &in, Pixel &obj)
	{
	//	in >> obj.r;
	//	in >> obj.g;
	//	in >> obj.b;
		char c;
		in.read( &c, 1);
		obj.r = (p_type) c;
		in.read( &c, 1);
		obj.g = (p_type) c;
		in.read( &c, 1);
		obj.b = (p_type) c;
		return in;
	}

};

#endif