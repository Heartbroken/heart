#ifndef __POOL_HPP__
#define __POOL_HPP__

#include <vector>

namespace heart
{
	template <typename _Type>
	struct pool_
	{
		typedef _Type type;

		inline pool_() : m_counter(0) {}

		inline uint add(const type &_v = type())
		{
			uint l_index;
			if (m_free.empty())
			{
				l_index = m_items.size();
				m_items.resize(m_items.size() + 1);
			}
			else
			{
				l_index = m_free.back();
				m_free.pop_back();
			}
			item &l_item = m_items[l_index];
			l_item.v.~_Type(); new(&l_item.v) _Type(_v);
			l_item.ID = ((++m_counter &= INDEX_MASK) << 16) | (l_index & INDEX_MASK);
			return l_item.ID;
		}
		inline bool exists(uint _ID) const
		{
			uint l_index = _ID & INDEX_MASK;
			if (l_index > m_items.size()) return false;
			if (m_items[l_index].ID != _ID) return false;
			return true;
		}
		inline void remove(uint _ID)
		{
			if (exists(_ID))
			{
				uint l_index = _ID & INDEX_MASK;
				m_items[l_index].ID = BAD_ID;
				m_free.push_back(l_index);
			}
		}
		inline void clear()
		{
			m_items.resize(0);
			m_free.resize(0);
		}
		inline const type& operator [] (uint _ID) const
		{
			return m_items[_ID & INDEX_MASK].v;
		}
		inline type& operator [] (uint _ID)
		{
			return m_items[_ID & INDEX_MASK].v;
		}
		inline uint first_ID() const
		{
			uint l_index = 0;
			while (l_index < m_items.size())
			{
				const item &l_item = m_items[l_index];
				if (l_item.ID != BAD_ID) return l_item.ID;
				++l_index;
			}
			return BAD_ID;
		}
		inline uint next_ID(uint _ID) const
		{
			if (!exists(_ID)) return BAD_ID;
			uint l_index = (_ID & INDEX_MASK) + 1;
			while (l_index < m_items.size())
			{
				const item &l_item = m_items[l_index];
				if (l_item.ID != BAD_ID) return l_item.ID;
				++l_index;
			}
			return BAD_ID;
		}
	private:
		static const uint INDEX_MASK = 0xffff;
		struct item { uint ID; type v; };
		std::vector<item> m_items;
		std::vector<uint> m_free;
		uint m_counter;
	};
};


#endif // __POOL_HPP__