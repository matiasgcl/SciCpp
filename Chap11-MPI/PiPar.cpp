#include <cmath>
#include <iostream>
#include <mpi.h>

// Serie para cálcular pi, un clásico:
// pi = 4*sum (-1)^n/(2n+1)

int main(int argc, char* argv[])
{
    int max_n = 100000;
    double sum = 0;

    double start, end;

    MPI::Init(argc, argv);

    MPI_Barrier(MPI_COMM_WORLD); /* IMPORTANT */
    start = MPI_Wtime();

    int num_procs = MPI::COMM_WORLD.Get_size();
    int rank = MPI::COMM_WORLD.Get_rank();

    for (int n = rank; n < max_n; n += num_procs)
    {
        // para ahorrar cálculos, no calculo (-1)^n, me pongo en casos
        double tmp = 1.0/(2.0*((double)(n))+1.0);
        if (n%2==0)
        {
            sum += tmp;
        }
        else
        {
            sum -= tmp;
        }
    }

    double global_sum;
    // void Comm::Reduce(const void* sendbuf, void* recvbuf, int count, const MPI::Datatype& datatype, const MPI::Op& op, int root) const
    MPI::COMM_WORLD.Reduce(&sum, &global_sum, 1, MPI::DOUBLE, MPI::SUM, 0);
    if (rank==0)
    {
        std::cout << "Pi es aproximadamente " << 4.0*global_sum << " con error " << 4.0*global_sum - M_PI << "\n";
    }

    MPI_Barrier(MPI_COMM_WORLD); /* IMPORTANT */
    end = MPI_Wtime();
    MPI::Finalize();

    if (rank == 0) { /* use time on master node */
        printf("Runtime = %f\n", end-start);
    }

    return 0;
}