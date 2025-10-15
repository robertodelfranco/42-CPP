#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <vector>
#include <deque>
#include <sys/time.h>

#define RED "\033[1;91m"
#define RESET "\033[0m"

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		long long			_timeVecUs;
		long long			_timeDeqUs;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void		sortDeque();
		void		sortVector();
		void		init(int ac, char **av);
		void		parseInput(int ac, char **av);

		std::deque<int>		getDeque() const;
		std::vector<int>	getVector() const;

		long long		getTimeVecUs() const;
		long long		getTimeDeqUs() const;

		static void compute_jacobsthal_sequence(std::vector<size_t> &out, size_t limit) {
			out.clear();
			out.push_back(0);
			if (limit == 0) return;
			out.push_back(1);
			while (out.back() < limit) {
				size_t s = out.size();
				unsigned long long next = (unsigned long long)out[s - 1] + 2ull * (unsigned long long)out[s - 2];
				out.push_back(static_cast<size_t>(next));
				if (out.size() > 100) break;
			}
		}

		static void generate_jacob_indices(std::vector<size_t> &order, size_t s_size) {
			order.clear();

			if (s_size == 0) return;

			std::vector<size_t> J;
			compute_jacobsthal_sequence(J, s_size);

			std::vector<char> used(s_size, 0);
			size_t k = 1;
			size_t start;
			size_t end_j;
			while (true) {
				if (k - 1 < J.size())
					start = J[k - 1];
				else
					start = J.back();
				if (k < J.size())
					end_j = J[k];
				else
					end_j = J.back();

				if (start >= s_size) break;

				size_t end = (end_j == 0) ? start : std::min(end_j, s_size);

				for (size_t i = start; i < end; ++i) {
					if (!used[i]) {
						order.push_back(i);
						used[i] = 1;
					}
				}
				if (order.size() >= s_size) break;
				if (k > J.size() + 10) break;
				++k;
			}
			for (size_t i = 0; i < s_size; ++i) {
				if (!used[i]) order.push_back(i);
			}
		}
		
		template <typename Container>
		void	build_pairs(
			Container &container,
			std::vector<typename Container::value_type> &L,
			std::vector<typename Container::value_type> &S,
			bool &has_odd,
			typename Container::value_type &last_element
		)
		{
			size_t n = container.size();
			size_t i = 0;

			while (i + 1 < n) {
				typename Container::value_type first = container[i];
				typename Container::value_type second = container[i + 1];

				if (first < second) {
					L.push_back(second);
					S.push_back(first);
				}
				else {
					L.push_back(first);
					S.push_back(second);
				}
				i += 2;
			}

			if (i < n) {
				has_odd = true;
				last_element = container[i];
			}
		}

		template <typename Container>
		void	merge_insert_sort(Container &container) {
			size_t n = container.size();
			if (n <= 1) return ;

			std::vector<typename Container::value_type> L;
			std::vector<typename Container::value_type> S;

			bool has_odd = false;

			typename Container::value_type last_element;

			build_pairs(container, L, S, has_odd, last_element);

			Container L_container;

			for (typename std::vector<typename Container::value_type>::iterator it = L.begin(); it != L.end(); ++it) {
				L_container.push_back(*it);
			}
			merge_insert_sort(L_container);

			std::vector<size_t> insert_order;
			generate_jacob_indices(insert_order, S.size());

			for (size_t idx = 0; idx < insert_order.size(); ++idx) {
				size_t pos = insert_order[idx];
				typename Container::value_type value_to_insert = S[pos];
				typename Container::iterator it = std::lower_bound(L_container.begin(), L_container.end(), value_to_insert);
				L_container.insert(it, value_to_insert);
			}

			if (has_odd) {
				typename Container::iterator it = std::lower_bound(L_container.begin(), L_container.end(), last_element);
				L_container.insert(it, last_element); 
			}

			container.clear();

			for (typename Container::iterator it = L_container.begin(); it != L_container.end(); ++it)
				container.push_back(*it);
		}
};

#endif