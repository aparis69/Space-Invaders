#pragma once

class Sprite
{
	protected:
		int imageIndex;  // Indice de l'image dans les assets
		int x, y;  
		int xSize, ySize;
		int vx, vy;
	public:
		// Constructor & Destructor
		Sprite(){}
		~Sprite(){};
		Sprite(int imIndex,int inx,int iny,int invx,int invy);

		// Member functions


		// Getter & Setter
		inline void MoveX(int mv){x+=mv;}
		inline void MoveY(int my){y+=my;}
		inline void SetPosition(int inx,int iny){x=inx;y=iny;}
		inline void EvolueFromVector(){x+=vx;y+=vy;}
		inline int GetX(){return x;}
		inline int GetY(){return y;}
		inline int GetIm(){return imageIndex;}
		inline int& Vx(){return vx;}
		inline int& Vy(){return vy;}
};

