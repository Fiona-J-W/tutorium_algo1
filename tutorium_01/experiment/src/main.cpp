
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

namespace config {
#ifdef MAX_ELEMENT_COUNT
constexpr std::size_t max_elements = MAX_ELEMENT_COUNT;
#else
constexpr std::size_t max_elements = 10000000;
#endif

#ifdef STEP
constexpr std::size_t step = STEP;
#else
constexpr std::size_t step = 10000;
#endif
}

template<typename Iterator, typename ValueType>
Iterator linear_search(Iterator begin, Iterator end, const ValueType& value) {
	Iterator it = begin;
	while(it != end) {
		if (*it == value) {
			return it;
		}
		++it;
	}
	return end;
}

template<typename Iterator, typename ValueType>
Iterator iterative_binary_search(Iterator begin, Iterator end, const ValueType& value) {
	auto left = begin;
	auto middle = begin;
	auto right = end;
	while(true) {
		middle = left + std::distance(left, right)/2;
		if (*middle < value) {
			left = middle;
		} else if(value < *middle) {
			right = middle;
		} else {
			return middle;
		}
		
		if(left == right){
			break;
		}
		
	}
	return end;
}

template<typename Iterator, typename ValueType>
Iterator binary_search_helper(Iterator begin, Iterator end, const ValueType& value, Iterator not_found) {
	if(begin == end) {
		return not_found;
	}
	auto distance = std::distance(begin, end);
	auto it = begin + distance/2;
	if(value < *it) {
		return binary_search_helper(begin, it, value, not_found);
	} else if (*it < value) {
		return binary_search_helper(it+1, end, value, not_found);
	} else {
		return it;
	}
}
template<typename Iterator, typename ValueType>
Iterator recursive_binary_search(Iterator begin, Iterator end, const ValueType& value) {
	return binary_search_helper(begin, end, value, end);
}

std::chrono::nanoseconds::rep time_diff(
		std::chrono::high_resolution_clock::time_point start,
		std::chrono::high_resolution_clock::time_point end)
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

void enforce(bool b, const char* message = "unexpected error") {
	if (!b) {
		throw std::runtime_error{message};
	}
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <filename>\n";
		return 1;
	}
	std::vector<unsigned> vec;
	std::ofstream times_file{argv[1]};
	std::mt19937_64 gen{std::random_device{}()};
	
	while (vec.size() < config::max_elements) {
		{
			std::uniform_int_distribution<unsigned> dist{1, 4};
			unsigned tmp = (vec.empty() ? 0 : vec.back()) + dist(gen);
			for(std::size_t i = 0; i < config::step; ++i) {
				tmp += dist(gen);
				vec.push_back(tmp);
			}
		}
		
		const auto elements = vec.size();
		std::cout << "n=" << elements << std::endl;
		times_file << elements;
		
		// don't take the middle one, since all binary searches would be constant then:
		const auto value = elements > 2 ? vec.at(1 + elements/2) : vec.front();
		
		// In order to prevent wrong meassurments due to cache-effects always switch between
		// a linear and a binary search.
		//
		// Also: the enforces are needed in order to prevent the compiler from completely
		// optimizing away the searches.
		
		{
			auto before = std::chrono::high_resolution_clock::now();
			auto it = iterative_binary_search(vec.begin(), vec.end(), value);
			auto after = std::chrono::high_resolution_clock::now();
			enforce(it != vec.end(), "iterative binary search");
			times_file << "  " << time_diff(before, after);
		}
		{
			auto before = std::chrono::high_resolution_clock::now();
			auto it = linear_search(vec.begin(), vec.end(), value);
			auto after = std::chrono::high_resolution_clock::now();
			enforce(it != vec.end(), "linear search");
			times_file << "  " << time_diff(before, after);
		}
		{
			auto before = std::chrono::high_resolution_clock::now();
			auto it = recursive_binary_search(vec.begin(), vec.end(), value);
			auto after = std::chrono::high_resolution_clock::now();
			enforce(it != vec.end(), "recursive binary search");
			times_file << "  " << time_diff(before, after);
		}
		{
			auto before = std::chrono::high_resolution_clock::now();
			auto it = std::find(vec.begin(), vec.end(), value);
			auto after = std::chrono::high_resolution_clock::now();
			enforce(it != vec.end(), "std::find");
			times_file << "  " << time_diff(before, after);
		}
		{
			auto before = std::chrono::high_resolution_clock::now();
			auto it = std::lower_bound(vec.begin(), vec.end(), value);
			auto after = std::chrono::high_resolution_clock::now();
			enforce(it != vec.end(), "std::lower_bound");
			times_file << "  " << time_diff(before, after);
		}
		
		times_file << '\n';
	}
}
