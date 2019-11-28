#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Vector.h>

namespace External
{
	struct Triangle
	{
	public:
		Vector3 point[3];

	};

	struct TriangleBry
	{
	public:
		Vector3 v[3];
		Vector3 Barycenter;
	};

}

#endif // !TRIANGLE_H

