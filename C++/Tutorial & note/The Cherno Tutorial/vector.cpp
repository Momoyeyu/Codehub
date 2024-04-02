#include <iostream>
#include <vector> // include the vector library to use vectors

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z) // syntax sugar here
	{
		std::cout << "Construct!\n";
	}

	Vertex(const Vertex &vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		// highlight that our vector is copied
		std::cout << "Copied!" << std::endl;
	}
};

std::ostream &operator<<(std::ostream &stream, const Vertex &vertex) // use reference & here to avoid copy
{
	stream << "(" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")";
	return stream;
}

int main()
{
	// create a vector of Vertex objects called vertices
	std::vector<Vertex> vertices; // vertices(2) can explicit the initial size of vector be 2

	// add a new Vertex object with x=1, y=2, and z=3 to the end of the vector
	vertices.push_back({1, 2, 3}); // create one, copy one
	vertices.push_back({4, 5, 6}); // create one, copy two

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	// erase() method delete the data it's parameter point to // we delate Vertex(4, 5, 6) here
	vertices.erase(vertices.begin() + 1);
	// begin() method return the initial location of the vector

	for (Vertex &v : vertices)
		std::cout << v << std::endl;

	std::vector<Vertex> vertices_2;
	vertices_2.reserve(3); // set the size of vector be 3
	vertices_2.emplace_back(1, 2, 3);
	vertices_2.emplace_back(4, 5, 6);
	vertices_2.emplace_back(4, 5, 6);
	// emplace_back() is technically better
	// because it don't need to copy the constructed Vertex like that in push_back() method

	for (Vertex &v : vertices_2)
		std::cout << v << std::endl;

	std::cin.get();
}
