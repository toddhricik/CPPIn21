// point class declaration
class Point
{
	public:
		Point();
		~Point();
		void SetX(int x);
		void SetY(int y);
		int GetX() const;
		int GetY() const;
	private:
		int itsX;
		int itsY;
};
