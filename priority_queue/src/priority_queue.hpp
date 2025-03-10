#ifndef SJTU_PRIORITY_QUEUE_HPP
#define SJTU_PRIORITY_QUEUE_HPP

#include <cstddef>
#include <functional>
#include <type_traits>
#include <iostream>
#include <assert.h>
#include "exceptions.hpp"

namespace sjtu {
/**
 * @brief a container like std::priority_queue which is a heap internal.
 * **Exception Safety**: The `Compare` operation might throw exceptions for certain data.
 * In such cases, any ongoing operation should be terminated, and the priority queue should be restored to its original state before the operation began.
 */
// 实现：斜堆 skew heap
template<typename T, class Compare = std::less<T>>
class priority_queue {
private:
	size_t Size;
	T *value;
	priority_queue *Leftson, *Rightson;
public:
	/**
	 * @brief default constructor
	 */
	priority_queue() : Size(0), value(nullptr), Leftson(nullptr), Rightson(nullptr) {}

	/**
	 * @brief copy constructor
	 * @param other the priority_queue to be copied
	 */
	priority_queue(const priority_queue &other) {
		Size = other.Size;
		if (other.value != nullptr)
			value = new T (*other.value);
		else value = nullptr;
		if (other.Leftson != nullptr)
			Leftson = new priority_queue(*other.Leftson);
		else Leftson = nullptr;
		if (other.Rightson != nullptr)
			Rightson = new priority_queue(*other.Rightson);
		else Rightson = nullptr;
	}

	/**
	 * @brief deconstructor
	 */
	~priority_queue() {
		if (value != nullptr) {
			delete value;
			value = nullptr;
		}
		if (Leftson != nullptr) {
			delete Leftson;
			Leftson = nullptr;
		}
		if (Rightson != nullptr) {
			delete Rightson;
			Rightson = nullptr;
		}
	}

	/**
	 * @brief Assignment operator
	 * @param other the priority_queue to be assigned from
	 * @return a reference to this priority_queue after assignment
	 */
	priority_queue &operator=(const priority_queue &other) {
		if (this == &other) return *this;
		Size = other.Size;
		if (value == nullptr) {
			if (other.value != nullptr)
				value = new T (*other.value);
		}
		else {
			if (other.value == nullptr) {
				delete value;
				value = nullptr;
			}
			else *value = *other.value;
		}
		delete Leftson;
		if (other.Leftson != nullptr)
			Leftson = new priority_queue(*other.Leftson);
		else Leftson = nullptr;
		delete Rightson;
		if (other.Rightson != nullptr)
			Rightson = new priority_queue(*other.Rightson);
		else Rightson = nullptr;
		return *this;
	}

	/**
	 * @brief get the top element of the priority queue.
	 * @return a reference of the top element.
	 * @throws container_is_empty if empty() returns true
	 */
	const T & top() const {
		if (Size == 0) throw container_is_empty();
		return *value;
	}

	/**
	 * @brief push new element to the priority queue.
	 * @param e the element to be pushed
	 */
	void push(const T &e) {
		if (Size == 0) {
			Size = 1;
			value = new T(e);
			return;
		}
		priority_queue newq;
		newq.push(e);
		merge(newq);
	}

	/**
	 * @brief delete the top element from the priority queue.
	 * @throws container_is_empty if empty() returns true
	 */
	void pop() {
		if (Size == 0) throw container_is_empty();
		if (Leftson == nullptr && Rightson == nullptr) {
			delete value; value = nullptr;
			Size = 0;
			return;
		}
		if (Leftson == nullptr) {
			priority_queue *tmp = Rightson;
			Size = tmp->Size;
			delete value;
			value = tmp->value;
			Leftson = tmp->Leftson;
			Rightson = tmp->Rightson;
			tmp->value = nullptr;
			tmp->Leftson = nullptr;
			tmp->Rightson = nullptr;
			delete tmp; tmp = nullptr;
			return;
		}
		if (Rightson == nullptr) {
			priority_queue *tmp = Leftson;
			Size = tmp->Size;
			delete value;
			value = tmp->value;
			Leftson = tmp->Leftson;
			Rightson = tmp->Rightson;
			tmp->value = nullptr;
			tmp->Leftson = nullptr;
			tmp->Rightson = nullptr;
			delete tmp; tmp = nullptr;
			return;
		}
		Leftson->merge(*Rightson);
		delete Rightson;
		Rightson = nullptr;
		priority_queue *tmp = Leftson;
		Size = tmp->Size;
		delete value;
		value = tmp->value;
		Leftson = tmp->Leftson;
		Rightson = tmp->Rightson;
		tmp->value = nullptr;
		tmp->Leftson = nullptr;
		tmp->Rightson = nullptr;
		delete tmp; tmp = nullptr;
	}

	/**
	 * @brief return the number of elements in the priority queue.
	 * @return the number of elements.
	 */
	size_t size() const {return Size;}

	/**
	 * @brief check if the container is empty.
	 * @return true if it is empty, false otherwise.
	 */
	bool empty() const {return Size == 0;}

	/**
	 * @brief merge another priority_queue into this one.
	 * The other priority_queue will be cleared after merging.
	 * The complexity is at most O(logn).
	 * @param other the priority_queue to be merged.
	 */
	void merge(priority_queue &other) {
		if (other.Size == 0) return;
		if (Size == 0) {
			Size = other.Size;
			value = other.value;
			Leftson = other.Leftson;
			Rightson = other.Rightson;
			other.Size = 0, other.value = nullptr;
			other.Leftson = nullptr;
			other.Rightson = nullptr;
			return;
		}
		if (Compare()(*value, *other.value))
			std::swap(Size, other.Size),
			std::swap(value, other.value),
			std::swap(Leftson, other.Leftson),
			std::swap(Rightson, other.Rightson);
		Size += other.Size;
		if (Rightson == nullptr) {
			Rightson = new priority_queue();
			Rightson->Size = other.Size;
			Rightson->value = other.value;
			Rightson->Leftson = other.Leftson;
			Rightson->Rightson = other.Rightson;
			other.Size = 0, other.value = nullptr;
			other.Leftson = nullptr;
			other.Rightson = nullptr;
		}
		else Rightson->merge(other);
		std::swap(Leftson, Rightson);
	}
};

}

#endif