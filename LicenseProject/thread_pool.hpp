#pragma once

#include "thread_safe_queue.hpp"
#include "GlobalExceptionHandler.hpp"

#include <mutex>
#include <atomic>
#include <vector>
#include <thread>
#include <stdexcept>
#include <functional>
#include <condition_variable>

class thread_pool {
public:
	thread_pool()
		: isDone{ false },
		worker_mtx{},
		worker_cv{}
	{
	}

	~thread_pool() = default;

	void start() {
		try {
			for (size_t i = 0; i < THREAD_COUNT; ++i)
				threads.push_back(std::thread(&thread_pool::worker_thread, this));
		}
		catch (...) {
			isDone = true;
			GlobalExceptionHandler::handle();
		}
	}

	template<typename FunctionType>
	void submit(FunctionType f) {
		if (isDone)
			throw std::runtime_error("The thread pool has been signaled to stop!");
		work_q.push(std::function<void()>(f));
		worker_cv.notify_one();
	}

	void waitForFinish() {
		isDone = true;
		worker_cv.notify_all();
		joinCaller();
	}

	void resetThreadPool() {
		threads.clear();
		isDone = false;
	}


protected:
	std::atomic_bool isDone;
	thread_safe_queue<std::function<void()>> work_q;

	void worker_thread() {
		while (!isDone || !work_q.empty()) {
			std::function<void()> task;
			if (work_q.try_pop(task)) {
				try { task(); }
				catch (...) { GlobalExceptionHandler::handle(); }
			}
			else {
				std::unique_lock lk(worker_mtx);
				worker_cv.wait(lk, [this] { return isDone || !work_q.empty(); });
			}
		}
	}

private:
	static const size_t THREAD_COUNT{ 10 };
	std::vector<std::thread> threads;
	std::condition_variable worker_cv;
	std::mutex worker_mtx;

	void joinCaller() {
		for (size_t i = 0; i < threads.size(); ++i)
			if (threads.at(i).joinable())
				threads.at(i).join();
	}
};