#pragma once
#include <iostream>

using namespace std;
//ნოდი
enum ColorType { RED, BLACK };
class RedBlackTreeNode
{
	friend class RedBlackTree;
	/*
	* მიუხედავად იმისია რომ ხე მეგობარი კლასისა არ ვიცი რატომ despite the fact that tree was friend class
	* i couldnt really access iys functions because of visual studio was bugging out so basically half of the 
	* code is written with getter setters, after restarting the visual studio it was fixed
	* so yeaa
	*/
private:
	//elements of node
	int value;
	ColorType Color;
	RedBlackTreeNode* parent;
	RedBlackTreeNode* left;
	RedBlackTreeNode* right;
public:
	//default Constructor
	RedBlackTreeNode()
		:value(0), Color(RED), left(NULL), right(NULL), parent(NULL)
	{}
	//Constructor
	RedBlackTreeNode(int inValue, ColorType color, RedBlackTreeNode* inLeft
		= NULL, RedBlackTreeNode* inRight = NULL, RedBlackTreeNode* inParent = NULL)
		:value(inValue), left(inLeft), right(inRight), parent(inParent),
		Color(color)
	{}
	//Getter Function
	inline int getValue() const
	{
		return value;
	}
	inline ColorType getColor() const
	{
		return Color;
	}
	inline RedBlackTreeNode* getpar() {
		return parent;
	}
	inline RedBlackTreeNode* getR() {
		return right;
	}
	inline RedBlackTreeNode* getL() {
		return left;
	}
	//Setter Function
	inline void setValue(int newVal)
	{
		value = newVal;
	}
	inline void setColor(ColorType color)
	{
		Color = color;
	}
	inline void setpar(RedBlackTreeNode* k) {
		parent = k;
	}
	inline void setR(RedBlackTreeNode* k) {
		right = k;
	}
	inline void setL(RedBlackTreeNode* k) {
		left = k;
	}
};
