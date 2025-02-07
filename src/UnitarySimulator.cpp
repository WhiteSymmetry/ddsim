#include "UnitarySimulator.hpp"

#include "dd/FunctionalityConstruction.hpp"

#include <chrono>

template<class Config>
void UnitarySimulator<Config>::Construct() {
    // carry out actual computation
    auto start = std::chrono::steady_clock::now();
    if (mode == Mode::Sequential) {
        e = dd::buildFunctionality(CircuitSimulator<Config>::qc.get(), Simulator<Config>::dd);
    } else if (mode == Mode::Recursive) {
        e = dd::buildFunctionalityRecursive(CircuitSimulator<Config>::qc.get(), Simulator<Config>::dd);
    }
    auto end         = std::chrono::steady_clock::now();
    constructionTime = std::chrono::duration<double>(end - start).count();
}

template class UnitarySimulator<dd::DDPackageConfig>;
