#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <forward_list>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <stdexcept>
#include <vector>

void enforce(bool b, const char* message = "unexpected error") {
	if (!b) {
		throw std::runtime_error{message};
	}
}

auto time_diff(
		std::chrono::high_resolution_clock::time_point start,
		std::chrono::high_resolution_clock::time_point end)
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

std::vector<std::uint64_t> make_random_vector(std::size_t elements) {
	static thread_local std::mt19937_64 gen{std::random_device{}()};
	std::vector<std::uint64_t> returnvec(elements);
	std::iota(returnvec.begin(), returnvec.end(), 0);
	std::shuffle(returnvec.begin(), returnvec.end(), gen);
	return returnvec;
}

template<typename Container>
void insert(Container& c, typename Container::value_type v) {
	auto it = c.begin();
	auto end = c.end();
	while(it != end && *it < v) {
		++it;
	}
	c.insert(it, v);
}

template<typename Container>
void remove(Container& c, typename Container::value_type v) {
	c.erase(std::find(c.begin(), c.end(), v));
}

int main(int argc, char** argv) {
	enforce(argc == 3, "invalid number of arguments");
	std::ofstream vec_times_file{argv[1], std::ios_base::out | std::ios_base::app};
	std::ofstream list_times_file{argv[2], std::ios_base::out | std::ios_base::app};
	
	std::vector<std::uint64_t> vec;
	std::list<std::uint64_t> list;
	std::forward_list<std::uint64_t> flist;
	
	for (std::size_t i = 1; i < 100000; i *= 2) {
		std::cout << i << std::endl;
		for(auto j = 0; j < 1; ++j) {
			auto insertion = make_random_vector(i);
			auto deletion = make_random_vector(i);
			{
				auto before = std::chrono::high_resolution_clock::now();
				{
					std::vector<std::uint64_t> vec;
					for (auto val: insertion) {
						insert(vec, val);
					}
					for (auto val: deletion) {
						remove(vec, val);
					}
				}
				auto after = std::chrono::high_resolution_clock::now();
				auto time = time_diff(before, after);
				std::cout << "vector: " << time << "ns\n";
				vec_times_file << i << "  " << time << '\n';
			}
			{
				auto before = std::chrono::high_resolution_clock::now();
				{
					std::list<std::uint64_t> vec;
					for (auto val: insertion) {
						insert(vec, val);
					}
					for (auto val: deletion) {
						remove(vec, val);
					}
				}
				auto after = std::chrono::high_resolution_clock::now();
				auto time = time_diff(before, after);
				std::cout << "list:   " << time << "ns\n";
				list_times_file << i << "  " << time << '\n';
			}
		}
	}
}


