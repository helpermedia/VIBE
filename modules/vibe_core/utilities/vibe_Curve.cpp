/**
 * @file    vibe_Curve.cpp
 * @author  Marcel Ritsema
 */

#include "vibe_Curve.h"

namespace vibe {

    Curve::Curve() : cType(CurveType::Linear), pointsMax(12)
    {

    }

    Curve::~Curve()
    {

    }

    const juce::Array<juce::Point<float>>& Curve::getPoints() const
    {
        return points;
    }

    const juce::Point<float>& Curve::getPoint(int index) const
    {
        return points.getReference(index);
    }

    void Curve::addPoint(const juce::Point<float> &point)
    {
        PointComparator comparator;
        points.addSorted(comparator, point);

        // New point added, path needs to be (re)created.
        createPath();
    }

    void Curve::addPoint(const juce::Point<int> &point)
    {
        addPoint(point.toFloat());
    }

    void Curve::addPoint(float x, float y)
    {
        juce::Point<float> point;
        point.setXY(x, y);
        addPoint(point);
    }

    void Curve::addPoint(int x, int y)
    {
        addPoint(static_cast<float>(x), static_cast<float>(y));
    }

    void Curve::erasePoint(int index)
    {
        points.remove(index);

        // Point is removed, path needs to be (re)created.
        createPath();
    }

    void Curve::setPointXY(float x, float y, int index)
    {
        auto& point = points.getReference(index);
        point.setXY(x, y);

        // Point position changed, path needs to be (re)created.
        createPath();
    }
    void Curve::setPointXY(int x, int y, int index)
    {
        setPointXY(static_cast<float>(x), static_cast<float>(y), index);
    }

    void Curve::setPointY(float y, int index)
    {
        auto& point = points.getReference(index);
        point.setY(y);

        // Point position changed, path needs to be (re)created.
        createPath();
    }

    void Curve::setPointY(int y, int index)
    {
        auto &point = points.getReference(index);
        point.setY(static_cast<float>(y));
    }

    int Curve::getIndexPointNearby(float x, float y, int margin) const
    {
        for (int i = 0; i < points.size(); ++i)
        {
            const juce::Point<float> &point = points[i];
            if (std::abs(x - point.getX()) < static_cast<float>(margin) && std::abs(y - point.getY()) < static_cast<float>(margin))
            {
                return i;
            }
        }
        return -1;
    }

    int Curve::getIndexPointNearby(int x, int y, int margin) const
    {
        return getIndexPointNearby(static_cast<float>(x), static_cast<float>(y), margin);
    }

    int Curve::getPointsMax() const
    {
        return pointsMax;
    }

    CurveType Curve::getCurveType()
    {
        return cType;
    }

    void Curve::setCurveType(CurveType curveType)
    {
        cType = curveType;
    }

    const juce::Path& Curve::getPath() const
    {
        return path;
    }

    void Curve::sortPoints()
    {
        PointComparator comparator;
        points.sort(comparator);
    }

    int Curve::PointComparator::compareElements(const juce::Point<float>& p1, const juce::Point<float>& p2) const
    {
        return p1.getX() - p2.getX();
    }

    void Curve::createPath()
    {
        
        DBG("Create path called.");
        
        // Reset path.
        path.clear();

        if (points.size() > 0)
        {
            path.startNewSubPath(points[0]);

            switch (cType)
            {
                case CurveType::Linear:
                    for (int i = 1; i < points.size(); ++i)
                    {
                        path.lineTo(points[i]);
                    }
                    break;
                case CurveType::Cubic:
                    break;
                case CurveType::Quadratic:
                    break;
            }
        }
    }

} // namespace vibe

