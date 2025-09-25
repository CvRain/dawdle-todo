#include "application.hpp"

int main(const int argc, char *argv[])
{
    auto application = Application(argc, argv);
    return application.exec();
}
