#pragma once

#include "Event.h"
#include "sxpch.h"

namespace Simplex {

    class SIMPLEX_EXPORT KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }
        virtual std::string ToString() const;

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(const int keycode)
            : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class SIMPLEX_EXPORT KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const int keycode, const int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };

    class SIMPLEX_EXPORT KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(const int keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}