#ifndef DRONEMANAGER_HPP_
#define DRONEMANAGER_HPP_

// Std
#include <map>
#include <string>
#include <vector>
// Custom
#include "drone.hpp"

class DroneManager {
 private:
  std::vector<Drone*>* allDrones_;
  std::map<std::string, std::vector<Drone*>*>* droneMap_;

 public:
  DroneManager();
  ~DroneManager();

  // Utility
  void OnStart(Engine* const engine) const noexcept;
  void OnUpdate(Engine* const engine) const noexcept;
  DroneManager* const AddDrone(Drone* drone, const std::string& tag) noexcept;
  std::vector<Drone*>* const FilterBasedOnRange(
      std::vector<Drone*>* drones, const Vector<float>& position,
      const float& range) const noexcept;
  // Getters
  std::vector<Drone*>* const GetAllDrones() const noexcept;
  unsigned int GetAllDroneCount() const noexcept;
  std::vector<Drone*>* const GetDronesByTag(
      const std::string& tag) const noexcept;
  unsigned int GetDroneCountByTag(const std::string& tag) const noexcept;
  Drone* const GetDroneByTagId(const std::string& tag,
                               unsigned int id) const noexcept;
};
#endif  // DRONEMANAGER_HPP_