#include <iostream>

#include "kompute/Kompute.hpp"

std::string device_type_to_string(vk::PhysicalDeviceType type) {
    switch (type) {
        case vk::PhysicalDeviceType::eOther:
            return "Other";
        case vk::PhysicalDeviceType::eIntegratedGpu:
            return "Integrated GPU";
        case vk::PhysicalDeviceType::eDiscreteGpu:
            return "Discrete GPU";
        case vk::PhysicalDeviceType::eVirtualGpu:
            return "Virtual GPU";
        case vk::PhysicalDeviceType::eCpu:
            return "CPU";
    }
    return "";
}

int main() {
    // Create a Kompute Manager
    kp::Manager mgr;

    // Get the GPU device properties
    vk::PhysicalDeviceProperties device_properties = mgr.getDeviceProperties();

    // Print the GPU information
    std::cout << "GPU Information:" << std::endl;
    std::cout << "  API Version: " << device_properties.apiVersion << std::endl;
    std::cout << "  Driver Version: " << device_properties.driverVersion
              << std::endl;
    std::cout << "  Vendor ID: " << device_properties.vendorID << std::endl;
    std::cout << "  Device ID: " << device_properties.deviceID << std::endl;
    std::cout << "  Device Type: "
              << device_type_to_string(device_properties.deviceType)
              << std::endl;
    std::cout << "  Name: " << device_properties.deviceName << std::endl;
    std::cout << "  Memory Size: "
              << device_properties.limits.maxMemoryAllocationCount << " MB"
              << std::endl;

    return 0;
}
