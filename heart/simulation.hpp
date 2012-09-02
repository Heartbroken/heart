#ifndef __SIMULATION_HPP__
#define __SIMULATION_HPP__

namespace heart
{
    struct world;
    struct rigid;
    struct field;

    /* Shape handle
     */
    struct shape
    {
        inline shape();
        inline shape(const shape &_s);
        inline shape& operator = (const shape &_s);
        inline bool operator == (const shape &_s) const;
        inline bool valid() const;
        inline const xname& name() const;
        inline rigid get_rigid() const;
        inline field get_field() const;
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
        inline joint();
        inline joint(const joint &_j);
        inline joint& operator = (const joint &_j);
        inline bool operator == (const joint &_j) const;
        inline bool valid() const;
        inline const xname& name() const;
        inline rigid get_rigid() const;
        inline void destroy();

    private:
        friend world;
        world &m_world; uint m_ID;
        inline joint(world &_world, uint _ID);
    };

    /* Rigid handle
     */
    struct rigid
    {
        inline rigid();
        inline rigid(const rigid &_r);
        inline rigid& operator = (const rigid &_r);
        inline bool operator == (const rigid &_r) const;
        inline shape create_shape(const xname &_name = xname_0, const real4x4 &_transform = r4x4_1, real _friction = 0.5f, real _bouncing = 0.0f, real _density = 1.0f) const;
        inline uint shapes_count() const;
        inline shape first_shape() const;
        inline shape next_shape(const shape &_s) const;
        inline joint create_joint(const xname &_name = xname_0, const real4x4 &_transform = r4x4_1);
        inline uint joints_count() const;
        inline joint first_joint() const;
        inline joint next_joint(const joint &_joint) const;
        inline bool valid() const;
        inline const xname& name() const;
        inline void destroy();

    private:
        friend world;
        world &m_world; uint m_ID;
        inline rigid(world &_world, uint _ID);
    };

    /* Field handle
     */
    struct field
    {
        inline field();
        inline field(const field &_f);
        inline field& operator = (const field &_f);
        inline bool operator == (const field &_f) const;
        inline shape create_shape(const xname &_name = xname_0, const real4x4 &_transform = r4x4_1) const;
        inline uint shapes_count() const;
        inline shape first_shape() const;
        inline shape next_shape(const shape &_s) const;
        inline bool valid() const;
        inline const xname& name() const;
        inline void destroy();

    private:
        friend world;
        world &m_world; uint m_ID;
        inline field(world &_world, uint _ID);
    };

    /* World - the root simulation class
     */
    struct world
    {
        inline world(const xname &_name = xname_0);

        inline const xname& name() const;

        inline rigid create_rigid(const xname &_name = xname_0, const real4x4 &_transform = r4x4_1);
        inline field create_field(const xname &_name = xname_0, const real4x4 &_transform = r4x4_1);

        inline uint shapes_count() const;
        inline shape first_shape();
        inline shape next_shape(const shape &_s);
        inline uint joints_count() const;
        inline joint first_joint();
        inline joint next_joint(const joint &_j);
        inline uint rigids_count() const;
        inline rigid first_rigid();
        inline rigid next_rigid(const rigid &_r);
        inline uint fields_count() const;
        inline field first_field();
        inline field next_field(const field &_f);

    private:
        xname m_name;

        friend shape;
        struct _shape
        {
            xname name; real4x4 transform;
            real friction, bouncing, density;
            uint rigid_ID, field_ID, next_shape_ID;
        };
        pool_<_shape> m_shapes;
        inline bool shape_is_valid(uint _ID) const;
        inline const xname& get_shape_name(uint _ID) const;
        inline rigid get_shape_rigid(uint _ID);
        inline field get_shape_field(uint _ID);

        friend joint;
        struct _joint
        {
            xname name; real4x4 transform;
            uint rigid_ID, next_joint_ID;
        };
        pool_<_joint> m_joints;
        inline bool joint_is_valid(uint _ID) const;
        inline const xname& get_joint_name(uint _ID) const;
        inline rigid get_joint_rigid(uint _ID);

        friend rigid;
        struct _rigid
        {
            enum rigid_type { rigid_type_static, rigid_type_dynamic };
            rigid_type type;
            xname name; real4x4 transform;
            uint typed_rigid_ID, first_shape_ID, first_joint_ID;
            uint shapes_count, joints_count;
        };
        pool_<_rigid> m_rigids;
        inline bool rigid_is_valid(uint _ID) const;
        inline const xname& get_rigid_name(uint _ID) const;
        inline shape create_rigid_shape(uint _rigid_ID, const xname &_name, const real4x4 &_transform, real _friction, real _bouncing, real _density);
        inline uint rigid_shapes_count(uint _rigid_ID) const;
        inline shape first_rigid_shape(uint _rigid_ID);
        inline shape next_rigid_shape(const shape &_s);
        inline void destroy_rigid_shape(uint _shape_ID);
        inline joint create_rigid_joint(uint _rigid_ID, const xname &_name, const real4x4 &_transform);
        inline uint rigid_joints_count(uint _rigid_ID) const;
        inline joint first_rigid_joint(uint _rigid_ID);
        inline joint next_rigid_joint(const joint &_j);
        inline void destroy_rigid_joint(uint _joint_ID);
        inline void destroy_rigid(uint _rigid_ID);

        friend field;
        struct _field
        {
            xname name; real4x4 transform;
            uint first_shape_ID, shapes_count;
        };
        pool_<_field> m_fields;
        inline bool field_is_valid(uint _ID) const;
        inline const xname& get_field_name(uint _ID) const;
        inline shape create_field_shape(uint _field_ID, const xname &_name, const real4x4 &_transform);
        inline uint field_shapes_count(uint _field_ID) const;
        inline shape first_field_shape(uint _field_ID);
        inline shape next_field_shape(const shape &_s);
        inline void destroy_field_shape(uint _shape_ID);
        inline void destroy_field(uint _field_ID);
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
    inline bool shape::operator == (const shape &_s) const
    {
        return valid() && (&m_world == &_s.m_world) && (m_ID == _s.m_ID);
    }
    inline bool shape::valid() const
    {
        return &m_world != 0 && m_world.shape_is_valid(m_ID);
    }
    inline const xname& shape::name() const
    {
        return valid() ? m_world.get_shape_name(m_ID) : xname_0;
    }
    inline rigid shape::get_rigid() const
    {
        return valid() ? m_world.get_shape_rigid(m_ID) : rigid();
    }
    inline field shape::get_field() const
    {
        return valid() ? m_world.get_shape_field(m_ID) : field();
    }
    inline void shape::destroy()
    {
        if (valid())
        {
            if (get_rigid().valid()) m_world.destroy_rigid_shape(m_ID);
            if (get_field().valid()) m_world.destroy_field_shape(m_ID);
        }
        m_ID = BAD_ID;
    }

    // joint

    inline joint::joint()
    :
        m_world(*(world*)0), m_ID(BAD_ID)
    {}
    inline joint::joint(world &_world, uint _ID)
    :
        m_world(_world), m_ID(_ID)
    {}
    inline joint::joint(const joint &_j)
    :
        m_world(_j.m_world), m_ID(_j.m_ID)
    {}
    inline joint& joint::operator = (const joint &_j)
    {
        this->~joint(); new(this) joint(_j); return *this;
    }
    inline bool joint::operator == (const joint &_j) const
    {
        return valid() && (&m_world == &_j.m_world) && (m_ID == _j.m_ID);
    }
    inline bool joint::valid() const
    {
        return &m_world != 0 && m_world.joint_is_valid(m_ID);
    }
    inline const xname& joint::name() const
    {
        return valid() ? m_world.get_joint_name(m_ID) : xname_0;
    }
    inline rigid joint::get_rigid() const
    {
        return valid() ? m_world.get_joint_rigid(m_ID) : rigid();
    }
    inline void joint::destroy()
    {
        if (valid()) m_world.destroy_rigid_joint(m_ID);
        m_ID = BAD_ID;
    }

    // rigid

    inline rigid::rigid()
    :
        m_world(*(world*)0), m_ID(BAD_ID)
    {}
    inline rigid::rigid(world &_world, uint _ID)
    :
        m_world(_world), m_ID(_ID)
    {}
    inline rigid::rigid(const rigid &_r)
    :
        m_world(_r.m_world), m_ID(_r.m_ID)
    {}
    inline rigid& rigid::operator = (const rigid &_r)
    {
        this->~rigid(); new(this) rigid(_r); return *this;
    }
    inline bool rigid::operator == (const rigid &_r) const
    {
        return valid() && (&m_world == &_r.m_world) && (m_ID == _r.m_ID);
    }
    inline bool rigid::valid() const
    {
        return &m_world != 0 && m_world.rigid_is_valid(m_ID);
    }
    inline const xname& rigid::name() const
    {
        return valid() ? m_world.get_rigid_name(m_ID) : xname_0;
    }
    inline shape rigid::create_shape(const xname &_name, const real4x4 &_transform, real _friction, real _bouncing, real _density) const
    {
        return valid() ? m_world.create_rigid_shape(m_ID, _name, _transform, _friction, _bouncing, _density) : shape();
    }
    inline uint rigid::shapes_count() const
    {
        return valid() ? m_world.rigid_shapes_count(m_ID) : 0;
    }
    inline shape rigid::first_shape() const
    {
        return valid() ? m_world.first_rigid_shape(m_ID) : shape();
    }
    inline shape rigid::next_shape(const shape &_s) const
    {
        return (_s.get_rigid() == *this) ? m_world.next_rigid_shape(_s) : shape();
    }
    inline joint rigid::create_joint(const xname &_name, const real4x4 &_transform)
    {
        return valid() ? m_world.create_rigid_joint(m_ID, _name, _transform) : joint();
    }
    inline uint rigid::joints_count() const
    {
        return valid() ? m_world.rigid_joints_count(m_ID) : 0;
    }
    inline joint rigid::first_joint() const
    {
        return valid() ? m_world.first_rigid_joint(m_ID) : joint();
    }
    inline joint rigid::next_joint(const joint &_j) const
    {
        return (_j.get_rigid() == *this) ? m_world.next_rigid_joint(_j) : joint();
    }
    inline void rigid::destroy()
    {
        if (valid()) m_world.destroy_rigid(m_ID);
        m_ID = BAD_ID;
    }

    // field

    inline field::field()
    :
        m_world(*(world*)0), m_ID(BAD_ID)
    {}
    inline field::field(world &_world, uint _ID)
    :
        m_world(_world), m_ID(_ID)
    {}
    inline field::field(const field &_f)
    :
        m_world(_f.m_world), m_ID(_f.m_ID)
    {}
    inline field& field::operator = (const field &_f)
    {
        this->~field(); new(this) field(_f); return *this;
    }
    inline bool field::operator == (const field &_f) const
    {
        return valid() && (&m_world == &_f.m_world) && (m_ID == _f.m_ID);
    }
    inline bool field::valid() const
    {
        return &m_world != 0 && m_world.field_is_valid(m_ID);
    }
    inline const xname& field::name() const
    {
        return valid() ? m_world.get_field_name(m_ID) : xname_0;
    }
    inline shape field::create_shape(const xname &_name, const real4x4 &_transform) const
    {
        return valid() ? m_world.create_field_shape(m_ID, _name, _transform) : shape();
    }
    inline uint field::shapes_count() const
    {
        return valid() ? m_world.field_shapes_count(m_ID) : 0;
    }
    inline shape field::first_shape() const
    {
        return valid() ? m_world.first_field_shape(m_ID) : shape();
    }
    inline shape field::next_shape(const shape &_s) const
    {
        return (_s.get_field() == *this) ? m_world.next_field_shape(_s) : shape();
    }
    inline void field::destroy()
    {
        if (valid()) m_world.destroy_field(m_ID);
        m_ID = BAD_ID;
    }

    // world

    inline world::world(const xname &_name)
    :
        m_name(_name)
    {}
    inline const xname& world::name() const
    {
        return m_name;
    }
    inline bool world::shape_is_valid(uint _ID) const
    {
        return m_shapes.exists(_ID);
    }
    inline const xname& world::get_shape_name(uint _ID) const
    {
        return m_shapes.get(_ID).name;
    };
    inline rigid world::get_shape_rigid(uint _ID)
    {
        return rigid(*this, m_shapes.get(_ID).rigid_ID);
    }
    inline field world::get_shape_field(uint _ID)
    {
        return field(*this, m_shapes.get(_ID).field_ID);
    }
    inline bool world::joint_is_valid(uint _ID) const
    {
        return m_joints.exists(_ID);
    }
    inline const xname& world::get_joint_name(uint _ID) const
    {
        return m_joints.get(_ID).name;
    }
    inline rigid world::get_joint_rigid(uint _ID)
    {
        return rigid(*this, m_joints.get(_ID).rigid_ID);
    }
    rigid world::create_rigid(const xname &_name, const real4x4 &_transform)
    {
        uint l_rigid_ID = m_rigids.add();
        _rigid &l_rigid = m_rigids.get(l_rigid_ID);
        l_rigid.name = _name;
        l_rigid.transform = _transform;
        l_rigid.first_shape_ID = BAD_ID;
        l_rigid.first_joint_ID = BAD_ID;
        l_rigid.typed_rigid_ID = BAD_ID;
        l_rigid.shapes_count = 0;
        l_rigid.joints_count = 0;
        return rigid(*this, l_rigid_ID);
    }
    inline uint world::rigids_count() const
    {
        return m_rigids.count();
    }
    inline rigid world::first_rigid()
    {
        return rigid(*this, m_rigids.first_ID());
    }
    inline rigid world::next_rigid(const rigid &_r)
    {
        return rigid(*this, m_rigids.next_ID(_r.m_ID));
    }
    inline bool world::rigid_is_valid(uint _ID) const
    {
        return m_rigids.exists(_ID);
    }
    inline const xname& world::get_rigid_name(uint _ID) const
    {
        return m_rigids.get(_ID).name;
    };
    inline shape world::create_rigid_shape(uint _rigid_ID, const xname &_name, const real4x4 &_transform, real _friction, real _bouncing, real _density)
    {
        uint l_shape_ID = m_shapes.add();

        _shape &l_shape = m_shapes.get(l_shape_ID);
        l_shape.name = _name;
        l_shape.transform = _transform;
        l_shape.friction = _friction;
        l_shape.bouncing = _bouncing;
        l_shape.density = _density;
        l_shape.rigid_ID = _rigid_ID;
        l_shape.field_ID = BAD_ID;

        _rigid &l_rigid = m_rigids.get(_rigid_ID);
        l_shape.next_shape_ID = l_rigid.first_shape_ID;
        l_rigid.first_shape_ID = l_shape_ID;
        ++l_rigid.shapes_count;

        return shape(*this, l_shape_ID);
    }
    inline uint world::shapes_count() const
    {
        return m_shapes.count();
    }
    inline shape world::first_shape()
    {
        return shape(*this, m_shapes.first_ID());
    }
    inline shape world::next_shape(const shape &_s)
    {
        return shape(*this, m_shapes.next_ID(_s.m_ID));
    }
    inline uint world::rigid_shapes_count(uint _rigid_ID) const
    {
        return m_rigids.get(_rigid_ID).shapes_count;
    }
    inline shape world::first_rigid_shape(uint _rigid_ID)
    {
        return shape(*this, m_rigids.get(_rigid_ID).first_shape_ID);
    }
    inline shape world::next_rigid_shape(const shape &_s)
    {
        return shape(*this, m_shapes.get(_s.m_ID).next_shape_ID);
    }
    inline void world::destroy_rigid_shape(uint _shape_ID)
    {
        _shape &l_shape = m_shapes.get(_shape_ID);
        _rigid &l_rigid = m_rigids.get(l_shape.rigid_ID);
        if (l_rigid.first_shape_ID == _shape_ID)
        {
            l_rigid.first_shape_ID = l_shape.next_shape_ID;
        }
        else
        {
            uint l_prev_shape_ID = l_rigid.first_shape_ID;
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
        --l_rigid.shapes_count;
        m_shapes.remove(_shape_ID);
    }
    inline joint world::create_rigid_joint(uint _rigid_ID, const xname &_name, const real4x4 &_transform)
    {
        uint l_joint_ID = m_joints.add();

        _joint &l_joint = m_joints.get(l_joint_ID);
        l_joint.name = _name;
        l_joint.transform = _transform;
        l_joint.rigid_ID = _rigid_ID;

        _rigid &l_rigid = m_rigids.get(_rigid_ID);
        l_joint.next_joint_ID = l_rigid.first_joint_ID;
        l_rigid.first_joint_ID = l_joint_ID;
        ++l_rigid.joints_count;

        return joint(*this, l_joint_ID);
    }
    inline uint world::joints_count() const
    {
        return m_joints.count();
    }
    inline joint world::first_joint()
    {
        return joint(*this, m_joints.first_ID());
    }
    inline joint world::next_joint(const joint &_j)
    {
        return joint(*this, m_joints.next_ID(_j.m_ID));
    }
    inline uint world::rigid_joints_count(uint _rigid_ID) const
    {
        return m_rigids.get(_rigid_ID).joints_count;
    }
    inline joint world::first_rigid_joint(uint _rigid_ID)
    {
        return joint(*this, m_rigids.get(_rigid_ID).first_joint_ID);
    }
    inline joint world::next_rigid_joint(const joint &_j)
    {
        return joint(*this, m_joints.get(_j.m_ID).next_joint_ID);
    }
    inline void world::destroy_rigid_joint(uint _joint_ID)
    {
        _joint &l_joint = m_joints.get(_joint_ID);
        _rigid &l_rigid = m_rigids.get(l_joint.rigid_ID);
        if (l_rigid.first_joint_ID == _joint_ID)
        {
            l_rigid.first_joint_ID = l_joint.next_joint_ID;
        }
        else
        {
            uint l_prev_joint_ID = l_rigid.first_joint_ID;
            while (l_prev_joint_ID != BAD_ID)
            {
                _joint &l_prev_joint = m_joints.get(l_prev_joint_ID);
                if (l_prev_joint.next_joint_ID == _joint_ID)
                {
                    l_prev_joint.next_joint_ID = l_joint.next_joint_ID;
                    break;
                }
                l_prev_joint_ID = l_prev_joint.next_joint_ID;
            }
        }
        --l_rigid.joints_count;
        m_joints.remove(_joint_ID);
    }
    inline void world::destroy_rigid(uint _rigid_ID)
    {
        _rigid &l_rigid = m_rigids.get(_rigid_ID);
        while (l_rigid.first_shape_ID != BAD_ID) destroy_rigid_shape(l_rigid.first_shape_ID);
        while (l_rigid.first_joint_ID != BAD_ID) destroy_rigid_joint(l_rigid.first_joint_ID);
        m_rigids.remove(_rigid_ID);
    }
    field world::create_field(const xname &_name, const real4x4 &_transform)
    {
        uint l_field_ID = m_fields.add();
        _field &l_field = m_fields.get(l_field_ID);
        l_field.name = _name;
        l_field.transform = _transform;
        l_field.first_shape_ID = BAD_ID;
        l_field.shapes_count = 0;
        return field(*this, l_field_ID);
    }
    inline uint world::fields_count() const
    {
        return m_fields.count();
    }
    inline field world::first_field()
    {
        return field(*this, m_fields.first_ID());
    }
    inline field world::next_field(const field &_f)
    {
        return field(*this, m_fields.next_ID(_f.m_ID));
    }
    inline bool world::field_is_valid(uint _ID) const
    {
        return m_fields.exists(_ID);
    }
    inline const xname& world::get_field_name(uint _ID) const
    {
        return m_fields.get(_ID).name;
    };
    inline shape world::create_field_shape(uint _field_ID, const xname &_name, const real4x4 &_transform)
    {
        uint l_shape_ID = m_shapes.add();

        _shape &l_shape = m_shapes.get(l_shape_ID);
        l_shape.name = _name;
        l_shape.transform = _transform;
        l_shape.friction = 0;
        l_shape.bouncing = 0;
        l_shape.density = 0;
        l_shape.rigid_ID = BAD_ID;
        l_shape.field_ID = _field_ID;

        _field &l_field = m_fields.get(_field_ID);
        l_shape.next_shape_ID = l_field.first_shape_ID;
        l_field.first_shape_ID = l_shape_ID;
        ++l_field.shapes_count;

        return shape(*this, l_shape_ID);
    }
    inline uint world::field_shapes_count(uint _field_ID) const
    {
        return m_fields.get(_field_ID).shapes_count;
    }
    inline shape world::first_field_shape(uint _field_ID)
    {
        return shape(*this, m_fields.get(_field_ID).first_shape_ID);
    }
    inline shape world::next_field_shape(const shape &_s)
    {
        return shape(*this, m_shapes.get(_s.m_ID).next_shape_ID);
    }
    inline void world::destroy_field_shape(uint _shape_ID)
    {
        _shape &l_shape = m_shapes.get(_shape_ID);
        _field &l_field = m_fields.get(l_shape.field_ID);
        if (l_field.first_shape_ID == _shape_ID)
        {
            l_field.first_shape_ID = l_shape.next_shape_ID;
        }
        else
        {
            uint l_prev_shape_ID = l_field.first_shape_ID;
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
        --l_field.shapes_count;
        m_shapes.remove(_shape_ID);
    }

    inline void world::destroy_field(uint _field_ID)
    {
        _field &l_field = m_fields.get(_field_ID);
        while (l_field.first_shape_ID != BAD_ID) destroy_field_shape(l_field.first_shape_ID);
        m_fields.remove(_field_ID);
    }

}

#endif // __SIMULATION_HPP__