#include <algorithm>
#include <vector>
#include <list>
#include <typeinfo>

using namespace std;

template <class T, class CONT = vector<T*> >
class TContainer
{
	public:
		TContainer() {}
		~TContainer() {}
		bool IsEmpty() const { return m_container.empty(); }
		size_t Size() const { return m_container.size(); }		
		void Insert(const T* _el) { m_container.insert(m_container.end(), (T*)_el); }
		const T* First() const { return *m_container.begin(); }
		const T* Last() const { return *m_container.rbegin(); }
		const T* Find(const T& _el) const {typename CONT::const_iterator it = find_if(m_container.begin(), m_container.end(), Equals<T>(_el)); if(it != m_container.end()) return *it; else return NULL; }
		const T* Remove(const T& _el);
		void RemoveAll() { m_container.clear(); }
		bool RemoveAndDelete(const T& _el) { const T* dataPtr = Remove(_el); if(dataPtr) delete dataPtr; return (bool) dataPtr; }
		void RemoveAndDeleteAll() {for_each(m_container.begin(), m_container.end(), Deleter<T>()); m_container.clear(); };
		const T* operator[](int _i) const;

	private:
		CONT m_container;

		TContainer(const TContainer& _cont){}
		void operator=(const TContainer& _cont){};
		//const T* list::operator[](int _i){};

		template <class TYPE>		
		class Equals	
		{
			public:					
				Equals(const TYPE& _val):m_val(_val){}				
				bool operator()(const TYPE* _val){ return *_val == m_val; }

			private:
				const TYPE m_val;
		};

		template <class TYPE>		
		struct Deleter
		{
			void operator()(TYPE* _p) { delete _p; }
		};
};

template <class T, class CONT>
const T* TContainer<T, CONT>::Remove(const T& _el)
{
	T* dataPtr = NULL;	
	typename CONT::iterator it = find_if(m_container.begin(), m_container.end(), Equals<T>(_el));
	if(it != m_container.end())
	{
		dataPtr = *it;	
		m_container.erase(it);
	}
	return dataPtr;
}

template <class T, class CONT>
const T* TContainer<T, CONT>::operator[](int _i) const
{
	T* res = NULL;
	if(typeid(m_container) != typeid(vector<T*>))
	{		
		typename CONT::const_iterator it = m_container.begin();
		for(int i = 0; i < _i && it != m_container.end(); ++i)
		{
			++it;
		}		
		if(it != m_container.end())
		{
			res = *it;		
		}			
	}
	else
	{
		//const vector<T*>* vec = dynamic_cast<const vector<T*>*>(&m_container);		
		//res = (*vec)[_i];
		//res = m_container[_i];		
	}
	return res;
}


















































