#pragma once

#include <vector>
#include <atomic>

namespace Vignoble {
	namespace Msg {

		template<typename T>
		class LfFifo
		{
			struct node
			{
				std::shared_ptr<T> data;
				node* next;

				node() : next(nullptr) {}
			};

			std::atomic<node*> head;
			std::atomic<node*> tail;

			node* pop_head()
			{
				node* const old_head = head.load() //1
					if (old_head == tail.load()) {
						return nullptr;
					}
				head.store(old_head->next);
				return old_head;
			}

		public:
			LfFifo() : head(new node), tail(head.load()) {}
			LfFifo(const LfFifo& other) = delete;
			LfFifo& operator=(const LfFifo& other) = delete;
			~LfFifo()
			{
				while (node* const old_head = head.load())
				{
					head.store(old_head->next);
					delete old_head;
				}
			}

			std::shared_ptr<T> pop()
			{
				node* old_head = pop_head();
				if (!old_head)
				{
					return std::shared_ptr<T>();
				}

				std::shared_ptr<T> const res(old_head->data); //2
				delete old_head;
				return res;
			}

			void push(T new_value)
			{
				std::shared_ptr<T> new_data(std::make_shared<T>(new_value));
				node* p = new node(); //3
				node* const old_tail = tail.load(); //4
				old_tail->data.swap(new_data); //5
				old_tail->next = p; //6
				tail.store(p); //7
			}

		};

	}
}