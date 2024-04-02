#include <iostream>

struct Vector2
{
	float x, y;
};

struct Vector4
{
	union // nameless union, let struct_1 and struct_2 share the same memery
	{
		struct // nameless struct_1
		{
			float w, x, y, z;
		};
		struct // nameless struct_2
		{
			Vector2 a, b;
		};
	};
};

void PrintVector2(const Vector2 &vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
	PrintVector2(vector.a);
	PrintVector2(vector.b);
	vector.z = 100.0f;
	std::cout << "---------------\n";
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cin.get();
}
