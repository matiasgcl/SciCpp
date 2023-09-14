#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[])
{
    MPI::Init(argc, argv);

    int num_procs = MPI::COMM_WORLD.Get_size();
    int rank = MPI::COMM_WORLD.Get_rank();
    std::cout << "Hola mundo desde el proceso " << rank << " de " << num_procs << "\n";
    
    MPI::Finalize();
    return 0;
}