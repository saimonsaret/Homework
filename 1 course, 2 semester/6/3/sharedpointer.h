#pragma once

template <typename type>
class SharedPointer{
	public:
		SharedPointer();
		SharedPointer(type *pointer);
		///Copy constructor
		SharedPointer(SharedPointer const &pointer);
		~SharedPointer();
		SharedPointer &operator=(SharedPointer const &pointer);
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
			~Data() {
				delete value;
			}
		};
		Data* data;
};

template<typename type>
SharedPointer<type>::SharedPointer() {
	data = new Data;
	data->count = 0;
	data->value = nullptr;
}

template<typename type>
SharedPointer<type>::SharedPointer(type *pointer) {
	data = new Data;
	data->count = 1;
	data->value = pointer;
}

template<typename type>
SharedPointer<type>::SharedPointer(SharedPointer const &pointer) {
	data = pointer.data;
	data->count++;
}

template <typename type>
SharedPointer<type>::~SharedPointer() {
	data->count--;
	if (data->count <= 0)
		delete data;
}

template <typename type>
SharedPointer<type>& SharedPointer<type>::operator=(SharedPointer const &pointer) {
	data->count--;
	if (data->count == 0)
		delete data;
	data = pointer.data;
	data->count++;
	return *this;
}
