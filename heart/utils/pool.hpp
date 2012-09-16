#ifndef __POOL_HPP__
#define __POOL_HPP__

namespace heart
{
	template <typename _Type, uint _Min = 10, uint _Grow = 60>
	struct pool_
	{
		typedef _Type type;

		inline pool_()
        :
            m_items(0), m_size(0), m_count(0), m_first_free(BAD_ID), m_counter(0)
        {}
        inline ~pool_()
        {
            clear(true);
        }

		inline uint add(const type &_v = type())
		{
            ++m_count;
			uint l_index;
            if (m_first_free == BAD_ID) grow();
            l_index = m_first_free;
            m_first_free = m_items[l_index].next_free;
			item &l_item = m_items[l_index];
			new(&l_item.v) _Type(_v);
			l_item.ID = ((++m_counter &= INDEX_MASK) << 16) | (l_index & INDEX_MASK);
			return l_item.ID;
		}
		inline bool exists(uint _ID) const
		{
			uint l_index = _ID & INDEX_MASK;
			if (l_index > m_size) return false;
			if (m_items[l_index].ID != _ID) return false;
			return true;
		}
		inline const type& get(uint _ID) const
		{
			return m_items[_ID & INDEX_MASK].v;
		}
		inline type& get(uint _ID)
		{
			return m_items[_ID & INDEX_MASK].v;
		}
		inline void remove(uint _ID)
		{
			if (exists(_ID))
			{
                --m_count;
				uint l_index = _ID & INDEX_MASK;
			    item &l_item = m_items[l_index];
                l_item.v.~_Type();
				l_item.ID = BAD_ID;
                l_item.next_free = m_first_free;
                m_first_free = l_index;
			}
		}
		inline void clear(bool _free = false)
		{
            uint l_ID = first_ID();
            while (l_ID != BAD_ID)
            {
                uint l_remove = l_ID;
                l_ID = next_ID(l_ID);
                remove(l_remove);
            }
            if (_free)
            {
                m_items = (items)realloc(m_items, 0);
                m_size = 0;
                m_first_free = BAD_ID;
            }
		}
		inline const type& operator [] (uint _ID) const
		{
			return get(_ID);
		}
		inline type& operator [] (uint _ID)
		{
			return get(_ID);
		}
		inline uint first_ID() const
		{
			uint l_index = 0;
			while (l_index < m_size)
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
			while (l_index < m_size)
			{
				const item &l_item = m_items[l_index];
				if (l_item.ID != BAD_ID) return l_item.ID;
				++l_index;
			}
			return BAD_ID;
		}
        inline uint count() const
        {
            return m_count;
        }

	private:
        inline pool_(const pool_&);
        inline pool_& operator = (const pool_&);
		static const uint INDEX_MASK = 0xffff;
        struct item
        {
            uint ID;
            union
            {
                struct { type v; };
                uint next_free;
            };
        };
        typedef item* items;
        items m_items;
        uint m_size, m_count;
        uint m_first_free;
        inline void grow()
        {
            uint l_new_size = m_size ? m_size + (m_size * _Grow / 100) : _Min;
            m_items = (items)realloc(m_items, l_new_size * sizeof(item));
            for (sint i = l_new_size - 1, s = m_size; i >= s; --i)
            {
                item &l_item = m_items[i];
                l_item.ID = BAD_ID;
                l_item.next_free = m_first_free;
                m_first_free = i;
            }
            m_size = l_new_size;
        }
		uint m_counter;
	};
};


#endif // __POOL_HPP__