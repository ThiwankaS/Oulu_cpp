#include "DrawableObject.hpp"
#include <Log.hpp>

namespace pixelmancy::graphics {

DrawableObject::DrawableObject()
{
}

void DrawableObject::setPosition(const Point& position)
{
    m_position = position;
}

void DrawableObject::setAngle(float angle)
{
    m_angle = angle;
}

const Point& DrawableObject::getPosition() const
{
    return m_position;
}

float DrawableObject::getAngle() const
{
    return m_angle;
}

void DrawableObject::drawOn(Image& image) const
{
    P_LOG_WARN() << "Class does not have a 'drawOn()'\n";
    (void)image;
}

} // namespace pixelmancy::graphics
