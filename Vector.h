#ifndef VECTOR_H
#define VECTOR_H
namespace fzzz
{
	template <typename T> class Vector
	{
	public:
		Vector(int init_size, const T &init_value = T());//普通构造函数
		Vector(const Vector &other);//拷贝构造
		static const int SPARE_CAPACITY = 10;//备用容量
	private:
		int size_;
		int capacity_;
		T *p_array_;
	};

	template <typename T>
	Vector<T>::Vector(int init_size, const T &init_value = T()) :
		size_(init_size > 0 ? init_size : 0),
		capacity_(init_size + SPARE_CAPACITY),
		p_array_(new T[capacity_])
	{
		for (size_t i = 0; i < init_size; ++i)
		{
			p_array_[i] = init_value;
		}
	}

	template <typename T>
	Vector<T>::Vector(const Vector &other):
		size_(other.size_),
		capacity_(other.capacity_),
		p_array_(new T[capacity_])
	{
		for (size_t i = 0; i < other.size_; ++i)
		{
			p_array_[i] = other.p_array_[i];
		}
	}

}
#endif