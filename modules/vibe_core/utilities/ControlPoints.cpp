/**
 * @file    ControlPoints.cpp
 * @author  Marcel Ritsema
 */

#include "ControlPoints.h"
namespace vibe {

    ControlPoints::ControlPoints()
        : indexSelected(-1), max(12)
    {

    }
    ControlPoints::~ControlPoints()
    {

    }

    const juce::Array<juce::Point<int>> &ControlPoints::getAll() const
    {
        return points;
    }

    void ControlPoints::add(const juce::Point<int> &point, bool selected)
    {
        PointComparator comparator;
        points.addSorted(comparator, point);
        if (selected)
            setSelected(point);
    }

    void ControlPoints::erase(int index)
    {
        // Remove element on specific position.
        points.remove(index);

        // Set selected index to -1.
        setSelected(-1);
    }

    void ControlPoints::setXY(int x, int y, int index)
    {
        DBG("Set PointXY Called. X = " + juce::String(x) + " and Y = " + juce::String(y) + " and Index = " + juce::String(index));
        auto& point = points.getReference(index);
        point.setXY(x, y);
    }

    void ControlPoints::setY(int y, int index)
    {
        auto& point = points.getReference(index);
        point.setY(y);
        DBG("Set PointY Called. X = " + juce::String(point.getX()) + " and Y = " + juce::String(y) + " and Index = " + juce::String(index));
    }

    void ControlPoints::setSelected(const juce::Point<int> &point)
    {
        int index = points.indexOf(point);

        if (index != -1)
            setSelected(index);
    }

    void ControlPoints::setSelected(int index)
    {
        indexSelected = index;
    }

    int ControlPoints::getIndexSelected() const
    {
        return indexSelected;
    }

    int ControlPoints::getIndexCloseBy(int x, int y, int margin) const
    {
        for (int i = 0; i < points.size(); ++i)
        {
            const juce::Point<int>& point = points[i];
            if (std::abs(x - point.getX()) < margin && std::abs(y - point.getY()) < margin)
            {
                // Found a point close by, return its index.
                return i;
            }
        }

        // No point found, return -1
        return -1;
    }

    int ControlPoints::getTotal() const
    {
        return static_cast<int>(points.size());
    }

    void ControlPoints::setMax(int maximum)
    {
        max = maximum;
    }

    int ControlPoints::getMax() const
    {
        return max;
    }

    void ControlPoints::sort()
    {
        PointComparator comparator;
        points.sort(comparator);
    }

    int ControlPoints::PointComparator::compareElements(const juce::Point<int> &p1, const juce::Point<int> &p2) const
    {
        return p1.getX() - p2.getX();
    }

} // namespace vibe
