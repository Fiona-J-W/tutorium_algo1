#include <chrono>
#include <cstdint>
#include <fstream>
#include <forward_list>
#include <iostream>
#include <list>
#include <random>
#include <stdexcept>
#include <vector>

void enforce(bool b, const char* message = "unexpected error") {
	if (!b) {
		throw std::runtime_error{message};
	}
}

std::chrono::nanoseconds time_diff(
		std::chrono::high_resolution_clock::time_point start,
		std::chrono::high_resolution_clock::time_point end)
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}

void print_result(const std::string& what, std::uint64_t result, std::chrono::nanoseconds time) {
	std::cout << what << " calculated " << result << " in " << time.count() << "ns." << std::endl;
}

int main(int argc, char** argv) {
	enforce(argc == 3, "invalid number of arguments");
	std::ofstream vec_times_file{argv[1], std::ios_base::out | std::ios_base::app};
	std::ofstream list_times_file{argv[2], std::ios_base::out | std::ios_base::app};
	auto seed = std::random_device{}();
	
	std::vector<std::uint64_t> vec;
	std::list<std::uint64_t> list;
	std::forward_list<std::uint64_t> flist;
	
	std::mt19937_64 vec_gen{seed};
	std::mt19937_64 list_gen{seed};
	//std::mt19937_64 flist_gen{seed};
	
	for(std::size_t old = 0, i = 1; i < 100000000; old = i, i*=2) {
		for(auto j = old; j < i; ++j) {
			vec.push_back(vec_gen());
			list.push_back(list_gen());
			//flist.push_back(flist_gen());
		}
		
		for(auto k = 0; k < 10; ++k) {
			{
				std::uint64_t xored = 0;
				auto before = std::chrono::high_resolution_clock::now();
				for(const auto& x: vec) {
					xored ^= x;
				}
				auto after = std::chrono::high_resolution_clock::now();
				print_result("vector", xored, time_diff(before, after));
				vec_times_file << i << "  " << time_diff(before, after).count() << '\n';
			}
			
			{
				std::uint64_t xored = 0;
				auto before = std::chrono::high_resolution_clock::now();
				for(const auto& x: list) {
					xored ^= x;
				}
				auto after = std::chrono::high_resolution_clock::now();
				print_result("list  ", xored, time_diff(before, after));
				list_times_file << i << "  " << time_diff(before, after).count() << '\n';
			}
		}
	}
}


