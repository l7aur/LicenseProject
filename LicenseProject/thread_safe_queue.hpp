#pragma once

#include <queue>
#include <condition_variable>
#include <mutex>
#include <memory>

template<typename L>
class thread_safe_queue {
public:
	thread_safe_queue() {}

	void push(L newValue) {
		std::lock_guard<std::mutex> lk(mtx);
		data_q.push(std::move(newValue));
		cond.notify_one(); //notify_all()
	}

	void wait_and_pop(L& value) {
		std::unique_lock<std::mutex> lk(mtx);
		cond.wait(lk, [this] { return !data_q.empty(); });
		value = std::move(data_q.front());
		data_q.pop();
	}

	std::shared_ptr<L> wait_and_pop() {
		std::unique_lock<std::mutex> lk(mtx);
		cond.wait(lk, [this] { return !data_q.empty(); });
		std::shared_ptr<L> res{ std::make_shared<L>(std::move(data_q.front())) };
		data_q.pop();
		return res;
	}

	bool try_pop(L& value) {
		std::lock_guard<std::mutex> lk(mtx);
		if (data_q.empty())
			return false;
		value = std::move(data_q.front());
		data_q.pop();
		return true;
	}

	std::shared_ptr<L> try_pop() {
		std::lock_guard<std::mutex> lk(mtx);
		if (data_q.empty())
			return std::shared_ptr<L>();
		std::shared_ptr<L> res{ std::make_shared<L>(std::move(data_q.front())) };
		data_q.pop();
		return res;
	}

	bool empty() {
		std::lock_guard<std::mutex> lk(mtx);
		return data_q.empty();
	}

private:
	mutable std::mutex mtx;
	std::queue<L> data_q;
	std::condition_variable cond;
};