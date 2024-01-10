#include "ControlPoints.h"
namespace vibe {

    ControlPoints::ControlPoints()
        : indexPointSelected(-1), maxPoints(12)
    {

    }
    ControlPoints::~ControlPoints()
    {

    }

    const juce::Array<juce::Point<float>> &ControlPoints::getPoints() const
    {
        return points;
    }

    void ControlPoints::addPoint(const juce::Point<float> &point, bool setSelected)
    {
        points.add(point);
        sortPoints();
        if (setSelected)
            setPointSelected(point);
    }

    void ControlPoints::deletePoint(int index)
    {
        // Remove element on specific position.
        points.remove(index);

        // Set selected index to -1.
        setPointSelected(-1);
    }

    void ControlPoints::setPointXY(int x, int y, int index)
    {
        DBG("Set PointXY Called. X = " + juce::String(x) + " and Y = " + juce::String(y) + " and Index = " + juce::String(index));
        auto& point = points.getReference(index);
        point.setXY(x, y);
    }

    void ControlPoints::setPointY(int y, int index)
    {
        auto& point = points.getReference(index);
        point.setY(y);
        DBG("Set PointY Called. X = " + juce::String(point.getX()) + " and Y = " + juce::String(y) + " and Index = " + juce::String(index));
    }

    void ControlPoints::setPointSelected(const juce::Point<float> &point)
    {
        int index = points.indexOf(point);

        if (index != -1)
            setPointSelected(index);
    }

    void ControlPoints::setPointSelected(int index)
    {
        indexPointSelected = index;
    }

    int ControlPoints::getIndexPointSelected() const
    {
        return indexPointSelected;
    }

    int ControlPoints::getIndexPointCloseBy(int x, int y, int margin) const
    {
        for (int i = 0; i < points.size(); ++i)
        {
            const juce::Point<float>& point = points[i];
            if (std::abs(x - point.getX()) < margin && std::abs(y - point.getY()) < margin)
            {
                // Found a point close by, return its index.
                return i;
            }
        }

        // No point found, return -1
        return -1;
    }

    int ControlPoints::getPointsTotal() const
    {
        return static_cast<int>(points.size());
    }

    bool ControlPoints::isFirstPoint(const juce::Point<float> &point) const
    {
        return false;
    }

    bool ControlPoints::isLastPoint(const juce::Point<float> &point) const
    {
        return false;
    }

    void ControlPoints::setPointsMax(int max)
    {
        maxPoints = max;
    }

    int ControlPoints::getPointsMax() const
    {
        return maxPoints;
    }

    void ControlPoints::sortPoints()
    {
        // Lambda comparator function for sorting points.
        auto comparePoints = [](const juce::Point<float>& p1, const juce::Point<float>& p2) {
            // Compare based on x-coordinate.
            return p1.getX() < p2.getX();
        };

        std::sort(points.begin(), points.end(), comparePoints);
    }

} // namespace vibe
