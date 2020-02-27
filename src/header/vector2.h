#pragma once

class Vector2
{
    private:
        int x, y;
    public:
        Vector2();
        Vector2(int x, int y);
        Vector2(const Vector2 &p);

        int getVector2X() const;
        int getVector2Y() const;
        void getVector2ByR(int &x, int &y);

        void setVector2(const int &x, const int &y);
        void setVector2X(const int &x);
        void setVector2Y(const int &y);

        Vector2& operator=(const Vector2 &other);

};
namespace std{
    bool isOverSize(const Vector2 &pos, const Vector2 &limit);
    bool isOverSize(const Vector2 &pos, const int &limit_x, const int &limit_y);
    bool isOverSize(const int &pos_x, const int &pos_y, const int &limit_x, const int &limit_y);
    bool isOverSize(const int &pos_x, const int &pos_y, const Vector2 &limit);
}