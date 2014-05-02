#pragma once

template <typename type>
class SharedPointer{
	public:
		SharedPointer() {
			data = new Data;
			data->count = 0;
			data->value = nullptr;
		}
		SharedPointer(type *pointer) {
			data = new Data;
			data->count = 1;
			data->value = pointer;
		}
		SharedPointer(SharedPointer const &pointer) {
			data = pointer.data;
			data->count++;
		}
		~SharedPointer() {
			data->count--;
			if (data->count <= 0) {
				delete data;
			}
		}
		SharedPointer &operator=(SharedPointer const &pointer) {
			data->count--;
			data = pointer.data;
			data->count++;
			return *this;
		}
		type* get() {
			return data->value;
		}
		int getCount() {
			return data->count;
		}


	private:
		struct Data {
			type* value;
			int count;
		};
		Data* data;
};
