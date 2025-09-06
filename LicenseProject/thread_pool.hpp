#pragma once

#include "thread_safe_queue.hpp"
#include "Warnings.hpp"
#include <atomic>
#include <functional>

class thread_pool {
public:
	thread_pool() noexcept(true)
		: isDone{ false } 
	{
	}

	~thread_pool() {
		isDone = true;

		for (size_t i = 0; i < threads.size(); ++i)
			if (threads.at(i).joinable())
				threads.at(i).join();
	}

	void start() {
		try {
			const size_t threadCount = std::thread::hardware_concurrency();
			for (size_t i = 0; i < threadCount; ++i)
				threads.push_back(std::thread(&thread_pool::worker_thread, this));
		}
		catch (const std::exception& e) {
			isDone = true;
			throw e;
		}
	}

	template<typename FunctionType>
	void submit(FunctionType f) { // type erasure
		work_q.push(std::function<void()>(f));
	}

	virtual void waitForFinish() {
		while (!work_q.empty());
		isDone = true;

		for (size_t i = 0; i < threads.size(); ++i)
			if (threads.at(i).joinable())
				threads.at(i).join();
	}

protected:
	std::atomic_bool isDone;
	thread_safe_queue<std::function<void()>> work_q;

	void worker_thread() {
		while (!isDone) {
			std::function<void()> task;
			if (work_q.try_pop(task)) {
				task();
			}
			else {
				std::this_thread::yield();
			}
		}
	}

private:
	std::vector<std::thread> threads;
};