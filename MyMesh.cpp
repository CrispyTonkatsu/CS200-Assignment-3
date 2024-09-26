/**
 * File: MyMesh.cpp
 * Name: Edgar Jose Donoso Mansilla (e.donosomansilla)
 * Assignment: 2
 * Course: CS200
 * Term: FALL24
 */

#include "MyMesh.h"
#include "Affine.h"

// How many peaks the star will have, any
static constexpr unsigned peak_count = 5;
static constexpr float spacing_angle = static_cast<float>(360) / static_cast<float>(peak_count);
// How far the spikes are supposed to
static constexpr float peak_distance = 3.f;
const glm::vec4 peak_location = glm::vec4(peak_distance, 0, 0, 1);
// The "radius" of the core
static constexpr float core_width = 2.f;
const glm::vec4 core_location = cs200::rotate(spacing_angle / 2) * glm::vec4(core_width, 0, 0, 1);
// Whether to display specific edges
const bool inner_edges = false;
const bool outer_edges = true;

namespace cs200 {
  MyMesh::MyMesh() {
    // Adding the origin to the list
    vertices.emplace_back(center());

    // Adding the core vertices
    for (unsigned i = 1; i < peak_count + 1; i++) {
      glm::mat4 rotation = rotate(static_cast<float>(i) * spacing_angle);

      vertices.emplace_back(rotation * core_location);

      if (inner_edges) edges.emplace_back(0, i);

      if (i != 1 && inner_edges) edges.emplace_back(i - 1, i);

      faces.emplace_back(0, i, i + 1);
    }

    // Adding the last edge and face
    if (inner_edges) edges.emplace_back(1, peak_count);
    faces.emplace_back(0, 1, peak_count);

    // Adding the peak vertices
    for (unsigned i = 1; i < peak_count + 1; i++) {
      glm::mat4 rotation = rotate(static_cast<float>(i) * spacing_angle);

      vertices.emplace_back(rotation * peak_location);

      unsigned adjusted_index = peak_count + i;

      if (outer_edges) {
        if (i != 1) edges.emplace_back(i - 1, adjusted_index);
        edges.emplace_back(i, adjusted_index);
      }

      if (i != 1) faces.emplace_back(adjusted_index, i, i - 1);
    }

    // Adding the last edge and face
    if (outer_edges) edges.emplace_back(peak_count, peak_count + 1);
    faces.emplace_back(1, peak_count, peak_count + 1);
  }

  int MyMesh::vertexCount() const { return static_cast<int>(vertices.size()); }
  const glm::vec4 *MyMesh::vertexArray() const { return &vertices[0]; }

  int MyMesh::edgeCount() const { return static_cast<int>(edges.size()); }
  const MyMesh::Edge *MyMesh::edgeArray() const { return &edges[0]; }

  int MyMesh::faceCount() const { return static_cast<int>(faces.size()); }
  const MyMesh::Face *MyMesh::faceArray() const { return &faces[0]; }

  glm::vec4 MyMesh::dimensions() const { return vector(peak_distance * 2, peak_distance * 2); }
  glm::vec4 MyMesh::center() const { return point(0, 0); }

} // namespace cs200
