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
		Sprite(int imIndex, int inx, int iny, int invx, int invy);
        Sprite(int imIndex, int inx, int iny, int invx, int invy, int inXSize, int inYSize);

		// Member functions
        inline void evolueFromVector() { x+=vx; y+=vy; }

		// Getter & Setter
		inline void moveX(int mv) { x+=mv; }
		inline void moveY(int my) { y+=my; }
		inline void setPosition(int inx,int iny) { x=inx; y=iny; }
		inline int getX() const { return x; }
		inline int getY() const { return y; }
		inline int getIm() { return imageIndex; }
		inline int getVx() const { return vx; }
		inline int getVy() const { return vy; }
        inline int getXSize() const { return xSize; }
        inline int getYSize() const { return ySize; }
};

