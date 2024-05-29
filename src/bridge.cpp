#include "bridge.h"

using namespace Generate;
using namespace SearchAlgorithms;

SearchAlgorithms::ORDERING_HEURISTIC ordering_heuristic = MINFILL;

// convert adjmat repr to quickbb internal graph struct
std::vector<std::vector<int>> extract_adjmat(rust::Vec<Row> flatmat)	{

	std::vector<std::vector<int>> mat;

	unsigned i = 0;
	for (Row r : flatmat)	{
		std::vector<int> row;
		std::copy(r.row.begin(), r.row.end(), std::back_inserter(row));
		mat.push_back(row);
		i++;
	}

	std::cout << "converted adjmat: " << "\n";
	for (std::vector<int> v : mat)	{
		for (int i : v)	{
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}

	return mat;
}

// run algo
int32_t quickbb(rust::Vec<Row> flatmat, int32_t time_bound, SearchAlgorithms::ORDERING_HEURISTIC ordering_heuristic)	{

	std::cout << "start quickbb subroutine" << "\n";
	std::vector<std::vector<int>> m = extract_adjmat(flatmat);
	std::cout << "adjmat extracted" << "\n";
	Graph g{m};
	std::cout << "init c++ graph" << "\n";
	g.printGraph();

	int32_t bound = g.getNumVertices();
	std::cout << "num vertices: " << bound << "\n";

	Search s;
	bound = s.branchAndBound(g, bound, time_bound);

	std::cout << "out: " << bound << "\n";

	return bound;
}

