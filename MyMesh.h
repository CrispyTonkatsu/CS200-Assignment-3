/**
 * File: MyMesh.hpp
 * Name: Edgar Jose Donoso Mansilla (e.donosomansilla)
 * Assignment: 2
 * Course: CS200
 * Term: FALL24
 */

#pragma once

#include <cstdlib>
#include <vector>
#include "Mesh.h"

namespace cs200 {
  class MyMesh final : public cs200::Mesh {
  public:
    MyMesh();

    // Vertex Functions
    int vertexCount() const override;
    const glm::vec4 *vertexArray() const override;

    // Edge Functions
    int edgeCount() const override;
    const Edge *edgeArray() const override;

    // Face Functions
    int faceCount() const override;
    const Face *faceArray() const override;

    // Dimension functions
    glm::vec4 dimensions() const override;
    glm::vec4 center() const override;

  private:
    std::vector<glm::vec4> vertices;
    std::vector<Edge> edges;
    std::vector<Face> faces;

  };
} // namespace cs200
