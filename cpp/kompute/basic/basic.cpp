#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "kompute/Kompute.hpp"

static std::vector<uint32_t> compile_source(const std::string& file_name) {
    std::string cmd =
        "glslangValidator -V " + file_name + " -o basic/basic.comp.spv";

    if (system(cmd.c_str())) {
        throw std::runtime_error("Error running glslangValidator command");
    }

    std::ifstream fileStream("basic/basic.comp.spv", std::ios::binary);
    std::vector<char> buffer;
    buffer
        .insert(buffer.begin(), std::istreambuf_iterator<char>(fileStream), {});

    return {
        (uint32_t*)buffer.data(),
        (uint32_t*)(buffer.data() + buffer.size())
    };
}

int main() {
    kp::Manager mgr;

    auto tensorInA = mgr.tensor({2.0, 4.0, 6.0});
    auto tensorInB = mgr.tensor({0.0, 1.0, 2.0});
    auto tensorOut = mgr.tensor({0.0, 0.0, 0.0});

    std::string shader("basic/basic.comp.glsl");

    std::vector<std::shared_ptr<kp::Tensor>> params =
        {tensorInA, tensorInB, tensorOut};

    std::shared_ptr<kp::Algorithm> algo =
        mgr.algorithm(params, compile_source(shader));

    mgr.sequence()
        ->record<kp::OpTensorSyncDevice>(params)
        ->record<kp::OpAlgoDispatch>(algo)
        ->record<kp::OpTensorSyncLocal>(params)
        ->eval();

    std::cout << "Output: {  ";
    for (const float& elem : tensorOut->vector()) {
        std::cout << elem << "  ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
