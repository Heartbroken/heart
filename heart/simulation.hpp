#ifndef __SIMULATION_HPP__
#define __SIMULATION_HPP__

namespace heart
{
    struct world;

    /* Shape handle
     */
    struct shape
    {
        inline shape();
        inline shape(const shape &_s);
        inline shape& operator = (const shape &_s);

        inline bool valid() const;
        inline const xstr32& name() const;
        inline shape next_shape() const;
        inline void destroy();

    private:
        friend world;
        world &m_world; uint m_ID;
        inline shape(world &_world, uint _ID);
    };

    /* Joint handle
     */
    struct joint
    {
        inline joint() : m_world(*(world*)0), m_ID(BAD_ID) {}
        inline joint(const joint &_j) : m_world(_j.m_world), m_ID(_j.m_ID) {}
        inline joint& operator = (const joint &_j) { this->~joint(); new(this) joint(_j); return *this; }

    private:
        friend world;
        world &m_world; uint m_ID;
        inline joint(world &_world, uint _ID) : m_world(_world), m_ID(_ID) {}
    };

    /* Rigidbody handle
     */
    struct rigidbody
    {
        inline rigidbody();
        inline rigidbody(const rigidbody &_b);
        inline rigidbody& operator = (const rigidbody &_b);

        inline shape create_shape(const xstr32 &_name, const real4x4 &_transform = r4x4_1, real _friction = 0.5f, real _bouncing = 0.0f, real _density = 1.0f) const;
        inline shape first_shape() const;
        inline joint create_joint(char* _name, const real4x4 &_transform = r4x4_1);

        inline bool valid() const;
        inline const xstr32& name() const;
        inline void destroy();

    private:
        friend world;
        world &m_world; uint m_ID;
        inline rigidbody(world &_world, uint _ID);
    };

    struct world
    {
        inline world(const xstr32 &_name = xs32_0);

        inline const xstr32& name() const { return m_name; }

        inline rigidbody create_rigidbody(const xstr32 &_name, const real4x4 &_transform = r4x4_1);
        inline shape create_shape(const xstr32 &_name, const real4x4 &_transform = r4x4_1, real _friction = 0.5f, real _bouncing = 0.0f);

    private:
        xstr32 m_name;
        rigidbody m_statics;

        friend shape;
        struct _shape
        {
            xstr32 name;
            real4x4 transform;
            real friction, bouncing, density;
            uint rigidbody_ID, next_shape_ID;
        };
        pool_<_shape> m_shapes;
        inline bool shape_is_valid(uint _ID) const;
        inline const xstr32& get_shape_name(uint _ID) const;
        inline shape next_rigidbody_shape(uint _shape_ID);

        friend joint;
        struct _joint
        {
        };
        pool_<_joint> m_joints;

        friend rigidbody;
        struct _rigidbody
        {
            enum rigidbody_type { rigidbody_type_static, rigidbody_type_dynamic };
            rigidbody_type type;
            xstr32 name; real4x4 transform;
            uint typed_rigidbody_ID, first_shape_ID, first_joint_ID;
        };
        pool_<_rigidbody> m_rigidbodys;
        inline bool rigidbody_is_valid(uint _ID) const;
        inline const xstr32& get_rigidbody_name(uint _ID) const;
        inline shape create_rigidbody_shape(uint _rigidbody_ID, const xstr32 &_name, const real4x4 &_transform, real _friction, real _bouncing, real _density);
        inline shape first_rigidbody_shape(uint _rigidbody_ID);
        inline void destroy_rigidbody_shape(uint _shape_ID);
        inline void destroy_rigidbody(uint _rigidbody_ID);

        struct _staticrigidbody
        {
        };
    };

    // Inlines

    // shape

    inline shape::shape()
    :
        m_world(*(world*)0), m_ID(BAD_ID)
    {}
    inline shape::shape(world &_world, uint _ID)
    :
        m_world(_world), m_ID(_ID)
    {}
    inline shape::shape(const shape &_s)
    :
        m_world(_s.m_world), m_ID(_s.m_ID)
    {}
    inline shape& shape::operator = (const shape &_s)
    {
        this->~shape(); new(this) shape(_s); return *this;
    }
    inline bool shape::valid() const
    {
        return &m_world != 0 && m_world.shape_is_valid(m_ID);
    }
    inline const xstr32& shape::name() const
    {
        return valid() ? m_world.get_shape_name(m_ID) : xs32_0;
    }
    inline shape shape::next_shape() const
    {
        return valid() ? m_world.next_rigidbody_shape(m_ID) : shape();
    }
    inline void shape::destroy()
    {
        if (valid()) m_world.destroy_rigidbody_shape(m_ID);
        m_ID = BAD_ID;
    }

    // rigidbody

    inline rigidbody::rigidbody()
    :
        m_world(*(world*)0), m_ID(BAD_ID)
    {}
    inline rigidbody::rigidbody(world &_world, uint _ID)
    :
        m_world(_world), m_ID(_ID)
    {}
    inline rigidbody::rigidbody(const rigidbody &_b)
    :
        m_world(_b.m_world), m_ID(_b.m_ID)
    {}
    inline rigidbody& rigidbody::operator = (const rigidbody &_b)
    {
        this->~rigidbody(); new(this) rigidbody(_b); return *this;
    }
    inline bool rigidbody::valid() const
    {
        return &m_world != 0 && m_world.rigidbody_is_valid(m_ID);
    }
    inline const xstr32& rigidbody::name() const
    {
        return valid() ? m_world.get_rigidbody_name(m_ID) : xs32_0;
    }
    inline shape rigidbody::create_shape(const xstr32 &_name, const real4x4 &_transform, real _friction, real _bouncing, real _density) const
    {
        return valid() ? m_world.create_rigidbody_shape(m_ID, _name, _transform, _friction, _bouncing, _density) : shape();
    }
    inline shape rigidbody::first_shape() const
    {
        return valid() ? m_world.first_rigidbody_shape(m_ID) : shape();
    }
    inline void rigidbody::destroy()
    {
        if (valid()) m_world.destroy_rigidbody(m_ID);
        m_ID = BAD_ID;
    }

    // world

    inline world::world(const xstr32 &_name)
    :
        m_name(_name)
    {
        m_statics = create_rigidbody("Statics");
    }
    inline bool world::shape_is_valid(uint _ID) const
    {
        return m_shapes.exists(_ID);
    }
    inline const xstr32& world::get_shape_name(uint _ID) const
    {
        return m_shapes.get(_ID).name;
    };
    inline shape world::create_shape(const xstr32 &_name, const real4x4 &_transform, real _friction, real _bouncing)
    {
        return m_statics.create_shape(_name, _transform, _friction, _bouncing);
    }
    rigidbody world::create_rigidbody(const xstr32 &_name, const real4x4 &_transform)
    {
        uint l_rigidbody_ID = m_rigidbodys.add();
        _rigidbody &l_rigidbody = m_rigidbodys.get(l_rigidbody_ID);
        l_rigidbody.name = _name;
        l_rigidbody.transform = _transform;
        l_rigidbody.first_shape_ID = BAD_ID;
        l_rigidbody.first_joint_ID = BAD_ID;
        l_rigidbody.typed_rigidbody_ID = BAD_ID;
        return rigidbody(*this, l_rigidbody_ID);
    }
    inline bool world::rigidbody_is_valid(uint _ID) const
    {
        return m_rigidbodys.exists(_ID);
    }
    inline const xstr32& world::get_rigidbody_name(uint _ID) const
    {
        return m_rigidbodys.get(_ID).name;
    };
    inline shape world::create_rigidbody_shape(uint _rigidbody_ID, const xstr32 &_name, const real4x4 &_transform, real _friction, real _bouncing, real _density)
    {
        uint l_shape_ID = m_shapes.add();

        _shape &l_shape = m_shapes.get(l_shape_ID);
        l_shape.name = _name;
        l_shape.transform = _transform;
        l_shape.friction = _friction;
        l_shape.bouncing = _bouncing;
        l_shape.density = _density;
        l_shape.rigidbody_ID = _rigidbody_ID;

        _rigidbody &l_rigidbody = m_rigidbodys.get(_rigidbody_ID);
        l_shape.next_shape_ID = l_rigidbody.first_shape_ID;
        l_rigidbody.first_shape_ID = l_shape_ID;

        return shape(*this, l_shape_ID);
    }
    inline shape world::first_rigidbody_shape(uint _rigidbody_ID)
    {
        return shape(*this, m_rigidbodys.get(_rigidbody_ID).first_shape_ID);
    }
    inline shape world::next_rigidbody_shape(uint _shape_ID)
    {
        return shape(*this, m_shapes.get(_shape_ID).next_shape_ID);
    }
    inline void world::destroy_rigidbody_shape(uint _shape_ID)
    {
        _shape &l_shape = m_shapes.get(_shape_ID);
        _rigidbody &l_rigidbody = m_rigidbodys.get(l_shape.rigidbody_ID);
        if (l_rigidbody.first_shape_ID == _shape_ID)
        {
            l_rigidbody.first_shape_ID = l_shape.next_shape_ID;
        }
        else
        {
            uint l_prev_shape_ID = l_rigidbody.first_shape_ID;
            while (l_prev_shape_ID != BAD_ID)
            {
                _shape &l_prev_shape = m_shapes.get(l_prev_shape_ID);
                if (l_prev_shape.next_shape_ID == _shape_ID)
                {
                    l_prev_shape.next_shape_ID = l_shape.next_shape_ID;
                    break;
                }
                l_prev_shape_ID = l_prev_shape.next_shape_ID;
            }
        }
        m_shapes.remove(_shape_ID);
    }
    inline void world::destroy_rigidbody(uint _rigidbody_ID)
    {
        _rigidbody &l_rigidbody = m_rigidbodys.get(_rigidbody_ID);
        while (l_rigidbody.first_shape_ID != BAD_ID) destroy_rigidbody_shape(l_rigidbody.first_shape_ID);
        m_rigidbodys.remove(_rigidbody_ID);
    }

}

#endif // __SIMULATION_HPP__