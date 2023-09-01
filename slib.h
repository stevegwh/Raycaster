#pragma once
#include <utility>
#include <vector>
#include <iostream>


namespace slib
{
struct vec2;
struct vec3;
struct vec4;
struct mat;

    struct zvec2
    {
        float x, y, w;
    };
    
    struct vec2
    {
        float x, y;
    };
    
    struct vec3
    {
        float x, y, z;
        vec3 &operator+=(float rhs);
        vec3 &operator-=(float rhs);
        vec3 &operator*=(float rhs);
        vec3 &operator/=(float rhs);
        vec3 operator-(float rhs) const;
        vec3 operator+(float rhs) const;
        vec3 operator*(float rhs) const;
        vec3 operator/(float rhs) const;
        vec3 &operator+=(const vec3 &rhs);
        vec3 &operator-=(const vec3 &rhs);
        vec3 &operator*=(const vec3 &rhs);
        vec3 &operator/=(const vec3 &rhs);
        vec3 operator-(const vec3 &rhs) const;
        vec3 operator+(const vec3 &rhs) const;
        vec3 operator*(const vec3 &rhs) const;
        vec3 operator/(const vec3 &rhs) const;
        vec3 operator*(const mat &rhs) const;
        vec3 operator*=(const mat &rhs);
        bool operator==(const vec3 &rhs) const;
        bool operator==(float rhs) const;
    };
    
    struct vec4
    {
        float x, y, z, w;
        vec4 operator*(const mat &rhs) const;
        vec4 operator*=(const mat &rhs);
    };
    
    struct mat
    {
        std::vector<std::vector<float>> data;
        explicit mat(std::vector<std::vector<float>> _data)
            : data(std::move(_data))
        {};
    
        mat &operator+=(const mat &rhs);
        mat &operator*=(const mat &rhs);
        mat operator*(const mat &rhs) const;
        mat operator*(const vec4 &rhs) const;
    
    };
    
    struct Frustum;
    
    struct Camera
    {
        vec3 pos;
        vec3 rotation;
        vec3 direction;
        const float zFar;
        const float zNear;
        Frustum *frustum;
        Camera(vec3 _pos, vec3 _rotation, vec3 _direction, float _zFar, float _zNear, Frustum *_frustum)
            :
            pos(_pos), rotation(_rotation), direction(_direction), zFar(_zFar), zNear(_zNear), frustum(_frustum)
        {};
    };
    
    struct Frustum
    {
        const float nearW;
        const float nearH;
        const float farW;
        const float farH;
        float near{};
        float far{};
        Frustum(float _nearW, float _nearH, float _farW, float _farH)
            :
            nearW(_nearW), nearH(_nearH), farW(_farW), farH(_farH)
        {};
    };
    
    struct Edge
    {
        vec3 &v1;
        vec3 &v2;
    };
    
    /*
     * Contains the index of the relevant vertices in the mutable vertices array of the object.
     */
    struct tri
    {
        int v1, v2, v3;
        vec3 center;
        vec3 normal;
    };
    
    struct Color
    {
        float r, g, b;
    };
}
