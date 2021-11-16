#include <iostream>
#include <filesystem>
#include <stdlib.h>
#include <cstring>
#include <string>

#include <FEBoundary.hpp>

int main(int argc, char *argv[]) {

    if(argc != 8){
        std::cout << "argc != 8, adjust parameters please. Args now = "<< argc << std::endl;
        return EXIT_FAILURE;
    }

    unsigned designLimitStress = std::stoul(argv[1]);
    std::string FEfullPath = std::string(argv[2]);
    std::string pinPath = std::string(argv[3]);
    std::string threadPath = std::string(argv[4]);
    std::string PRPath = std::string(argv[5]);
    std::string subtractRegionExportPath = std::string(argv[6]);
    std::string regionDataExportPath = std::string(argv[7]);

    std::cout << "in CppFeValidator before validation" << std::endl;

    fe::FEBoundary validator(
        designLimitStress,
        FEfullPath,
        pinPath,
        threadPath,
        PRPath,
        subtractRegionExportPath,
        regionDataExportPath
    );

    if(!validator.isFeasibleSolution()){
        std::cout << "Sadly this case was not feasible" << std::endl;
        return 1;
    }
    std::cout << "This case was feasible! Returning 0" << std::endl;
    return 0;
}
