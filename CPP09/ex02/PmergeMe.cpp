#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vec(), _deq(), _timeVecUs(0), _timeDeqUs(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq), _timeVecUs(other._timeVecUs), _timeDeqUs(other._timeDeqUs) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
		_timeVecUs = other._timeVecUs;
		_timeDeqUs = other._timeDeqUs;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::init(int ac, char **av) {
	_timeDeqUs = 0;
	_timeVecUs = 0;

	_vec.reserve(static_cast<size_t>(ac - 1));

	parseInput(ac, av);
	
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i];
		if (i < _vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	
	sortVector();
	sortDeque();
	
	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i];
		if (i < _vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << _timeVecUs << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << _timeDeqUs << " us" << std::endl;
}

void	PmergeMe::parseInput(int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		if (av[i] == NULL)
			throw std::invalid_argument("Error: Null input");

		size_t len = std::strlen(av[i]);
		if (len == 0)
			continue ;

		for (size_t j = 0; j < len; ++j) {
			if (!std::isdigit(static_cast<unsigned char>(av[i][j])))
				throw std::invalid_argument("Error: Invalid character in input");
		}

		long num = std::atol(av[i]);

		if (num < 0 || num > static_cast<long>(std::numeric_limits<int>::max()))
			throw std::out_of_range("Error: Number out of range");

		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}

	if (_vec.size() < 2 || _deq.size() < 2)
		throw std::invalid_argument("Error: Not enough valid numbers to sort");
}

void	PmergeMe::sortDeque() {
	std::clock_t 	start, end;

	start = std::clock();

	merge_insert_sort(_deq);

	end = std::clock();

	_timeDeqUs = (double)(end - start) * 1000000.0 / (double)CLOCKS_PER_SEC;
}

void	PmergeMe::sortVector() {
	std::clock_t	start, end;

	start = std::clock();

	merge_insert_sort(_vec);

	end = std::clock();
	_timeVecUs = (double)(end - start) * 1000000.0 / (double)CLOCKS_PER_SEC;
}

std::deque<int>	PmergeMe::getDeque() const {
	return _deq;
}

std::vector<int>	PmergeMe::getVector() const {
	return _vec;
}

long long	PmergeMe::getTimeVecUs() const {
	return _timeVecUs;
}

long long	PmergeMe::getTimeDeqUs() const {
	return _timeDeqUs;
}
