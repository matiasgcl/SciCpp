// Alg Lin Paralelo, construcciones básicas
#include <mpi.h>
#include <cmath>
#include <cassert>

class MpiVector
{
private:
    // Componentes asociadas a cada trozo de vector
    // mLo <= i < mHi
    int mLo, mHi, mSize;
    double* mData;
    double* mGlobalData;
public:
    MpiVector(int vecSize)
    {
        int num_procs = MPI::COMM_WORLD.Get_size();
        int rank = MPI::COMM_WORLD.Get_rank();
        int ideal_local_size = vecSize / num_procs; // ideal en el sentido que salvo la 'cola', será la partición estándar para paralelizar

        assert(ideal_local_size > 0);
        mLo = ideal_local_size * rank;
        mHi = ideal_local_size * (rank+1);

        // El proceso de más arriba (top) toma la cola
        if(rank==num_procs-1)
        {
            mHi = vecSize; // ojo esto es paralelizado! (es el mHi correspondiente a rank == num_procs-1)
        }
        assert(mHi > mLo); // verificar que no hay nada raro
        mData = new double[mHi - mLo];
        mGlobalData = new double[vecSize];
        mSize = vecSize;
    }
    ~MpiVector()
    {
        delete[] mData;
        delete[] mGlobalData;
    }

    double& operator[](int globalIndex)
    {
        // paso global -> local
        assert(mLo <= globalIndex && globalIndex < mHi);
        return mData[globalIndex-mLo];
    }

    int GetHi()
    {
        return mHi;
    }

    int GetLo()
    {
        return mLo;
    }

    double CalculateNorm() const
    {
        double local_sum = 0.0;
        for(int i=0; i<mHi-mLo; i++)
        {
            local_sum += mData[i]*mData[i];
        }
        double global_sum;
        MPI::COMM_WORLD.Allreduce(&local_sum, &global_sum, 1, MPI::DOUBLE, MPI::SUM);
        return sqrt(global_sum);
    }
    void UpdateGlobal()
    {
        int num_procs = MPI::COMM_WORLD.Get_size();
        int* num_per_proc = new int[num_procs];
        int local_size = mHi-mLo;
        MPI::COMM_WORLD.Allgather(&local_size, 1, MPI::INT, num_per_proc, 1, MPI::INT);
        int* lows_per_proc = new int[num_procs];
        MPI::COMM_WORLD.Allgather(&mLo, 1, MPI::INT, lows_per_proc, 1, MPI::INT);
        MPI::COMM_WORLD.Allgatherv(mData, local_size, MPI::DOUBLE, mGlobalData, num_per_proc, lows_per_proc, MPI::DOUBLE);
        delete[] num_per_proc;
        delete[] lows_per_proc;
    }
};