//
// Created by Steve Wheeler on 23/08/2023.
//
#pragma once
#include <utility>
#include <vector>
#include "slib.h"
#include "sMaths.hpp"

struct Mesh
{
    const std::vector<slib::vec3> verticies;
    const std::vector<slib::tri> faces;
    const std::vector<slib::vec2> textureCoords;
    const slib::texture texture;
    const slib::vec3 centroid;
    Mesh(const std::vector<slib::vec3>& _verticies, const std::vector<slib::tri>& _faces, 
         const std::vector<slib::vec2>& _textureCoords, slib::texture  _texture) :
        verticies(_verticies), faces(_faces), textureCoords(_textureCoords), texture(std::move(_texture)),
        centroid(sMaths::getCentroid(verticies))
    {}
};
