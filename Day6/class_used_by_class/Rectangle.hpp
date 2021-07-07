// rectangle declaration
#include "Point.hpp"

class Rectangle
{
	public:
		Rectangle(int top, int left, int bottom, int right);
		~Rectangle();

		int GetTop() const;
		int GetLeft() const;
		int GetBottom() const;
		int GetRight() const;

		Point GetUpperLeft() const;
		Point GetLowerLeft() const;
		Point GetUpperRight() const;
		Point GetLowerRight() const;

		void SetUpperLeft(Point Location);
		void SetLowerLeft(Point Location);
		void SetUpperRight(Point Location);
		void SetLowerRight(Point Location);

		void SetTop(int top);
		void SetLeft(int left);
		void SetBottom(int bottom);
		void SetRight(int right);

		int GetArea() const;

	private:
		Point itsUpperLeft;
		Point itsUpperRight;
		Point itsLowerLeft;
		Point itsLowerRight;
		int itsTop;
		int itsLeft;
		int itsBottom;
		int itsRight;
};
