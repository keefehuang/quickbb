#pragma once

#include "rust/cxx.h"
#include "tensorcontraction/src/quickbb.rs.h"

#include "Generate.h"
#include "Graph.h"
#include "SearchAlgorithms.h"

std::vector<std::vector<int32_t>> extract_adjmat(rust::Vec<Row> flatmat);
int32_t quickbb(rust::Vec<Row> flatmat, int32_t time_bound, SearchAlgorithms::ORDERING_HEURISTIC ordering_heuristic);

