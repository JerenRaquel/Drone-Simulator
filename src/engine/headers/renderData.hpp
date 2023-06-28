#ifndef RENDERDATA_HPP_
#define RENDERDATA_HPP_

class MeshRenderData;
class TextRenderData;

// Std
#include <string>
// Lib
#include "mat4x4.hpp"
// Engine
#include "material.hpp"
#include "transform.hpp"
#include "util/vector.hpp"
#include "shaders/shader.hpp"
#include "camera.hpp"

class MeshRenderData {
 private:
  std::string meshType_;
  Material* material_;    // Freed in other classes
  Transform* transform_;  // Freed in other classes

 public:
  bool shouldRender_ = true;

  /*
    Types: ["Cone", "Quad"]
   */
  MeshRenderData(const std::string& meshType, Material* material,
                 Transform* transform);
  ~MeshRenderData();

  // Utility
  void PassUniforms(const Shader* const shader,
                    const glm::mat4x4& cameraMatrix) const noexcept;
  void UnbindTexture() const noexcept;

  // Getters
  const std::string& GetMeshType() const noexcept;
  Material* const GetMaterial() const noexcept;
  Transform* const GetTransform() const noexcept;
};

class TextRenderData {
 private:
  std::string text_;
  Vector<int> position_;
  float scale_;

 public:
  bool shouldRender_ = true;
  Vector3<float> color_;

  TextRenderData(const std::string& text, const Vector<int>& position,
                 const Vector3<float>& color, const float& scale);
  ~TextRenderData();

  // Getters
  const std::string& GetText() const noexcept;
  const Vector<int>& GetPosition() const noexcept;
  const float GetScale() const noexcept;
};
#endif  // RENDERDATA_HPP_